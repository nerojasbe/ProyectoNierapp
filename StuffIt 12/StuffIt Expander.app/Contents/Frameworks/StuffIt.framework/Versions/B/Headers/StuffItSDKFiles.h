/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKFiles.h
//
//   Description:   Interfaces for working with files.
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
//  $Id: StuffItSDKFiles.h,v 1.15.2.1 2006/10/05 00:18:18 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKFiles.h
	
	\brief Interfaces for working with files.
*/

#ifndef STUFFITSDKFILES_H
#define STUFFITSDKFILES_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDK_H
#include <StuffIt/StuffItSDK.h>
#endif

#ifndef STUFFITSDKERRORS_H
#include <StuffIt/StuffItSDKErrors.h>
#endif

#ifndef STUFFITSDKSTRINGS_H
#include <StuffIt/StuffItSDKStrings.h>
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
	\brief A reference to a file system item.
*/
typedef struct OpaqueFSObject *				FSObjectRef; /* object used by engine to refer to file system entities*/

/*!
	\brief A reference to a list of FSObjectRefs.
*/
typedef struct OpaqueFileList *				FSObjectListRef; /* list of FSObjectRefs */

/** @defgroup Mac APIs only available on MacOS
 *  These functions, primarily in StuffItSDKFiles.h and StuffItSDKStrings.h are
 *	only available in the MacOS version of the SDK.
 *  @{
 */
 
 #if TARGET_OS_MAC
/*!
	\brief Creates a reference to a file system item from a FSSpec.
	
 	Creates an FSObjectRef from an FSSpec to a present or non-existent file system item.
	
	Mac only API.

	\param inSpec Pointer to a FSSpec to a present or non-existent file system item. Null is invalid.
	\param outObjectRef Pointer to FSObjectRef that will receive new reference. Must be disposed of with DisposeFSObject.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_  EngineError
NewFSObjectFromFSSpec(
	const FSSpec *		inSpec,
	FSObjectRef *		outObjectRef) WEAK_LINK;
#endif

/*!
	\brief Creates a reference to a file system item from a FSRef.
	
 	Creates an FSObjectRef from a FSRef to an existing file system item.
	
	Mac only API.

	\param inRef Pointer to a FSRef to an existing file system item. Null is invalid.
	\param inName If the desired FSObjectRef needs to reference a non-existant item, then
	provide the parent folder in the inRef paramater, and pass filename here. Can be null.
	\param outObjectRef Pointer to FSObjectRef that will receive new reference. Must be disposed of with DisposeFSObject.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewFSObjectFromFSRef(
	const FSRef *		inRef,
	const CFStringRef   inName, /* can be NULL */
	FSObjectRef *		outObjectRef) WEAK_LINK;

/*!
	\brief Creates a reference to a file system item from an AppleEvent descriptor.
	
 	Creates an FSObjectRef from an AEDesc. Attempts to coerce the descriptor
	to an appropriate type first with typeFileURL, then typeFSRef, and finally typeFSSpec.
	
	Mac only API.

	This API is no longer supported as it requires Carbon.framework which the SDK no longer
	links against.

	\param inDesc Pointer to an AEDesc that can be coerced into appropriate type. Null is invalid.
	\param outObjectRef Pointer to FSObjectRef that will receive new reference. Must be disposed of with DisposeFSObject.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_  EngineError
NewFSObjectFromAEDesc(
	const AEDesc *		inDesc,
	FSObjectRef *		outObjectRef) WEAK_LINK;
#endif

/*!
	\brief Creates a reference to a file system item from an AliasHandle.
	
	 Creates an FSObjectRef from an AliasHandle.
	
	Mac only API.

	\param inAlias The AliasHandle to use. Null is invalid.
	\param outObjectRef Pointer to FSObjectRef that will receive new reference. Must be disposed of with DisposeFSObject.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewFSObjectFromAliasHandle(
	const AliasHandle	inAlias,
	FSObjectRef *		outObjectRef) WEAK_LINK;

/*!
	\brief Create a new FSObject.
	
 	Creates an FSObjectRef from a CFURL.
	
	Mac only API.

	\param inURL The CFURL to use. Null is invalid.
	\param outObjectRef Pointer to FSObjectRef that will receive new reference. Must be disposed of with DisposeFSObject.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
NewFSObjectFromCFURL(
	const CFURLRef		inURL,
	FSObjectRef *		outObjectRef) WEAK_LINK;
#endif
/** @} */

/*!
	\brief  Creates a FSObjectRef from a path.
	
 	Creates a reference to a file system item from a fully qualified path in a c string.
	
	Common API.

	\param inCString The fully qualified path to use. Null is invalid.
	\param outObjectRef Pointer to FSObjectRef that will receive new reference. Must be disposed of with DisposeFSObject.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewFSObjectFromPath(
	const char *		inCString,
	FSObjectRef *		outObjectRef) WEAK_LINK;

/*!
	\brief  Creates a FSObjectRef from a path.
	
 	Creates a reference to a file system item from a fully qualified path in a wide-character string.
	
	Common API.

	\param inWString The fully qualified path to use. Null is invalid.
	\param outObjectRef Pointer to FSObjectRef that will receive new reference. Must be disposed of with DisposeFSObject.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewFSObjectFromUnicodePath(
	const NativeWideChar *		inWString,
	FSObjectRef *		outObjectRef) WEAK_LINK;

/*!
	\brief Releases a FSObjectRef.
	
	Disposes of an FSObjectRef created by any of the NewFSObjectXXX.
	
	Common API.

	\param inObject The FSObjectRef to dispose. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
DisposeFSObject(
	FSObjectRef			inObject) WEAK_LINK;

/*!
	\brief Get a c string representing a fully qualified path from a FSObjectRef.
	
 	Copies the fully qualified path form the FSObject into the StringRef. The
 	StringRef needs to be disposed of with DisposeStringRef.
	
	Common API.
	
	\param inObject The FSObjectRef. Null is invalid.
	\param outPath Pointer to a StringRef to receive path. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
AcquirePathFromFSObject(
	const FSObjectRef	inObject,
	StringRef *			outPath) WEAK_LINK;

#if TARGET_OS_MAC
/*!
	\ingroup Mac
	\brief Get a FSSpec from a FSObjectRef.
	
	Creates a FSSpec from a FSObjectRef.
	
	Mac only API.
	
	\param inObject The FSObjectRef. Null is invalid.
	\param outSpec Pointer to FSSpec to be extracted. Null is invalid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_  EngineError
GetFSSpecFromFSObject(
	const FSObjectRef	inObject,
	FSSpec *			outSpec) WEAK_LINK;
#endif

/*!
	\ingroup Mac
	\brief Get a FSRef from a FSObjectRef.
	
 	Creates a FSRef from a FSObjectRef. This only succeeds when
	the referenced file system item exists.
	
	Mac only API.

	\param inObject The FSObjectRef. Null is invalid.
	\param outRef Pointer to FSRef to be extracted. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
GetFSRefFromFSObject(
	const FSObjectRef	inObject,
	FSRef *				outRef) WEAK_LINK;

/*!
	\ingroup Mac
	\brief Get a CFURLRef from a FSObjectRef.
	
 	Creates a CFURLRef from a FSObjectRef.
	
	Mac only API.

	\param inObject The FSObjectRef. Null is invalid.
	\param outRef Pointer to CFURLRef to be extracted. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
GetCFURLFromFSObject(
	const FSObjectRef	inObject,
	CFURLRef *				outRef) WEAK_LINK;
#endif

/*!
	\brief Compares two FSObjectRefs for equality.
	
	Examines the given FSObjectRefs to determine if they
	reference the same file system item.
	
	Common API.

	\param inObjectA The FSObjectRef. Null is invalid.
	\param inObjectB The FSObjectRef. Null is invalid.
	\return Returns true if the FSObjectRefs reference the same item.
*/
extern _PASCAL_  Boolean
FSObjectsEqual(
	const FSObjectRef	inObjectA,
	const FSObjectRef	inObjectB) WEAK_LINK;

/*!
	\brief Copies one FSObjectRef to another.
	
 	Copies an existing FSObjectRef to a newly created one. Both
	will reference the same file system item.
	
	Common API.

	\param inObject The FSObjectRef. Null is invalid.
	\param outCopy Pointer to FSObjectRef to receive copy. Null is invalid. Must be disposed
	of with DisposeFSObject
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
CopyFSObject(
	const FSObjectRef inObject, 
	FSObjectRef *outCopy) WEAK_LINK;

/*!
	\brief Gets name from object.
	
 	Acquires a copy of the name of the FSObjectRef. The client is
	responsible for disposing of the returned StringRef.
	
	Common API.

	\param inObject The FSObjectRef. Null is invalid.
	\param outName Pointer to StringRef to receive name. Null is invalid. Must be disposed
	of with DisposeStringRef.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
AcquireFSObjectName(
	const FSObjectRef	inObject,
	StringRef			*outName) WEAK_LINK;

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ File Lists                                                                        */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Creates a file list.
	
 	Creates a new file list. The client is responsible for disposing the file
	list with DisposeFSObjectList.
	
	Common API.

	\param inEngineRef EngineRef returned from OpenStuffItEngine. Null is invalid.
	\param outFileList Pointer to FSObjectListRef to receive created file list. Null is invalid. Must be disposed
	of with DisposeFSObjectList.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewFSObjectList(EngineRef inEngineRef, FSObjectListRef *outFileList) WEAK_LINK;

#if TARGET_OS_MAC
/*!
	\ingroup Mac
	\brief Add a FSSpec to a file list.
	
 	Add a FSSpec to the given file list.
	
	Mac only API.

	\param inEngineRef EngineRef returned from OpenStuffItEngine. Null is invalid.
	\param inSrcSpec Pointer to a valid FSSpec. Null is invalid.
	\param inFileList A FSObjectListRef to update. Null is invalid.
	\return Returns an EngineError
*/
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
extern _PASCAL_  EngineError
AddFSSpecToFSObjectList(
	EngineRef			inEngineRef,
    const FSSpec *      inSrcSpec,
    FSObjectListRef		inFileList ) WEAK_LINK;
#endif

/*!
	\ingroup Mac
	\brief Add a CFURL to a file list.
	
 	Add a CFURL to the given file list.
	
	Mac only API.

	\param inEngineRef EngineRef returned from OpenStuffItEngine. Null is invalid.
	\param inSrcURL A valid CFURLRef that represents a file system URL. Null is invalid.
	\param inFileList A FSObjectListRef to update. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
AddCFURLToFSObjectList(
	EngineRef			inEngineRef,
    const CFURLRef      inSrcURL,
    FSObjectListRef		inFileList ) WEAK_LINK;

/*!
	\ingroup Mac
	\brief Add a FSRef to a file list.
	
 	Add a FSRef to the given file list.
	
	Mac only API.

	\param inEngineRef EngineRef returned from OpenStuffItEngine. Null is invalid.
	\param inSrcRef Pointer to a valid FSRef. Null is invalid.
	\param inFileList A FSObjectListRef to update. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
AddFSRefToFSObjectList(
	EngineRef			inEngineRef,
    const FSRef *      	inSrcRef,
    FSObjectListRef  	inFileList ) WEAK_LINK;
#endif

/*!
	\brief Add a pathname to a file list.
	
 	Add a pathname to an existing file list.
	
	Common API.

	\param inEngineRef EngineRef returned from OpenStuffItEngine. Null is invalid.
	\param inPath Pointer to a C string describing a valid file system path. Null is invalid.
	\param inFileList A FSObjectListRef to update. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
AddPathToFSObjectList(
	EngineRef			inEngineRef,
    const char *	  	inPath,
    FSObjectListRef		inFileList ) WEAK_LINK;

/*!
	\brief Add a pathname to a file list.
	
 	Add a unicode pathname to an existing file list.
	
	Common API.

	\param inEngineRef EngineRef returned from OpenStuffItEngine. Null is invalid.
	\param inPath Pointer to a wide-character string describing a valid file system path. Null is invalid.
	\param inFileList A FSObjectListRef to update. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
AddUnicodePathToFSObjectList(
	EngineRef			inEngineRef,
    const NativeWideChar *	  	inPath,
    FSObjectListRef		inFileList ) WEAK_LINK;

/*!
	\brief Add a FSObjectRef to a file list.
	
 	Appends a FSObjectRef to an existing file list.
	
	Common API.

	\param inEngineRef EngineRef returned from OpenStuffItEngine. Null is invalid.
	\param inSrcObject Valid FSObjectRef created from NewFSObjectXXX. Null is invalid.
	\param inFileList A FSObjectListRef to update. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
AddFSObjectToFSObjectList(
	EngineRef			inEngineRef,
    const FSObjectRef   inSrcObject,
    FSObjectListRef		inFileList ) WEAK_LINK;

/*!
	\brief Copy an FSObjectList.
	
	Creates a new FSObjectListRef and copies the contents of the
	supplied ArchiveListRef. The newly created list bust be disposed of with DisposeFSObjectList.
	
	Common API.

	\param inFileList FSObjectListRef to copy. Null is invalid.
	\param outFileList Pointer to FSObjectListRef to receive created copy. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
CopyFSObjectList(
	const FSObjectListRef	inFileList,
	FSObjectListRef			*outFileList) WEAK_LINK;

/*!
	\brief Determine the size of an FSObjectList.
	
 	Returns the number of elements stored within an FSObjectList.
	
	Common API.

	\param inFileList FSObjectListRef to count. Null is invalid.
	\return Returns number of elements or 0.
*/
extern _PASCAL_  uint32_t
CountFSObjectList(
    const FSObjectListRef	inFileList ) WEAK_LINK;

/*!
	\brief Get an FSObjectRef from a FSObjectListRef.
	
 	Extracts the nth FSObjectRef from an FSObjectListRef. The client is
	responsible for disposing of the FSObjectRef with DisposeFSObjectRef.
	
	Common API.

	\param inObjectList Valid FSObjectListRef. Null is invalid.
	\param inIndex 0 based index to reference the item.
	\param outFSSpec Pointer to FSObjectRef. Null is invalid. Must be disposed by client.
	\return Returns an EngineError.
*/
extern _PASCAL_  EngineError
GetNthFSObject(
	const FSObjectListRef	inObjectList,
	uint32_t						inIndex,
	FSObjectRef					*outFSSpec) WEAK_LINK;

/*!
	\brief Dispose an FSObjectListRef.
	
 	Disposes of an FSObjectListRef created by NewFSObjectList.
	
	Common API.

	\param inFileList Valid FSObjectListRef to dispose. Null is invalid.
	\return Returns an EngineError.
*/
extern _PASCAL_  void
DisposeFSObjectList(
    FSObjectListRef		inFileList ) WEAK_LINK;

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif