/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItEngineSDKConfig.h
//
//   Description:   Platform and Compiler configuration.
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
//
//  Allume Systems, Inc.                   http://www.allume.com/
//  245 Westridge Drive                    (831) 761-6200
//  Watsonville, CA  95076                 (831) 761-6206 FAX
//
//--------------------------------------------------------------------------------------------------
//  $Id:
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKConfig.h
	
	\brief StuffItEngineSDKConfig.h specifies the settings necessary to use the SDK with the currently
	supported platforms.
*/

#ifndef STUFFITSDKCONFIG_H
#define STUFFITSDKCONFIG_H

/*!
	\brief __USE_DEPRECATED_STUFFIT_SDK_APIS__ controls the visibility of API that is no longer recommended for use.
*/
#ifndef __USE_DEPRECATED_STUFFIT_SDK_APIS__
#define __USE_DEPRECATED_STUFFIT_SDK_APIS__ 1
#endif

/*!
	\brief __SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__ controls the visibility of API that is no longer available.
*/
#ifndef __SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
#define __SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__ 1
#endif

#if macintosh || TARGET_OS_MAC || ((__MWERKS__ >= 022110) && __MACH__)

	#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
	#include <Carbon/Carbon.h>
	#else
	#include <CoreServices/CoreServices.h>
	#endif

/*!
	\brief WEAK_LINK 
*/
#if !__MWERKS__
	#define WEAK_LINK __attribute__((weak_import))
#else
	#define WEAK_LINK
#endif

/*!
	\brief _PASCAL_ Syntactic aspartame
*/
	#define _PASCAL_ pascal

/*!
	\brief NativeDateTime Alias of native OS type representing time
*/
	typedef LocalDateTime	NativeDateTime;

	#if defined __cplusplus
		#include <cstddef> // ptrdiff_t, size_t
	#else
		#include <stddef.h>
	#endif

/*!
	\brief NativeWideChar A 16 bit character type
*/
	#if __MWERKS__
	typedef wchar_t			NativeWideChar;
	#else #if __GNUC__
	typedef uint16_t		NativeWideChar;
	#endif

#elif (defined _MSC_VER && defined WIN32) || (defined __MWERKS__ && defined __INTEL__)

	#undef COMPILER_MSVC
	#undef COMPILER_DOTNET
	#undef TARGET_OS_WIN32
	#define WEAK_LINK

	#define TARGET_OS_WIN32 1
	#define COMPILER_MSVC 1
	#if _MSC_VER >= 1300
        #define COMPILER_DOTNET 1
    #endif

	#define _PASCAL_
   	#define CALLBACK_API(_type, _name) _type (__cdecl * _name)

	#if defined __cplusplus
		typedef bool Boolean;
	#else
		typedef unsigned char Boolean;
		#undef false
		#undef true
		#define false  0
		#define true 1
	#endif
	
	#define nil NULL

	// integer types
    #include <limits.h>
	typedef __int8 int8_t;
	typedef __int16 int16_t;
	typedef __int32 int32_t;
	typedef __int64 int64_t;
	typedef unsigned __int8 uint8_t;
	typedef unsigned __int16 uint16_t;
	typedef unsigned __int32 uint32_t;
	typedef unsigned  __int64 uint64_t;
	
	// The largest integer type
	typedef int64_t intmax_t;
	typedef uint64_t uintmax_t;

	// Integer type capable of holding any pointer
	#if !COMPILER_DOTNET
		typedef signed int intptr_t;
		typedef unsigned int uintptr_t;
	#endif

	// The most efficient integer type, at least 16 bits long
	typedef signed int intfast_t;
	typedef unsigned int uintfast_t;

	#if defined __cplusplus
		#define INT8_MIN (-128)
		#define INT16_MIN (-32767-1)
		#define INT32_MIN (-2147483647-1)
		#define INT8_MAX (127)
		#define INT16_MAX (32767)
 		#define INT32_MAX (2147483647)
		#define UINT8_MAX (255U)
		#define UINT16_MAX (65535U)
		#define UINT32_MAX (4294967295U)
		#define INT64_MIN (-9223372036854775807-1)
		#define INT64_MAX (9223372036854775807)
		#define UINT64_MAX (18446744073709551615U)
	#endif
	
	typedef unsigned char uchar_t;

	#if defined __cplusplus
		#include <cstddef> // ptrdiff_t, size_t
	#else
		#include <stddef.h>
	#endif
	
	typedef uint64_t NativeDateTime;
	typedef wchar_t	NativeWideChar;
	
#else
	#error Unsupported platform
#endif

#endif  //STUFFITSDKCONFIG_H