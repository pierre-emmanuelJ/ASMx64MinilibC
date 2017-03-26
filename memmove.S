BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  memmove:function

memmove:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

	XOR R8, R8
        CMP RDI, RSI 
        jz end
        jb copy
        
	mov R8, RDX
	DEC R8
endcopy:
        cmp R8, -1
	jz end
	mov cl, byte [RSI + R8]
	mov byte [RDI + R8], cl
	DEC R8
	jmp endcopy

copy:
	cmp R8, RDX
	jz end
	mov cl, byte [RSI + R8]
	mov byte [RDI + R8], cl
	INC R8
	jmp copy


end:
	mov RAX, RDI
        LEAVE                       ; Epilogue
        RET                         ; Return
