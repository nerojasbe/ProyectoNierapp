#ifndef PRIVATEENTRYPOINTS_H
#define PRIVATEENTRYPOINTS_H

#include "StuffIt/StuffItSDKErrors.h"
#include "StuffIt/StuffItSDKArchives.h"

#ifdef __cplusplus
extern "C" {
#endif

EngineError 
PrintArchiveRef(ArchiveRef inArchive, StringRef *outXML);

EngineError
OpenArchiveInMode(EngineRef inEngineRef, ArchiveRef inArchiveRef, ArchiveMode inPermission, StringRef inPassword);

#ifdef __cplusplus
}
#endif

#endif