#include <stdio.h>

#include <kernel/tty.h>

void test_scroll(){
    int i = 0;
    while (i < 80 + 20)
    {
	   printf("This is line %i\n", i++);
	}
    printf("hello World");

}

void kernel_main(void) {
	terminal_initialize();
	printf("Hello, kernel World!\n");
	test_scroll();
}
