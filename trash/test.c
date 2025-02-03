#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[10];  // Small buffer
    strcpy(buffer, input);  // No bounds checking (buffer overflow risk)
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char long_input[100];
    memset(long_input, 'A', 99);
    long_input[99] = '\0';

    vulnerable_function(long_input);
    return 0;
}
