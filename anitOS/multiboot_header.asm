section .multiboot
align 4
dd 0x1BADB002              ; Multiboot magic number
dd 0                       ; Flags (set to 0 for basic Multiboot)
dd -(0x1BADB002 + 0)       ; Checksum (magic + flags + checksum = 0)