BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  memset:function             ; Export 'memset'

memset:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX
        XOR R8, R8

loop:
        cmp R8, RDX
        jz end

        mov [RDI + r8], sil
        inc R8
        jmp loop                    ; Loop jump to loop

end:
        mov RAX, RDI
        LEAVE                       ; Epilogue
        RET                         ; Return
