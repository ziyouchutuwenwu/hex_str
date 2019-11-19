#ifndef HEX_TO_STR_H
#define HEX_TO_STR_H

/*
#include "hex_str/hex_to_str.h"

int main(void) {
    char rx_buffer[] = {0xC8, 0x32, 0x9B, 0xFD, 0x0E, 0x01};
    char hex_str_array[32] = {0};

    int len = hex_to_str(rx_buffer, sizeof(rx_buffer), hex_str_array);
    printf("hex_str_array: %s\n", hex_str_array);

    char new_hex_bytes[100] = {0};
    int len_to_save = str_to_hex(hex_str_array, new_hex_bytes);

    return 0;
}
*/
int hex_to_str(unsigned char* input_buffer, unsigned int input_buffer_len, char* hex_str_to_save);
int str_to_hex(char* hex_str, unsigned char* bytes_to_save);

static int raw_str_to_hex(char* hex_str, unsigned char* bytes_to_save);
static char* del_substr(char* origin_str, const char* str_to_delete);

#endif