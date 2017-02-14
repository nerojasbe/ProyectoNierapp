/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKArchives.h
//
//   Description:   Interfaces for working with archive objects.
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
//--------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKArchives.h
	
	\brief Interfaces for working with archives.

	When working with archives and their contents, it's important to note that the archive
	almost always has to be opened in kExtracMode or kFullMode for any useful information
	to be returned.
*/

#ifndef STUFFITSDKARCHIVES_H
#define STUFFITSDKARCHIVES_H

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
	\brief Reference to an archive
	
 	Reference to an archive returned from AcquireArchiveRef. Released with
	ReleaseArchiveRef.
*/
typedef struct OpaqueArchiveRef *           ArchiveRef;

/*!
	\brief The modes to open an archive.
	
 	The different modes that can be used to open an archive. Not all archives
	support all modes. Use GetFormatAttributes to determine a format's maximum mode.
*/
typedef uint16_t ArchiveMode;

/*!
	\brief The modes to open an archive.
	
 	The different modes that can be used to open an archive. Not all archives
	support all modes. Use GetFormatAttributes to determine a format's maximum mode.
*/
enum ArchiveModes
{
    kClosedMode  =   0,			/**< Archive is closed. */
    kExtractMode =   0x0007, 	/**< For expanding selected content. Read only. */
    kFullMode    =   0x00FF 	/**< Full access to the archive. */
};

/*!
	\brief Conversion method.
*/
typedef uint16_t ConversionMethod; 
/*!
	\brief Options for archive conversion
	
 	Options for handling encoding when converting archives.
*/
enum ConversionMethods
{
	kConvertPreserveEncoding				= 0x0001 /**<kConvertPreserveEncoding Preserve the encoding of the source archive. 
													The converted archive will have the same encoding. */
};


/*!
	\brief Acquire an ArchiveRef
	
	Before an archive can be used, an reference to it needs to exist. AcquireArchiveRef
	returns a reference to an existing archive that can then be used to open the archive, modify it, 
	manipulate items within it, etc. Acquisition should not be confused with opening an archive which can
	only be done after an archive is acquired.
	
	If inSpec references a compound archive, such as a .tar.gz, then AcquireArchive will attempt to acquire the inner most
	archive; in this case, the .tar. See #kEnginePropertyIDOpenCompoundArchives to control this behavior.
	
	The ArchiveRef must be released with ReleaseArchiveRef.

	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inSpec The FSObjectRef of the archive to acquire. Null is invalid.
	\param outRef Pointer to ArchiveRef to receive acquired archive. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError AcquireArchive(
	EngineRef					inEngineRef,
	const FSObjectRef			inSpec,
	ArchiveRef					*outRef) WEAK_LINK;

/*!
	\brief Release an ArchiveRef
	
	Release an ArchiveRef acquired from AcquireArchiveRef. Do not confuse
	releasing an ArchiveRef with closing an archive which is done before releasing it.

	\param inRef ArchiveRef to release. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError ReleaseArchive(
	ArchiveRef					inRef) WEAK_LINK;

/*!
	\brief Acquire a new archive
	
	Creates a new archive from the given format and acquires it.
	
	The ArchiveRef must be released with ReleaseArchiveRef.

	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inSpec The FSObjectRef of the archive to create and acquire. Null is invalid.
	\param inArchiveType The format to create the new archive with. Null is invalid.
	\param outArchiveRef Pointer to ArchiveRef to receive acquired archive. Null is invalid.	
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireNewArchiveFromFSObject(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSpec,
    ConstFormatIDParam			inArchiveType,
    ArchiveRef					*outArchiveRef ) WEAK_LINK;

/*!
	\brief Acquire a new archive creating an optional archive index.
	
	Creates a new archive from the given format and acquires it optionally creating
	an archive index. Archive indexes are only supported by StuffIt X. An archive index
	allows the contents of an archive to be browsed even if the original archive is
	not present.
	
	The ArchiveRef must be released with ReleaseArchiveRef.

	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inSpec The FSObjectRef of the archive to create and acquire. Null is invalid.
	\param inArchiveType The format to create the new archive with. Null is invalid.
	\param inIndexFile Optional parameter specifying the name and location to create an archive index. Null indicates
	no index should be created.
	\param outArchiveRef Pointer to ArchiveRef to receive acquired archive. Null is invalid.	
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireNewArchiveCreatingIndex(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSpec,
    ConstFormatIDParam			inArchiveType,
	FSObjectRef					inIndexFile,
    ArchiveRef					*outArchiveRef ) WEAK_LINK;

/*!
	\brief Open an archive.
	
	Open an archive that has been previosly acquired using a given mode. Not all
	formats support all ArchiveModes. Use GetFormatAttributes to determine specific format
	features.

	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveRef The archive ref to open. Null is invalid.
	\param inPermission The mode to open the archive with. See ArchiveModes.
	\return EngineError
*/
extern _PASCAL_ EngineError
OpenArchive(
    EngineRef                   inEngineRef,
    ArchiveRef					inArchiveRef,
    ArchiveMode                 inPermission ) WEAK_LINK;


/*!
	\brief Open an encrypted archive.
	
	Open an encrypted archive that has been previously acquired using a given mode. Not all
	formats support all ArchiveModes. Use GetFormatAttributes to determine specific format
	features.

	Note: Some formats support more than one type of encryption, item by item and full archive.
	The distinction is that an archive with item by item encryption generally does not need to
	have the password known when the archive is opened, but archives with full encryption do.
	Currently, StuffItX is the only format that supports both types of encryption. 
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveRef The archive ref to open. Null is invalid.
	\param inPermission The mode to open the archive with. See ArchiveModes.
	\param inPassword The password to use when opening the archive. May be null.
	\return EngineError
*/
extern _PASCAL_ EngineError
OpenEncryptedArchive(
    EngineRef                   inEngineRef,
    ArchiveRef					inArchiveRef,
    ArchiveMode                 inPermission,
    StringRef					inPassword ) WEAK_LINK;

/*!
	\brief Close an archive.
	
	Closes an archive opened with OpenArchive.

	\param inArchiveRef The archive ref to close. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
CloseArchive(
    ArchiveRef                  inArchiveRef ) WEAK_LINK;

/*!
	\brief Create an index for an archive.
	
	Creates an external index file for an existing archive if the archive format
	supports external indexing such as StuffIt X.

	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchive The archive to index. Null is invalid.
	\param inIndexFile The index file to create. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
CreateArchiveIndex(
	EngineRef					inEngineRef, 
	FSObjectRef					inArchive,
	FSObjectRef					inIndexFile ) WEAK_LINK;

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Archive Passwords                                                                 */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Verify an archive's password.
	
	Determine if the password to an archive is correct.

	\param inEngineRef Reference to the StuffIt Engine obtained from OpenStuffItEngine. Null is invalid.
	\param inArchiveRef The archive to check. Null is invalid.
	\param inPassword The password to verify. Null is invalid.
	\return EngineError Returns kStuffItErrorPasswordCannotBeVerified if the password is invalid, or
	kStuffItErrorNoEncryptedContentFound if the archive does not contain any
	encrypted content.
*/
extern _PASCAL_ EngineError
VerifyArchivePassword(
    EngineRef                   inEngineRef,
    ArchiveRef                  inArchiveRef,
    StringRef	                inPassword ) WEAK_LINK;

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Accessor functions                                                                */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Get archive's format.
	
 	Gets the format of the specified archive.

	\param inArchiveRef The archive whose format is desired. Null is invalid.
	\param outFormat The format of the archive. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveFormat(
    const ArchiveRef            inArchiveRef,
    FormatID                  	outFormat ) WEAK_LINK;

/*!
	\brief Get archive's mode.
	
 	Get the mode that archive was opened in.

	\param inArchiveRef The archive whose mode is desired. Null is invalid.
	\param outMode Pointer to ArchiveMode to receive the mode. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveMode(
    const ArchiveRef            inArchiveRef,
    ArchiveMode                 *outMode) WEAK_LINK;

/*!
	\brief Query an archive's read only state.
	
	Determine if an archive can be written to, i.e. if it is currently open for writing - 
	open in full mode - and can be modified.

	\param inArchiveRef The archive to check. Null is invalid.
	\param outReadOnly Pointer to a Boolean to receive the archive's state. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError 
IsArchiveReadOnly(
	const ArchiveRef 			inArchiveRef, 
	Boolean *					outReadOnly) WEAK_LINK;


/*!
	\brief Get maximum access mode.
	
	Returns the maximum access mode of the given format.

	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to ArchiveMode. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetArchiveFormatMaximumAccessMode(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	ArchiveMode *				outAttribute ) WEAK_LINK;

/*!
	\brief Get redundancy attribute.
	
	Returns true if the archive was created with redundancy enabled.

	\param inArchiveRef The archive to check. Null is invalid.
	\return Returns true if redundancy is enabled.
*/
extern _PASCAL_ Boolean
ArchiveHasRedundancy(
	const ArchiveRef			inArchiveRef) WEAK_LINK;
	
/*!
	\brief Get archive encryption attribute.
	
	Returns true if archive was created with archive level encryption. Caveat: The archive
	must already be open to determine if it is encrypted. With some archive formats, it is 
	necessary to know the passphrase in order to open the archive.
		
	\param inArchiveRef The archive to check. Null is invalid.
	\return Returns true if encryption is enabled.
*/
extern _PASCAL_ Boolean 
ArchiveIsEncrypted(
	const ArchiveRef inArchiveRef) WEAK_LINK;

/*!
	\brief Get the file system object backing the archive.
	
	Returns the FSObject that respresents the archive in the file system. The
	caller is responsible for disposing of outObject.
	
	\param inArchiveRef The archive to check. Null is invalid.
	\param outObject	Receiver of the FSObjectRef. Null is invalid;
	\return Returns an EngineError.	
*/
extern _PASCAL_ EngineError
GetFSObjectFromArchive(
	const ArchiveRef			inArchiveRef, 
	FSObjectRef *				outObject) WEAK_LINK;

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Archive Utilities                                                                 */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Verify an archive.
	
	Checks the archive's integrity.
	
	Adheres to property callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The FSObjectRef to verify. Null is invalid.
	\param inPassword Optional password for the archive. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
VerifyArchive(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    const StringRef           	inPassword ) WEAK_LINK;

/*!
	\brief Recover an archive.
	
	Attempts to recover as much data as possible from a damaged archive.
	
	Adheres to properties destination prompt, delete action, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The FSObjectRef of the archive to recover. Null is invalid.
	\param inDestination Optional destination folder. Can be null.
	\param outResult Optional pointer to FSObjectRef to receive recovered data. Can be null.
	\param inPassword Optional password for the archive.
	\return EngineError
*/
extern _PASCAL_  EngineError
RecoverArchive(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    const FSObjectRef           inDestination,
    FSObjectRef *               outResult,
    StringRef		            inPassword ) WEAK_LINK;

/*!
	\deprecated Use TransformArchive instead.
	\brief Converts an archive.
	
	Converts an archive from one format to another.
	
	Adheres to properties destination prompt, delete action, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The archive to convert. Null is invalid.
	\param inDestination Optional FSObjectRef to destination. If null, the conversion
	will take place in the same folder as inSource using inSource's name as a basis
	for the new name. If inDestination is a folder, the conversion will take place in that
	folder again using inSource's name as a basis for the name. If inDestination references
	a non-existant file, the conversion will take place in that folder using the name
	specified.
	\param outResult Optional pointer to FSObjectRef to receive converted archive. Must
	be disposed of by client. Can be null.
	\param inFormatToConvertTo The archive format to convert to. Null is invalid.
	\param inPassword Optional password for the source archive.
	\param inWhatToConvert Controls the propagation of the source's encoding. For example, if
	the source archive is a .zip.uu and it is being converted to .sit, this parameter controls
	whether or not the result would be .sit or .sit.uu. See ConversionMethod.
	\param inRenameOriginal True if the original should be renamed.
	\return EngineError
*/
extern _PASCAL_  EngineError
ConvertArchive(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    const FSObjectRef           inDestination,
    FSObjectRef *               outResult,
    ConstFormatIDParam			inFormatToConvertTo,
    StringRef		            inPassword,
    ConversionMethod            inWhatToConvert,
    Boolean                     inRenameOriginal ) WEAK_LINK;

/*!
	\brief Transforms an archive.
	
	Creates a new archive of the desired format from the contents of the 
	source archive.
	
	Adheres to properties destination prompt, delete action, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The archive to convert. Null is invalid.
	\param inDestination Optional FSObjectRef to destination. If null, the conversion
	will take place in the same folder as inSource using inSource's name as a basis
	for the new name. If inDestination is a folder, the conversion will take place in that
	folder again using inSource's name as a basis for the name. If inDestination references
	a non-existant file, the conversion will take place in that folder using the name
	specified.
	\param outResult Optional pointer to FSObjectRef to receive converted archive. Must
	be disposed of by client. Can be null.
	\param inFormatToConvertTo The archive format to convert to. Null is invalid.
	\param inSourcePassword Optional password for the source archive.
	\param inDestinationPassword Optional password for the destination archive.
	\param inWhatToConvert Controls the propagation of the source's encoding. For example, if
	the source archive is a .zip.uu and it is being converted to .sit, this parameter controls
	whether or not the result would be .sit or .sit.uu. See ConversionMethod.
	\param inRenameOriginal True if the original should be renamed.
	\return EngineError
*/
extern _PASCAL_  EngineError
TransformArchive(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    const FSObjectRef           inDestination,
    FSObjectRef *               outResult,
    ConstFormatIDParam			inFormatToConvertTo,
    StringRef		            inSourcePassword,
    StringRef		            inDestinationPassword,
    ConversionMethod            inWhatToConvert,
    Boolean                     inRenameOriginal ) WEAK_LINK;

/*!
	\warning This function is unsupported and its use is not recommended.
	\brief Start a transaction with an archive.
	
	Creates a new transaction. All changes to the archive will be grouped
	until EndTransaction is called at which time the changes will be written out to 
	the archive. Begin/EndTransaction can be nested.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inArchive The archive to start a transaction. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
BeginTransaction(
    EngineRef                   inEngineRef,
	ArchiveRef					inArchive ) WEAK_LINK;
	
/*!
	\warning This function is unsupported and its use is not recommended.
	\brief Stop a transaction in an archive.
	
	Stops a transaction. All changes to the archive will be written out to 
	the archive if this is the top most transaction.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inArchive The archive to start a transaction. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
EndTransaction(
    EngineRef                   inEngineRef,
	ArchiveRef					inArchive ) WEAK_LINK;

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif