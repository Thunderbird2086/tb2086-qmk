#include "quantum.h"

static const char *read_layer_5x1(int layer) {
    static const char PROGMEM font_layer[4][6] = {
        {0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0},
        {0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0},
        {0xda, 0xdb, 0xdc, 0xdd, 0xde, 0},
        {0x95, 0x96, 0x97, 0x98, 0x99, 0},
    };

    return font_layer[layer];
}

static const char *read_layer_5x3(int layer) {
    static const char PROGMEM font_layer[4][16] = {
        {0x20, 0x85, 0x86, 0x87, 0x20,
         0x20, 0xa5, 0xa6, 0xa7, 0x20,
         0x20, 0xc5, 0xc6, 0xc7, 0x20,
         0},
        {0x20, 0x88, 0x89, 0x8a, 0x20,
         0x20, 0xa8, 0xa9, 0xaa, 0x20,
         0x20, 0xc8, 0xc9, 0xca, 0x20,
         0},
        {0x20, 0x8b, 0x8c, 0x8d, 0x20,
         0x20, 0xab, 0xac, 0xad, 0x20,
         0x20, 0xcb, 0xcc, 0xcd, 0x20,
         0},
        {0x20, 0x8e, 0x8f, 0x90, 0x20,
         0x20, 0xae, 0xaf, 0xb0, 0x20,
         0x20, 0xce, 0xcf, 0xd0, 0x20,
         0},
    };

    return font_layer[layer];
}

const char *read_layer(int layer, bool is_one_line) {
    return (is_one_line ? read_layer_5x1(layer)
                        : read_layer_5x3(layer));
}

