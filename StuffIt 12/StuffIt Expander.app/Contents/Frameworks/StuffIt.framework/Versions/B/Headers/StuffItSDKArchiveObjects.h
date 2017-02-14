/*--------------------------------------------------------------------------------------------------
//
//     File Name:   StuffItSDKArchiveObjects.h
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
//--------------------------------------------------------------------------------------------------
//  $Id: StuffItSDKArchiveObjects.h,v 1.20.2.1 2006/10/05 00:17:55 mjones Exp $
//------------------------------------------------------------------------------------------------*/

/*!
	\file StuffItSDKArchiveObjects.h
	
	\brief Interfaces for working with archive objects.

	The functions and types in this file define the interfaces to working with objects with an archive.
	
	It's best to think of an archive as a file system. An archive may contain a hierarchy of files and
	folders which can be iterated over.
	
	For example, to iterate the contents of the top or root of an archive would be similar to the following:
	
	#AcquireArchive
	
	#OpenArchive or #OpenEncryptedArchive
	
	#AcquireRootArchiveObject
	
	#NewArchiveIterator
	
	#AcquireCurrentArchiveObject
	
	#AcquireNextArchiveObject
		
	#DisposeArchiveIterator
	
	#ReleaseArchive
*/

#ifndef STUFFITSDKARCHIVEOBJECTS_H
#define STUFFITSDKARCHIVEOBJECTS_H

#ifndef STUFFITSDKCONFIG_H
#include <StuffIt/StuffItSDKConfig.h>
#endif

#ifndef STUFFITSDKTYPES_H
#include <StuffIt/StuffItSDKTypes.h>
#endif

#ifndef STUFFITSDKARCHIVES_H
#include <StuffIt/StuffItSDKArchives.h>
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
	\brief Reference to an item within an archive. 
	
	Reference to an item within an archive. Released with ReleaseArchiveObject.
*/
typedef struct OpaqueArcObjectRef *         ArchiveObjectRef;

/*!
	\brief Reference to a list of archive objects.
	
	Reference to a list of archive objects. Disposed with DisposeArchiveObjectList.
*/
typedef struct OpaqueObjectList *			ArchiveObjectListRef;

/*!
	\brief Reference to an archive iterator.
	
	Reference to an archive iterator. Disposed with DisposeArchiveIterator.
*/
typedef struct ArcIteratorRef *             ArchiveIteratorRef;

#if TARGET_OS_MAC
/*!
	\brief union of FileInfo and FolderInfo.
   
   	Union of FileInfo and FolderInfo structs for use with GetArchiveObjectFinderInfo().

    Mac only.
*/
union ArchiveObjectFinderInfo
{
    FileInfo        fileInfo;	/**< The file info. */
    FolderInfo      folderInfo;	/**< The folder info. */
};

/*!
	\brief union of FileInfo and FolderInfo.
   
   	Union of FileInfo and FolderInfo structs for use with GetArchiveObjectFinderInfo().

    Mac only.
*/
typedef union ArchiveObjectFinderInfo ArchiveObjectFinderInfo;

/*!
	\brief union of ExtendedFileInfo and ExtendedFolderInfo.
    
    Union of ExtendedFileInfo and ExtendedFolderInfo structs for use with GetArchiveObjectFinderInfo().
    
    Mac only.
*/
union ArchiveObjectExtendedFinderInfo
{
    ExtendedFileInfo    fileInfo; /**< The extended file info. */
    ExtendedFolderInfo  folderInfo; /**< The extended folder info. */
};

/*!
	\brief union of ExtendedFileInfo and ExtendedFolderInfo.
    
    Union of ExtendedFileInfo and ExtendedFolderInfo structs for use with GetArchiveObjectFinderInfo().
    
    Mac only.
*/
typedef union ArchiveObjectExtendedFinderInfo ArchiveObjectExtendedFinderInfo;
#endif

/*!
	\brief Get archive's root object.
	
	Acquire the archive object that represents that root of the archive.
	
	\param inArchiveRef The archive whose root object is desired. Null is invalid.
	\param outRootObject Pointer to an ArchiveObjectRef to receive the object. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
AcquireRootArchiveObject(
	ArchiveRef		 			inArchiveRef, 
	ArchiveObjectRef 			*outRootObject) WEAK_LINK;

/*!
	\brief Query the root object.
	
	Determine if the specified object is the root of an archive.
	
	\param inObject The object to check. Null is invalid.
	\return True if inObject is the root object.
	
*/
extern _PASCAL_ Boolean
IsArchiveObjectRootObject(
	ArchiveObjectRef			inObject) WEAK_LINK;

/*!
	\brief Copy an archive object.
	
	Copies an archive object. Both the source object and the copy must
	be released with ReleaseArchiveObject.
	
	\param inRef The archive object to copy. Null is invalid.
	\param outCopy Pointer to an ArchiveObjectRef to receive the copy. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireArchiveObject(
	const ArchiveObjectRef			inRef,
	ArchiveObjectRef *				outCopy ) WEAK_LINK;

/*!
	\brief Get an archive object from its path.
	
	Gets an archive object from a path relative to the archive. The object must
	be released with ReleaseArchiveObject. The path separator is /.
	
	\param inArchiveRef The archive to get the object from. Null is invalid.
	\param inPath The path relative to the archive of the object, eg. Folder/Folder/File.txt.
	The leading forward slash is optional. Null is invalid.
	\param outObject Pointer to an ArchiveObjectRef to receive the copy. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireArchiveObjectFromPath(
	const ArchiveRef 				inArchiveRef, 
	const StringRef 				inPath, 
	ArchiveObjectRef *				outObject) WEAK_LINK;

/*!
	\brief Get archive objects whose names match the specified name mask and are located in the specified folder.
	
	Gets a list of archive objects whose names match the specifed name mask from the specifed archive
	folder recursively or not.
	The objects from the list must be released with ReleaseArchiveObject. The folder path separator is /.
	
	\param inArchiveRef The archive to get the object from. Null is invalid.
	\param inFolder The start folder path relative to the archive root object, eg. Folder1/Folder2.
	The leading forward slash is optional. If the parameter is null the archive's root forlder is assumed.
	\param inMask The name mask against wich archive items names will be matched, eg. a*.txt.
	If the parameter is null "*" - everything is assumed.
	\param outList Pointer to an ArchiveObjectListRef to receive the archive object list. Null is invalid.
	\param inRecurse Recurse into archive subfolders flag.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireArchiveObjectsFromNameMask(
	const ArchiveRef 				inArchiveRef, 
	const StringRef 				inFolder, 
	const StringRef 				inMask, 
	ArchiveObjectListRef *			outList,
	Boolean							inRecurse) WEAK_LINK;

/*!
	\brief Release an ArchiveObjectRef
	
	Releases an ArchiveObjectRef acquired through iteration or other
	means. Any API that is prefixed with "Acquire" is returning an reference that
	will need to be released.
	
	Not releasing an ArchiveObject may leak memory.
	
	\param inRef ArchiveObject to release.
	\return EngineError
*/
extern _PASCAL_ EngineError
ReleaseArchiveObject(
    ArchiveObjectRef            inRef ) WEAK_LINK;

/*!
	\brief Compares two ArchiveObjectRefs.
	
	Determines if two ArchiveObjectRefs reference the same item
	in an archive.
	
	\param inObject1 ArchiveObject to compare.
	\param inObject2 ArchiveObject to compare.
	\return EngineError
*/
extern _PASCAL_ Boolean
ArchiveObjectsEqual(
	ArchiveObjectRef			inObject1,
	ArchiveObjectRef			inObject2) WEAK_LINK;

/*!
	\brief Gets the EngineRef used by the archive object.
	
	Every archive object is created tied to a specific EngineRef.
	
	\param inObject ArchiveObject to query.
	\param outEngineRef Engine attached to this object.
	\return EngineError
*/
extern _PASCAL_ EngineError 
GetEngineFromArchiveObject(
	ArchiveObjectRef			inObject, 
	EngineRef *					outEngineRef) WEAK_LINK;

/*!
	\brief Create a new archive iterator.
	
	Creates a new archive iterator for the given parent. To iterate
	the top level of an archive, acquire the root archive object with AcquireRootArchiveObject.
	The iterator must be disposed with DisposeArchiveIterator.
	
	\param inParent The parent ArchiveObjectRef to iterate. Must refer to a folder. Null is invalid.
 	\param outIteratorRef Pointer to ArchiveIteratorRef to receive new iterator. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
NewArchiveIterator(
    ArchiveObjectRef            inParent,
    ArchiveIteratorRef *        outIteratorRef ) WEAK_LINK;


/*!
	\brief Dispose of an archive iterator.
	
	Disposes of an archive iterator created with NewArchiveIterator.
	
	\param inRef The iterator to dispose of. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
DisposeArchiveIterator(
    ArchiveIteratorRef          inRef ) WEAK_LINK;


/*!
	\brief Reset an archive iterator.
	
	Resets an archive iterator back to the beginning of the archive object it
	is iterating.
	
	\param inRef The iterator to reset. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
ResetArchiveIterator(
    ArchiveIteratorRef          inRef) WEAK_LINK;


/*!
	\brief Get the next archive object.
	
	Acquires the next archive object in the container. Returns kStuffItErrorNoObjectAtThatLocation
	if the end of the container is reached.
	
	\param inRef The iterator. Null is invalid.
	\param outObjectRef Pointer to an ArchiveObjectRef to receive next object. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireNextArchiveObject(
    ArchiveIteratorRef          inRef,
    ArchiveObjectRef *          outObjectRef ) WEAK_LINK;


/*!
	\brief Get the current archive object.
	
	Acquires the current archive object in the container. Returns kStuffItErrorNoObjectAtThatLocation
	if the end of the container is reached. After creating an archive iterator, calling 
	AcquireCurrentArchiveObject will return the first object.
	
	\param inRef The iterator. Null is invalid.
	\param outObjectRef Pointer to an ArchiveObjectRef to receive current object. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireCurrentArchiveObject(
    ArchiveIteratorRef          inRef,
    ArchiveObjectRef *          outObjectRef ) WEAK_LINK;


/*!
	\brief Get the parent archive object.
	
	Given an object, AcquireParentArchiveObject accquires its parent object. Returns kStuffItErrorNoObjectAtThatLocation
	if inObjectRef is the root archive object.
	
	\param inObjectRef The object whose lineage is in question. Null is invalid.
	\param outParentObjectRef Pointer to an ArchiveObjectRef to receive parent object. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireParentArchiveObject(
    ArchiveObjectRef            inObjectRef,
    ArchiveObjectRef *          outParentObjectRef ) WEAK_LINK;

/*
	Archive object property accessors.
*/

/*!
	\brief Archive Object Property identifier
*/
typedef const char *					  ConstArchiveObjectPropertyIDParam;

/** \defgroup StringArchiveObjectProperties String based archive object properties */

/*!
	\brief Get an archive object's name.

	The kArchiveObjectPropertyIDName property returns the name of the archive object.
	 
	 This property is read/write.
	 
	\ingroup StringArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDName		"name"


/*!
	\brief Get an archive object's comments.

	The kArchiveObjectPropertyIDComments property returns any comments belonging to the archive object.
	 
	 This property is read/write.
	 
	\ingroup StringArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDComments	"comments"

/*!
	\brief Archive object's relative path.

	The kArchiveObjectPropertyIDPath property returns the path of the archive object
	relative to its parent archive.
	 
	 This property is read-only.
	 
	\ingroup StringArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDPath 		"path"

/*!
	\brief Archive object's source path.

	The kArchiveObjectPropertyIDSourcePath property returns the file system path of the 
	archive object when it was added to the archive. It can be used to determine the
	destination for expanding the item.
	 
	 This property is read/write.
	 
	\ingroup StringArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDSourcePath "sourcePath"

/** \defgroup IntegerArchiveObjectProperties Integer based archive object properties. */

/*!
	\brief Archive object's creation date.

	The kArchiveObjectPropertyIDCreationDate property returns the creation date of the 
	archive object.
	 
	 This property is read/write.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDCreationDate		"creationDate"

/*!
	\brief Archive object's modification date.

	The kArchiveObjectPropertyIDModificationDate property returns the modification date of the 
	archive object.
	 
	 This property is read/write.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDModificationDate	"modificationDate"

/*!
	\brief Archive object's compressed size.

	The kArchiveObjectPropertyIDCompressedSize property returns the compressed size of the 
	archive object.
	 
	 This property is read-only.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDCompressedSize		"compressedSize"

/*!
	\brief Archive object's expanded size.

	The kArchiveObjectPropertyIDExpandedSize property returns the expanded size of the 
	archive object.
	 
	 This property is read-only.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDExpandedSize		"expandedSize"

/*!
	\brief Archive object's data fork compressed size.

	The kArchiveObjectPropertyIDDataForkCompressedSize property returns the compressed size of the 
	archive object's data fork.
	 
	 This property is read-only.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDDataForkCompressedSize	"dataForkCompressedSize"

/*!
	\brief Archive object's data fork expanded size.

	The kArchiveObjectPropertyIDDataForkExpandedSize property returns the expanded size of the 
	archive object's data fork.
	 
	 This property is read-only.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDDataForkExpandedSize	"dataForkExpandedSize"

/*!
	\brief Archive object's resource fork compressed size.

	The kArchiveObjectPropertyIDResourceForkCompressedSize property returns the compressed size of the 
	archive object's resource fork.
	 
	 This property is read-only.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDResourceForkCompressedSize	"resourceForkCompressedSize"

/*!
	\brief Archive object's resource fork expanded size.

	The kArchiveObjectPropertyIDResourceForkExpandedSize property returns the expanded size of the 
	archive object's resource fork.
	 
	 This property is read-only.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDResourceForkExpandedSize	"resourceForkExpandedSize"

/*!
	\brief Archive object's valence.

	The kArchiveObjectPropertyIDFolderValence property returns the number of archive objects within an
	archive object.
	 
	 This property is read-only.
	 
	\ingroup IntegerArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDFolderValence 		"valence"

/** \defgroup BooleanArchiveObjectProperties Boolean based archive object properties. */

/*!
	\brief Archive object's compressed flag.

	The kArchiveObjectPropertyIDCompressed property returns true if the archive object is compressed.
	 
	 This property is read-only.
	 
	\ingroup BooleanArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDCompressed			"compressed"

/*!
	\brief Archive object's encrypted flag.

	The kArchiveObjectPropertyIDEncrypted property returns true if the archive object is encrypted.
	 
	 This property is read-only.
	 
	\ingroup BooleanArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDEncrypted			"encrypted"

/*!
	\brief Archive object's folder flag.

	The kArchiveObjectPropertyIDFolder property returns true if the archive object is a folder.
	 
	 This property is read-only.
	 
	\ingroup BooleanArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDFolder				"folder"

/*!
	\brief Archive object's locked flag.

	The kArchiveObjectPropertyIDLocked property returns true if the archive object is locked.
	 
	 This property is read-only.
	 
	\ingroup BooleanArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDLocked				"locked"

/** \defgroup StructArchiveObjectProperties Structure based archive object properties. */

/*!
	\brief Archive object's Mac Finder info.

	The kArchiveObjectPropertyIDMacFinderInfo property contains the archive object's
	Finder information.
	
	Note: This property is only accessible via the GetArchiveObjectFinderInfo.

	This property is read/write.
	 
	\ingroup StructArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDMacFinderInfo		"macFinderInfo"

/*!
	\brief Archive object's extended Mac Finder info.

	The kArchiveObjectPropertyIDExtendedMacFinderInfo property contains the archive object's
	extended Finder information.
	
	Note: This property is only accessible via the GetArchiveObjectExtendedFinderInfo.

	This property is read/write.
	 
	\ingroup StructArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDExtendedMacFinderInfo	"extendedMacFinderInfo"

/*!
	\brief Archive object's Mac file type.

	The kArchiveObjectPropertyIDFileType property contains the archive object's file type.
	 
	 This property is read/write.
	 
	\ingroup StructArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDFileType			"fileType"

/*!
	\brief Archive object's Mac file creator.

	The kArchiveObjectPropertyIDFileCaretor property contains the archive object's file creator.
	 
	 This property is read/write.
	 
	\ingroup StructArchiveObjectProperties
*/
#define		kArchiveObjectPropertyIDFileCreator			"fileCreator"

/*!
	\brief Get a string from an archive object.
	
	Returns the value of a string property of an archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID Which property to query. Null is invalid.
	\param outValue The value of the property. Null is invalid.
	\return Returns an EngineError.
*/
extern _PASCAL_ EngineError
AcquireArchiveObjectStringProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID,
	StringRef *							outValue) WEAK_LINK;

/*!
	\brief Get a boolean from an archive object.
	
	Returns the value of a boolean property of an archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID Which property to query. Null is invalid.
	\param outValue The value of the property. Null is invalid.
	\return Returns an EngineError.
*/
extern _PASCAL_ EngineError
GetArchiveObjectBooleanProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID,
	Boolean *							outValue) WEAK_LINK;
 
/*!
	\brief Get an integer from an archive object.
	
	Returns the value of an integer property of an archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID Which property to query. Null is invalid.
	\param outValue The value of the property. Null is invalid.
	\return Returns an EngineError.
*/
extern _PASCAL_ EngineError
GetArchiveObjectIntegerProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID,
	uint64_t *							outValue) WEAK_LINK;

/*!
	\brief Get date and time from an archive object.
	
	Returns the value of a date and time property of an archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID Which property to query. Null is invalid.
	\param outValue The value of the property. Null is invalid.
	\return Returns an EngineError.
*/
extern _PASCAL_ EngineError
GetArchiveObjectDateTimeProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID,
	DateTimeRef *						outValue) WEAK_LINK;

/*!
	\brief Set a string property of an archive object.
	
	Sets the value of a string property of an archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID The property to change. Null is invalid.
	\param inValue The new value of the property. Null is invalid.
	\return Returns an EngineError.
*/
extern _PASCAL_ EngineError
SetArchiveObjectStringProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID,
	StringRef							inValue) WEAK_LINK;

/*!
	\brief Set a boolean property of an archive object.
	
	Sets the value of a boolean property of an archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID The property to change. Null is invalid.
	\param inValue The new value of the property.
	\return Returns an EngineError.
*/
extern _PASCAL_ EngineError
SetArchiveObjectBooleanProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID,
	Boolean								inValue) WEAK_LINK;

/*!
	\brief Set an integer property of an archive object.
	
	Sets the value of an integer property of an archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID The property to change. Null is invalid.
	\param inValue The new value of the property.
	\return Returns an EngineError.
*/
extern _PASCAL_ EngineError
SetArchiveObjectIntegerProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID,
	uint64_t							inValue) WEAK_LINK;

/*!
	\brief Set a date and time property of an archive object.
	
	Sets the value of a date and time property of an archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID The property to change. Null is invalid.
	\param inValue The new value of the property.
	\return Returns an EngineError.
*/
extern _PASCAL_ EngineError
SetArchiveObjectDateTimeProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID,
	DateTimeRef							inValue) WEAK_LINK;

/*!
	\brief Property exists flag.
	
	Determine if a given property exists for the archive object.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID The property to change. Null is invalid.
	\return Returns true if the property exists.
*/
extern _PASCAL_ Boolean 
ArchiveObjectHasProperty(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID) WEAK_LINK;

/*!
	\brief Property availability flag.
	
	Determine if a given property is available for the archive object. A property
	can exist but not be available. This typically indicates that to get the property
	may involve a time consuming task.
	
	\param inObjectRef Reference to the archive object. Null is invalid.
	\param inPropertyID The property to change. Null is invalid.
	\return Returns true if the property is available.
*/
extern _PASCAL_ Boolean
ArchiveObjectPropertyAvailable(
	ArchiveObjectRef					inObjectRef, 
	ConstArchiveObjectPropertyIDParam	inPropertyID)  WEAK_LINK;


#if __USE_DEPRECATED_STUFFIT_SDK_APIS__
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Archive Object Comments                                                       */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/


/*!
	\brief Get archive item comments.
	
	Get the comments of an archive item. The client is responsible for disposing of
	the comments.
	
	To get the comments of an archive itself, pass this function the root archive object obtained
	from AcquireRootArchiveObject.
	
	\param inObject The archive item whose comments are desired. Null is invalid.
	\param outString Pointer to a StringRef to receive the comments. Must be disposed of
	with DisposeStringRef. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireArchiveObjectComments(
    ArchiveObjectRef            inObject,
    StringRef *                 outString )  WEAK_LINK;


/*!
	\brief Set archive item comments.
	
	Set the comments of an archive item. The client is responsible for disposing of
	the comments.
	
	To set the comments of an archive itself, pass this function the root archive object obtained
	from AcquireRootArchiveObject.
	
	\param inObject The archive item whose comments are to be changed. Null is invalid.
	\param inString The StringRef of the comments. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
SetArchiveObjectComments(
    ArchiveObjectRef            inObject,
    StringRef                   inString )  WEAK_LINK;

/*!
	\brief Determine if archive item has comment.
	
	Returns true if the archive item has comments.
	
	\param inObject The archive item to check. Null is invalid.
	\return Boolean True if archive object has comments.
*/
extern _PASCAL_ Boolean
ArchiveObjectHasComments(
	ArchiveObjectRef			inObject )  WEAK_LINK;
	
/*!
	\brief Get archive object name.
	
	Get the name of an archive object. The resulting name must be disposed of by the client.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outName Pointer to a StringRef to receive the name. Must be disposed of with DisposeStringRef.
	Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
AcquireArchiveObjectName(
    ArchiveObjectRef            inObjectRef,
    StringRef *               	outName )  WEAK_LINK;

/*!
	\brief Get archive object creation date.
	
	Get the creation date of an archive object.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outCreationDate Pointer to a DateTimeRef to receive the date. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectCreationDate(
    ArchiveObjectRef            inObjectRef,
    DateTimeRef *               outCreationDate )  WEAK_LINK;

/*!
	\brief Get archive object modification date.
	
	Get the modification date of an archive object.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outModificationDate Pointer to a DateTimeRef to receive the date. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectModificationDate(
    ArchiveObjectRef            inObjectRef,
    DateTimeRef *               outModificationDate )  WEAK_LINK;

#endif

#if TARGET_OS_MAC
/*!
	\brief Get Finder information.
	
	Get the meta data from from the specified archive object.
	
	Mac Only API.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outFinderInfo Pointer to a FinderInfo union to receive the meta-data. Long live the meta-data!
	Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectFinderInfo(
    ArchiveObjectRef            inObjectRef,
    ArchiveObjectFinderInfo *	outFinderInfo )  WEAK_LINK;


/*!
	\brief Get extended Finder information.
	
	Get the extended meta data from from the specified archive object.
	
	Mac Only API.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outFinderInfo Pointer to a ExtendedFinderInfo union to receive the meta-data. Long live the meta-data!
	Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectExtendedFinderInfo(
    ArchiveObjectRef            inObjectRef,
    ArchiveObjectExtendedFinderInfo *        outFinderInfo )  WEAK_LINK;
#endif

#if __USE_DEPRECATED_STUFFIT_SDK_APIS__
/*!
	\brief Get compression information.
	
	Determine if the specified archive object is compressed.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outIsCompressed Pointer to a Boolean to receive the data. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectIsCompressed(
    ArchiveObjectRef            inObjectRef,
    Boolean *                   outIsCompressed )  WEAK_LINK;


/*!
	\brief Get encryption information.
	
	Determine if the specified archive object is encrypted. If the object is a
	folder, then returns true if any content is encrypted.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outIsEncrypted Pointer to a Boolean to receive the data. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectIsEncrypted(
    ArchiveObjectRef            inObjectRef,
    Boolean *                   outIsEncrypted )  WEAK_LINK;


/*!
	\brief Get folder information.
	
	Determine if the specified archive object is a folder.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outIsFolder Pointer to a Boolean to receive the data. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectIsFolder(
    ArchiveObjectRef            inObjectRef,
    Boolean *                   outIsFolder )  WEAK_LINK;


/*!
	\brief Get read-only information.
	
	Determine if the specified archive object is locked, ie. read-only.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outIsLocked Pointer to a Boolean to receive the data. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectIsLocked(
    ArchiveObjectRef            inObjectRef,
    Boolean *                   outIsLocked )  WEAK_LINK;


/*!
	\brief Get size information.
	
	Gets the total compressed and expanded sizes of the specified archive object.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outCompressedSize Pointer to a uint64_t to receive the data. Can be null.
	\param outExpandedSize Pointer to a uint64_t to receive the data. Can be null.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectSizes(
    ArchiveObjectRef            inObjectRef,
    uint64_t *                  outCompressedSize,
    uint64_t *                  outExpandedSize )  WEAK_LINK;


/*!
	\brief Get fork size information.
	
	Gets the compressed and expanded sizesof the forks for the specified archive object.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outDataForkCompressedSize Pointer to a uint64_t to receive the data. Can be null.
	\param outDataForkExpandedSize Pointer to a uint64_t to receive the data. Can be null.
	\param outRsrcForkCompressedSize Pointer to a uint64_t to receive the data. Can be null.
	\param outRsrcForkExpandedSize Pointer to a uint64_t to receive the data. Can be null.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectForkSizes(
    ArchiveObjectRef            inObjectRef,
    uint64_t *                  outDataForkCompressedSize,
    uint64_t *                  outDataForkExpandedSize,
    uint64_t *                  outRsrcForkCompressedSize,
    uint64_t *                  outRsrcForkExpandedSize )  WEAK_LINK;


/*!
	\brief Get container information.
	
	Gets the number of files in the specified archive folder.
	
	\param inObjectRef The archive item. Must be a folder. Null is invalid.
	\param outNumberOfFiles Pointer to a uint32_t to receive the data. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
GetArchiveObjectNumberOfFiles(
    ArchiveObjectRef            inObjectRef,
    uint32_t *                    outNumberOfFiles )  WEAK_LINK;

#endif

/*!
	\brief Get archive object's archive.
	
	Gets the parent archive of the specified archive item. The client is
	responsible for releasing the parent with ReleaseArchiveRef.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outArchiveRef Pointer to an ArchiveRef to receive the archive. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
AcquireArchiveObjectParentArchive(
	ArchiveObjectRef			inObjectRef,
	ArchiveRef					*outArchiveRef)  WEAK_LINK;

#if __USE_DEPRECATED_STUFFIT_SDK_APIS__
/*!
	\brief Get objects path.
	
	Gets the objects path relative to the archive. The client is
	responsible for releasing the StringRef containing the path.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outPath Pointer to a StringRef to receive the path. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
AcquireArchiveObjectPath(
	ArchiveObjectRef			inObjectRef, 
	StringRef					*outPath)  WEAK_LINK;

/*!
	\brief Set an archive object's name.
	
	Sets the name of the specified archive item.
	
	\param inObjectRef The archive item. Null is invalid.
	\param inName The new name. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
SetArchiveObjectName(
    ArchiveObjectRef            inObjectRef,
    StringRef                 	inName )  WEAK_LINK;


/*!
	\brief Set an archive object's creation date.
	
	Sets the creation date of the specified archive item.
	
	\param inObjectRef The archive item. Null is invalid.
	\param inCreationDate The creation date.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
SetArchiveObjectCreationDate(
    ArchiveObjectRef            inObjectRef,
    DateTimeRef                 inCreationDate )  WEAK_LINK;

/*!
	\brief Set an archive object's modification date.
	
	Sets the modification date of the specified archive item.
	
	\param inObjectRef The archive item. Null is invalid.
	\param inModificationDate The modification date.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
SetArchiveObjectModificationDate(
    ArchiveObjectRef            inObjectRef,
    DateTimeRef                 inModificationDate )  WEAK_LINK;

#endif

#if TARGET_OS_MAC
/*!
	\brief Set an archive object's Finder information.
	
	Sets the Finder information of the specified archive item.
	
	Mac only API.
	
	\param inObjectRef The archive item. Null is invalid.
	\param inFInfo The new meta-data. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
SetArchiveObjectFinderInfo(
    ArchiveObjectRef            inObjectRef,
    const ArchiveObjectFinderInfo *          inFInfo )  WEAK_LINK;


/*!
	\brief Set an archive object's extended Finder information.
	
	Sets the extended Finder information of the specified archive item.
	
	Mac only API.
	
	\param inObjectRef The archive item. Null is invalid.
	\param inFXInfo The new meta-data. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
SetArchiveObjectExtendedFinderInfo(
    ArchiveObjectRef            inObjectRef,
    const ArchiveObjectExtendedFinderInfo *  inFXInfo )  WEAK_LINK;
#endif


#if __USE_DEPRECATED_STUFFIT_SDK_APIS__
/*!
	\brief Get an archive object's source path.
	
	Gets the file system path of the archive object. This is
	the path of the item that was added to the archive. It can
	be used to determine the destination for expanding the item.
	
	\param inObjectRef The archive item. Null is invalid.
	\param outSourcePath String containing the path. Null is invalid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
AcquireArchiveObjectSourcePath(
	ArchiveObjectRef			inObjectRef,
	StringRef *					outSourcePath)  WEAK_LINK;

/*!
	\brief Set an archive object's source path.
	
	Gets the file system path of the archive object. This is
	the path of the item that was added to the archive. It can
	be used to determine the destination for expanding the item.
	
	\param inObjectRef The archive item. Null is invalid.
	\param inSourcePath String containing the path. Null is valid.
	\return EngineError
	
*/
extern _PASCAL_ EngineError
SetArchiveObjectSourcePath(
	ArchiveObjectRef			inObjectRef,
	StringRef					inSourcePath)  WEAK_LINK;

#endif

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Archive Object Manipulation                                                       */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Create a new folder in an archive.
	
	Given a parent folder, a new folder is created with the specified name.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inParentRef Location within the archive to create the folder. Null is invalid.
	\param inFolderName Name of the folder to create. Null is invalid.
	\param inRenameOnConflict True if the folder should be renamed if an item with the same name
	already exists.
	\param outFolderRef Pointer to ArchiveObjectRef to receive new folder. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireNewFolderInArchive(
    EngineRef                   inEngineRef,
    ArchiveObjectRef            inParentRef,
    StringRef                   inFolderName,
    Boolean                     inRenameOnConflict,
    ArchiveObjectRef *          outFolderRef )  WEAK_LINK;


/*!
	\brief Delete items from an archive
	
	Delete a list of ArchiveObjectRefs from an open archive.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inObjectList List of ArchiveObjectRefs to delete. Null is invalid.
	\param inPassword Optional password for the archive. If null, and one or more of the items in
	inObjectList requires a password, the StuffIt Engine will prompt the user for the password unless
	engine status callback is not null in which case the item will be ignored.
	\return EngineError
*/
extern _PASCAL_ EngineError
DeleteArchiveObjects(
    EngineRef                   inEngineRef,
    const ArchiveObjectListRef  inObjectList,
    const StringRef           	inPassword )  WEAK_LINK;


/*!
	\brief Copy archive items.
	
	Copies items within an archive or between multiple archives.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inObjectList The list of ArchiveObjectRefs in the source archive to copy. Null is invalid.
	\param inParentRef The destination within the same archive or another archive for the copy. Null
	is invalid.
	\param inPasswordFrom Optional password to the source items. Can be null.
	\param inPasswordTo Optional password for the destination. Can be null.
	\return EngineError	
*/
extern _PASCAL_ EngineError
CopyArchiveObjects(
    EngineRef                   inEngineRef,
    const ArchiveObjectListRef	inObjectList,
    ArchiveObjectRef            inParentRef,
    const StringRef          	inPasswordFrom,
    const StringRef           	inPasswordTo )  WEAK_LINK;


/*!
	\brief Move archive items.
	
	Move archive items from one parent to another within an archive.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param inObjectList List of ArchiveObjectRefs to move. Null is invalid.
	\param inParentRef The destination parent location. Null is invalid.
	\param inPassword Optional password. If one or more of the items requires a password and the
	given password is incorrect or null, the StuffIt Engine will prompt the user for a password
	unless status callback is not null.
	\return EngineError	
*/
extern _PASCAL_ EngineError
MoveArchiveObjects(
    EngineRef                   inEngineRef,
    const ArchiveObjectListRef  inObjectList,
    ArchiveObjectRef            inParentRef,
    const StringRef             inPassword )  WEAK_LINK;


/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Archive Object Lists                         		                                */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Create an archive object list.
	
	Creates a new archive object list. Archive object lists are used when
	manipulating many items within an archive at once.
	
	Dispose with DisposeArchiveObjectList.
	
	\param inEngineRef Reference to the engine obtained from OpenStuffItEngine. Null is invalid.
	\param outObjectList Pointer to ArchiveObjectListRef to receive new list. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
NewArchiveObjectList( EngineRef inEngineRef,
					  ArchiveObjectListRef	*outObjectList )  WEAK_LINK;


/*!
	\brief Add to an archive object list.
	
	Add an ArchiveObjectRef to an archive list. The ArchiveObjectRef added to the list is acquired by the list
	and released when DisposeArchiveObjectList is called, therefore callers can release an ArchiveObjectRef
	immediately after adding it to a list.
	
	\param inObject The archive object to add. Null is invalid.
	\param inOutObjectList The archive object list to update. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
AddToArchiveObjectList(
    ArchiveObjectRef            inObject,
    ArchiveObjectListRef        inOutObjectList )  WEAK_LINK;


/*!
	\brief Count archive objects.
	
	Returns the number of archive objects within the list.
	
	\param inObjectList The archive object list to count. Null is invalid.
	\return Number of archive objects.
*/
extern _PASCAL_ uint32_t
CountArchiveObjectList(
    const ArchiveObjectListRef  inObjectList )  WEAK_LINK;


/*!
	\brief Copy archive objects.

	Make a copy of an existing archive object list

	\param inObjectList The archive object list to copy. Null is invalid.
	\param outCopy The list to create. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
CopyArchiveObjectList(
	const ArchiveObjectListRef	inObjectList,
	ArchiveObjectListRef *		outCopy)  WEAK_LINK;

/*!
	\brief Get the nth archive object.
	
	Retrieves the archive object at the given index. The result must be
	released with ReleaseArchiveObject.
	
	\param inObjectList The list. Null is invalid.
	\param inIndex 0 based index.
	\param outObject Pointer to ArchiveObjectRef to receive object. Null is invalid.
	Must be released with ReleaseArchiveObject
	\return EngineError
*/
extern _PASCAL_ EngineError
AcquireNthArchiveObject(
	const ArchiveObjectListRef	inObjectList,
	uint32_t					inIndex,
	ArchiveObjectRef			*outObject)  WEAK_LINK;

/*!
	\brief Dispose of an archive object list.
	
	Dispose of an archive object list obtained from NewArchiveObjectList.
	
	\param inObjectList The list to dispose. Null is invalid.
	\return EngineError
*/
extern _PASCAL_ void
DisposeArchiveObjectList(
    ArchiveObjectListRef        inObjectList )  WEAK_LINK;

/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/
/*  ¥ Archive Object Forks                         		                                */
/*ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ*/

/*!
	\brief Name of a fork. 
	
	Used to reference a named fork in an archive object.
*/
typedef const char *						ArchiveObjectForkID;

/** \defgroup Forks Fork names supported by the StuffIt Engine */
/*!
	\brief The main fork. 
*/
#define kArchiveObjectForkIDMain			"main"

/*!
	\brief The Macintosh data fork. 
*/
#define kArchiveObjectForkIDMacData			"main"

/*!
	\brief The Macintosh resource fork. 
*/
#define kArchiveObjectForkIDMacResource		"resource"

/*!
	\brief The fork containing a thumbnail representation of the archive object. 
*/
#define kArchiveObjectForkIDThumbnail		"thumb"

/*!
	\brief Reference to a fork. 
	
	Reference to a named fork of an archive object. Used to expand fork data
	into memory.
*/
typedef const struct OpaqueForkRef *			ArchiveObjectForkRef;

/*!
	\brief Get an archive object fork.
	
	Get an archive object's named fork. The fork can then be used to extract its data.
	
	\param inRef	The archive object. NULL is invalid.
	\param inForkID	The named identifier of the fork.
	\param outFork	The reference to the fork. NULL is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
GetArchiveObjectFork(
	ArchiveObjectRef 			inRef, 
	ArchiveObjectForkID 		inForkID, 
	ArchiveObjectForkRef *		outFork)  WEAK_LINK;

/*!
	\brief Get an archive object fork description.
	
	Get a description of the data contained within an archive fork. The description
	is returned as a MIME identifier such as application/octet-stream or image/jpeg.
	
	\param inFork	The fork to query. NULL is invalid.
	\param outDescription	The description of the fork data. NULL is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
GetArchiveObjectForkDescription(
	ArchiveObjectForkRef		inFork, 
	ArchiveObjectForkID *		outDescription)  WEAK_LINK;

/*!
	\brief Get an archive object fork's size.
	
	Get's the expanded size of a fork.
	
	\param inFork	The fork to query. NULL is invalid.
	\param outForkSize	The size of the expanded fork data. NULL is invalid.
	\return EngineError
*/
extern _PASCAL_ EngineError
GetArchiveObjectForkSize(
	ArchiveObjectForkRef		inFork,
	uint64_t *					outForkSize)  WEAK_LINK;

/*!
	\brief Get an archive object fork's size.
	
	Get's the expanded size of a fork.

	\param inEngine	Reference to the engine. NULL is invalid.
	\param inFork	The fork to query. NULL is invalid.
	\param inBuffer	The buffer to cpy the fork data to. NULL is invalid.
	\param bufferSize	The size of the buffer. 0 is invalid.
	\param outBytesRead	The actual number of bytes copied. NULL is invalid.
	\param inPassword	Optional password to decrypt the fork data. May be NULL.
	\return EngineError
*/
extern _PASCAL_ EngineError
GetArchiveObjectForkData(
	EngineRef					inEngine,
	ArchiveObjectForkRef		inFork,
	char *						inBuffer,
	uint64_t 					bufferSize,
	uint64_t *					outBytesRead,
	StringRef 					inPassword) WEAK_LINK;


#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif