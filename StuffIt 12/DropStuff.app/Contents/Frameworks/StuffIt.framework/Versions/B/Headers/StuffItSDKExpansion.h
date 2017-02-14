/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKExpansion.h
//
//   Description:   Interfaces for expanding and decoding archives.
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
//  $Id: StuffItSDKExpansion.h,v 1.7.2.1 2006/10/05 00:18:15 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKExpansion.h
	
	\brief Provides interfaces for expanding and decoding archives.
*/

#ifndef STUFFITSDKEXPANSION_H
#define STUFFITSDKEXPANSION_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKERRORS_H
#include <StuffIt/StuffItSDKErrors.h>
#endif

#ifndef STUFFITSDKFILES_H
#include <StuffIt/StuffItSDKFiles.h>
#endif

#ifndef STUFFITSDKSTRINGS_H
#include <StuffIt/StuffItSDKStrings.h>
#endif

#ifndef STUFFITSDKFORMATS_H
#include <StuffIt/StuffItSDKFormats.h>
#endif

#ifndef STUFFITSDKARCHIVEOBJECTS_H
#include <StuffIt/StuffItSDKArchiveObjects.h>
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
	\brief Exand or decode an archive
	
	Expands or decodes the source archive.
	
	Adheres to properties create folder method, delete action, deep expansion, destination prompt,
	conflict resolution, save comments, callbacks.
	
	Note: It is possible for the expansion to return successully, but for outResultList to be empty.
	This occurs when merging or some other criteria exists such that all the items in the archive
	to be expanded are skipped. SDK versions prior to 0x0810 return kStuffItErrorUserCanceled in this
	instance.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource FSObjectRef of source archive. Null is invalid.
	\param inDestination FSObjectRef of destination folder. If null, the destination will
	be the same as the source archive. If destination prompt property, this parameter will be
	ignored.
	\param outResultList Optional pointer to ArchiveFileListRef to receive root items expanded.
	If not null, the FSObjectRef must be disposed of via DisposeArchiveFileList.
	\param inPassword Optional StringRef of the password to the archive. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
ExpandOrDecodeFile(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    const FSObjectRef           inDestination,
    FSObjectListRef *	        outResultList,
    StringRef		            inPassword ) WEAK_LINK;


/*!
	\brief Expand archive objects from an archive
	
	Expands a list of objects from an already opened archive.
	
	Note: It is possible for the expansion to return successully, but for outResultList to be empty.
	This occurs when merging or some other criteria exists such that all the items in the archive
	to be expanded are skipped. SDK versions prior to 0x0810 return kStuffItErrorUserCanceled in this
	instance.
		
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inObjectList List of ArchiveObjectRefs to expand. Null is 	\param inDestination The folder to expand into. If null, the destination will
	be the same as the archive that contains the items in inObjectList.
	\param outResultList Optional pointer to ArchiveFileListRef to receive root items expanded.
	Can be null.
	\param inPassword Optional password for the archive that contains inObjectList.
	\return EngineError
*/
extern _PASCAL_ EngineError
ExpandArchiveObjects(
    EngineRef                   inEngineRef,
    const ArchiveObjectListRef	inObjectList,
    const FSObjectRef           inDestination,
    FSObjectListRef *        outResultList,
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