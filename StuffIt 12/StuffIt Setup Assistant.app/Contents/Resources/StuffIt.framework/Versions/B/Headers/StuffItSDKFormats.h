/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKFormats.h
//
//   Description:   Interfaces for working with StuffIt Engine formats.
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
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKFormats.h
	
	\brief StuffItSDKFormats.h provides interfaces for accessing formats and setting their
	various properties.
*/

#ifndef STUFFITSDKFORMATS_H
#define STUFFITSDKFORMATS_H

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
	\brief Storage for a format name

	Storage for a format name
*/
typedef char							  FormatID[50];
/*!
	\brief Const pointer to a format name

	Const pointer to a format name
*/
typedef const char *					  ConstFormatIDParam;

/*
	The formats known to the StuffIt Engine
	
	For human readable strings, use AcquireFormatName
*/
/** \defgroup Formats Formats supported by the StuffIt Engine */
/*!
	\brief Unknown format.

	\ingroup Formats
*/
#define kFormatIDUnknown					""
/*!
	\brief No format.

	\ingroup Formats
*/
#define kFormatIDNone						""

/*!
	\brief StuffIt X format.
 
	\ingroup Formats
*/
#define kFormatIDStuffItX					"sitx"
/*!
	\brief StuffIt 5 format.

	\ingroup Formats
*/
#define kFormatIDStuffIt5                   "sit5"
/*!
	\brief StuffIt 4.5 or older format.

	\ingroup Formats
*/
#define kFormatIDStuffIt                    "sit"
/*!
	\brief AppleSingle format.

	\ingroup Formats
*/
#define kFormatIDAppleSingle                "apple"
/*!
	\brief AppleDouble format.

	\ingroup Formats
*/
#define kFormatIDAppleDouble				"double"
/*!
	\brief Arc format.

	\ingroup Formats
*/
#define kFormatIDArc                        "arc"
/*!
	\brief ARJ format.

	\ingroup Formats
*/
#define kFormatIDArj                        "arj"
/*!
	\brief CAB format.

	\ingroup Formats
*/
#define kFormatIDCab						"cab"
/*!
	\brief Binhex format.

	\ingroup Formats
*/
#define kFormatIDBinHex                     "hqx"
/*!
	\brief BtoA format.

	\ingroup Formats
*/
#define kFormatIDBtoA                       "btoa"
/*!
	\brief BZip format.

	\ingroup Formats
*/
#define kFormatIDBZip                       "bz2"
/*!
	\brief CompactPro format.

	\ingroup Formats
*/
#define kFormatIDCompactPro                 "cpt"
/*!
	\brief Freeze format.

	\ingroup Formats
*/
#define kFormatIDFreeze                     "freeze"
/*!
	\brief GZip format.

	\ingroup Formats
*/
#define kFormatIDGZip                       "gz"
/*!
	\brief LHa format.

	\ingroup Formats
*/
#define kFormatIDLHa                        "lha"
/*!
	\brief MacBinary format.

	\ingroup Formats
*/
#define kFormatIDMacBinary                  "bin"
/*!
	\brief MIME format.

	\ingroup Formats
*/
#define kFormatIDMime                       "mime"
/*!
	\brief Private File format.

	\ingroup Formats
*/
#define kFormatIDPrivateFile                "pf"
/*!
	\brief RAR format.

	\ingroup Formats
*/
#define kFormatIDRar                        "rar"
/*!
	\brief SCOCompress format.

	\ingroup Formats
*/
#define kFormatIDScoCompress                "sco"
/*!
	\brief TAR format.

	\ingroup Formats
*/
#define kFormatIDTar                        "tar"
/*!
	\brief Unix Compact format.

	\ingroup Formats
*/
#define kFormatIDUnixCompact                "compact"
/*!
	\brief UnixCompress format.

	\ingroup Formats
*/
#define kFormatIDUnixCompress               "compress"
/*!
	\brief Unix Pack format.

	\ingroup Formats
*/
#define kFormatIDUnixPack                   "pack"
/*!
	\brief UUEncode format.

	\ingroup Formats
*/
#define kFormatIDUUCode                     "uu"
/*!
	\brief YEncode format.

	\ingroup Formats
*/
#define kFormatIDYEncode					"yenc"
/*!
	\brief Zip format.

	\ingroup Formats
*/
#define kFormatIDZip                        "zip"

/*!
	\brief StuffIt Segment format.

	\ingroup Formats
*/
#define kFormatIDStuffItSegment             "sitseg"
/*!
	\brief StuffIt Segment format.

	\ingroup Formats
*/
#define kFormatIDStuffItSegmentN            "sitsegN"

/*!
	\brief StuffIt Spacesaver format.

	\ingroup Formats
*/
#define kFormatIDStuffItSpacesaver            "spacesaver"

/*!
	\brief ShrinkWrap disk image.
*/
#define kImageTypeShrinkWrap30              "image-shrinkwrap"
/*!
	\brief ShrinkWrap self-extracting disk image.
*/
#define kImageTypeShrinkWrapSMI30           "image-shrinkwrap-smi"
/*!
	\brief Norton Disk image.
*/
#define kImageTypeNDIF                      "image-ndif"
/*!
	\brief Disk Copy 4.2 disk image.
*/
#define kImageTypeDiskCopy42                "image-diskcopy"
/*!
	\brief Drive Container disk image.
*/
#define kImageTypeDriveContainer            "image-drivecontainer"
/*!
	\brief DiskDup+ disk image.
*/
#define kImageTypeDiskDupPlus               "image-diskdup"
/*!
	\brief MSDOS disk image.
*/
#define kImageTypeMSDOS                     "image-msdos"
/*!
	\brief DART disk image.
*/
#define kImageTypeDART                      "image-dart"
/*!
	\brief Floppier disk image.
*/
#define kImageTypeFloppierImage             "image-floppier"
/*!
	\brief FastCopy disk image.
*/
#define kImageTypeFastCopyImage             "image-fastcopy"
/*!
	\brief DiskCopyCMP image.
*/
#define kImageTypeDiskCopyCmpImage          "image-diskcopycmp"
/*!
	\brief MacOSX Disk Copy image.
*/
#define kImageTypeDiskCopyXImage			"image-diskcopyx"
/*!
	\brief DiskCopy image segment.
*/
#define kImageTypeDiskImageSegment          "image-segment"

/*!
	\brief Container to hold format suffix string.
*/
typedef char		FormatExtension[16];

/*!
	\brief Container to hold format mime type string.
*/
typedef char		FormatMimeType[256];

/*!
	\brief A reference to a format iterator.
*/
typedef struct OpaqueFormatIterator *		FormatIteratorRef;

/*!
	\brief Used with SetFormatIntegerProperty when a default value is desired, but the actual
	value isn't known.

	\ingroup IntegerFormatProperties
*/
uint32_t
GetFormatIntegerPropertyDefaultValue();

/*!
	\brief Compression level.
*/
typedef int32_t CompressionLevel;
/*!
	\brief Levels used to compress items.
	
	Each format that supports compression, may also have the option to
	specify the level of compression.
*/
enum CompressionLevels{
	kCompressionLevelDefault				=	0xFFFFFFFF, /**< Use the default compression level defined by the format. */
	kCompressionLevelMaximum				=	0xFFFFFFFE, /**< Use the maximum compression level defined by the format. */
    kCompressionLevelNone                   =   0,			/**< Use no compression. */
    kCompressionLevelFastest				=	1			/**< Use the fastest level available in the format. */
};

/*!
	\brief Compression method.
*/
typedef int32_t CompressionMethod;
/*!
	\brief Methods used to compress items.
	
	Each format that supports compression, may also have the option to
	specify the method of compression.
*/
enum CompressionMethods{
	kCompressionMethodDefault				=	0xFFFFFFFF,	/**< Use the default compression method defined by the format. */
    kCompressionMethodNone                  =   0 /**< Do not perform any compression. */
};

/*!
	\brief Extent level.
*/
typedef int32_t ExtentLevel;

/*!
	\brief Extent level used in compression.

	Each format that supports extents, may also have the option to
	specify the level.
*/
enum ExtentLevels{
	kExtentLevelDefault						=	0xFFFFFFFF /**< Use the default extent level defined by the format. */
};

/*!
	\brief Encryption method.
*/
typedef int32_t EncryptionMethod;
/*!
	\brief Methods used to encrypt items.
	
	Each format that supports encryption, may also have the option to
	specify the method of encryption.
*/
enum EncryptionMethods {
	kEncryptionMethodDefault				=	0xFFFFFFFF, /**< Use the default encryption method defined by the format. */
    kEncryptionMethodNone                  	=   0			/**< Do not perform any encryption. */
};

/*!
	\brief Encryption key size.
*/
typedef int32_t EncryptionKeySize;
/*!
	\brief Methods used to set encryption key size.

	Each format that supports encryption, may also have the option to
	specify the encryption key size.
*/
enum EncryptionKeySizes {
	kEncryptionKeySizeDefault				=	0xFFFFFFFF, /**< Use the default encryption key size defined by the format. */
    kEncryptionKeySizeNone                  =   0			/**< Do not perform any encryption. */
};

/*!
	\brief Encoding level.
*/
typedef int32_t EncodingLevel;
/*!
	\brief Methods used to set encoding level of a format.
	
	Each format that supports encoding has the option to specify the type
	of encoding.
*/
enum EncodingLevels {
	kEncodingLevelDefault					=	0xFFFFFFFF, /**< Use the default encoding level defined by the format. */
    kEncodingLevelNone                  	=   0			/**< Do not perform any encoding. */
};

/*!
	\brief Redundancy level.
*/
typedef int32_t RedundancyLevel;
/*!
	\brief Methods used to set redundancy level of a format.
	
	Each format that supports redundancy has the option to specify the level of redundancy.
*/
enum RedundancyLevels {
	kRedundancyLevelDefault					=	0xFFFFFFFF,	/**< Use the default redundancy level defined by the format. */
    kRedundancyLevelNone                  	=   0			/**< Do not use any redundancy. */
};

/*!
	\brief Format Property identifier
*/
typedef const char *					  ConstFormatPropertyIDParam;

/** \defgroup StringFormatProperties String based format properties */

/*!
	\brief Get a format's name.

	The kFormatPropertyIDName property returns the name of the format. This is the name
	used to identify the format to the various APIs that require a #FormatID or
	#ConstFormatIDParam as a parameter.
	 
	 This property is read-only.
	 
	\ingroup StringFormatProperties
*/
#define		kFormatPropertyIDName 			"formatName"

/*!
	\brief Get a format's long name.

	The kFormatPropertyIDLongName property returns the long name of the format. This name is more
	suitable for display.
	 	 
	 This property is read-only.

	\ingroup StringFormatProperties
*/
#define		kFormatPropertyIDLongName		"longName"

/*!
	\brief Get a format's suffix.

	The kFormatPropertyIDSuffix property returns the suffix associated with a format.
	 
	 This property is read-only.
	 
	\ingroup StringFormatProperties
*/
#define		kFormatPropertyIDSuffix			"suffix"

/*!
	\brief Get a format's MIME type.

	The kFormatPropertyIDMimeType property returns the MIME type associated with a format.
	 
	 This property is read-only.
	 
	\ingroup StringFormatProperties
*/
#define		kFormatPropertyIDMimeType		"mimeType"

/*!
	\brief Get a format's UTI.

	Returns the Universal Type Identifier for a format.
	
	This property is read-only.
	 
	\ingroup StringFormatProperties
*/
#define		kFormatPropertyUTI				"uti"

/** \defgroup IntegerFormatProperties Integer based format properties. */

/*!
	\brief Current format compression method.

	The kFormatPropertyIDCurrentCompressionMethod property can be used to get or set a format's compression method. When setting
	the compression method, the #CompressionLevel for that #CompressionMethod is also set. See #CompressionMethod.
	 	 
	 This property is read/write.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentCompressionMethod	"compMethod"

/*!
	\brief Minimum format compression method.

	The kFormatPropertyIDMinimumCompressionMethod property returns a format's maximum compression method.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumCompressionMethod	"compMethodLeast"

/*!
	\brief Maximum format compression method.

	The kFormatPropertyIDMaximumCompressionMethod property returns a format's maximum compression method.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumCompressionMethod	"compMethodMost"

/*!
	\brief Default format compression method.

	The kFormatPropertyIDDefaultCompressionMethod property returns a format's default compression method.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultCompressionMethod	"compMethodDefault"

/*!
	\brief Current format compression level.

	The kFormatPropertyIDCurrentCompressionLevel property can be used to get or set a format's compression level. See #CompressionLevel.
	 	 
	 This property is read/write.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentCompressionLevel	"compressionLevel"
/*!
	\brief Minimum format compression level.

	The kFormatPropertyIDMinimumCompressionLevel property returns a format's minimum compression level. See #CompressionLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumCompressionLevel	"compressionLeast"
/*!
	\brief Maximum format compression level.

	The kFormatPropertyIDMaximumCompressionLevel property returns a format's maximum compression level. See #CompressionLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumCompressionLevel	"compressionMost"
/*!
	\brief Default format compression level.

	The kFormatPropertyIDDefaultCompressionLevel property returns a format's default compression level. See #CompressionLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultCompressionLevel	"compressionDefault"

/*!
	\brief Minimum format compression ratio.

	The kFormatPropertyIDMinimumCompressionRatio property returns a format's minimum compression ratio.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumCompressionRatio 	"minCompressionRatio"
/*!
	\brief Maximum format compression ratio.

	The kFormatPropertyIDMaximumCompressionRatio property returns a format's maximum compression ratio.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumCompressionRatio	"maxCompressionRatio"
/*!
	\brief Current format compression ratio.

	The kFormatPropertyIDCurrentCompressionRatio property returns a format's current compression ratio.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentCompressionRatio	"compressionRatio"

/*!
	\brief Minimum format compression speed.

	The kFormatPropertyIDMinimumCompressionSpeed property returns a format's minimum compression speed.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumCompressionSpeed	"minCompressionSpeed"
/*!
	\brief Maximum format compression speed.

	The kFormatPropertyIDMaximumCompressionSpeed property returns a format's maximum compression speed.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumCompressionSpeed	"maxCompressionSpeed"
/*!
	\brief Current format compression speed.

	The kFormatPropertyIDMaximumCompressionSpeed property returns a format's current compression speed.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentCompressionSpeed	"compressionSpeed"

/*!
	\brief Minimum format expansion speed.

	The kFormatPropertyIDMinimumExpansionSpeed property returns a format's minimum expansion speed.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumExpansionSpeed		"minExpansionSpeed"
/*!
	\brief Maximum format expansion speed.

	The kFormatPropertyIDMaximumExpansionSpeed property returns a format's maximum expansion speed.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumExpansionSpeed		"maxExpansionSpeed"
/*!
	\brief Current format expansion speed.

	The kFormatPropertyIDCurrentExpansionSpeed property returns a format's current expansion speed.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentExpansionSpeed		"expansionSpeed"

/*!
	\deprecated This property is no longer supported.
	\brief Current compression memory requirements.

	The kFormatPropertyIDCompressionMemory property returns a format's compression memory requirements.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCompressionMemory			"compressionMemory"
/*!
	\deprecated This property is no longer supported.
	\brief Current expansion memory requirements.

	The kFormatPropertyIDExpansionMemory property returns a format's expansion memory requirements.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDExpansionMemory			"expansionMemory"

/*!
	\brief Current encryption method.

	The kFormatPropertyIDCurrentEncryptionMethod property can be used to get or set a format's encryption method. See #EncryptionMethod.
	Setting the #EncryptionMethod will also set the #EncryptionKeySize to the default for that method.
	 	 
	 This property is read/write.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentEncryptionMethod	"encryptMethod"
/*!
	\brief Minimum encryption method.

	The kFormatPropertyIDMinimumEncryptionMethod property returns a format's minimum encryption method. See #EncryptionMethod.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumEncryptionMethod	"encryptMethodLeast"
/*!
	\brief Maximum encryption method.

	The kFormatPropertyIDMaximumEncryptionMethod property returns a format's maximum encryption method. See #EncryptionMethod.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumEncryptionMethod	"encryptMethodMost"
/*!
	\brief Default encryption method.

	The kFormatPropertyIDDefaultEncryptionMethod property returns a format's default encryption method. See #EncryptionMethod.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultEncryptionMethod	"encryptMethodDefault"

/*!
	\brief Current encryption key size.

	The kFormatPropertyIDCurrentEncryptionKeySize property can be used to get or set a format's encryption key size. See #EncryptionKeySize.
	 	 
	 This property is read/write.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentEncryptionKeySize	"keySize"
/*!
	\brief Minimum encryption key size.

	The kFormatPropertyIDMinimumEncryptionKeySize property returns a format's minimum encryption key size. See #EncryptionKeySize.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumEncryptionKeySize	"keySizeLeast"
/*!
	\brief Maximum encryption key size.

	The kFormatPropertyIDMaximumEncryptionKeySize property returns a format's maximum encryption key size. See #EncryptionKeySize.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumEncryptionKeySize	"keySizeMost"
/*!
	\brief Default encryption key size.

	The kFormatPropertyIDDefaultEncryptionKeySize property returns a format's default encryption key size. See #EncryptionKeySize.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultEncryptionKeySize	"keySizeDefault"

/*!
	\brief Current extent level.

	The kFormatPropertyIDCurrentCompressionExtent property can be used to get or set a format's extent level. See #ExtentLevel.
	 	 
	 This property is read/write.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentCompressionExtent	"compExtent"
/*!
	\brief Minimum extent level.

	The kFormatPropertyIDMinimumCompressionExtent property returns a format's minimum extent level. See #ExtentLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumCompressionExtent	"compExtentLeast"
/*!
	\brief Maximum extent level.

	The kFormatPropertyIDMaximumCompressionExtent property returns a format's maximum extent level. See #ExtentLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumCompressionExtent	"compExtentMost"
/*!
	\brief Default extent level.

	The kFormatPropertyIDDefaultCompressionExtent property returns a format's default extent level. See #ExtentLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultCompressionExtent	"compExtentDefault"

/*!
	\brief Current encoding level.

	The kFormatPropertyIDCurrentEncodingLevel property can be used to get or set a format's encoding level. See #EncodingLevel.
	 	 
	 This property is read/write.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentEncodingLevel		"encodeLevel"
/*!
	\brief Minimum encoding level.

	The kFormatPropertyIDMinimumEncodingLevel property returns a format's minimum encoding level. See #EncodingLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumEncodingLevel		"encodetLevelLeast"
/*!
	\brief Maximum encoding level.

	The kFormatPropertyIDMaximumEncodingLevel property returns a format's maximum encoding level. See #EncodingLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumEncodingLevel		"encodeLevelMost"
/*!
	\brief Default encoding level.

	The kFormatPropertyIDDefaultEncodingLevel property returns a format's default encoding level. See #EncodingLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultEncodingLevel		"encodeLevelDefault"
/*!
	\brief Encoding subset.

	The kFormatPropertyIDEncodingSubset property returns a format's encoding subset.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDEncodingSubset				"encodeSubset"
/*!
	\brief Encoding overhead.

	The kFormatPropertyIDEncodingSubset property returns a format's encoding overhead.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDEncodingOverhead			"encodeOverhead"

/*!
	\brief Current redundancy level.

	The kFormatPropertyIDCurrentRedundancyLevel property can be used to get or set a format's redundancy level. See #RedundancyLevel.
	 	 
	 This property is read/write.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentRedundancyLevel		"redundancyLevel"
/*!
	\brief Minimum redundancy level.

	The kFormatPropertyIDMinimumRedundancyLevel property returns a format's minimum redundancy level. See #RedundancyLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumRedundancyLevel		"redundancytLevelLeast"
/*!
	\brief Maximum redundancy level.

	The kFormatPropertyIDMaximumRedundancyLevel property returns a format's maximum redundancy level. See #RedundancyLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumRedundancyLevel		"redundancyLevelMost"
/*!
	\brief Default redundancy level.

	The kFormatPropertyIDDefaultRedundancyLevel property returns a format's default redundancy level. See #RedundancyLevel.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultRedundancyLevel		"redundancyLevelDefault"
/*!
	\brief Redundancy level overhead.

	The kFormatPropertyIDRedundancyOverhead property returns a format's redundancy level overhead.
	 	 
	 This property is read-only.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDRedundancyOverhead			"redundancyOverhead"

/*!
	\brief Segment size.

	The kFormatPropertyIDSegmentSize property can be used to get or set a format's segment creation size.
	 	 
	 This property is read/write.

	\ingroup IntegerFormatProperties
*/
#define 	kFormatPropertyIDSegmentSize				"segmentSize"

/*
	Boolean based format properties
*/
/** \defgroup BooleanFormatProperties Boolean based format properties */

/*!
	\brief Set block mode permission.

	The kFormatPropertyIDBlockMode property enables blockmode compression
	for formats that support it such as #kFormatIDStuffItX.
	 
	The default is true.

	\ingroup BooleanFormatProperties
*/
#define		kFormatPropertyIDBlockMode					"blockMode"

/*!
	\brief Set compression optimizers.

	The kFormatPropertyIDCompressionOptimizers enables the use of compression optimizers
	during compression of items into an archive. Supported by #kFormatIDStuffItX.
	 
	The default is true.

	\ingroup BooleanFormatProperties
*/
#define 	kFormatPropertyIDCompressionOptimizers		"filters"

/*! \deprecated See #kFormatPropertyIDCompressionOptimizers

	\ingroup BooleanFormatProperties
*/
#define		kFormatPropertyIDCompressionFilters			kFormatPropertyIDCompressionOptimizers

/*!
	\brief Set whole archive compression.

	The kFormatPropertyIDArchiveLevelEncryption allows an archive to be created with whole
	archive encryption rather than encrypting items on an individual basis.
	 
	The default is false.

	\ingroup BooleanFormatProperties
*/
#define		kFormatPropertyIDArchiveLevelEncryption		"encryptArchive"

/*!
	\brief Set number of threads.

	kFormatPropertyIDMaxThreads controls the number of threads to be used when compressing
	or expanding.
	 
	The default is 0.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaxThreads					"maxThreads"

/*!
	\brief Get the max file size.

	kFormatPropertyIDMaxFileSize returns the maximum size in bits that a format supports.
	 
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaxFileSize				"fileSizeBits"

/*!
	\brief Toggle creation of image thumbnails.
	
	kFormatPropertyIDThumbnails controls whether or not thumbnail
	previews are created for images stored within archives.
	
	This property is read/write.
	
	Available in SDK version 0x812
	\ingroup BooleanFormatProperties
*/
#define		kFormatPropertyIDThumbnails					"thumbNails"

/*!
	\deprecated Use kFormatPropertyIDRecompression with the kRecompressJPEG flag
	\brief Get the current JPEG compressor.
	
	kFormatPropertyCurrentJPEGCompressor controls which JPEG compressor
	to use.
	
	This property is read/write.
	
	Available in SDK version 0x812
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentJPEGCompressionMethod		"jpegRule"

/*!
	\deprecated No longer supported. See kFormatPropertyIDRecompression
	\brief Get the minimum JPEG compressor.
	
	kFormatPropertyMinimumJPEGCompressor returns the minimum JPEG compressor.
	
	This property is read-only.
	
	Available in SDK version 0x812
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumJPEGCompressionMethod		"jpegRuleLeast"

/*!
	\deprecated No longer supported. See kFormatPropertyIDRecompression
	\brief Get the maximum JPEG compressor.
	
	kFormatPropertyMaximumJPEGCompressor returns the maximum JPEG compressor.
	
	This property is read-only.
	
	Available in SDK version 0x812
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumJPEGCompressionMethod		"jpegRuleMost"

/*!
	\deprecated No longer supported. See kFormatPropertyIDRecompression
	\brief Get the default JPEG compressor.
	
	kFormatPropertyDefaultJPEGCompressor returns the default JPEG compressor.
	
	This property is read-only.
	
	Available in SDK version 0x812
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultJPEGCompressionMethod		"jpegRuleDefault"

/*!
	\deprecated No longer supported. See kFormatPropertyIDRecompression
	\brief Current jpeg compression level.

	The kFormatPropertyIDCurrentJPEGCompressionLevel property can be used to get or set jpeg compression level.
	 	 
	 This property is read/write.

	 Available in SDK version 0x812
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDCurrentJPEGCompressionLevel	"jpegLevel"

/*!
	\deprecated No longer supported. See kFormatPropertyIDRecompression
 	\brief Minimum jpeg compression level.

	The kFormatPropertyIDMinimumJPEGCompressionLevel property returns minimum jpeg compression level.
	 	 
	 This property is read-only.

	 Available in SDK version 0x812
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMinimumJPEGCompressionLevel	"jpegLevelLeast"

/*!
	\deprecated No longer supported. See kFormatPropertyIDRecompression
	\brief Maximum jpeg compression level.

	The kFormatPropertyIDMaximumJPEGCompressionLevel property returns maximum jpeg compression level.
	 	 
	 This property is read-only.

	 Available in SDK version 0x812
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaximumJPEGCompressionLevel	"jpegLevelMost"

/*!
	\deprecated No longer supported. See kFormatPropertyIDRecompression
	\brief Default jpeg compression level.

	The kFormatPropertyIDDefaultJPEGCompressionLevel property returns default jpeg compression level.
	 	 
	 This property is read-only.

	 Available in SDK version 0x812
	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDDefaultJPEGCompressionLevel	"jpegLevelDefault"

/*!
	\brief Ensures that archives created with compression/encrytion method(s) that are supported by self-extractor.

	This property is for Windows OS only.

	The kFormatPropertyIDSelfExtracting property ensures that archives are being created with compression/encrytion 
	method(s) that are supported by self-extractors.
	Such archives can be used for ceating self-extracting archives later. This property is available for sitx format
	only, it is ignored for other formats. 
	 	 
	This property is read/write.
	Default is false.

	Available in SDK version 0x820
	\ingroup BooleanFormatProperties
*/
#define		kFormatPropertyIDSelfExtracting		"selfExtracting"

/*!
	\brief Format supports indexing.
	
	kFormatPropertyIDIndexable indicates that a format supports the creation of a separate index archive. An
	index archive can be used to browse the contents of an archive when the actual archive is not available.
	They are much smaller than the original archive as they do not contain any of the compressed data.
	
	This property is read-only.
	
	Available in SDK version 0x820.
	\ingroup BooleanFormatProperties
	
*/
#define		kFormatPropertyIDIndexable		"createsIndex"

/*!
	\brief Recompress when an archive is being added into sitx.

	The kFormatPropertyIDRecompress property is available for sitx format only and 
	when set to true it ensures	that if a zip archive is being added to sitx it is 
	recompressed. It results in better compression ratio.
	 	 
	This property is read/write.
	Default is false.

	\ingroup BooleanFormatProperties
*/
#define		kFormatPropertyIDRecompress		"recompressArchives"

/*!
	\brief Maximum version of a StuffIt X archive.

	kFormatPropertyIDMaxVersion controls the features that a StuffIt X archive will use when it
	is created. Current versions are:
	
	0 - Initial version. Released with StuffIt Mac 7.0
	1 - Added encrypted catalogs and new general purpose compressor. Released with StuffIt Mac 9.0
	2 - Added JPEG compressor. Released with StuffIt Mac 10.0
	3 - Added external catalogs (archive indexing). The actual format did not change. Released with StuffIt Mac 11.0
	4 - Added zip archive recompression. Creation and expansion in StuffIt Windows 11. Expansion in StuffIt Mac 11.0.2
	5 - File type recompressors: mp3, bmp, jls, j2k, png, tiff, pxm, gif, psd, pict, pdf. Released with StuffIt Mac 12.0
	 	 
	This property is read/write.
	Default is 5.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDMaxVersion		"maxVersion"

/*!
	\brief Masks used to specify which recompressors to use.
	
	StuffIt X contains compressors specific to certain file types which can be
	enabled or disabled as desired.
*/
enum RecompressionMasks
{
	kRecompressNone = 0,			/**< Disable all recompressors. */
	kRecompressJPEG = 1 << 0,		/**< Enable the JPEG image recompressor. */
	kRecompressMP3 = 1 << 1,		/**< Enable the MP3 audio recompressor. */
	kRecompressBMP = 1 << 2,		/**< Enable the BMP image recompressor. */
	kRecompressGIF = 1 << 3,		/**< Enable the GIF image recompressor. */
	kRecompressPNG = 1 << 4,		/**< Enable the PNG image recompressor. */
	kRecompressTIFF = 1 << 5,		/**< Enable the TIFF image recompressor. */
	kRecompressPDF = 1 << 6,		/**< Enable the PDF recompressor. */
	kRecompressJPEG2K = 1 << 7,		/**< Enable the JPEG 2K image recompressor. */
	kRecompressJPEGLossless = 1 << 8,	/**< Enable the JPEG lossless image recompressor. */
	kRecompressPSD = 1 << 9,		/**< Enable the PSD image recompressor */
	kRecompressPICT = 1 << 10,		/**< Enable the PICT image recompressor */
	kRecompressPTT5 = 1 << 11,		/**< Enable the PTT5 image compressor. */
	kRecompressPXM = 1 << 12,		/**< Enable the PXM image compressor. */
	
	kRecompressAll = 0xFFFFFFFF,	/**< Enable all recompressors. */
};

/*!
	\brief Controls compression of certain file types.

	kFormatPropertyIDRecompression specifies a mask which enables or disables compressors within the 
	StuffIt X format for file types that are typically already compressed.  The files types affected are:
	jpeg, mp3, bmp, gif, png, tiff, and pdf.

	This property is read/write.
	Default is kRecompressAll.

	\ingroup IntegerFormatProperties
*/
#define		kFormatPropertyIDRecompression	"recompression"

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ File Classification                                                               */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Classifies a file
	
	Determines if a given file is of a format the StuffIt Engine is aware of.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inObject Reference to file to classify obtained from NewXXXFSObject. Null is invalid.
	\param outFileType The format that this file contains.
	\return Returns an EngineError
*/
extern _PASCAL_  EngineError
DetermineFileFormat(
    EngineRef                   inEngineRef,
    const FSObjectRef           inObject,
    FormatID                  outFileType ) WEAK_LINK;


/*!
	\brief Recursively classifies a file
	
	Attempts to burrow down into a compound archive to determine the interior
	format.

	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inObject Reference to file to classify obtained from NewXXXFSObject. Null is invalid.
	\param outFormat The format that this file contains.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
DetermineInnermostFileFormat(
	EngineRef					inEngineRef,
	const FSObjectRef			inObject,
	FormatID					outFormat) WEAK_LINK;

/*!
	\brief Determine if a file is a StuffIt archive.
	
	Quick and dirty test to determine if a file is a StuffIt archive.
	Does not guarantee that the file is actually an archive. Use DetermineFileFormat
	for accurate classification.
	
	\param inSource The source FSObjectRef. Null is invalid.
	\param isStuffItFileType Returns true if the file is a StuffIt archive. Null is invalid.
	\return EngineError
*/
extern _PASCAL_  EngineError
IsStuffItArchive(
    const FSObjectRef  			inSource, 
    Boolean *					isStuffItFileType ) WEAK_LINK;

/*!
	\brief Determine if a format is a StuffIt format.
	
	Indicates if a format is in the StuffIt format family, ie.
	StuffIt, StuffIt5, or StuffItX.
	
	\param inFormat The format to test. Null is invalid.
	\return True if the format belongs to the StuffIt family.
*/
extern _PASCAL_ Boolean
IsStuffItFormat(
	ConstFormatIDParam			inFormat) WEAK_LINK;

/*
	Format Property accessors
*/

/*!
	\brief Get existence of a property.
	
	Indicates whether or not the format has a given property.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param inProperty The property to query. Null is invalid.
	\return True if the property exists.
*/
extern _PASCAL_ Boolean
FormatHasProperty(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat,
	ConstFormatPropertyIDParam	inProperty) WEAK_LINK;

/*!
	\brief Get a string from a format
	
	Returns the value of a string property of a format. The string must be disposed
	with DisposeStringRef.
	
	Available in the 0x0811 version of the SDK.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param inProperty The property to query. Null is invalid.
	\param outValue The value of the property. Null is invalid.
*/
extern _PASCAL_ EngineError
AcquireFormatStringProperty(
	EngineRef 						inEngineRef, 
	ConstFormatIDParam 				inFormat, 
	ConstFormatPropertyIDParam 		inProperty, 
	StringRef *						outValue) WEAK_LINK;

/*!
	\brief Get an integer from a format
	
	Returns the value of an integer property of a format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param inProperty The property to query. Null is invalid.
	\param outValue The value of the property. Null is invalid.
*/
extern _PASCAL_ EngineError 
GetFormatIntegerProperty(
	EngineRef 						inEngineRef, 
	ConstFormatIDParam 				inFormat, 
	ConstFormatPropertyIDParam 		inProperty, 
	uint32_t *						outValue) WEAK_LINK;
	
/*!
	\brief Set an integer property of a format
	
	Sets the value of an integer property of a format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param inProperty The property to query. Null is invalid.
	\param inValue The new value of the property.
*/
extern _PASCAL_ EngineError 
SetFormatIntegerProperty(
	EngineRef 					inEngineRef, 
	ConstFormatIDParam 			inFormat, 
	ConstFormatPropertyIDParam 		inProperty, 
	uint32_t 					inValue) WEAK_LINK;
	
/*!
	\brief Get a boolean from a format
	
	Returns the value of a boolean property of a format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param inProperty The property to query. Null is invalid.
	\param outValue The value of the property. Null is invalid.
*/
extern _PASCAL_ EngineError 
GetFormatBooleanProperty(
	EngineRef 					inEngineRef, 
	ConstFormatIDParam 			inFormat, 
	ConstFormatPropertyIDParam 		inProperty, 
	Boolean *					outValue) WEAK_LINK;

/*!
	\brief Set a boolean property of a format
	
	Sets the value of an boolean property of a format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param inProperty The property to query. Null is invalid.
	\param inValue The new value of the property.
*/
extern _PASCAL_ EngineError 
SetFormatBooleanProperty(
	EngineRef 					inEngineRef, 
	ConstFormatIDParam 			inFormat, 
	ConstFormatPropertyIDParam 		inProperty, 
	Boolean 					inValue) WEAK_LINK;

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Format Attributes		                                                            */
/*	Most accessors have been deprecated in favor of the Get/SetFormatProperty functions.*/
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Gets the name of a format.
	
	Returns the name of a format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param outFormatName Pointer to a StringRef to receive format name Must be 
	disposed of with DisposeStringRef. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
AcquireFormatName(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat,
	StringRef *					outFormatName) WEAK_LINK;

/*!
	\brief Gets the primary MacOS file type of a particular format.
	
	Returns the primary MacOS file type of a particular format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param outAttribute Pointer to a FourCharType. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatPrimaryFileType(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	FourCharType *				outAttribute ) WEAK_LINK;

/*!
	\brief Gets the secondary MacOS file type of a particular format.
	
	Returns the secondary MacOS file type of a particular format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param outAttribute Pointer to a FourCharType. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatSecondaryFileType(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	FourCharType *				outAttribute ) WEAK_LINK;

/*!
	\brief Gets the tertiary MacOS file type of a particular format.
	
	Returns the tertiary MacOS file type of a particular format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param outAttribute Pointer to a FourCharType. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatTertiaryFileType(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	FourCharType *				outAttribute ) WEAK_LINK;

/*!
	\brief Gets the MacOS creator type of a particular format.
	
	Returns the MacOS creator type of a particular format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param outAttribute Pointer to a FourCharType. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatCreatorType(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	FourCharType *				outAttribute ) WEAK_LINK;

/*!
	\brief Gets the suffix of a particular format.
	
	Returns the suffix of a particular format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param outAttribute FormatExtension. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatExtension(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	FormatExtension				outAttribute ) WEAK_LINK;

/*!
	\brief Gets mime type.
	
	Returns the mime type of a particular format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to interrogate. Null is invalid.
	\param outAttribute FormatMimeType. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMimeType(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	FormatMimeType				outAttribute ) WEAK_LINK;

#if __USE_DEPRECATED_STUFFIT_SDK_APIS__

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get minimum compression method.
	
	Returns the minimum compression method of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to CompressionMethod. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMinimumCompressionMethod(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	CompressionMethod *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead.
	\brief Get maximum compression method.
	
	Returns the maximum compression method of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to CompressionMethod. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMaximumCompressionMethod(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	CompressionMethod *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get default compression method.
	
	Returns the default compression method of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to CompressionMethod. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatDefaultCompressionMethod(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	CompressionMethod *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use SetFormatIntegerProperty instead with appropriate property name.
	\brief Sets the compression method of a format.
	
	If supported by the format, this sets the compression method of a format.
	
	Each format that supports compression defines a default compression method.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param inMethod New value. See CompressionMethods.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatCompressionMethod(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	CompressionMethod		inMethod) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the current compression method of a format.
	
	If supported by the format, this returns the current compression method of a format.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outMethod Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatCurrentCompressionMethod(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	CompressionMethod *		outMethod) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets minimum compression level.
	
	Returns the minimum compression level of the given format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to CompressionLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMinimumCompressionLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	CompressionLevel *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get maximum compression level.
	
	Returns the maximum compression level of the given format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to CompressionLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMaximumCompressionLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	CompressionLevel *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get default compression level.
	
	Returns the default compression level of the given format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to CompressionLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatDefaultCompressionLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	CompressionLevel *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use SetFormatIntegerProperty instead with appropriate property name.
	\brief Sets the compression level of a format.
	
	If supported by the format, this sets the compression level of a format.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to change. Null is invalid.
	\param inValue New value. See CompressionLevels.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatCompressionLevel(
	EngineRef				inEngineRef,
	ConstFormatIDParam 	inFormat,
	CompressionLevel		inValue) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the current compression level of a format.
	
	If supported by the format, this returns the current compression level of a format.
	
	Each format that support compression defines a default level for compression.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outValue Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatCurrentCompressionLevel(
	EngineRef				inEngineRef,
	ConstFormatIDParam 	inFormat,
	CompressionLevel *		outValue) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets minimum extent level.
	
	Returns the minimum extent level of the given format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to ExtentLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMinimumExtentLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	ExtentLevel *				outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get maximum extent level.
	
	Returns the maximum extent level of the given format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to ExtentLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMaximumExtentLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	ExtentLevel *				outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get default extent level.
	
	Returns the default extent level of the given format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to ExtentLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatDefaultExtentLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	ExtentLevel *				outAttribute ) WEAK_LINK;

/*!
	\deprecated Use SetFormatIntegerProperty instead with appropriate property name.
	\brief Sets the compression method of a format.
	
	If supported by the format, this sets the compression method of a format.
	
	Each format that supports compression defines a default compression method.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param inLevel New value. See CompressionMethods.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatExtentLevel(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	ExtentLevel		 		inLevel) WEAK_LINK;
	
/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the current compression method of a format.
	
	If supported by the format, this returns the current compression method of a format.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outLevel Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatCurrentExtentLevel(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	ExtentLevel *		 	outLevel) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get minimum encryption method.
	
	Returns the minimum encryption method of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncryptionMethod. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMinimumEncryptionMethod(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	EncryptionMethod *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get maximum encryption method.
	
	Returns the maximum encryption method of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncryptionMethod. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMaximumEncryptionMethod(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	EncryptionMethod *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get default encryption method.
	
	Returns the default encryption method of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncryptionMethod. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatDefaultEncryptionMethod(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	EncryptionMethod *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use SetFormatIntegerProperty instead with appropriate property name.
	\brief Sets the encryption method of a format.
	
	If supported by the format, this sets the encryption method of a format.
	
	Each format that supports encryption defines a default encryption method. Typically,
	this corresponds to no encryption.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param inMethod New value. See EncryptionMethods.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatEncryptionMethod(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	EncryptionMethod		inMethod) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the current encryption method of a format.
	
	If supported by the format, this returns the current encryption method of a format.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outMethod Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatCurrentEncryptionMethod(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	EncryptionMethod *		outMethod) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get minimum encryption key size.
	
	Returns the minimum encryption key size of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncryptionKeySize. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMinimumEncryptionKeySize(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	EncryptionKeySize *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get maximum encryption key size.
	
	Returns the maximum encryption key size of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncryptionKeySize. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMaximumEncryptionKeySize(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	EncryptionKeySize *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get default encryption key size.
	
	Returns the default encryption key size of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncryptionKeySize. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatDefaultEncryptionKeySize(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	EncryptionKeySize *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use SetFormatIntegerProperty instead with appropriate property name.
	\brief Sets the encryption key size of a format.
	
	If supported by the format, this sets the encryption key size of a format.
	
		
	Each format that supports encryption defines a default encryption key size method.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param inValue New value. See EncryptionKeySizes.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatEncryptionKeySize(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	EncryptionKeySize 		inValue) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the current encryption key size of a format.
	
	If supported by the format, this returns the current encryption key size of a format.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outValue Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatCurrentEncryptionKeySize(
	EngineRef				inEngineRef,
	ConstFormatIDParam 	inFormat,
	EncryptionKeySize * 	outValue) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get minimum encoding level.
	
	Returns the minimum encoding level of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncodingLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMinimumEncodingLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	EncodingLevel *				outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get maximum encoding level.
	
	Returns the maximum encoding level of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncodingLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMaximumEncodingLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	EncodingLevel *				outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get default encoding level.
	
	Returns the default encoding level of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to EncodingLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatDefaultEncodingLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	EncodingLevel *				outAttribute ) WEAK_LINK;

/*!
	\deprecated Use SetFormatIntegerProperty instead with appropriate property name.
	\brief Sets the encoding level of a format.
	
	If supported by the format, this sets the encoding level of a format.
	
	Each format that supports archive level encoding provides a default value.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param inLevel New value. See EncodingLevels.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatEncodingLevel(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	EncodingLevel  			inLevel) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the current encoding level of a format.
	
	If supported by the format, this returns the current encoding level of a format.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outLevel Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatCurrentEncodingLevel(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	EncodingLevel *  		outLevel) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get encoding subset.
	
	Returns the encoding level character set size of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to uint32_t. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatEncodingSubset(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	uint32_t *					outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get encoding overhead.
	
	Returns the encoding overhead of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to uint32_t. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatEncodingOverhead(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	uint32_t *					outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get minimum rendundancy level.
	
	Returns the minimum rendundancy level of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to RedundancyLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMinimumRedundancyLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	RedundancyLevel *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get maximum rendundancy level.
	
	Returns the maximum rendundancy level of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to RedundancyLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatMaximumRedundancyLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	RedundancyLevel *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get default rendundancy level.
	
	Returns the maximum rendundancy level of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to RedundancyLevel. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatDefaultRedundancyLevel(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	RedundancyLevel *			outAttribute ) WEAK_LINK;

/*!
	\deprecated Use SetFormatIntegerProperty instead with appropriate property name.
	\brief Sets the redundancy level of a format.
	
	If supported by the format, this sets the redundancy level of a format.
	
	Each archive that supports redundancy provides a default value.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param inLevel New value. See RedundancyLevels.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatRedundancyLevel(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	RedundancyLevel  		inLevel) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the current redundancy level of a format.
	
	If supported by the format, this returns the current redundancy level of a format.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outLevel Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatCurrentRedundancyLevel(
	EngineRef				inEngineRef,
	ConstFormatIDParam 		inFormat,
	RedundancyLevel *  		outLevel) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Get rendundancy overhead.
	
	Returns the overhead of the desired format.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to uint32_t. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatRedundancyOverhead(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	uint32_t *					outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatBooleanProperty instead with appropriate property name.
	\brief Get the formats block mode status.
	
	Indicates the formats current block mode compression status.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Pointer to Boolean. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatBlockModeCompression(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat,
	Boolean *					outAttribute ) WEAK_LINK;

/*!
	\deprecated Use SetFormatBooleanProperty instead with appropriate property name.
	\brief Set the formats block mode status.
	
	If the format supports block mode compression, SetFormatBlockModeCompression will enable or
	disable it.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param inAttribute True if block mode compression should be enabled. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatBlockModeCompression(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat,
	Boolean 					inAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatBooleanProperty instead with appropriate property name.
	\brief Get encryption support.
	
	Returns the format's encryption support.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Returns true if format supports encryption. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
FormatSupportsEncryption(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	Boolean *					outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatBooleanProperty instead with appropriate property name.
	\brief Get compression support.
	
	Returns the format's compression support.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Returns true if format supports compression. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
FormatSupportsCompression(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	Boolean *					outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatBooleanProperty instead with appropriate property name.
	\brief Get archive support.
	
	Returns the format's archive support.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Returns true if format supports archiving. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
FormatSupportsArchiving(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	Boolean *					outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatBooleanProperty instead with appropriate property name.
	\brief Get archive creation.
	
	Returns the format's ability to create a file.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat Which format to query. Null is invalid.
	\param outAttribute Returns true if format supports creation. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
FormatSupportsCreation(
	EngineRef					inEngineRef,
	ConstFormatIDParam		inFormat, 
	Boolean *					outAttribute ) WEAK_LINK;

/*!
	\deprecated Use GetFormatBooleanProperty instead with appropriate property name.
	\brief Gets the resource support property.
	
	Returns true if the format supports resource forks.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outAttribute Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
FormatSupportsResourceFork(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat,
	Boolean *					outAttribute) WEAK_LINK;

/*!
	\deprecated Use GetFormatBooleanProperty instead with appropriate property name.
	\brief Gets the filter property of a format.
	
	If supported by the format, gets the current value of the filter property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outAttribute Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatUseCompressionFilter(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	Boolean *					outAttribute) WEAK_LINK;

/*!
	\deprecated Use SetFormatBooleanProperty instead with appropriate property name.
	\brief Sets the filter property of a format.
	
	If supported by the format, set the filter property.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param inAttribute Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
SetFormatUseCompressionFilter(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	Boolean 					inAttribute) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the estimated memory required for compression.
	
	Returns the formats estimated memory requirements for compression based on
	the current compression settings.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outAttribute Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatEstimatedCompressionMemory(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	uint32_t * 					outAttribute) WEAK_LINK;

/*!
	\deprecated Use GetFormatIntegerProperty instead with appropriate property name.
	\brief Gets the estimated memory required for expansion.
	
	Returns the formats estimated memory requirements for expansion based on
	the current compression settings.
	
	\param inEngineRef Reference obtained from OpenStuffItEngine. Null is invalid.
	\param inFormat The format to query. Null is invalid.
	\param outAttribute Current value. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetFormatEstimatedExpansionMemory(
	EngineRef					inEngineRef,
	ConstFormatIDParam			inFormat, 
	uint32_t * 					outAttribute) WEAK_LINK;

#endif //__USE_DEPRECATED_STUFFIT_SDK_APIS__

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Format Iteration		                                                            */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Create format iterator.
	
	Creates a new iterator for accessing formats known to the StuffIt Engine. The client
	is responsible for disposing of the iterator with DisposeFormatIterator.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param outIteratorRef Newly created format iterator. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
NewFormatIterator(
	EngineRef					inEngineRef, 
	FormatIteratorRef *			outIteratorRef ) WEAK_LINK;

/*!
	\brief Dispose of a format iterator.
	
	Disposes of a format iterator created with NewFormatIterator.
	
	\param inRef The format iterator from NewFormatIterator. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
DisposeFormatIterator(
	FormatIteratorRef			inRef ) WEAK_LINK;

/*!
	\brief Reset a format iterator.
	
	Resets a format iterator to the beginning of the list of formats.
	
	\param inRef The format iterator from NewFormatIterator. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError 
ResetFormatIterator(
	FormatIteratorRef			inRef ) WEAK_LINK;

/*!
	\brief Gets next format.
	
	Get the next format in the list of formats referenced in the format iterator.
	
	\param inRef The format iterator from NewFormatIterator. Null is invalid.
	\param outFormat Returns the next format in the list. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetNextFormat(
	FormatIteratorRef			inRef,
	FormatID					outFormat ) WEAK_LINK;

/*!
	\brief Gets current format.
	
	Get the current format in the list of formats referenced in the format iterator.
	
	\param inRef The format iterator from NewFormatIterator. Null is invalid.
	\param outFormat Returns the current format in the list. Null is invalid.
	\return Returns an EngineError
*/
extern _PASCAL_ EngineError
GetCurrentFormat(
	FormatIteratorRef			inRef,
	FormatID					outFormat ) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif