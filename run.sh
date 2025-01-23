#!/bin/bash

# for os type
osName=$(uname -s)

set -xue

# QEMU file path
QEMU=qemu-system-riscv32

# new: path to clang and compiler flags
if [ "$osName" == "Darwin" ] # macOS
then
    CC=/usr/local/opt/llvm/bin/clang
elif [ "$osName" == "Linux" ] # Linux
then
    CC=clang
else
    echo "unkown OS"
fi

CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib"

# new: build the kernel
$CC $CFLAGS -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf \
    kernel.c common.c

# Start QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot \
    -d unimp,guest_errors,int,cpu_reset -D qemu.log \
    -kernel kernel.elf # new: load the kernel