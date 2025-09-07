/**
 * GV2F
 * Copyright 2011 PAR Government Systems
 *
 * Restricted Rights:
 * Use, reproduction, or disclosure of executable code, application interface
 * (API), source code, or related information is subject to restrictions set
 * forth in the contract and/or license agreement.    The Government's rights
 * to use, modify, reproduce, release, perform, display, or disclose this
 * software are restricted as identified in the purchase contract. Any
 * reproduction of computer software or portions thereof marked with this
 * legend must also reproduce the markings. Any person who has been provided
 * access to this software must be aware of the above restrictions.
 */


#ifndef PGSC_METADATAINJECTOR_C_H
#define PGSC_METADATAINJECTOR_C_H

#include "mediamultiplexer_c.h"
#include "mediaconsumers_c.h"

#ifdef __cplusplus 
extern "C" {
#endif

typedef void* MetadataInjector_C;

typedef struct MetadataInjectorStatusUpdateConsumer_C_s {
    void *opaque;
    void (*mediaStreamExtentsUpdate)(void *opaque, long startMillis, 
                                     long endMillis);
    void (*mediaEOF)(void *opaque);
    void (*mediaFatalError)(void *opaque, const char *info);

    // MetadataInjectorStatusUpdateConsumer extension
    void (*mediaOpened)(void *opaque, long mediaTimeMiilis);
    void (*mediaTimeUpdate)(void *opaque, long mediaTimeMillis);
} MetadataInjectorStatusUpdateConsumer_C;

typedef struct KLVInjector_C_s {
    void *opaque;
    void (*mediaKLVData)(void *opaque, KLVData *data);

    // KLVInjector extension
    void (*combineKLV)(void *opaque, int _combine);
} KLVInjector_C;

MetadataInjector_C MetadataInjector_create(int sync);
int MetadataInjector_destroy(MetadataInjector_C injector);

KLVInjector_C *MetadataInjector_getKLVInjector(MetadataInjector_C inj);
int MetadataInjector_setMinimumLatency(MetadataInjector_C inj, int latencyMillis);
int MetadataInjector_setOutputSink(MetadataInjector_C inj, const MultiplexerDataSink_C* sink);
int MetadataInjector_setStatusUpdateConsumer(MetadataInjector_C inj, MetadataInjectorStatusUpdateConsumer_C *consumer);

int MetadataInjector_openFile(MetadataInjector_C inj, const char *file);
int MetadataInjector_openRtsp(MetadataInjector_C inj, const char *addr, int timeout);
int MetadataInjector_openStream(MetadataInjector_C inj, const char *mcastAddr, int port, int timeout);
int MetadataInjector_close(MetadataInjector_C inj);

#ifdef __cplusplus 
}; // extern "C"
#endif

#endif
