
PROGRAM_SPACE equ 0x8000

ReadDisk:

	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 64 ; sectors to read
	mov dl, [BOOT_DISK] ; pointer of boot disk
	mov ch, 0x00 ; Cilinder 0
	mov dh, 0x00 ; head 0 
	mov cl, 0x02 ; Sector 2
	
	int 0x13 ; disk read BIOS interupt
	jc DiskReadFailed ; carry flag
	ret

BOOT_DISK:
	db 0
	
DiskReadErrorString:
	db 'Disk read failed.',0

DiskReadFailed:
	mov bx, DiskReadErrorString
	call PrintString
	
	jmp $