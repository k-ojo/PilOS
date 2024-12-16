#include "trash.h"
#include <stdio.h>
#include "../lib/lib.h"

int main(void){

    char * buff = "Hello, I am gideon from nowhere, going to somewhere I don't know\n"; 
    uint8_t *mess = (uint8_t *)buff;
    printf("%u\n", crc32_byte(mess, 8));
    return (0);
}

int A[] = {
    8,   9,   10,
    5,   7,   10,
    4,   5,   7,
    100, 2,   19,
    200, 8,   56,
    20,  76,  18
};