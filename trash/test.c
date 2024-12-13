#include "trash.h"
#include <stdio.h>
#include "../lib/lib.h"

int main(void){

    char * buff = "Hello, I am gideon from nowhere, going to somewhere I don't know\n"; 
    uint8_t *mess = (uint8_t *)buff;
    printf("%u\n", crc32_byte(mess, 8));
    return (0);
}