nasm ./Source/Assembly/Sector1/bootloader.asm -f bin -o bootloader.bin

nasm ./Source/Assembly/Sector2/ExtendedProgram.asm -f elf64 -o ExtendedProgram.o

gcc -Ttext 0x8000 -ffreestanding -Wall -mno-red-zone -m64 -c "./Source/Kernel.cpp" -o "Kernel.o"

ld -T"link.ld"

cat bootloader.bin kernel.bin > bootloader.flp

qemu-system-x86_64 -drive file=bootloader.flp,format=raw