/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKReturnReceipt.h
//
//   Description:   Interfaces for accessing return receipts in StuffIt Archives.
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
//  $Id: StuffItSDKReturnReceipt.h,v 1.8.2.1 2006/10/05 00:18:32 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKReturnReceipt.h
	
	\brief StuffItSDKReturnReceipt.h provides interfaces for working with return receipts
	in StuffIt5 archives.
*/

#ifndef STUFFITSDKRETURNRECEIPT_H
#define STUFFITSDKRETURNRECEIPT_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKARCHIVES_H
#include <StuffIt/StuffItSDKArchives.h>
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
	\brief Return receipt action. See #ReturnReceiptActions.
*/
typedef uint16_t ReturnReceiptAction;
/*!
	\brief Options for handling Return Receipts
	
	Indicators for what the StuffIt Engine should do when it encounters a return receipt during expansion.
*/
enum ReturnReceiptActions
{
    kReturnReceiptPromptUser        = 0, /**< Display a dialog prompting the user for resolution */
    kReturnReceiptRespond           = 1, /**< Respond to the return receipt. */
    kReturnReceiptSave              = 2, /**< Save the return receipt to a file. */
    kReturnReceiptIgnore            = 3, /**< Ignore the return receipt. */
    kReturnReceiptDelete            = 4  /**< Delete the return receipt. */
};

/*!
	\brief Add a return receipt.
	
	Add a return receipt to an open archive.
	
	\param inEngineRef Reference to the StuffIt Engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveRef The archive to add a return receipt to. Null is invalid.
	\param inEmailAddress The email address to add to the return receipt. Null is invalid.
	\param inUserName The user name to add to the return receipt. Null is invalid.
	\param inComment The optional comment to add to the return receipt. Can be null.
	\return EngineError
*/
extern _PASCAL_ EngineError
AddReturnReceiptToArchive(
    EngineRef                   inEngineRef,
    ArchiveRef                  inArchiveRef,
    StringRef                 	inEmailAddress,
    StringRef                 	inUserName,
    StringRef                 	inComment ) WEAK_LINK;

/*!
	\brief Get return receipt data.
	
	Get return receipt data from an open archive.
	
	\param inEngineRef Reference to the StuffIt Engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveRef The archive to add a return receipt to. Null is invalid.
	\param outEmailAddress Optional pointer to a StringRef to receive the email address to get 
	from the return receipt. Can be null.
	\param outUserName Option pointer to a StringRef to receive the user name to get from
	the return receipt. Can be null.
	\param outComment Optional pointer to a StringRef to receive the comment to get from the
	return receipt. Can be null.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireReturnReceiptFromArchive(
    EngineRef                   inEngineRef,
    ArchiveRef                  inArchiveRef,
    StringRef *               	outEmailAddress,
    StringRef *               	outUserName,
    StringRef *               	outComment ) WEAK_LINK;

/*!
	\brief Delete return receipt.
	
	Delete return receipt from an open archive.
	
	\param inEngineRef Reference to the StuffIt Engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveRef The archive to remove the return receipt from. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
DeleteReturnReceiptFromArchive(
    EngineRef                   inEngineRef,
    ArchiveRef                  inArchiveRef ) WEAK_LINK;

/*!
	\brief Check for a return receipt.
	
	Determine if an open archive has a return receipt.
	
	\param inEngineRef Reference to the StuffIt Engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveRef The archive to check for a return receipt. Null is invalid.
	\return Boolean
*/
extern _PASCAL_ Boolean
ArchiveHasReturnReceipt(
    EngineRef                   inEngineRef,
    ArchiveRef                  inArchiveRef ) WEAK_LINK;

/*!
	\brief Does the archive have support for return receipt.
	
	Determine if an open archive supports return receipt.
	
	\param inArchiveRef The archive to check. Null is invalid.
	\return Boolean
*/
extern _PASCAL_ Boolean
ArchiveSupportsReturnReceipt(
	ArchiveRef					inArchiveRef ) WEAK_LINK;

/*!
	\brief Check item for return receipt.
	
	Determine if an item in an open archive is the return receipt.
	
	\param inObject The ArchiveObjectRef to check. Null is invalid.
	\return Boolean
*/
extern _PASCAL_ Boolean
IsObjectReturnReceipt(
    ArchiveObjectRef            inObject ) WEAK_LINK;

/*!
	\brief Perform return receipt action.
	
	Do the requested action and return the actual action that was
	performed.
	
	\param inEngineRef Reference to the StuffIt Engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveRef The archive with the return receipt. Null is invalid.
	\param inOutAction The requested action to perform. On return, it contains the actual action 
	performed. See ReturnReceiptActions. Null is invalid. 
	\return EngineError
*/
extern _PASCAL_ EngineError
DoReturnReceiptActionArchiveRef(
    EngineRef                   inEngineRef,
    ArchiveRef                  inArchiveRef,
    ReturnReceiptAction *       inOutAction ) WEAK_LINK;

/*!
	\brief Performs a return receipt action.
	
	If an archive has return receipt, DoReturnReceiptActionFSObject will
	perform the requested action. Depending on the action, the StuffIt Engine may
	display UI.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The archive. Null is invalid.
	\param inOutAction Pointer to the action to perform. On return, the actual
	action is returned. See ReturnReceiptActions. Null is invalid.
	\return EngineError
*/
extern _PASCAL_  EngineError
DoReturnReceiptActionFSObject(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    ReturnReceiptAction *       inOutAction ) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif