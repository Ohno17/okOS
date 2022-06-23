getopts ":d" OPTS

case $OPTS in
  d ) OPTS=1 ;;
  ? ) echo "No options supplied. Use -d for debug mode."
    OPTS=0 ;;
esac

nasm ./Source/Assembly/Sector1/bootloader.asm -f bin -o bootloader.bin

nasm ./Source/Assembly/Sector2/ExtendedProgram.asm -f elf64 -o ExtendedProgram.o

gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "./Source/Kernel.cpp" -o "Kernel.o"

if [ $OPTS = 0 ]; then
  FILE=bootloader.bin
  if [ ! -f "$FILE" ]; then
    echo "Assembly build error. Bootloader.bin does not exist."
    rm kernel.bin
    rm ExtendedProgram.o
    rm Kernel.o
    exit 1
  fi

  FILET=kernel.bin
  if [ ! -f "$FILET" ]; then
    echo "C build error. Kernel.bin does not exist"
    rm bootloader.bin
    rm ExtendedProgram.o
    exit 1
  fi
fi

ld -T"link.ld"

cat bootloader.bin kernel.bin > bootloader.flp

rm bootloader.bin
rm ExtendedProgram.o
rm kernel.bin
rm Kernel.o

qemu-system-x86_64 -fda bootloader.flp