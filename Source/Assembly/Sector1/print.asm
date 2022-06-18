PrintString:
	push ax
	push bx

	mov ah, 0x0e
	.Loop:
		cmp [bx], byte 0 ; check for null terminator
	je .Exit
		mov al, [bx]
		int 0x10 ; BIOS print interupt
		inc bx ; increment bx register
		jmp .Loop
	.Exit:
		pop ax
		pop bx
    	ret 


