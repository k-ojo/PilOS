#include "kernel.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

/**
* strlen- calculates the len of a string
* @str: input string
* Return: Length of str
*/
size_t strlen(const char* str)
{
    size_t len = 0;
    while (str[len])
        len++;
    return (len);
}

/**
 * terminal_iniatilize- initializes the VGA with space ' ' as place-holder  
 * 
 * Return: nothing
**/
void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

/**
 * scroll- scrolls the screen down
 * 
 * Return: Nothing
 */
void scroll(void)
{
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			const size_t nindex = (y + 1) * VGA_WIDTH + x;
			if (y != VGA_HEIGHT - 1)
				terminal_buffer[index] = terminal_buffer[nindex];
			else
				terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

/**
 * terminal_setcolor- changes the terminal color to input color
 * @color: the input color
 */
void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}

/**
 * termial_putentryat: outputs character c to screen
 * @c: character to be printed to terminal
 * @color: color of the character
 * @x: x coordinate on screen
 * @y: y coordinate on screen
 * 
 */
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

/**
 * terminal_putchar: puts character to screen
 * @c: input character on screen
 * Return: Nothing
 */
void terminal_putchar(char c) 
{
	if (c ==  '\n'){
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT){
			scroll();
			terminal_row--;
		}
	}

	else {
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (++terminal_column == VGA_WIDTH) {
			terminal_column = 0;
			if (++terminal_row == VGA_HEIGHT) {
				scroll();
				terminal_row--;
			}
		}
	}
}

/**
 * terminal_write- writes a string to the screen
 * @dat: input string
 * @size: input size
 * 
 * Return: nothing
 */
void terminal_write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

/**
 * terminal_writestring: writes strings to screen
 * @data: Input data
 * 
 * Return: Nothing
 */
void terminal_writestring(const char* data) 
{
	terminal_write(data, strlen(data));
}

/**
 * kernel_main- kernel entry point
 * 
 * Return: Nothing
 */
void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();
	test_scroll();

	/* Newline support is left as an exercise. */
	terminal_writestring("Hello World!\n");
}