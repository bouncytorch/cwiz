#include <cwiz.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>

ma_decoder decoder;
cw_Audio audio;

ma_result cw_init() {
    return MA_SUCCESS;
}

int cw_open_audio(const char *path) {
    ma_decoder_config cfg = ma_decoder_config_init(ma_format_f32, 0, 0);
    ma_result res = ma_decoder_init_file(path, &cfg, &decoder);
    if (res) { return res; }
    audio.sample_rate = decoder.outputSampleRate;
    audio.channels = decoder.outputChannels;

    res = ma_decoder_get_length_in_pcm_frames(&decoder, &audio.frames);
    if (res) { return res; }

    audio.data = (float*) malloc(audio.frames * audio.channels * sizeof(float));
    uint64_t frames_read;
    res = ma_decoder_read_pcm_frames(&decoder, audio.data, audio.frames, (ma_uint64*) &frames_read);
    if (res) { return res; }

    printf("Frames to process: %lld\n", audio.frames);

    // uint64_t width  = audio.frames,
    //          height = 1080;
    // uint8_t *pixels = (uint8_t*) malloc(width * height * sizeof(uint8_t));

    // for (uint64_t i = 0; i < width*height; i++)
    //     pixels[i] = 0xFF;

    // for (uint64_t f = 0; f < frames_read; f++) {
    //     for (uint32_t c = 0; c < audio.channels; c++) {
    //         uint64_t index = f * audio.channels + c;
    //         // here we are taking the og sample and normalizing it
    //         float sample = (audio.data[index] + 1) / 2;
    //         int pix = height * sample;
    //         pixels[index + width * pix] = 0x00;
    //     }
    // }

    // free(pixels);
    return 0;
}


void cw_clean() {
    free(audio.data);
    ma_decoder_uninit(&decoder);
}
