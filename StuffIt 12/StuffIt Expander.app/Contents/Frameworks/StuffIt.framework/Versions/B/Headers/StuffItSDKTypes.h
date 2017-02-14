/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKTypes.h
//
//   Description:   Basic types used by the StuffIt Engine SDK.
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
//  $Id: StuffItSDKTypes.h,v 1.5.6.1 2006/10/05 00:18:45 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*! \file StuffItSDKTypes.h
	
	\brief Basic types used by the StuffIt Engine SDK.
*/

#ifndef STUFFITSDKTYPES_H
#define STUFFITSDKTYPES_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
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
	A four character value.
*/
typedef uint32_t							FourCharType;

/*!
	Container that holds the date in the native size of the platform.
*/
typedef NativeDateTime						DateTimeRef;

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif