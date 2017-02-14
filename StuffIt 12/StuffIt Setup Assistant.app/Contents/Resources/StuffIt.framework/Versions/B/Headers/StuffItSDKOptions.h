/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKOptions.h
//
//   Description:   Interfaces for accessing SDK options.
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
//  $Id: StuffItSDKOptions.h,v 1.29.2.1 2006/10/05 00:18:29 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKOptions.h
	
	\brief StuffItSDKOptions.h provides interfaces for accessing and customizing of
	the various properties of the SDK.
	
	When using various APIs within the StuffIt SDK, the behaviour of expansion and compression
	can be further refined by changing various engine properties. Most properties are accessed
	using GetEngineBooleanProperty or SetEngineBooleanProperty, or similarly named APIs. The
	rest are accessed with specific functions such as SetPeriodicCallbackUserData. There are older
	APIs that address each property specifically, but are deprecated in favor of the more generic
	accessors.
*/

#ifndef STUFFITSDKOPTIONS_H
#define STUFFITSDKOPTIONS_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKERRORS_H
#include <StuffIt/StuffItSDKErrors.h>
#endif

#ifndef STUFFITSDKCALLBACKS_H
#include <StuffIt/StuffItSDKCallbacks.h>
#endif

#ifndef STUFFITSDKFORMATS_H
#include <StuffIt/StuffItSDKFormats.h>
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
	\brief These are useful constants to pass to sdk option routines.
*/
enum {
    kPromptForDestination					=   true,
    kDontPromptForDestination				=   false,
	kResolveAliases                         =   true,
    kDontResolveAliases                     =   false,
    kRecompressCompressed                   =   false,
    kDontRecompressCompressed               =   true,
    kSaveComments                           =   true,
    kDontSaveComments                       =   false,
	kIgnoreInvisibleSystemItems				=	true,
	kDontIgnoreInvisibleSystemItems			=	false,
	kPreserveResourceFork					=	true,
	kDontPreserveResourceFork				=	false
};

/*!
	\brief Useful for supplying no password.
*/
#define kNoPassword 				nil

/*!
	\brief Useful for indicating destination is the same location as the original.
*/
#define	kDestinationSameAsOriginal	nil

/*!
	\brief Useful for ignoring the result.
*/
#define kIgnoreResult				nil

/*!
	\brief Conflict resolution method. Use for file system conflcits. See #ConflictResolutionMethods.
*/
typedef uint16_t ConflictResolutionMethod;
/*!
	\brief Options for resolving conflicts
	
	Used when expanding or compressing items and the destination has an item with the same
	name.
*/

enum ConflictResolutionMethods {
    kConflictResolutionPrompt               =   0,	/**< The StuffIt Engine allows the user to resolve the conflict by displaying a file browser. */
    kConflictResolutionReplaceExisting      =   1,	/**< The conflicting item in the destination will be replaced. */
    kConflictResolutionAutoRename           =   2,	/**< The conflicting item in the destination will be ignored and the new item will be renamed. */
    kConflictResolutionSkipItem             =   3,	/**< The conflicting item in the destination will be ignored and the new item will be skipped. */
	kConflictResolutionKeepNewer			=	4,	/**< The conflicting item is replaced if it is older. */
	kConflictResolutionErrorOnConflict		=	5,	/**< Return kStuffItErrorDuplicateFileNames if a conflict occurs. */
	kConflictResolutionMergeWithExisting	=	0x8000	/**< When a conflict exists at the folder level, merge the contents rather than replace them. */
};

/*
    Values for CopyArchiveObjects and MoveArchiveObjects
*/
/*!
	\brief Duplicate resolution method. Used for conflicts within archives. See #DuplicateResolutionMethods.
*/
typedef uint16_t DuplicateResolutionMethod;
/*!
	\brief Options for resolving name conflicts
	
	Used when adding, copying or moving items within archives and the destination has an 
	item with the same name.
*/
enum DuplicateResolutionMethods
{
    kCopyMoveErrorOnConflict        =   0,	/**< Return kStuffItErrorDuplicateFileNames if a conflict exists. */
    kCopyMoveReplaceOnConflict      =   1,	/**< Replace the conflicting item in the destination. */
    kReserved                       =   2,	/**< Not used*/
    kCopyMoveAutoRename				=	3,	/**< The conflicting item in the destination will be ignored and the new item will be renamed. */
	kCopyMoveReplaceOlder			=	4,	/**< Only replace if the existing item is older. */
	kCopyMoveReplaceFromFileSystem	=	5,	/**< If the item being added is from a file system, replace the conflicting item with it. */
	kCopyMoveKeepExisting			=	6,	/**< Keep the existing item when a conflict occurs. */
    kCopyMovePromptOnConflict       =   7,  /**< The StuffIt Engine allows the user to resolve the duplicate name conflict by displaying the Conflict Resolution Dialog. */
	kCopyMoveMergeWithExisting		=	0x8000	/**< When a conflict exists at the folder level, merge the contents rather than replace them. */
};

/*!
	\brief Folder creation method. See #CreateFolderMethods.
*/
typedef uint16_t CreateFolderMethod;
/*!
	\brief Options for creating folders during expansion
	
	When expanding an archive, the CreateFolderMethod can be specified to have the
	StuffIt Engine potentially create an enclosing folder around the expanded items.
*/
enum CreateFolderMethods {
    kCreateFolderNever                      =   0,	/**< Never create an enclosing folder. */
    kCreateFolderSmart                      =   1,	/**< Only create an enclosing folder if the archive contains mulitple items 
    													in its root, or the archive has a comment associated with it. */
    kCreateFolderAlways                     =   2	/**< Always create an enclosing folder. */
};


/*!
	\brief Encoding method. See #EncodeMethods.
*/
typedef uint16_t EncodeMethod;
/*!
	\brief Options for encoding files
	
	These options determine how a mulit-forked file is  encoded within an archive format
	 that doesn't support multi-forked files.
*/
 enum EncodeMethods{
    kEncodeNever                            =   0,	/**< Never encode the file. */
    kEncodeSmart                            =   1,	/**< Only encode the file if it contains multiple forks. On the Mac, Internet Config
														is queried to determine if the file needs encoding. */
    kEncodeAlways                           =   2	/**< Always encode the file. */
};

/*!
	\brief Delete Action. See #DeleteActions.
*/
typedef uint32_t DeleteAction;
/*!
	\brief Options for deleting source items after compression or expansion
	
	Using these flags with the compression of expansion APIs, will
	indicate to the StuffIt Engine what should be done with the source items.
*/
enum DeleteActions {
	kDontDelete								=	0,	/**< Ignore the source items. */
	kDeleteOriginals						=	1	/**< Delete the source items. */
};

/*!
	\brief Expansion Option. See #ExpansionOptions.
*/
typedef uint32_t ExpansionOption;

/*!
	\brief Options for expanding archives within archives.
*/
enum ExpansionOptions {
	kExpandOnlyInitialArchive = 0,	/**< Only expand the initial archive. */
	kExpandCompoundArchive = 1,	/**< Expand compound archives such as .sit.bin or .tar.gz. */
	kExpandNestedArchives = 2,	/**< Expand nested archives, eg. .tar.sit or MacBinary files encoded within a zip archive. */
	kExpandMacEncodings = 4	/**< Only expand nested archives that are Macintosh encodings, MacBinary, Binhex, and AppleSingle,
								 and that are stored within a format such as zip which does not have native support for Mac
								 resource forks. */
};

/*!
	\brief Preserve Mac Resource Output Option. See #ResourceOutputOptions.
*/
typedef uint32_t ResourceOutputOption;

/*!
	\brief Options for expanding sit5 and sitx archives containing resource and info as well as data fork. 
	This option is useful when expaning Mac archives on Windows.
*/
enum ResourceOutputOptions {
	kDoNotPreserve = 0,		/**< Do not preserve resource and info; expand only data fork. */
	kMacBinaryOutput = 1,	/**< MacBinary output. */
	kAppleDoubleOutput = 2,	/**< Apple Double output. */
	kNtfsOutput = 3			/**< NTFS stream output. */
};

/*!
	\brief Data clients of the SDK can supply for a compression filter.
*/
typedef void * CompressionFilterClientData;

/*!
	\brief The definition of the function to supply when adding a filter to the compression stream.
*/
typedef CALLBACK_API( Boolean, CompressionFilterProcPtr )(FSObjectRef, CompressionFilterClientData);

#if TARGET_OS_WIN32
	typedef CompressionFilterProcPtr    CompressionFilterUPP;
    #define NewCompressionFilterCallback(userRoutine)   ((CompressionFilterUPP)(userRoutine))
    #define DisposeCompressionFilterCallback(userUpp)
#elif TARGET_RT_MAC_MACHO || TARGET_RT_MAC_CFM
	typedef struct OpaqueCompressionFilter *    CompressionFilterUPP;
	extern _PASCAL_  CompressionFilterUPP NewCompressionFilterCallback(CompressionFilterProcPtr) WEAK_LINK;
	extern _PASCAL_  void DisposeCompressionFilterCallback(CompressionFilterUPP) WEAK_LINK;
#else
	#error Unknown Compiler Target
#endif

/*!
	\brief A reference to a compression filter.
*/
typedef struct OpaqueCompressionFilter *				CompressionFilterRef;

/*!
	\brief Engine Property identifier
*/
typedef const char *					  ConstEnginePropertyIDParam;

/** \defgroup BooleanEngineProperties Boolean based engine properties */

/*! 
	\brief Destination prompt property

	Setting kEnginePropertyIDDestinationPrompt to true will cause
	the SDK to display the OS's folder selection dialog allowing the
	user to select a destination. The default is kDontPromptForDestination.

	\ingroup BooleanEngineProperties
*/
#define		kEnginePropertyIDDestinationPrompt			"destinationPrompt"

/*!
	\brief Save archive comments property

	Setting the kEnginePropertyIDSaveComments property to true will save
	archive comments to a text file during expansion of an archive. The default 
	is kSaveComments.

	\ingroup BooleanEngineProperties
*/
#define		kEnginePropertyIDSaveComments				"saveComments"

/*! @ingroup BooleanEngineProperties 
	\brief Ignore return receipts property

	Setting the kEnginePropertyIDIgnoreReturnReceipts property to true will force the
	SDK to ignore return receipts associated with the archive during expansion. The default 
	is false.
*/
#define		kEnginePropertyIDIgnoreReturnReceipts		"ignoreReturnReceipts"

/*! \ingroup BooleanEngineProperties 
	\brief Resolve aliases property

	Setting the kEnginePropertyIDResolveAliases property to true will resolve any alias
	or shortcut that is passed explicitly to the SDK for compression. The default 
	is kDontResolveAliases.
*/
#define		kEnginePropertyIDResolveAliases				"resolveAliases"

/*! \ingroup BooleanEngineProperties 
	\brief Prevent recompression property

	Setting the kEnginePropertyIDNoRecompression property to true will prevent files of
	formats that are already compressed, such as another archive or mp3 file from being
	compressed again. The default is kDontRecompressCompressed.
*/
#define		kEnginePropertyIDNoRecompression			"noRecompression"

/*! \ingroup BooleanEngineProperties 
	\brief Ignore invisible system items property

	Setting the kEnginePropertyIDIgnoreInvisibleSystemItems property to true will prevent 
	invisible files generated by the OS from being added to an archive during compression. 
	Typically, these are files that contain information specific to the current user at the
	time of compression and generally do not serve any purpose as part of an archive. The 
	default is kDontIgnoreInvisibleSystemItems.
*/
#define		kEnginePropertyIDIgnoreInvisibleSystemItems	"ignoreInvisibleSystemItems"

/*! \ingroup BooleanEngineProperties 
	\brief Preserve Mac resource forks property
	\deprecated Use integer type property kEnginePropertyIDPreserveMacResource instead.

	Setting the kEnginePropertyIDPreserveResourceFork property to true will cause the SDK
	to preserve the resource fork of Macintosh files by encoding the resulting files into
	Mac binary when expanding on another OS that does not support Mac resource forks. 
	Setting kEnginePropertyIDPreserveMacResource overwrites this property.
	The default is false.
*/
#define		kEnginePropertyIDPreserveResourceFork		"preserveResourceFork"

/*! \ingroup BooleanEngineProperties 
	\brief Save root source path property

	If the kEnginePropertyIDSaveRootSourcePath property is true, any item added to the root level of
	an archive during compression will have the file system pathname added to that archive objects
	properties. This is useful for storing the origin of a file for later expansion to the same location. 
	The default is false.
*/
#define		kEnginePropertyIDSaveRootSourcePath			"saveRootSourcePath"

/** \defgroup IntegerEngineProperties Integer based engine properties */

/*! 
	\brief Preserve Mac resource forks property

	The kEnginePropertyIDPreserveMacResource property controls output from sit, sit5 and sitx archives 
	expansion when Mac resource or info is present. Setting the property to kMacBinaryOutput,
	will cause the SDK to encode the resulting files into Mac binary. Setting to kAppleDoubleOutput or kNtfsOutput
	will casue the SDK to output Mac REsource and info into apple double file or NTFS stream
	respectively. Setting this property overwrites kEnginePropertyIDPreserveResourceFork
	property.
	The default is #kDoNotPreserve.

	\ingroup IntegerEngineProperties
*/
#define		kEnginePropertyIDPreserveMacResource		"preserveMacResource"

/*!
	\brief Delete action property

	The kEnginePropertyIDDeleteAction property controls the how the source items are
	handled after a successful expansion or compression. After a successful exansion, the archive
	is deleted. After a successful compression, the items added to the archive are deleted. See
	#DeleteActions.
	 
	The default is #kDontDelete.

	\ingroup IntegerEngineProperties
*/
#define		kEnginePropertyIDDeleteAction				"deleteAction"

/*!
	\brief Conflict resolution property

	The kEnginePropertyIDConflictResolutionMethod property controls the how name collisions are
	handled within the file system. See #ConflictResolutionMethods.
	 
	The default is #kConflictResolutionAutoRename.

	\ingroup IntegerEngineProperties
*/
#define		kEnginePropertyIDConflictResolutionMethod	"conflictResolution"

/*!
	\brief Duplicate resolution property

	The kEnginePropertyIDDuplicateResolutionMethod property controls the how name collisions are
	handled within an archive. See #DuplicateResolutionMethods.
	 
	The default is #kCopyMoveErrorOnConflict.

	\ingroup IntegerEngineProperties
*/
#define		kEnginePropertyIDDuplicateResolutionMethod	"duplicateResolution"

/*!
	\brief Create folder method property

	The kEnginePropertyIDCreateFolderMethod property controls the creation of an enclosing folder
	when an archive is expanded. See #CreateFolderMethods.
	 
	The default is #kCreateFolderSmart.

	\ingroup IntegerEngineProperties
*/
#define		kEnginePropertyIDCreateFolderMethod			"createFolderMethod"

/*!
	\brief Expansion options property

	The kEnginePropertyIDExpansionOptions property controls how archives should be expanded. 
	See #ExpansionOptions.
	 
	The default is #kExpandCompoundArchive + #kExpandMacEncodings.

	\ingroup IntegerEngineProperties
*/
#define		kEnginePropertyIDExpansionOptions			"expansionOptions"

/*!
	\brief Pre-encoding method property

	The kEnginePropertyIDPreEncodingMethod property determines how files with
	resource forks should be handled when being added to a archive whose format
	does not support them. This property is used in conjuction with the 
	#kEnginePropertyIDPreEncodingFormat property. See #EncodeMethods.
	 
	The default is #kEncodeSmart.

	\ingroup IntegerEngineProperties
*/
#define		kEnginePropertyIDPreEncodingMethod			"preEncodingMethod"

/** \defgroup FormatIDProperties FormatID based engine properties */

/*!
	\brief Pre-encoding format property

	The kEnginePropertyIDPreEncodingFormat property indicates which format should
	be used when encoding a file with a resource fork into an archive whose format
	does not support them. This property is used in conjuction with the 
	#kEnginePropertyIDPreEncodingMethod property.
	 
	The default is #kFormatIDNone.

	\ingroup FormatIDProperties
*/
#define		kEnginePropertyIDPreEncodingFormat			"preEncodingFormat"

/*!
	\brief Post-encoding format property

	The kEnginePropertyIDPostEncodingFormat property indicates which format should
	be used when encoding an archive. Typically, this property is used to create
	compound archives such as .sit.bin or .tar.gz.
	 
	The default is #kFormatIDNone.

	\ingroup FormatIDProperties
*/
#define		kEnginePropertyIDPostEncodingFormat			"postEncodingFormat"

/*!
	\brief Create a read-only archive

	The kEnginePropertyIDReadOnlyArchive property specifies that a new archive be 
	created read-only. The option is only useful with APIs that create and add 
	content all in one step such as #CompressOrEncodeFSObject and #ArchiveFSObjectList
	and formats like StuffItX which can create such an archive.
	 
	The default is false.

	\ingroup BooleanEngineProperties
*/
#define		kEnginePropertyIDReadOnlyArchive			"readOnly"

/*!
	\brief Set executable permission.

	The kEnginePropertyIDForceExecutable property set the executable bit on systems that
	support such a bit in their permissions model. For formats where the executable bit
	is available, this property is ignored.
	 
	The default is false.

	\ingroup BooleanEngineProperties
*/
#define 	kEnginePropertyIDForceExecutable			"executable"

/*!
	\brief Controls the use of threads in the engine.
	
	kEnginePropertyUseThreads when set to true, will allow the engine to use threads. This
	property controls formats that havve the ability to distribute operations across
	multiple threads. See #kFormatPropertyIDMaxThreads.
	
	The default is false.
*/
#define		kEnginePropertyIDUseThreads					"useThreads"

/*!
	\brief Controls how the engine opens an archive.
	
	kEnginePropertyIDOpenCompoundArchives when set to true, enables the engine to open a compound archive, such
	as a .tar.gz, and provide access directly to the tar archive. If false, the gz archive would be returned.	
	See AcquireArchive.
	
	The default is true.
*/
#define		kEnginePropertyIDOpenCompoundArchives		"openCompoundArchives"

/*!
	\brief Restore sdk options.
	
	Set each property of the sdk to its default value.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
RestoreSDKOptionsToDefaults(
	EngineRef		inEngineRef ) WEAK_LINK;

/*!
	\brief Gets a boolean engine property.
	
	Gets the specified boolean engine property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inPropertyID Property to get. Null is invalid.
	\param outValue New setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError  
GetEngineBooleanProperty(
	EngineRef					inEngineRef,
	ConstEnginePropertyIDParam	inPropertyID,
	Boolean *		 			outValue) WEAK_LINK;

/*!
	\brief Sets a boolean engine property.
	
	Sets the specified boolean engine property to true or false.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inPropertyID Property to set. Null is invalid.
	\param inValue New setting.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
SetEngineBooleanProperty(
	EngineRef					inEngineRef,
	ConstEnginePropertyIDParam	inPropertyID,
	Boolean 		 			inValue) WEAK_LINK;


/*!
	\brief Gets an integer engine property.
	
	Gets the specified integer engine property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inPropertyID Property to get. Null is invalid.
	\param outValue New setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError  
GetEngineIntegerProperty(
	EngineRef					inEngineRef,
	ConstEnginePropertyIDParam	inPropertyID,
	uint32_t *		 			outValue) WEAK_LINK;

/*!
	\brief Sets an integer engine property.
	
	Sets the specified integer engine property to true or false.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inPropertyID Property to set. Null is invalid.
	\param inValue New setting.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
SetEngineIntegerProperty(
	EngineRef					inEngineRef,
	ConstEnginePropertyIDParam	inPropertyID,
	uint32_t 		 			inValue) WEAK_LINK;

/*!
	\brief Gets a FormatID engine property.
	
	Gets the specified FormatID engine property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inPropertyID Property to get. Null is invalid.
	\param outValue New setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError  
GetEngineFormatIDProperty(
	EngineRef					inEngineRef,
	ConstEnginePropertyIDParam	inPropertyID,
	FormatID 		 			outValue) WEAK_LINK;

/*!
	\brief Sets a FormatID engine property.
	
	Sets the specified FormatID engine property to true or false.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inPropertyID Property to set. Null is invalid.
	\param inValue New setting.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
SetEngineFormatIDProperty(
	EngineRef					inEngineRef,
	ConstEnginePropertyIDParam	inPropertyID,
	ConstFormatIDParam 		 	inValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Sets the destination prompt property
	
	If this property is true, the SDK will prompt the user for a destination.
	
	The default is kDontPromptForDestination.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue New setting.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
SetDestinationPrompt(
	EngineRef		inEngineRef, 
	Boolean			inValue ) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Gets the destination prompt property.
	
	Returns the current value of the prompt for destination property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetDestinationPrompt(
	EngineRef		inEngineRef, 
	Boolean *		outValue ) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Sets the delete action property.
	
	Determines how the SDK will handle source items after an operation is successful.
	The default is kDontDelete.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue New setting. See DeleteActions.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
SetDeleteAction(
	EngineRef		inEngineRef, 
	DeleteAction	inValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Gets the delete action property.
	
	Returns the current value of the delete action property.
	
	The default is kDontDelete.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetDeleteAction(
	EngineRef		inEngineRef,
	DeleteAction *	outValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Sets the conflict resolution property.
	
	Determines how the SDK will handle duplicate name conflicts during an operation
	such as compression or expansion.
	
	The default is kConflictResolutionAutoRename.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue New setting. See ConflictResolutionMethods.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetConflictResolutionMethod(
	EngineRef					inEngineRef, 
	ConflictResolutionMethod 	inValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Gets the conflict resolution property.
	
	Returns the current value of the conflict resolution property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
GetConflictResolutionMethod(
	EngineRef					inEngineRef, 
	ConflictResolutionMethod *	outValue) WEAK_LINK;

/*!
	\brief Sets the client provided status callback.
	
	Sets the client provided status callback.
	
	The default is kNoCallback.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue The callback. Null is valid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_ EngineError 
SetStatusCallback(
	EngineRef					inEngineRef, 
	EngineStatusCallbackUPP		inValue) WEAK_LINK;
#endif

/*!
	\brief Gets the current status callback.
	
	Returns the current status callback.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_ EngineError
GetStatusCallback(
	EngineRef					inEngineRef, 
	EngineStatusCallbackUPP *	outValue) WEAK_LINK;
#endif
/*!
	\brief Sets the client data.
	
	Sets the client data passed to the periodic and status callbacks.
	
	The default is null.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue The data. Null is valid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_ EngineError 
SetStatusCallbackUserData(
	EngineRef		inEngineRef, 
	SDKClientData	inValue) WEAK_LINK;
#endif
/*!
	\brief Gets the client data.
	
	Returns the current client data.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_ EngineError
GetStatusCallbackUserData(
	EngineRef			inEngineRef, 
	SDKClientData *		outValue) WEAK_LINK;
#endif
/*!
	\brief Sets the client provided periodic callback.
	
	Sets the client provided periodic callback.

	The default is kNoCallback.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue The callback. Null is valid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_ EngineError
SetPeriodicCallback(
	EngineRef					inEngineRef, 
	EnginePeriodicCallbackUPP	inValue) WEAK_LINK;
#endif
/*!
	\brief Gets the current periodic callback.
	
	Returns the current periodic callback.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_ EngineError
GetPeriodicCallback(
	EngineRef						inEngineRef, 
	EnginePeriodicCallbackUPP *		outValue) WEAK_LINK;
#endif
/*!
	\brief Sets the client data.
	
	Sets the client data passed to the periodic and status callbacks.
	
	The default is null.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue The data. Null is valid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_ EngineError 
SetPeriodicCallbackUserData(
	EngineRef		inEngineRef, 
	SDKClientData	inValue) WEAK_LINK;
#endif

#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
/*!
	\brief Gets the client data.
	
	Returns the current client data.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetPeriodicCallbackUserData(
	EngineRef			inEngineRef, 
	SDKClientData *		outValue) WEAK_LINK;
#endif

/*!
	\deprecated Use generic integer accessor.

	\brief Determines folder creation.
	
	Determines if an enclosing folder should be created when expanding an archive.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue See CreateFolderMethods.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetCreateFolderMethod(
	EngineRef				inEngineRef, 
	CreateFolderMethod		inValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Gets folder creation method.
	
	Returns the current value of the folder creation property.
	
	The default is kCreateFolderSmart.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetCreateFolderMethod(
	EngineRef 				inEngineRef,
	CreateFolderMethod *	outValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Sets archive expansion options.
	
	Sets the property that governs whether or not a compound archive is expanded until complete.
	
	The default is kExpandCompoundArchive + kExpandMacEncodings.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue Expansion options to use when expanding archives.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetExpansionOptions(
	EngineRef		inEngineRef,
	ExpansionOption	inValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Gets archive expansion options.
	
	Returns the current value of the expansion options.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetExpansionOptions(
	EngineRef		inEngineRef,
	ExpansionOption *outValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Sets the save comments property.
	
	Sets the property that governs whether or not archive comments are saved when an archive is expanded.

	The default is kSaveComments.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue True if archive comments should be saved.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetSaveComments(
	EngineRef		inEngineRef,
	Boolean			inValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Gets the save comments property.
	
	Returns the current value of the save comments property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetSaveComments(
	EngineRef		inEngineRef,
	Boolean *		outValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Sets the ignore return receipts property.
	
	Sets the property that governs if return receipts should be ignored
	during expansion.

	The default is false.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue True if return receipts should be ignored.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetIgnoreReturnReceipts(
	EngineRef		inEngineRef,
	Boolean			inValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Gets the ignore return receipts property.
	
	Returns the current value of the ignore return receipts property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetIgnoreReturnReceipts(
	EngineRef		inEngineRef,
	Boolean *		outValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Sets the resolve aliases property.
	
	Sets the property that governs whether or not aliases are resolved when compressing files.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue True if aliases should be resolved.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetResolveAliases(
	EngineRef		inEngineRef, 
	Boolean		 	inValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Gets the resolve aliases property.
	
	Returns the current value of the resolve aliases property.

	The default is kDontResolveAliases.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetResolveAliases(
	EngineRef		inEngineRef,
	Boolean *		outValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Sets the no recompression property.
	
	Sets the property that governs whether or not existing compressed items should
	be recompressed when adding them to an archive.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue True if recompression should not occur.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetNoRecompression(
	EngineRef		inEngineRef,
	Boolean			inValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Gets the no recompression property.
	
	Returns the current value of the no recompression property.

	The default is kDontRecompressCompressed.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine.
	\param outValue Current setting. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetNoRecompression(
	EngineRef		inEngineRef,
	Boolean *		outValue) WEAK_LINK;

/*!
	\deprecated Use generic FormatID accessor.

	\brief Sets the pre-encoding format.
	
	This sets the format to use when an item being added to an archive needs to be encoded. Works
	in conjunction with the pre-encoding method property.
	
	The default is kFormatNone.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue Format to encode with. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetPreEncodingFormat(
	EngineRef				inEngineRef,
	ConstFormatIDParam	inValue) WEAK_LINK;

/*!
	\deprecated Use generic FormatID accessor.

	\brief Gets the pre-encoding format.
	
	This returns the format currently used to encode items.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current format to encode with. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetPreEncodingFormat(
	EngineRef				inEngineRef, 
	FormatID 				outValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Sets the pre-encoding method format.
	
	Determines how items should be added to an archive. Works in
	conjunction with the pre-encoding type property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue Format to encode with. See EncodeMethods.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetPreEncodingMethod(
	EngineRef			inEngineRef, 
	EncodeMethod 		inValue) WEAK_LINK;
	
/*!
	\deprecated Use generic integer accessor.

	\brief Gets the pre-encoding method.
	
	This returns the current pre-encoding method.
	
	The default is kEncodeSmart.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current format to encode with. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetPreEncodingMethod(
	EngineRef			inEngineRef,
	EncodeMethod *		outValue) WEAK_LINK;

/*!
	\deprecated Use generic FormatID accessor.

	\brief Sets the post-encoding format.
	
	Determines how archives should be encoded after compression.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue Format to encode archive with. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetPostEncodingFormat(
	EngineRef				inEngineRef, 
	ConstFormatIDParam	inValue) WEAK_LINK;

/*!
	\deprecated Use generic FormatID accessor.

	\brief Gets the post-encoding format.
	
	This returns the current pre-encoding method.
	
	The default is kFormatNone.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current format to encode archive with. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetPostEncodingFormat(
	EngineRef				inEngineRef, 
	FormatID				outValue) WEAK_LINK;

/*!
	\deprecated Use generic integer accessor.

	\brief Sets the duplicate resolution method.
	
	Determines how duplicates should be handled when manipulating item within an archive.
	
	The default is kCopyMoveErrorOnConflict.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue New value. See DuplicateResolutionMethods.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetDuplicateResolutionMethod(
	EngineRef						inEngineRef, 
	DuplicateResolutionMethod		inValue) WEAK_LINK;
	
/*!
	\deprecated Use generic integer accessor.

	\brief Gets the current duplicate resolution method.
	
	This returns the current value of the duplicate resolution property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetDuplicateResolutionMethod(
	EngineRef						inEngineRef, 
	DuplicateResolutionMethod *		outValue) WEAK_LINK;

/*!
	\deprecated Use generic boolean accessor.

	\brief Sets the ignore invisible system items property.
	
	Determines if invisible items maintained by the OS should be ignored during compression.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inValue True if items should be ignored.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetIgnoreInvisibleSystemItems(
	EngineRef						inEngineRef, 
	Boolean							inValue) WEAK_LINK;
	
/*!
	\deprecated Use generic boolean accessor.

	\brief Gets the current ignore invisible system items property.
	
	This returns the current value of the ignore invisible system items property.
	
	The default is kDontIgnoreInvisibleSystemItems.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param outValue Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetIgnoreInvisibleSystemItems(
	EngineRef						inEngineRef, 
	Boolean *						outValue) WEAK_LINK;

/*!
	\brief Add a compression filter.
	
	Adds a compression filter that will be called prior to adding files to an
	archive. Remove it with RemoveCompressionFilter.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFilter The filter to be called. Null is invalid.
	\param inData Optional client data.
	\param outRef Pointer to a CompressionFilterRef to receive reference to filter. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
AddCompressionFilter(
	EngineRef						inEngineRef,
	CompressionFilterUPP			inFilter,
	CompressionFilterClientData		inData,
	CompressionFilterRef			*outRef) WEAK_LINK;

/*!
	\brief Remove a compression filter.
	
	Removes a compression filter added with AddCompressionFilter.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inRef The reference to the added filter. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
RemoveCompressionFilter(
	EngineRef						inEngineRef,
	CompressionFilterRef			inRef) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif