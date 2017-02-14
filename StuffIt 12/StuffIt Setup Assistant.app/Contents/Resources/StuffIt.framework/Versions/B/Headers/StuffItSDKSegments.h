/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKSegments.h
//
//   Description:   Interfaces for segmenting and joining files.
//) WEAK_LINK;
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
//  $Id: StuffItSDKSegments.h,v 1.15.2.1 2006/10/05 00:18:38 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKSegments.h
	
	\brief Interfaces for segmenting and joining archives and files.
	
	In general all of the APIs in this header are deprecated. They were specific to the StuffIt Segment
	format, or sitseg, and are the only functions in the StuffIt SDK that are specific to any particular
	format. Segment and join have always been implemented in terms of compress and expand, and now that there
	is more than one segmenting format, ie. StuffItX, it is no longer necessary for the specific segment and
	join functions to exist.
	
	When choosing which format to select for segmenting, StuffItX segmenting provides for all of the features
	of a non-segmented StuffItX archive including large file size support which the older StuffIt Segment format
	cannot support. 
*/

#ifndef STUFFITSDKSEGMENTS_H
#define STUFFITSDKSEGMENTS_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKFILES_H
#include <StuffIt/StuffItSDKFiles.h>
#endif

#ifndef STUFFITSDKSELFEXTRACTING_H
#include <StuffIt/StuffItSDKSelfExtracting.h>
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
	\brief Segment Size. See #SegmentSizes.
*/
typedef uint32_t	SegmentSize;
/*!
	\brief Large segment Size. See #SegmentSizes.
*/
typedef uint64_t	LargeSegmentSize;
/*!
	\brief Sizes for segmenting.
    
    Useful segment sizes that you can specify for segmenting.
*/
enum SegmentSizes{
    kSegmentSingleSided                     =     390 * 1024, /**< Single sided floppy disk */
    kSegmentInterchange                     =     700 * 1024, /**< 700k floppy disk */
    kSegmentDoubleSided                     =     775 * 1024, /**< Double sided floppy disk */
    kSegmentHighDensity                     =    1350 * 1024, /**< High density floppy disk */
    kSegmentFourtyFour                      =   42000 * 1024, /**< 44MB removable disk */
    kSegmentEightyEight                     =   84000 * 1024, /**< 88MB removable disk */
    kSegmentZip100                          =   95000 * 1024, /**< 100MB Zip disk */
    kSegmentSuperDisk                       =  115000 * 1024, /**< SuperDisk */
    kSegmentSonyHiFD                        =  195000 * 1024, /**< Sony HiFD */
    kSegmentZip250                          =  245000 * 1024, /**< Zip 250MB disk */
    kSegmentCDROM                           =  640000 * 1024, /**< CDRom */
    kSegmentMaxPossible                     =       0,		  /**< Use the largest size available */
    kSegmentSizeMaximum						= 	0xFFFFFFFE	  /**< Use the maximum size. For use with SetFormatIntegerProperty in StuffItSDKFormats.h */
};

/*!
	\brief Count number of segments.
	
	Determine the number of segments that would be created for a file
	based on a segment size.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource FSObjectRef of file. Null is invalid.
	\param segSize Size of segments. Can be from SegmentSizes or any positive integer.
	\param numSegments Pointer to uint32_t to receive number of segments. Null is invalid. 
	\return EngineError
*/
extern _PASCAL_  EngineError
CountSegmentsFSObject(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    SegmentSize                 segSize,
    uint32_t *                  numSegments ) WEAK_LINK;

/*!
	\deprecated Use CompressOrEncodeFSObject as a more robust alternative.

	\brief Split a file into segments
	
	Create segments of a file given a segment size.
	
	Adheres to properties destination prompt, delete action, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The FSObjectRef of a file to be segmented. Null is invalid.
	\param inDestination Optional destination. If null, the segments will be created in the
	same folder as inSource using inSource's name. If inDestination specifies a folder, 
	then the segments will be created in that folder with the same naming as if inDestination
	was null. If inDestination specifes a non-existant file, the segments will be created in that
	folder using the name specified.
	\param outResult Optional FSObjectRef to receive first segment. Can be null.
	\param inSegmentSize Size of segments. Can be from SegmentSizes or any positive integer.
	\return EngineError
*/
extern _PASCAL_  EngineError
CreateSegmentsFSObject(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    const FSObjectRef           inDestination,
    FSObjectRef *               outResult,
    SegmentSize                 inSegmentSize ) WEAK_LINK;


/*!
	\brief Split a file into segments
	
	Create segments of an archive of files and folders using a specified format and given a segment size.
	
	Adheres to properties destination prompt, delete action, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFileList List of files to be archived and segmented. Null is invalid.
	\param inDestination Optional destination. If null, the segments will be created in the
	same folder as inSource using inSource's name. If inDestination specifies a folder, 
	then the segments will be created in that folder with the same naming as if inDestination
	was null. If inDestination specifes a non-existant file, the segments will be created in that
	folder using the name specified.
	\param outResults Optional FSObjectListRef to receive segments created. Can be null.
	\param inFormat The format to use for segmenting. Null is invalid.
	\param inSegmentSize Size of segments. Can be from SegmentSizes or any positive integer.
	\param inPassword Optional password for ecrypting the segments. Can be null.
	\return EngineError
*/
extern _PASCAL_ EngineError
CreateSegmentsWithFormat(
	EngineRef					inEngineRef,
	const FSObjectListRef		inFileList,
    const FSObjectRef           inDestination,
    FSObjectListRef *           outResults,
	ConstFormatIDParam			inFormat,
    LargeSegmentSize            inSegmentSize,
    const StringRef			    inPassword ) WEAK_LINK;
	
/*!
	\brief Split a file into segments and index file
	
	Create segments of an archive of files and folders using a specified format and given a segment size optionally
	creating a separate index file.
	
	Adheres to properties destination prompt, delete action, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFileList List of files to be archived and segmented. Null is invalid.
	\param inDestination Optional destination. If null, the segments will be created in the
	same folder as inSource using inSource's name. If inDestination specifies a folder, 
	then the segments will be created in that folder with the same naming as if inDestination
	was null. If inDestination specifes a non-existant file, the segments will be created in that
	folder using the name specified.
	\param outResults Optional FSObjectListRef to receive segments created. Can be null.
	\param inFormat The format to use for segmenting. Null is invalid.
	\param inSegmentSize Size of segments. Can be from SegmentSizes or any positive integer.
	\param inPassword Optional password for ecrypting the segments. Can be null.
	\param inIndexFile Optional file to create an index archive. Can be null.
	\return EngineError
*/
_PASCAL_ EngineError
CreateSegmentsWithFormatAndIndex(
	EngineRef					inEngineRef,
	const FSObjectListRef		inFileList,
    const FSObjectRef           inDestination,
    FSObjectListRef *           outResults,
    ConstFormatIDParam			inFormat,
    LargeSegmentSize            inSegmentSize,
    const StringRef				inPassword,
	FSObjectRef					inIndexFile) WEAK_LINK;

/*!
	\deprecated Use ExpandOrDecodeFile as a more robust alternative.

	\brief Join segments into a single file.
	
	Create a file from segments.

	Adheres to property destination prompt, delete action, callbacks.

	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The FSObjectRef of the first segment. Null is invalid.
	\param inDestination Optional destination. If null, the joined file will be created in the
	same folder as inSource. If inDestination specifies a folder, 
	then the joined file will be created in that folder.
	\param outResults Optional FSObjectListRef to receive joined file. Can be null.
	\return EngineError
*/
extern _PASCAL_  EngineError
JoinSegmentsFSObject(
    EngineRef                   inEngineRef,
    const FSObjectRef           inSource,
    const FSObjectRef           inDestination,
    FSObjectListRef *       	outResults ) WEAK_LINK;

/*!
	\brief Determines if a file is the first segment.
	
	Determines if a file is the first in a series of segments.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inSource The FSObjectRef of the file. Null is invalid.
	\return True if inSource is the first segment.
*/
extern _PASCAL_  Boolean
IsFirstSegmentFSObject(
	const EngineRef				inEngineRef,
	const FSObjectRef			inSource ) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif