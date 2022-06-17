
PROGRAM_SPACE equ 0x8000

ReadDisk:

	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 32 			;Number of sectors read
	mov dl, [BOOT_DISK] ;daonde esta lendo
	mov ch, 0x00		; cylinder 0
	mov dh, 0x00		; head 0 
	mov cl, 0x02		; sector 2
	
	int 0x13 ; disc read BIOS interupt
	jc DiskReadFailed ; carry flag
	ret

BOOT_DISK:
	db 0
	
DiskReadErrorString:
	db 'Disk Read Failed',0

DiskReadFailed:
	mov bx, DiskReadErrorString
	call PrintString
	
	jmp $
