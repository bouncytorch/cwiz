#include <stdbool.h>
#include <miniaudio.h>
#include <stdint.h>

#ifndef CWIZ_H
#define CWIZ_H

typedef struct {
    float *data;
    ma_uint32 channels;
    ma_uint32 sample_rate;
    ma_uint64 frames;
} cw_Audio;

ma_result cw_init();
int       cw_open_audio(const char *path);
void      cw_clean();

#endif
