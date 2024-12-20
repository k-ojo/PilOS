default: run

.PHONY: default build run clean

multiboot_header.o: multiboot_header.asm
	mkdir -p build
	nasm -f elf64 multiboot_header.asm

boot.o: boot.asm
	mkdir -p build
	nasm -f elf64 boot.asm

kernel.bin: multiboot_header.o boot.o linker.ld
	ld -m elf_x86_64 -n -o build/kernel.bin -T linker.ld build/multiboot_header.o build/boot.o

default: os.iso

os.iso: kernel.bin grub.cfg
	mkdir -p  build/isofiles/boot/grub
	cp grub.cfg build/isofiles/boot/grub
	cp build/kernel.bin build/isofiles/boot/
	grub-mkrescue -o build/os.iso build/isofiles

run: os.iso
	qemu-system-x86_64 -cdrom os.iso

clean:
	rm -rf build