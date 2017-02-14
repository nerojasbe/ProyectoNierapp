/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKSelfExtracting.h
//
//   Description:   Interfaces for creating self-extracting archives.
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
//  $Id: StuffItSDKSelfExtracting.h,v 1.7.2.1 2006/10/05 00:18:40 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKSelfExtracting.h
	
	\brief StuffItSDKSelfExtracting.h provides interfaces for creating self-extracting
	archives.
*/

#ifndef STUFFITSDKSELFEXTRACTING_H
#define STUFFITSDKSELFEXTRACTING_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKFILES_H
#include <StuffIt/StuffItSDKFiles.h>
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
	\brief Platform type. See #PlatformTypes.
*/
typedef uint16_t PlatformType;
/*!
	\brief Options for creating Self Extracting Archives
	
	Options used to determine what kind of Self Extracting Archive to create.
*/
enum PlatformTypes{
    kPlatformMacOSClassic	=   0,	/**< Create SEAs for Classic MacOS. */
    kPlatformMSWindows		=   2	/**< Create Windows SEA. */
};

/*!
	\brief Create a Self Extracting archive.
	
	Converts an existing archive into a SEA.
	
	Adheres to property callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource FSObjectRef of an archive to convert to an SEA. Null is invalid.
	\param outResult Optional pointer to an FSObjectRef to receive SEA. Can be null.
	\param inPlatform Type of SEA to create. See PlatformTypes.
	\return EngineError
*/
extern _PASCAL_  EngineError
AddSelfExtractingToArchive(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    FSObjectRef					*outResult,
    PlatformType                inPlatform ) WEAK_LINK;

/*!
	\brief Convert a Self-Extracting Archive into a regular archive.
	
	Converts a SEA into a standard archive.
	
	Adheres to property callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource FSObjectRef of an archive to convert. Null is invalid.
	\param outResult Optional pointer to an FSObjectRef to receive archive. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
RemoveSelfExtractingFromArchive(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    FSObjectRef					*outResult ) WEAK_LINK;

/*!
	\brief Determine if a FSObjectRef is a Self-Extracting Archive.

	Determine if a FSObjectRef is a Self-Extracting Archive.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource FSObjectRef of a file to classify. Null is invalid.
	\param outIsSelfExtracting True if FSObjectRef is a SEA. Null is invalid.
	\param outPlatform Optional pointer to PlatformType. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
IsArchiveSelfExtracting(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    Boolean *                   outIsSelfExtracting,
    PlatformType *              outPlatform ) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif