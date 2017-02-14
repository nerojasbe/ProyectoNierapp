/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKErrors.h
//
//   Description:   Errors returned by the StuffIt Engine SDK.
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
//  $Id: StuffItSDKErrors.h,v 1.18.2.1 2006/10/05 00:18:12 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*! \file StuffItSDKErrors.h
	
	\brief Errors returned by the StuffIt Engine SDK.
*/

#ifndef STUFFITSDKERRORS_H
#define STUFFITSDKERRORS_H

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

/*! \brief Error type returned.

Most APIs within the SDK return an EngineError.
*/
typedef int32_t 							EngineError;

/*! \brief Errors returned by the APIs.
	
	The EngineErrors that can be returned from the various APIs in the SDK.

*/
enum StuffItSDKErrors {
	kStuffItErrorNoError						= 0,	//!< No error.
	kStuffItErrorUserCanceled 					= 17501,//!< The user has canceled an operation.
    kStuffItErrorDuplicateFileNames				= 17502,//!< Duplicate file name.
    kStuffItErrorVersionNotAvailable        	= 17503,//!< Version information is not available.
    kStuffItErrorInvalidFileType           		= 17504,//!< The type of file was not what was expected. Typically seen when attempting to create SEAs and the item is already an SEA.
    kStuffItErrorEngineIsBusy              		= 17505,//!< The engine is busy. Returned when an attempt is made to start another operation while one is already current.
	kStuffItErrorInvalidRegistration			= 17506,//!< The registration code is invalid.
	kStuffItErrorInvalidPassword				= 17507,//!< The password is invalid.
	kStuffItErrorArchiveVerificationFailed		= 17508,//!< The archive is damaged.
	kStuffItErrorNoObjectAtThatLocation			= 17509,//!< An attempt to acquire an ArchiveObjectRef failed. Returned when an attempt is made to iterate past the end of a container.
    kStuffItErrorUnsupportedArchiveFormat		= 17510,//!< The archive is known but the current operation doesn't support it.
    kStuffItErrorUnknownArchiveVersion			= 17511,//!< The version of the archive is newer than the engine can work with.
    kStuffItErrorObjectNotInArchive				= 17512,//!< Requested ArchiveObjectRef is not in the archive.
    kStuffItErrorObjectAttributeNotAvailable 	= 17513,//!< Requested attribute does not exist for ArchiveObjectRef.
    kStuffItErrorUnknownFormat					= 17514,//!< The StuffIt Engine was unable to determine the file format.
    kStuffItErrorPlatformNotSupported			= 17515,//!< Attempt to create a SEA for an unsupported platform.
    kStuffItErrorNoFormatsFound					= 17516,//!< The StuffIt Engine was unable to find any plugins.
    kStuffItErrorArchiveAlreadyOpen				= 17517,//!< The archive is already open.
    kStuffItErrorArchiveNotOpen					= 17518,//!< The archive is not open.
    kStuffItErrorConversionNotSupported			= 17519,//!< The format does not support conversion.
    kStuffItErrorCompressionNotSupported		= 17520,//!< The format does not support compression.
    kStuffItErrorArchiveRecoveryFailed			= 17521,//!< The attempt to recover the contents of an archive failed.
    kStuffItErrorUnicodeConversionFailed		= 17522,//!< A StringRef was not created because it the string failed to be converted to UniCode.
	kStuffItErrorInvalidParameter				= 17523,//!< A parameter is invalid. Typically caused by a null parameter that shouldn't be but also caused when a folder is expected instead of a file or vice versa.
	kStuffItErrorInsufficientMemory				= 17524,//!< There is not enough memory to perform the operation.
	kStuffItErrorInsufficientStack				= 17525,//!< There is not insufficient stack to perform the operation.
	kStuffItErrorDiskFull						= 17526,//!< There is not insufficient disk space to perform the operation.
	kStuffItErrorInsufficientPriviledges		= 17527,//!< Insufficient priviledges.
	kStuffItErrorCannotAddSelfExtracting		= 17528,//!< Failed to add self extracting
	kStuffItErrorCannotRemoveSelfExtracting		= 17529,//!< Failed to remove self extracting
	kStuffItErrorFolderSpecifiedForFile			= 17530,//!< A folder was specified when a file was required
	kStuffItErrorFormatAttributeNotAvailable	= 17531,//!< Requested attribute is not available.
	kStuffItErrorFormatAttributeReadOnly		= 17532,//!< Attribute cannot be changed.
	kStuffItErrorObjectListNotFromSingleArchive	= 17533,//!< ArchiveObjectList contains items from multiple archives.
	kStuffItErrorInvalidDestination				= 17534,//!< Destination provided for move or copy is invalid.
	kStuffItErrorUnknownCompression				= 17535,//!< Archive was compressed with an unknown compression method.
	kStuffItErrorIOError						= 17536,//!< An I/O error occurred.
	kStuffItErrorDamagedArchive					= 17537,//!< The archive format is corrupt.
	kStuffItErrorDamagedContent					= 17538,//!< The archive data is corrupt.
	kStuffItErrorReturnReceiptNotFound			= 17539,//!< The archive did not have a return receipt. 
	kStuffItErrorFormatError					= 17540,//!< An error occured within the specified format.
	kStuffItErrorInvalidAccessMode				= 17541,//!< An operation was performed on an archive opened in the incorrect mode. Eg. compression when opened in expand.
	kStuffItErrorTransactionVoided				= 17542,//!< The transaction was cancelled because the archive is no longer open.
	kStuffItErrorNewerArchiveVersion			= 17543,//!< The archive is newer than the engine supports.
	kStuffItErrorSourceTooLargeToSegment		= 17544,//!< The source file is greater than 2GB.
	kStuffItErrorNoEncryptedContentFound		= 17545,//!< The archive does not contain any encrypted content.
	kStuffItErrorPasswordCannotBeVerified		= 17546,//!< The archive format does not support verifying passwords.
	kStuffItErrorFileSpecifiedForFolder			= 17547,//!< A file was specified where a folder required.
	kStuffItErrorArchiveObjectListRefIsEmpty	= 17548,//!< The ArchiveObjectListRef does not contain any objects.
	kStuffItErrorInvalidIndex					= 17549,//!< The index is out of range.
	kStuffItErrorLibraryNotFound				= 17550,//!< The shared library was not found.
	kStuffItErrorEnginePropertyNotAvailable		= 17551,//!< Requested engine property is not available.
	kStuffItErrorSegmentConflict				= 17552,//!< A name conflict occurred while creating segments..
	kStuffItErrorDataTagNotFoundInContext		= 17553,//!< The requested data tag was not found in the context.
	kStuffItErrorUnableToGetDataFromContext		= 17554,//!< The data could not be extracted from the context.
	kStuffItErrorUnknownMetaType				= 17555,//!< Unknown meta information was found in the archive.
	kStuffItErrorUnknownFileAttribute			= 17556,//!< An unknown file attribute was found in the archive.
	kStuffItErrorUnknownAlgorithm				= 17557,//!< An unknown algorithm was used to compress data in the archive.
	kStuffItErrorForkNotFound					= 17558,//!< The requested fork was not found in the archive object.
	kStuffItErrorJpegCrcMismatch				= 17559,//!< CRC mismatch in sitx with compressed jpeg.
	kStuffItErrorDataTagReadOnly				= 17560,//!< The data referenced by the tag cannot be changed
	kStuffItErrorFormatDoesNotSupportIndex		= 17561,//!< The format does support the creation of a separate index file.
	kStuffItErrorNoBackingStore					= 17562,//!< The backing file for the archive could not be determined.
	kStuffItErrorInvalidNotification			= 17563,//!< The notification is either invalid or the class and message are mis-paired

	kStuffItErrorUnsupported					= 17998,//!< The operation is unsupported.
	kStuffItErrorInternalError					= 17999 //!< Bug in the StuffIt Engine.
};

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif
