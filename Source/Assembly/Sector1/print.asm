PrintString:
	push ax
	push bx

	mov ah, 0x0e
	.Loop:
		cmp [bx], byte 0 ; Bx for conditonal null terminator
	je .Exit
		mov al, [bx]
		int 0x10 ;interuption
		inc bx ; incrment bx
		jmp .Loop
	.Exit:
		pop ax
		pop bx
    ret 