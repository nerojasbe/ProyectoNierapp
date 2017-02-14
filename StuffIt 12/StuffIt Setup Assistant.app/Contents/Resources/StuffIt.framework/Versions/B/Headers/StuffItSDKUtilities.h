/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKUtilities.h
//
//   Description:   General utilities.
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
//  $Id: StuffItSDKUtilities.h,v 1.7.2.1 2006/10/05 00:18:48 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKUtilities.h
	
	\brief General utilities not directly related to expansion or compression.
*/

#ifndef STUFFITSDKUTILITIES_H
#define STUFFITSDKUTILITIES_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKFILES_H
#include <StuffIt/StuffItSDKFiles.h>
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
	\brief Options for mounting disk images.
	
	Options for how disk images are mounted.
*/
enum DiskImageOptions {
    kMountImageLocked                       =   false,
    kMountImageUnlocked                     =   true,
    kDontVerifyChecksumOnMounting           =   false,
    kVerifyChecksumOnMounting               =   true,
    kDontMountImageAsRAMDisk                =   false,
    kMountImageAsRAMDisk                    =   true
};

/*!
	\brief Text conversion method. See #TextConversionMethods.
*/
typedef uint16_t TextConversionMethod;
/*!
	\brief Constants for ConvertTextFile
	
	Options for how ConvertTextFile converts files.
*/
enum TextConversionMethods{
    kTextFileConvertToMac                   =   0, /**< Convert line endings to Mac (CR) */
    kTextFileConvertToDOS                   =   1, /**< Convert line endings to Dos (CRLF) */
    kTextFileConvertToUNIX                  =   2  /**< Convert line endings to Unix (LF) */
};



/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Misc Utilities	                                                                */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Mount a disk image.
	
	Mounts a disk image.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The FSObjectRef of the disk image to mount. Null is invalid.
	\param inUnlocked True if the image should be mounted writable.
	\param inVerify True if the image should be verified.
	\param inRamDisk True if the image should be mounted as a RAM disk.
	\param outDriveNumber Returns optional drive number. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
MountDiskImage(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    Boolean                     inUnlocked,
    Boolean						inVerify,
    Boolean                     inRamDisk,
    int16_t *                    outDriveNumber ) WEAK_LINK;

/*!
	\brief Convert a text file's line endings.
	
	Converts the line endings of a text file to another platform's format.
	
	Adheres to properties destination prompt, delete action, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The FSObjectRef of the text file to convert. Null is invalid.
	\param inDestination Optional destination file. Can be null.
	\param outResultSpec Optional pointer to FSObjectRef to receive converted file. Can be null.
	\param inConversionMethod Which platform's line endings to convert to. See TextConversionMethods.
	\return EngineError
*/
extern _PASCAL_  EngineError
ConvertTextFile(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    const FSObjectRef           inDestination,
    FSObjectRef *               outResultSpec,
    TextConversionMethod        inConversionMethod ) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif