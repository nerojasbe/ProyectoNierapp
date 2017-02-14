/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKCompression.h
//
//   Description:   Interfaces for compressing and encoding items.
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
//  $Id: StuffItSDKCompression.h,v 1.7.2.1 2006/10/05 00:18:05 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKCompression.h
	
	\brief Provides interfaces for compressing and encoding items.
*/

#ifndef STUFFITSDKCOMPRESSION_H
#define STUFFITSDKCOMPRESSION_H

#if PRAGMA_ONCE
#pragma once
#endif

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKERRORS_H
#include <StuffIt/StuffItSDKErrors.h>
#endif

#ifndef STUFFITSDKFORMATS_H
#include <StuffIt/StuffItSDKFormats.h>
#endif

#ifndef STUFFITSDKFILES_H
#include <StuffIt/StuffItSDKFiles.h>
#endif

#ifndef STUFFITSDKARCHIVEOBJECTS_H
#include <StuffIt/StuffItSDKArchiveObjects.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

/*!
	\brief Compress or encode a single item
	
	Create an archive from the single FSObjectRef provided.

	Adheres to properties destination prompt, delete action, resolve aliases, conflict resolution,
	no recompression, pre-encoding type, pre-encoding method, post encoding, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormatType The type of archive to be created. Null is invalid.
	\param inSource FSObjectRef to add to the new archive. Null is invalid.
	\param inDestination Optional FSObjectRef indicating the destination of the archive. If null,
	the archive will be created in the parent folder of inSource. The name
	of the archive will also be derived from inSource. If the destination is a folder, then
	the archive will be created in that folder using the same naming as if the destination was null.
	If the archive points to a non-existant file, then the archive will be created using that information.
	\param outResult Optional pointer to an FSObjectRef to receive the created archive. Can be null.
	\param inPassword The password to use for encrypting. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
CompressOrEncodeFSObject(
    EngineRef                   inEngineRef,
    ConstFormatIDParam	        inFormatType,
    const FSObjectRef           inSource,
    const FSObjectRef           inDestination,
    FSObjectRef *               outResult,
	const StringRef				inPassword ) WEAK_LINK;


/*!
	\brief Add a list of file system items into an archive.
	
	Create an archive based on a list of items.
	
	Adheres to properties destination prompt, delete action, resolve aliases, conflict resolution,
	no recompression, pre-encoding type, pre-encoding method, post encoding, callbacks.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveType The type of archive to be created. Null is invalid.
	\param inFileList The list of items to add to the archive. Null is invalid.
	\param inDestination Optional FSObjectRef indicating the destination of the archive. If null,
	the archive will be created in the parent folder of the first item in inFileList. The name
	of the archive will also be derived from the first item. If the destination is a folder, then
	the archive will be created in that folder using the same naming as if the destination was null.
	If the archive points to a non-existant file, then the archive will be created using that information.
	\param outResult Optional pointer to an FSObjectRef to receive the created archive. Can be null.
	\param inPassword The password to use for encrypting. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
ArchiveFSObjectList(
    EngineRef                   inEngineRef,
    ConstFormatIDParam        	inArchiveType,
    const FSObjectListRef		inFileList,
    const FSObjectRef           inDestination,
    FSObjectRef *               outResult,
    StringRef		            inPassword ) WEAK_LINK;

/*!
	\brief Add a list of file system items into an archive and index.
	
	Create an archive based on a list of items, and optionally optionally create an index
	file if the archive format, such as StuffIt X, supports it. An index file is a separate version
	of the archive that contains enough information to allow for browsing the archives contents, but
	none of the compressed data. 
	
	If the index archive is expanded or individual content is extracted, the original
	archive will be used, if available, for the expansion. If the archive can't be found, a 
	#kSearchFolderNotification will be issued asking the client for the whereabouts of the actual
	archive. 
	
	Adheres to properties destination prompt, delete action, resolve aliases, conflict resolution,
	no recompression, pre-encoding type, pre-encoding method, post encoding, callbacks.
	
	Available in SDK 0x0812

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveType The type of archive to be created. Null is invalid.
	\param inFileList The list of items to add to the archive. Null is invalid.
	\param inDestination Optional FSObjectRef indicating the destination of the archive. If null,
	the archive will be created in the parent folder of the first item in inFileList. The name
	of the archive will also be derived from the first item. If the destination is a folder, then
	the archive will be created in that folder using the same naming as if the destination was null.
	If the archive points to a non-existant file, then the archive will be created using that information.
	\param outResult Optional pointer to an FSObjectRef to receive the created archive. Can be null.
	\param inPassword The password to use for encrypting. Can be null.
	\param inIndexFile Optional file to create an index in. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
ArchiveFSObjectListCreatingIndex(
    EngineRef                   inEngineRef,
    ConstFormatIDParam        	inArchiveType,
    const FSObjectListRef		inFileList,
    const FSObjectRef           inDestination,
    FSObjectRef *               outResult,
    StringRef		            inPassword,
	FSObjectRef					inIndexFile) WEAK_LINK;

/*!
	\brief Add items to an archive
	
	Given a list of FSObjectRefs, add them to an already open archive.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inParentRef Location within the archive to add the items. Null is invalid.
	\param inFileList List of FSObjectRefs to be added to the archive. Null is invalid.
	\param outObjectList Optional pointer to ArchiveObjectListRef to receive list of ArchiveObjectRefs
	added to the archive. Can be null.
	\param inPassword The password to use for encrypting. Can be null.
	\return EngineError
*/
extern _PASCAL_ EngineError
AddItemsToArchive(
    EngineRef                   inEngineRef,
    ArchiveObjectRef            inParentRef,
    const FSObjectListRef		inFileList,
    ArchiveObjectListRef	    *outObjectList,
    StringRef		            inPassword ) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif