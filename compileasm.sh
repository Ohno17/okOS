clear
getopts ":d" OPTS

case $OPTS in
  d ) OPTS=1 ;;
  ? ) echo "No options supplied. Use -d for debug mode."
    OPTS=0 ;;
esac

nasm ./Source/Assembly/boot.asm -f bin -o bootloader.bin

nasm ./Source/Assembly/extended.asm -f elf64 -o ExtendedProgram.o

gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "./Source/Kernel.c" -o "Kernel.o"

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
echo "All files compiled..."
ld -T"link.ld"
echo "Linking complete..."

cat bootloader.bin kernel.bin > bootloader.flp

rm bootloader.bin
rm ExtendedProgram.o
rm kernel.bin
rm Kernel.o

echo "Removed all object and bin files... cleaned."
echo "Running..."
qemu-system-x86_64 -drive format=raw,file=bootloader.flp,index=0,if=floppy -serial stdio
echo "Stopped."