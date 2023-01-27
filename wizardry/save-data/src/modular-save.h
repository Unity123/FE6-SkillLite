#pragma once

#include "common-chax.h"
#include "debug.h"

#include "ms-memmap.h"

#define EMS_CHUNK_INVALID_OFFSET ((u16)-1)

struct EmsChunk {
    /* 00 */ u16 off;
    /* 02 */ u16 size;

    /* 04 */ void (*save)(u8* dst, const u32 size);
    /* 08 */ void (*load)(u8* src, const u32 size);
};

extern const struct EmsChunk EmsChunkSa[], EmsChunkSu[];

extern const int gMsaTotalSize;
extern const int gMsaUsedSize;
extern const int gMsaRsvSize;

extern const int gMsuTotalSize;
extern const int gMsuUsedSize;
extern const int gMsuRsvSize;

noreturn void ModSaveErrLog(char *str);
