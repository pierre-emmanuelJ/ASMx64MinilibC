BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  my_memcpy                   ; Export 'strlen'

my_memcpy:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        MOV RAX, RDI
        XOR R8, R8
loop:
        cmp R8, RDX
        jz end

        mov cl, byte [RSI + R8]
        mov byte [RDI + R8], cl
        INC R8
        jmp loop

end:
        LEAVE                       ; Epilogue
        RET                         ; Return
