/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKStrings.h
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
//  $Id: StuffItSDKStrings.h,v 1.10.2.1 2006/10/05 00:18:43 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKStrings.h
	
	\brief Interfaces for working with strings.
*/

#ifndef STUFFITSDKSTRINGS_H
#define STUFFITSDKSTRINGS_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
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
	\brief A reference to a string.
*/
typedef struct OpaqueStringObject *			StringRef; /* reference to strings used by the engine */

#if TARGET_OS_MAC
/*!
	\ingroup Mac
	\brief Creates a string reference from a CFString.
	
	Creates a string reference from a CFString.
	
	Mac only API.

	\param inCFString Valid CFString. Null is invalid.
	\param outStringRef Pointer to StringRef that will receive new reference. Must be disposed of with DisposeStringRef.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewStringRefFromCFString(
	CFStringRef 		inCFString, 
	StringRef *			outStringRef) WEAK_LINK;
#endif

/*!
	\brief Creates a new string reference from a pascal string.
	
	Creates a string reference from a pascal string.
	
	Common API.
	
	\param inPascalString Valid pascal string. Null is invalid.
	\param outStringRef Pointer to StringRef that will receive new reference. Must be disposed of with DisposeStringRef.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewStringRefFromPascalString(
	const uint8_t * 	inPascalString, 
	StringRef *			outStringRef) WEAK_LINK;

/*!
	\brief Creates a new string reference from a C string.
	Creates a string reference from a C string.
	
	Common API.
	
	\param inCString Valid C string. Null is invalid.
	\param outStringRef Pointer to StringRef that will receive new reference. Must be disposed of with DisposeStringRef.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewStringRefFromCString(
	const char * 		inCString, 
	StringRef *			outStringRef) WEAK_LINK;

/*!
	\brief Creates a new string reference from a wide-character string.
	Creates a string reference from a C string.
	
	Common API.
	
	\param inWString Valid wide-character string. Null is invalid.
	\param outStringRef Pointer to StringRef that will receive new reference. Must be disposed of with DisposeStringRef.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
NewStringRefFromUnicodeString(
	const NativeWideChar * 	inWString, 
	StringRef *				outStringRef) WEAK_LINK;

/*!
	\brief Disposes of a string reference.
	Releases a StringRef created from NewStringRefXXX.
	
	Common API.
	
	\param inStringRef StringRef to dispose. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
DisposeStringRef(
	StringRef			inStringRef) WEAK_LINK;


/*!
	\brief Copies a string reference.
	Creates a new StringRef containing the same contents as the original.
	
	Common API.
	
	\param inStringRef StringRef to copy. Null is invalid.
	\param outCopy Pointer to a StringRef to receive new string. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
CopyStringRef(
	StringRef			inStringRef,
	StringRef *			outCopy) WEAK_LINK;

#if TARGET_OS_MAC
/*!
	\ingroup Mac
	\brief Creates a CFString from a StringRef.
	
	Creates a new CFString from a StringRef. The client is responsible for
	disposing of the resulting CFString.
	
	Mac only API.
	
	\param inStringRef StringRef to extract the CFString from. Null is invalid.
	\return CFString or null.
*/
extern _PASCAL_ CFStringRef
AcquireCFStringFromStringRef(
	StringRef 			inStringRef) WEAK_LINK;
#endif

/*!
	\brief Extracts a C string from a StringRef.
	Returns a C string from the given StringRef.
	
	Common API.
	
	\param inStringRef StringRef to get the C string from. Null is invalid.
	\return C string or null.
*/

extern _PASCAL_ const char *
GetCStringFromStringRef(StringRef inStringRef) WEAK_LINK;

/*!
	\brief Extracts a wide-character string from a StringRef.
	Returns a wide-character string from the given StringRef.
	
	Common API.
	
	\param inStringRef StringRef to get the C string from. Null is invalid.
	\return wide-character string or null.
*/
extern _PASCAL_ const NativeWideChar *
GetUnicodeStringFromStringRef(StringRef inStringRef) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif