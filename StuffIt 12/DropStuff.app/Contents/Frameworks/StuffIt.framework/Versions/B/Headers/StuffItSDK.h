/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDK.h
//
//   Description:   Interfaces for accessing the StuffIt Engine.
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
//  $Id: StuffItSDK.h,v 1.18.2.1 2006/10/05 00:17:52 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\mainpage StuffIt Engine SDK
	
	The StuffIt Engine SDK is a cross-platform suite of APIs allowing a client to access
	the StuffIt Engine for basic \ref compress and \ref expand as well as more advanced
	tasks such as \ref manipulation of an archive's contents.
	
	\section contents Contents
	- \ref installation_page
	- \ref usage_page
	- \ref examples_page

	\page installation_page Installation
	
	\section installation Installation
	\subsection mac_install Mac OS X Installation
	
	The SDK is broken into two parts, the SDK and the StuffIt Engine. The SDK consists of StuffIt.framework which
	provides a stub library with symbols to link against.
	This framework should be placed into your build system wherever it is most convenient for your projects. 
	It is what your projects will link against.
	
	The StuffIt Engine has two main pieces, StuffIt.framework and StuffItCore.framework. Within StuffItCore.framework
	is a Plug-Ins folder which contains the different archive, compression, and encoding formats the engine knows about.
	It is recommended that the StuffIt Engine be placed in your bundle's Frameworks folder rather than installing it 
	in a global location such as /Library/Frameworks to avoid possible conflicts. The engine can be customized by removing
	the format plugins which are not used by your product.
		
	There are two versions of the StuffIt SDK, A and B, the latter being the current one. The main difference
	between the two is which OS libraries they are linked against. The B version only links against CoreServices making it suitable
	for executables that need to run in environments where a WindowServer might not be present, consequently, the B version supplies no
	user interface what-so-ever. The B version also does not support older file system types, namely the FSSpec structure as well as 
	any type that relies on Carbon to function such as AEDesc. The A version link against Carbon and also will supply user interface 
	if desired. It is recommended that you use the B version as it will be the only one supported into the future.
	
	\subsection win_install Windows Installation
	
	Forthcoming.
	
	\page usage_page Using the StuffIt Engine SDK
	\section using Using the StuffIt Engine SDK
	
	In order for the SDK to be cross platform, certain data types and object representations
	needed to be abstracted. \ref strings and references to \ref fsobjects need to be converted
	from their platform specific types to their respective StuffIt SDK types.
	
	\subsection strings Strings
	
	The StringRef is used to provide strings to the SDK where necessary. A StringRef can
	be created a number in a number of ways that is dependant on the platform the SDK is 
	executing on. For instance, a c string or pascal string may be used to create a StringRef on
	Windows or MacOS, but only the MacOS supports creation of a StringRef from a CFString.
	
	Example:
	\code
	NewStringRefFromCString("hello world", &newString)
	\endcode

	See StuffItSDKStrings.h.
	
	\subsection fsobjects File System Objects
	
	An #FSObjectRef is the sole way of providing objects to the SDK that represent an item
	within the file system. Similar to #StringRef, creation of an #FSObjectRef varies
	by platform.
	
	Example:
	\code
	NewFSObjectFromFSRef(&someFileRef, NULL, &newFSObject)
	\endcode

	See StuffItSDKFiles.h.

	\subsection usage Basic Usage
	
	Using the SDK generally entails calling #OpenStuffItEngine, building the FSObjectRefs and StringRefs that reference the
	files or archives to work with, passing them to an expansion or compression routine, disposing of the items created
	and closing the engine.
	
	Example:
	\code
	EngineError		err = kStuffItErrorNoError;
	EngineRef		engineRef = NULL;
	
	err = OpenStuffItEngine(&engineRef, NULL);
	
	...do stuff...
	
	err = CloseStuffItEngine(engineRef);
	\endcode
	
	Also see \ref examples_page.
	
	When more control is necessary, then the #EngineRef returned by #OpenStuffItEngine can be configured to behave in various ways.
	For instance, by default expanding a .sitx.hqx archive will expand both the binhex (.hqx) and StuffIt X archive (.sitx) in one
	step. However, this may not always be desirable and the engine can be changed to only expand the binhex portion using the
	APIs defined in StuffItSDKOptions.h, which would look like 
	\code
	SetEngineIntegerProperty(theEngine, kEnginePropertyIDExpansionOptions, kExpandOnlyInitialArchive)
	\endcode
	
	It might be helpful to think of an EngineRef as an object and it's property data members.
	
	Similarly, when dealing with compression or encoding, formats can be customized, such as enabling encryption, by calling
	APIs in StuffItSDKFormats.h. For example, to enable encryption when creating a StuffIt X archive you would call
	\code
	SetFormatIntegerProperty(theEngine, kFormatIDStuffItX, kFormatPropertyIDCurrentEncryptionMethod, kEncryptionMethodDefault)
	\endcode
	and then start the compression.
	
	\subsection expansion Expansion
	
	The most commonly used expansion API is #ExpandOrDecodeFile.
	\code
	ExpandOrDecodeFile(engineRef, someArchive, NULL, NULL, NULL)
	\endcode
	would expand an archive referenced by someArchive into the same location that the archive was in.
	The other parameters are optional and determine destination, the result, and a password respectively.
	 
	See \ref expand example.
	
	\subsection compression Compression
	
	When compressing an archive, the two most common routines are #CompressOrEncodeFSObject and #ArchiveFSObjectList.
	\code
	CompressOrEncodeFSObject(engineRef, kFormatIDStuffItX, sourceFile, NULL, NULL, NULL)
	\endcode
	would create a StuffIt X archive in the same location as the item referenced by sourceFile. Similar to expansion, the
	destination, result, and password can all be ignored to get default behavior.
	Note: If encryption is desired, it is not enough to simply supply a passphrase as formats that provide encryption may
	have different encryption methods and the format needs to know which one to use first. Calling
	\code
	SetFormatIntegerProperty(theEngine, kFormatIDStuffItX, kFormatPropertyIDCurrentEncryptionMethod, kEncryptionMethodDefault)
	\endcode
	before calling CompressOrEncodeFSObject and supplying a passphrase would create an encrypted archive.
	
	\code
	ArchiveFSObjectList(engineRef, kFormatIDStuffItX, sourceFiles, NULL, NULL, NULL)
	\endcode
	is similar to #CompressOrEncodeFSObject except that it allows for a collection of files and folders to be
	archived.

	See \ref compress example.
	
	\subsection notifications Notifications
	
	The SDK uses notifications to provide the client with status information about the expansion or compression
	as well as other interactions that might require user feedback such as request for passwords or
	locating the next part of a segmented archive.
	
	Example:
	\code
	void Expand(EngineRef engineRef, FSObjectRef someArchive)
	{
	EngineError	err = kStuffItErrorNoError;
	
	NotificationCallback	callback = NewNotificationCallback(PasswordNotification);
	err = InstallNotification(engineRef, kQueryNotificationClass, kPasswordNotification, callback, NULL);
	
	//During expansion, any encrypted archive will trigger a password notification query
	err = ExpandOrDecodeFile(engineRef, someArchive, NULL, NULL, NULL);
	
	err = RemoveNotification(engineRef, kQueryNotificationClass, kPasswordNotification);
	DisposeNotificationCallback(callback);
	}
	
	_PASCAL_ QueryNotification PasswordNotification(NotificationClass inClass, NotificationMessage inMessage, ContextRef inContext, ContextUserData inUserData)
	{
		if (inClass != kQueryNotificationClass)
			{
			return kNotificationIgnored;
			}
		
		StringRef	password;
		
		//Get the password from the user and put it in a StringRef
		//Note: The context of this callback may not be the main thread. 
		EngineError err = NewStringRefFromCString("new password", &password);
		
		//The SDK assumes ownership of the string created from NewStringRef...
		SetDataInContext(inContext, kPasswordQueryDataTag, &password, sizeof(StringRef *));
		
		return kNotificationHandled;
	}
	\endcode
	
	Notifications are bound to the engine in which they are created, so installing a notification on an EngineRef and
	using another will not yield desirable results.
	
	See StuffItSDKNotifications.h and StuffItSDKOptions.h.

	\subsection ui User Interface
	
	This section is deprecated and no longer supported.
	
	The SDK can display user interface in four different areas, progress, password entry,
	destination selection, and return receipt handling. User Interface can be entirely
	suppressed by setting the EngineStatusCallbackProcPtr to SuppressStatusProc. See 
	StuffItSDKCallbacks.h and StuffItSDKOptions.h.
	
	As of the 0x820 version, the SDK will no longer provide any user interface. On Mac OS X, the SDK links against
	CoreServices.framework allowing it to be used from many different contexts such as command line tools and
	GUI apps.
	
	The SDK provides a notification mechanism defined in StuffItSDKNotifications.h for getting status during an operation
	or when it's necessary for information to be supplied during an expansion or compression.
	
	\subsection threads Using the StuffIt SDK from a thread
	
	As of version 0x810, the SDK can be used from within a preemptive thread. When called from such
	a thread, any user interface that the engine might display will be suppressed. Typically, a client
	would use notifications to handle any user feedback. Be aware that when using notifications, the context in
	which the notification is delivered may not be in the main thread of the executable.
	
	In general, when using the StuffIt SDK from a thread, it's a good idea to create an #EngineRef specific to that thread.
	
	\section examples Examples
	Examples of SDK Usage can be found \ref examples_page here.
*/


/*!
	\file StuffItSDK.h
	
	\brief Interfaces for accessing opening and closing the StuffIt Engine and for determining
	version information and registration.
*/

#ifndef STUFFITSDK_H
#define STUFFITSDK_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKERRORS_H
#include <StuffIt/StuffItSDKErrors.h>
#endif

#if TARGET_RT_MAC_CFM
	#ifndef __CODEFRAGMENTS__
	#include <CodeFragments.h>
	#endif
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

/*! \brief Useful for supplying no registration.

*/
#define	kNoRegistrationNumber		nil

/*! \brief Useful version constants.
    
    This is the version of the library you know about the top byte is the version, the bottom is the
    revision. See documentation for how to use this information.
*/

enum LibraryVersion {
    kCurrentLibraryVersion                  =   0x0830,		/**< kCurrentLibraryVersion Current version of the library. */
    kFirstSupportedEngine                   =   0x0700		/**< kFirstSupportedEngine Earliest version of the StuffIt Engine that can be used with the SDK. */ 
};

/*! \brief A reference to the StuffItEngine.

	An EngineRef is returned by OpenStuffItEngine and is used
	by many of the APIs throughout the SDK. It is disposed of
	with CloseStuffItEngine.

*/
typedef struct OpaqueEngineObject *         EngineRef;

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Engine version checking and availability                                          */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Get the version of the StuffIt Engine SDK
	
	Determine the version of the StuffIt Engine SDK.
	
	\return Version of the StuffIt Engine SDK
*/

extern _PASCAL_  int16_t
GetStuffItEngineLibraryVersion( void );

/*! \brief Get the verion of the StuffIt Engine.
	
	Determine the major version number, minor version number, patch level and build number 
    of the StuffIt Engine.
	
	The function supercedes the older GetVersionInfo function.

	\param inEngineRef Reference obtained from OpenStuffItEngine.
	\param outMajor Pointer to uint16_t representing a major version number. Null is invalid.
	\param outMinor Pointer to uint16_t representing a minor version number. Null is invalid.
	\param outPatchLevel Pointer to uint16_t representing a patch level. Null is invalid.
	\param outBuild Pointer to uint16_t representing a build number. Null is invalid.
	\return Returns an EngineError
*/
extern EngineError 
GetStuffItEngineVersionNumber(EngineRef inEngineRef, uint16_t* outMajor, uint16_t* outMinor, uint16_t* outPatchLevel, uint16_t* outBuild);

/*! \deprecated Use GetStuffItEngineVersionNumber instead. 
	\brief Get the verion of the StuffIt Engine SDK.
	
	Determine the major version number, minor version number, patch level and build number 
    of the StuffIt Engine SDK

	Note: The Mac OS version of this function returns its values in BCD making GetStuffItEngineVersionNumber a much better choice to get
	this information.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine.
	\param outMajor Pointer to uint16_t representing a major version number. Null is invalid.
	\param outMinor Pointer to uint16_t representing a minor version number. Null is invalid.
	\param outPatchLevel Pointer to uint16_t representing a patch level. Null is invalid.
	\param outBuild Pointer to uint16_t representing a build number. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
GetVersionInfo(EngineRef inEngineRef, uint16_t* outMajor, uint16_t* outMinor, uint16_t* outPatchLevel, uint16_t* outBuild);

/*! \brief Determine if the StuffIt Engine is registered
	
	Determine if the StuffIt Engine is registered

	\return True if the StuffIt Engine is registered.
*/
extern _PASCAL_ Boolean
IsStuffItEngineRegistered( void ) WEAK_LINK;

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Engine Open and Close                                                             */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*! \brief Opens the StuffIt Engine
	
	Initializes the StuffIt Engine and returns a reference used throughout
	the sdk.

	\param outEngineRef Reference returned if the engine has opened successfully. Null is invalid.
	\param registrationCode License code provided by Allume
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
OpenStuffItEngine(
    EngineRef *     outEngineRef,
    const char *	registrationCode ) WEAK_LINK;

/*! \brief Closes the StuffIt Engine
	
	Closes the StuffIt Engine and releases any resources created by it.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
CloseStuffItEngine(
    EngineRef       inEngineRef ) WEAK_LINK;


#if TARGET_RT_MAC_CFM
    #ifdef __cplusplus
        inline Boolean StuffItEngineLibraryAvailable() { return ((GetStuffItEngineLibraryVersion != (void*)kUnresolvedCFragSymbolAddress)); }
    #else
        #define StuffItEngineLibraryAvailable()  ((GetStuffItEngineLibraryVersion != (void*)kUnresolvedCFragSymbolAddress))
    #endif
#elif TARGET_RT_MAC_MACHO
	extern _PASCAL_ Boolean StuffItEngineLibraryAvailable() WEAK_LINK;
#elif TARGET_OS_WIN32
    #ifdef __cplusplus
        inline Boolean StuffItEngineLibraryAvailable() { return true; }	// TODO: Needs to change for MachO
    #else
        #define StuffItEngineLibraryAvailable()  (true)	// TODO: Needs to change for MachO
    #endif
#else
	#error Unknown Compiler Target
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif

/*!
	\page examples_page Examples
	\section compress Compression
	
	The following examples illustrate compression and expansion. They use Mac platform specific types
	for file system representation, but that is easily replaced with other representations.
	
	
	\code
	void ArchiveFiles(const std::vector<FSRef> &fileList)
	{
		EngineRef 	engineRef;
		EngineError	err = kStuffItErrorNoError;
		
		// Open the StuffIt Engine. Passing nil for the reg code param will return an error
		// if the user does not have registered version of deluxe installed.
		err = OpenStuffItEngine(&engineRef, nil);
		
		FSObjectListRef		filesToCompress;
		
		// Create a list of file system objects for the engine to compress.
		err = NewFSObjectList(mEngineRef, &filesToCompress);
		
		for (std::vector<FSRef>::iterator index = fileList.begin(); index != fileList.end(); ++index)
			{
			err = AddFSRefToFSObjectList(engineRef, *index, filesToCompress);
			}
		
		// Create a StuffItX archive in the same location as the source files
		// 
		// Uncomment to encode the archive with binhex. The first line is the preferred mechanism
		// for accessing options but is only available in sdk 8 and later. The second line is
		// available from 7.0 on and will eventually be removed.

		//err = SetEngineFormatIDProperty(engineRef, kEnginePropertyIDPostEncodingFormat, kFormatIDBinHex);
		//err = SetPostEncodingFormat(engineRef, kFormatIDBinHex);

		err = ArchiveFSObjectList(engineRef, kFormatIDStuffItX, filesToCompress, nil, nil, nil);
		
		// Everything that starts with New... has a corresponding Dispose. Similarly, everything that
		// starts with Acquire... has a paired Release.
		err = DisposeFSObjectList(filesToCompress);
		
		err = CloseStuffItEngine(engineRef);
	}
	\endcode
	
	\section expand Expansion

	\code
	void ExpandFile(const FSRef &archive)
	{
		EngineRef 	engineRef;
		EngineError	err = kStuffItErrorNoError;
		
		// Open the StuffIt Engine. Passing nil for the reg code param will return an error
		// if the user does not have registered version of deluxe installed.
		err = OpenStuffItEngine(&engineRef, nil);
		
		FSObjectRef		archiveToExpand;
		
		// Create file system object for the engine to expand.
		err = NewFSObjectFromFSRef(archive, NULL, &archiveToExpand);

		// Expand an archive in the same location as the source
		err = ExpandOrDecodeFile(engineRef, archiveToExpand, nil, nil, nil);
		
		// Everything that starts with New... has a corresponding Dispose. Similarly, everything that
		// starts with Acquire... has a paired Release.
		err = DisposeFSObject(filesToCompress);
		
		err = CloseStuffItEngine(engineRef);
	}

	\endcode
	
	\section manipulation Archive browsing

	Archive browsing and manipulation is very similar to accessing a hierarchical file system. An archive
	always has a root folder object which can be iterated, and its contents examined.
	
	\code
	void IterateArchiveRoot(EngineRef engine, FSObjectRef archiveFile)
	{
		EngineError	err = kStuffItErrorNoError;
		
		//Before opening an archive it must be acquired and eventually released.
		ArchiveRef	archiveRef;
		err = AcquireArchive(engine, archiveFile, &archiveRef);
		
		//Open the archive. Archives can be opened in read-only or read-write.
		//If the archive is encrypted, use #OpenEncryptedArchive
		err = OpenArchive(engine, archiveRef, kFullMode);
		
		//Acquire the root of the archive. It's a folder, so its contents can be
		//iterated. As will all APIs that begin with Acquire, the object will need
		//to be released.
		ArchiveObjectRef	rootObject;
		err = AcquireRootArchiveObject(archiveRef, &rootObject);
		
		//Create an iterator for the root object.
		ArchiveIteratorRef	iteratorRef;
		err = NewArchiveIterator(rootObject, &iteratorRef);
		
		//Examine the object the iterator currently points to.
		ArchiveObjectRef	currentObject;
		err = AcquireCurrentArchiveObject(iteratorRef, &currentObject);
		
		//Loop over each object the iterator references.
		while (err != kStuffItErrorNoObjectAtThatLocation)
			{
			//Get the name of the current object
			StringRef	objectName;
			err = AcquireArchiveObjectStringProperty(currentObject, kArchiveObjectPropertyIDName, &objectName);
			
			//Dispose of the name and the current object and get the next one
			err = DisposeStringRef(objectName);
			
			err = ReleaseArchiveObject(currentObject);
			
			err = AcquireNextArchiveObject(iteratorRef, &currentObject);
			}

		//And finally, dispose and release everything
		err = DisposeArchiveIterator(iteratorRef);
		
		err = ReleaseArchiveObject(rootObject);
		
		err = CloseArchive(archiveRef);
		
		err = ReleaseArchive(archiveRef);
	}
	\endcode
*/