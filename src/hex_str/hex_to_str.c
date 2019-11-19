#include <stdio.h>
#include <string.h>
#include "hex_to_str.h"

int hex_to_str(unsigned char* input_buffer, unsigned int input_buffer_len, char* hex_str_to_save)
{
    char str_buf[65] = {0};
    char pbuf[64];

    // 格式化字符串的长度
    int times = 5;

    for(unsigned int i = 0; i < input_buffer_len; i++) {
        sprintf(pbuf, "0x%02X ", input_buffer[i]);
        strncat(str_buf, pbuf, times);
    }
    strncpy(hex_str_to_save, str_buf, input_buffer_len * times);

    return input_buffer_len * times;
}

int str_to_hex(char* hex_str, unsigned char* bytes_to_save)
{
	char hex_str_without_prefix_space[100] = {0};
    strncpy(
        hex_str_without_prefix_space,
        del_substr(del_substr(hex_str, "0x"), " "),
        strlen(hex_str)/5 * 2 );

    printf("hex_str_array: %s\n", hex_str_without_prefix_space);

    int len_to_save = raw_str_to_hex(hex_str_without_prefix_space, bytes_to_save);

    return len_to_save;
}

static int raw_str_to_hex(char* hex_str, unsigned char* bytes_to_save)
{
    char* p = hex_str;
    char high = 0, low = 0;
    int tmplen = strlen(p), cnt = 0;
    tmplen = strlen(p);
    while(cnt < (tmplen / 2))
    {
        high = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;
		low = (*(++ p) > '9' && ((*p <= 'F') || (*p <= 'f'))) ? *(p) - 48 - 7 : *(p) - 48;
        bytes_to_save[cnt] = ((high & 0x0f) << 4 | (low & 0x0f));
        p ++;
        cnt ++;
    }
    if(tmplen % 2 != 0) bytes_to_save[cnt] = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;

    return tmplen / 2 + tmplen % 2;
}

static char* del_substr(char* origin_str, const char* str_to_delete) {
    int len = strlen(origin_str);
    int len_sub = strlen(str_to_delete);
    int i, j, k, m;

    if ( len >= len_sub ) {
        for(i=0,j=0; i<len; ) {
            if(origin_str[i]==str_to_delete[0])
            {
                for(k=i,m=0; origin_str[k]==str_to_delete[m];k++,m++);
                if(!str_to_delete[m]) i+=len_sub;
            }
            origin_str[j++]=origin_str[i++];
        }
    }
    if (i==len ) origin_str[j]='\0';

    return origin_str;
}