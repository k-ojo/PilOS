#include "kernel.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

void test_scroll() {
	for (size_t y = 0; y < VGA_HEIGHT + 5; y++)
		for (size_t x = 0; x < VGA_WIDTH; x++)
			terminal_putchar('A' + (y % 26));
}