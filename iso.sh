#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/pilos.kernel isodir/boot/pilos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
set timeout=3
set default=0
menuentry "pilos" {
	multiboot /boot/pilos.kernel
}
EOF
grub-mkrescue -o pilos.iso isodir
