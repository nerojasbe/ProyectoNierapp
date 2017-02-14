/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKNotifications.h
//
//   Description:   Interfaces for working with strings.
//
//--------------------------------------------------------------------------------------------------
//
//  Copyright (c) 1992-2006 Smith Micro Software, Inc.
//
//  This source code and specific concepts contained herein are Confidential
//  Information and Property of Smith Micro Software.
//  Distribution is prohibited without written permission of Smith Micro Software.
//
//--------------------------------------------------------------------------------------------------
//
//  Allume Systems, Inc. a division of Smith Micro Software
//  185 Westridge Drive                    (831) 761-6200
//  Watsonville, CA  95076                 (831) 761-6206 FAX
//  http://www.stuffit.com/
//
//--------------------------------------------------------------------------------------------------
//  $Id:
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKNotifications.h
	
	\brief Interfaces for working with notifications.

	The SDK uses the notification mechanism to supply information to the client
	about the state of the current operation.
	
	For instance, it can be used to provide progress. It can also be used to pass
	data back to the SDK such as when an encrypted archive is being expanded but
	no password for given. If the password notification is installed, the client 
	would receive a notification and potentially display some user interface to
	get the password.
	
	Notifications are grouped by class and type. The #kFileSystemNotification contains
	#kFilePermissionsErrorNotification as one of its types. This notification would
	occur if a file was encountered during a compression that the current process did
	not have priviledges to.
	
	There are two general kinds of notifications. The most common is read-only and
	contains information about the operation such as the number of bytes completed in
	an expansion and the total bytes to expand. The other kind is a write-only, or query,
	notification where the client supplies data back to the SDK.

	A notification is installed by referencing its class and type. When the notification
	occurs, a opaque context pointer is provided which contains the data of interest for
	that notification. For #kFileSystemNotification, the context would contain an
	#FSObjectRef of the item the client is being notified about. Context data is
	retrieved by querying the context for a tag. Each context may have several different
	tags associated with it.

	The following table lists the notification class, type, and tag relationships.
	
	- #kFileSystemNotification
		- #kFilePermissionsErrorNotification
			- #kFSObjectDataTag
		- #kArchiveSegmentNotification
			- #kFSObjectDataTag
		- #kItemConflictNotification
			- #kFSObjectDataTag
			- #kEngineRefDataTag
			- #kArchiveObjectDataTag (Optional)
			
	- #kFileSystemPreflightNotification
		- #kFilePermissionsErrorNotification
			- #kFSObjectDataTag
			
	- #kProgressNotificationClass
		- #kInitializeNotification,
		- #kTerminateNotification,
		- #kPreProcessNotification,
		- #kItemProcessedNotification,
			- #kItemNameDataTag
		- #kStatusNotification,
			- #kItemsCompletedDataTag
			- #kTotalItemsDataTag
			- #kBytesCompletedDataTag
			- #kTotalBytesDataTag
	
	- #kQueryNotificationClass
		- #kPasswordNotification
			- #kEngineRefDataTag
			- #kArchiveObjectDataTag
			- #kPasswordQueryDataTag
		- #kSearchFolderNotification
			- #kEngineRefDataTag
			- #kItemNameDataTag
			- #kSearchFolderQueryDataTag
		- #kSourcePathNotification
			- #kEngineRefDataTag
			- #kFSObjectDataTag
			- #kPathQueryDataTag
			
	- #kGeneralNotificationClass
		- #kBeginNotification
			- #kEngineRefDataTag
		- #kEndNotification
			- #kEngineRefDataTag
			- #kEngineErrorDataTag

Here's an example of a notification that handle progress information.
\code
_PASCAL_ NotificationStatus ProgressNotification(NotificationClass inClass, NotificationMessage inMessage, ContextRef inContext, ContextUserData inUserData)
{
	if (inClass != kProgressNotificationClass)
		{
		return kNotificationIgnored;
		}
	
	uint64_t	completedBytes,
				totalBytes;
				
	GetDataFromContext(inContext, kBytesCompletedDataTag, &completedBytes, sizeof(completedBytes));
	GetDataFromContext(inContext, kTotalBytesDataTag, &totalBytes, sizeof(totalBytes));

	return kNotificationHandled;
}
\endcode

Here's another example of a notification illustrating a password query.
\code
_PASCAL_ QueryNotification PasswordNotification(NotificationClass inClass, NotificationMessage inMessage, ContextRef inContext, ContextUserData inUserData)
{
	if (inClass != kQueryNotificationClass)
		{
		return kNotificationIgnored;
		}
	
	StringRef	password;
	
	EngineError err = NewStringRefFromCString("new password", &password);
	
	//The SDK assumes ownership of the string created from NewStringRef...
	SetDataInContext(inContext, kPasswordQueryDataTag, &password, sizeof(StringRef *));
	
	return kNotificationHandled;
}
\endcode
*/

#ifndef STUFFITSDKNOTIFICATIONS_H
#define STUFFITSDKNOTIFICATIONS_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDK_H
#include <StuffIt/StuffItSDK.h>
#endif

#ifndef STUFFITSDKERRORS_H
#include <StuffIt/StuffItSDKErrors.h>
#endif

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

/*!
	\brief A reference to a context that is part of a notification event.
*/
typedef void * ContextRef;

/*!
	\brief A reference to the data that is contained within a ContextRef.
*/
typedef void * ContextUserData;

/*!
	\brief Message type used to identify a class of notifications.
*/
typedef uint32_t NotificationClass;

/*!
	\brief Message type used to identify notifications within a NotificationClass.
*/
typedef uint32_t NotificationMessage;

/*!
	\brief Tag type used to identify data within ContextData.
*/
typedef uint32_t ContextDataTag;

/*!
	\brief Status to indicate how the notification was handled by the client.
*/
typedef uint32_t  NotificationStatus;

/*!
	\brief The messages that can be returned by the client in NotificationStatus.
*/
enum NotificationStatusMessages
{
	kNotificationIgnored = 0,
	kNotificationHandled = 1,
	kNotificationCanceled
};

/*!
	\brief The callback for client installed notifications.
	
	This callback is invoked by the StuffIt Engine when the desired notification occurs. Depending on the notification,
	returning kNotificationHandled will cause the sdk to ignore operations that otherwise would have been performed. For
	example, files that do not have read permissions will cause the StuffIt Engine to stop, but a notification could be
	installed to log the event and have the engine continue.
	
	\param inClass The class of notification.
	\param inMessage The current state of the operation. 
	\param inContext The context associated with this event.
	\param inUserData Client supplied data.
	\return Return kNotificationHandled to suppress further action for this notification.
*/
typedef CALLBACK_API( NotificationStatus, NotificationCallbackProcPtr )(NotificationClass inClass, NotificationMessage inMessage, ContextRef inContext, ContextUserData inUserData);

#if TARGET_OS_WIN32
	typedef NotificationCallbackProcPtr    NotificationCallback;
    #define NewNotificationCallback(userRoutine)   ((NotificationCallback)(userRoutine))
    #define DisposeNotificationCallback(userUpp)
#elif TARGET_RT_MAC_MACHO || TARGET_RT_MAC_CFM
	typedef struct OpaqueNotificationProc *    NotificationCallback;
	extern _PASCAL_  NotificationCallback NewNotificationCallback(NotificationCallbackProcPtr) WEAK_LINK;
	extern _PASCAL_  void DisposeNotificationCallback(NotificationCallback) WEAK_LINK;
#else
	#error Unknown Compiler Target
#endif

/*!
	\brief Installs a notification.
	
	Installs a notification that will be invoked whenever the desired NotificationMessage occurs.

	\param inEngine An engine reference.
	\param inClass The class of notification to install.
	\param inMessage The desired notification to install.
	\param inCallback The callback to invoke.
	\param inUserData Client supplied data.
	\return EngineError.
*/
extern _PASCAL_ EngineError 
InstallNotification(
	EngineRef 				inEngine, 
	NotificationClass		inClass,
	NotificationMessage 	inMessage, 
	NotificationCallback 	inCallback, 
	ContextUserData			inUserData) WEAK_LINK;

/*!
	\brief Removes a notification.
	
	Removes a notification.

	\param inEngine An engine reference.
	\param inClass The class of notification to remove.
	\param inMessage The desired notification to install.
	\return EngineError.
*/
extern _PASCAL_ EngineError 
RemoveNotification(
	EngineRef				inEngine,
	NotificationClass		inClass,
	NotificationMessage 	inMessage) WEAK_LINK;

/*!
	\brief SDK notification classes.
*/
enum StuffItSDKNotificationClasses
{
	kFileSystemNotification = 1,			//!< File system related notifications
	kFileSystemPreflightNotification = 2,	//!< File system notifications occuring during preflight
	
	kProgressNotificationClass = 100,		//!< Progress notifications
	
	kQueryNotificationClass = 200,			//!< Query notifications

	kGeneralNotificationClass = 300			//!< General notifications
};

/*!
	\brief SDK notification types.
*/
enum StuffItSDKNotificationTypes
{
	//File System notification types.
	kFilePermissionsErrorNotification = 1,	//!< Permissions error type
	kArchiveSegmentNotification,			//!< Archive segment type
	kItemConflictNotification,				//!< Name conflict type
	
	//Progress notification types
	kInitializeNotification,				//!< Progress beginning type
	kTerminateNotification,					//!< Progress ending type
	kItemProcessedNotification,				//!< Item type
	kStatusNotification,					//!< Status type
	kPreProcessNotification,				//!< Item preprocess type
	
	//Password notification
	kPasswordNotification,					//!< Password query type
	
	//Search notification
	kSearchFolderNotification,				//!< New destination query type
	
	//Source path notification
	kSourcePathNotification,				//!< Source path query type

	//General notifications
	kBeginNotification,						//!< Sent at the start of an operation such as expansion
	kEndNotification						//!< Sent when an operation completes
};

/*!
	\brief Various data tags.
*/
enum DataTags
{
	//File system tags
	kFSObjectDataTag = 1,					//!< #FSObjectRef tag
	
	//EngineRef data tags
	kEngineRefDataTag,						//!< #EngineRef tag

	//Archive object data tags
	kArchiveObjectDataTag,					//!< #ArchiveObjectRef tag
	
	//Progress data tags
	kItemNameDataTag,						//!< #StringRef tag
	kItemsCompletedDataTag,					//!< 64 bit integer tag
	kTotalItemsDataTag,						//!< 64 bit integer tag
	kBytesCompletedDataTag,					//!< 64 bit integer tag
	kTotalBytesDataTag,						//!< 64 bit integer tag
	
	//Query data tags
	kPasswordQueryDataTag,					//!< #StringRef query tag
	kSearchFolderQueryDataTag,				//!< #FSObjectRef query tag
	kPathQueryDataTag,						//!< #StringRef query tag
	
	kEngineErrorDataTag						//!< #EngineError tag 

};

/*!
	\brief Gets data from a context.
	
	Given a ContextData tag and a corresponding ContextRef, outBuffer will contain the
	desired data if the ContextRef contains it and inBufferSize indicates that outBuffer
	is large enough to contain it.

	\param inContext the current context. 
	\param inTag The desired tag.
	\param outBuffer Container to hold the data. Null is invalid.
	\param inBufferSize Size of outBuffer. Zero is invalid.
	\return EngineError.
*/

extern _PASCAL_ EngineError
GetDataFromContext(
	ContextRef			inContext,
	ContextDataTag		inTag,
	void *				outBuffer,
	uint32_t			inBufferSize) WEAK_LINK;


/*!
	\brief Sets data in a context.
	
	Sets the given #ContextDataTag to the desired data. Only tags that are queries can
	be written to otherwise an error will be returned.

	\param inContext the current context. 
	\param inTag The desired tag.
	\param inData The buffer with the new data. Null is invalid.
	\param inDataSize Size of inData. Zero is invalid.
	\return EngineError.
*/
extern EngineError 
SetDataInContext(
	ContextRef			inContext,
	ContextDataTag		inTag,
	void *				inData,
	uint32_t			inDataSize) WEAK_LINK;

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif