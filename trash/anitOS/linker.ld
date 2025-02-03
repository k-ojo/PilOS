ENTRY(start)

SECTIONS {
    /* Set the entry point of the kernel at the start of the file */
    . = 1M;

    /* Ensure the multiboot header is at the very beginning */
    .boot :
    {
        KEEP(*(.multiboot_header))  /* Keep the Multiboot header section */
    }

    /* Place the .text section (code) after the multiboot header */
    .text :
    {
        *(.text)
    }

    /* Place any read-only data here */
    .rodata :
    {
        *(.rodata)
    }

    /* Place initialized data here */
    .data :
    {
        *(.data)
    }

    /* BSS section for uninitialized data */
    .bss :
    {
        *(COMMON)
        *(.bss)
    }
}
