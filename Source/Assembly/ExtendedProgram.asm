
jmp EnterProtectedMode 

%include "./Source/Assembly/gdt.asm"
%include "./Source/Assembly/print.asm"

EnterProtectedMode:
	call EnableA20
	cli  ; disable interupts
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp codeseg:StartProtectedMode

EnableA20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret

[bits 32]

%include "./Source/Assembly/CPUID.asm"
%include "./Source/Assembly/SimplePaging.asm"

StartProtectedMode:
	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov [0xb8000], byte 'H'

	call DetectCPUID
	call DetectLongMode
	call SetUpIdentityPaging
	call EditGDT

	jmp codeseg:Start64Bit 

[bits 64]
[extern _start]

Start64Bit:
	mov edi, 0xb8000

	;mov rax, 0x0f200f200f200f20 ; BlackScreen
	mov rax, 0x1f201f201f201f20 ; blueScreen

	mov ecx, 500 
	rep stosq
	call _start
	jmp $

times 2048-($-$$) db 0 ; pad zeros 4 sectors