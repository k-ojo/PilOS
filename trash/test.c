#include "trash.h"
#include <stdio.h>

void counter() {
    static int count = 0; // Initialized only once
    count++;
    printf("Count: %d\n", count);
}

int main() {
    counter(); // Count: 1
    counter(); // Count: 2
    counter(); // Count: 3
    return 0;
}
