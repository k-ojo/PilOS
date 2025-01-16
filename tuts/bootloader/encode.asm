; nasmw encode.asm -f bin -o encode.bin
mov ax, bx          ; 2-byte instruction
mov cx, [temp]      ; Instruction accessing `temp`
temp db 0x99        ; Label `temp`
   times 510-($-$$) db 0
   db 0x55
   db 0xAA