#ifndef _LIB_
#define _LIB_

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

uint32_t crc32_byte(uint8_t *, uint32_t);

typedef struct _avl
{
    int data;
    /* data */
    avlbt *left, *right;
    
}avlbt;


#endif