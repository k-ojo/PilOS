# PilOS

PilOS is a custom bare-bones operating system designed to explore low-level system programming, kernel development, and operating system concepts. The goal of this project is to build a minimal yet functional OS from scratch while allowing contributions from developers interested in OS development.

## 📌 Features (Planned & Implemented)
- [x] Multiboot-compliant bootloader
- [x] Basic kernel with text-mode output
- [ ] Memory management (paging, heap, etc.)
- [ ] Task scheduling & multitasking
- [ ] Filesystem support
- [ ] Networking stack

---

## 🔧 Setting Up the Cross Compiler
To build PilOS, you need a cross-compiler that targets `i686-elf`. This ensures compatibility with the OS without relying on your host system’s toolchain.

### 📜 Prerequisites
Ensure you have the following installed:
- `gcc` (native compiler)
- `binutils`
- `make`
- `nasm` (for assembly)
- `qemu` (for testing)
- `Xorriso`
- `GNU make` (4.0 or later)
- `git`

### 🔹 Step 1: Installing Dependencies
#### Ubuntu/Debian:
```sh
sudo apt update && sudo apt install -y build-essential nasm qemu-system-x86 git
```
#### Arch Linux:
```sh
sudo pacman -S base-devel nasm qemu git
```

### 🔹 Step 2: Building the Cross-Compiler
#### Download Binutils & GCC:
```sh
mkdir -p ~/cross-compiler && cd ~/cross-compiler
wget http://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.xz
wget http://ftp.gnu.org/gnu/gcc/gcc-13.2.0/gcc-13.2.0.tar.xz
```

#### Extract the source code:
```sh
tar -xvf binutils-2.40.tar.xz && tar -xvf gcc-13.2.0.tar.xz
```

#### Build and install Binutils:
```sh
mkdir binutils-build && cd binutils-build
../binutils-2.40/configure --target=i686-elf --prefix=/usr/local/cross --with-sysroot --disable-nls --disable-werror
make -j$(nproc)
sudo make install
```

#### Build and install GCC:
```sh
cd ../gcc-13.2.0
./contrib/download_prerequisites
mkdir ../gcc-build && cd ../gcc-build
../gcc-13.2.0/configure --target=i686-elf --prefix=/usr/local/cross --disable-nls --enable-languages=c --without-headers
make -j$(nproc) all-gcc
sudo make install-gcc
```

#### Verify the installation:
```sh
/usr/local/cross/bin/i686-elf-gcc --version
```
If you see the GCC version with `i686-elf`, then the cross-compiler is set up correctly!

---

## 🛠 Building PilOS
Once you have the cross-compiler set up, clone the repository and compile the kernel:
```sh
git clone https://github.com/yourusername/PilOS.git
cd PilOS
./build.sh
```

## 🚀 Running PilOS
Test PilOS using QEMU:
```sh
./quemu.sh
```

---

## 📜 Contributing
We welcome contributions! If you're interested in contributing:
1. Fork the repository.
2. Clone your fork:
   ```sh
   git clone https://github.com/yourusername/PilOS.git
   ```
3. Create a feature branch:
   ```sh
   git checkout -b feature-name
   ```
4. Make your changes, commit, and pull request