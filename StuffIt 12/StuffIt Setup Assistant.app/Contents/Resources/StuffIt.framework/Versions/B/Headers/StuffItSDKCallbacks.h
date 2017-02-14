/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKCallbacks.h
//
//   Description:   Interfaces for custom callbacks.
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
//  $Id: StuffItSDKCallbacks.h,v 1.12.2.1 2006/10/05 00:18:03 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKCallbacks.h

	\brief StuffItSDKCallbacks.h provides interfaces for creating and using custom
	callbacks.

	\deprecated As of SDK version 0x820 the functions and definitions within this file are no longer
	used. See StuffItSDKNotifications.h
*/

#ifndef STUFFITSDKCALLBACKS_H
#define STUFFITSDKCALLBACKS_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__

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
	\brief Useful for supplying no callback.
*/
#define kNoCallback 				nil

/*
	\deprecated
 
	Here are the declarations for the StuffIt Engine callbacks for progress and status. Both
    CFM and non-CFM declarations are present.

    EngineStatusCallback is passed a Ptr to the structure defined below with all the info about where
    things during an expansion/stuffing so that you can display your own progress. Return false
    unless the user aborted, in which case return true.

    EnginePeriodicCallback should return true unless the user aborted, in which case return false.
*/

/*!
	\brief Structure provided to the user defined status callback.
	
	\deprecated Many of the APIs can be given callbacks for client provided progress. When
	the callback is invoked, this structure is passed to it which contains information about the
	operation in progress.
*/
struct EngineStatusRec
{
    uint32_t          itemsDone;                  /**< Number of items processed. */
    uint32_t          itemsTotal;                 /**< Total number of items. */
    uint64_t          overallDone;                /**< Number of bytes processed. */
    uint64_t          overallTotal;               /**< Total number of bytes. */

    const char	      *currentFileName;			  /**< Current item name. */

    const char     	  *operationName;             /**< Current operation string. (Supplied by StuffIt Engine. Optional). */
    const char    	  *actionName;				  /**< Current action string. (Supplied by StuffIt Engine. Optional). */
    const char		  *remainMsg;				  /**< Current remaining string. (Supplied by StuffIt Engine. Optional). */
};

/*!
	\deprecated See StuffItSDKNotifications.h.
*/
typedef struct EngineStatusRec EngineStatusRec;

/*!
	\brief Engine status message
*/
typedef uint16_t EngineStatusMessage;
/*!
	\brief Messages provided to status callback.
	
	\deprecated When the status callback is invoked, an EngineStatusMessage is provided to
	indicate the current state of the operation.
*/
enum EngineStatusMessages
{
	kStatusInitialize = 0, 	/**< Do any initialization prior to the operation beginning. */
	kStatusTerminate,		/**< Tear down any initialization done in kStatusInitialize. */

	kStatusItemChange,		/**< An operation is in progress, and the current item has changed. */
	kStatusProgressChange,	/**< An operation is in progress, and the number of items and/or bytes has changed. */
	
	kStatusPreFlight		/**< If an operation reuires lengthy setup, the message will be sent to the callback. */
};

/*!
	\brief Data clients of the SDK can supply for each of the callbacks.
*/
typedef void * SDKClientData;

/*!
	\brief The callback for client provided progress.
	
	\deprecated Callback invoked by the StuffIt Engine during an operation which has progress such as expansion
	or compression.
	
	\param inMessage The current state of the operation. 
	\param pb Pointer to EngineStatusRec.
	\param userData Client supplied data.
	\return Return true to continue the current operation.
*/
typedef CALLBACK_API( Boolean, EngineStatusCallbackProcPtr )(EngineStatusMessage inMessage, EngineStatusRec *pb, SDKClientData userData);

/*!
	\brief The callback for client provided idle processing.
	
	\deprecated Callback invoked by the StuffIt Engine during an operation to give the client idle time.
	
	\param userData Client supplied data.
	\return Return true to continue the current operation.
*/
typedef CALLBACK_API( Boolean, EnginePeriodicCallbackProcPtr )(SDKClientData userData);

#if TARGET_OS_WIN32
	typedef EngineStatusCallbackProcPtr    EngineStatusCallbackUPP;
	typedef EnginePeriodicCallbackProcPtr  EnginePeriodicCallbackUPP;

    #define NewEngineStatusCallback(userRoutine)   ((EngineStatusCallbackUPP)(userRoutine))
    #define NewEnginePeriodicCallback(userRoutine) ((EnginePeriodicCallbackUPP)(userRoutine))
    #define DisposeEngineStatusCallback(userUpp)
    #define DisposeEnginePeriodicCallback(userUpp)
#elif TARGET_RT_MAC_MACHO || TARGET_RT_MAC_CFM
	typedef struct OpaqueStatusProc *    EngineStatusCallbackUPP;
	typedef struct OpaquePeriodicProc *  EnginePeriodicCallbackUPP;

	extern _PASCAL_  EngineStatusCallbackUPP NewEngineStatusCallback(EngineStatusCallbackProcPtr) WEAK_LINK;
	extern _PASCAL_  EnginePeriodicCallbackUPP NewEnginePeriodicCallback(EnginePeriodicCallbackProcPtr) WEAK_LINK;
	extern _PASCAL_  void DisposeEngineStatusCallback(EngineStatusCallbackUPP) WEAK_LINK;
	extern _PASCAL_  void DisposeEnginePeriodicCallback(EnginePeriodicCallbackUPP) WEAK_LINK;
#else
	#error Unknown Compiler Target
#endif

// values returned from callback procs
enum
{
	kProceed = true,		
	kDontProceed = false
};

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
	Use SuppressStatusProc when you don't want user interface displayed when
	using the engine.
ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*!
	\brief Suppresses progress.
	
	\deprecated Supply this function in the status callback when you do not want the
	StuffIt Engine to display any progress UI.
*/
extern _PASCAL_  Boolean
SuppressStatusProc(EngineStatusMessage inMessage, EngineStatusRec *pb, void *userData) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif