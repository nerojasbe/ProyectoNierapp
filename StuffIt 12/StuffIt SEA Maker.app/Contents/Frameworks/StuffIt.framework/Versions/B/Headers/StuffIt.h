/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItEngine.h
//
//   Description:   Master include for all of the StuffIt SDK.
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
//  $Id: StuffIt.h,v 1.4.2.1 2006/10/05 00:17:49 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	@header StuffIt
	
	Master include for all of the StuffIt SDK.
*/

#ifndef __STUFFIT_H__
#define __STUFFIT_H__

#include <StuffIt/StuffItSDKConfig.h>

#include <StuffIt/StuffItSDKTypes.h>
#include <StuffIt/StuffItSDK.h>
#include <StuffIt/StuffItSDKErrors.h>
#include <StuffIt/StuffItSDKFiles.h>
#include <StuffIt/StuffItSDKStrings.h>
#include <StuffIt/StuffItSDKFormats.h>
#include <StuffIt/StuffItSDKOptions.h>
#if !__SUPPRESS_UNSUPPORTED_STUFFIT_SDK_APIS__
#include <StuffIt/StuffItSDKCallbacks.h>
#endif
#include <StuffIt/StuffItSDKExpansion.h>
#include <StuffIt/StuffItSDKCompression.h>
#include <StuffIt/StuffItSDKSegments.h>
#include <StuffIt/StuffItSDKSelfExtracting.h>
#include <StuffIt/StuffItSDKArchives.h>
#include <StuffIt/StuffItSDKArchiveObjects.h>
#include <StuffIt/StuffItSDKReturnReceipt.h>
#include <StuffIt/StuffItSDKUtilities.h>
#include <StuffIt/StuffItSDKNotifications.h>

#endif /* __STUFFIT_H__ */
