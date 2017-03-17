BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  strstr
EXTERN  strlen

strstr:
        ;PUSHFQ
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX
        XOR R8, R8                ; Initialize return value to 0

loop:
        cmp byte [RDI], 0x0
        jz end

loop2:
        cmp byte [RSI + R8], 0x0
        jz find
        cmp byte [RDI + R8], 0x0
        jz end

        MOV cl, byte [RDI + R8]
        MOV dl, byte [RSI + R8]

        cmp cl, dl
        jnz endloop2

        INC R8
        jmp loop2

endloop2:

        XOR R8, R8
        INC RDI
        jmp loop                    ; Loop jump to loop

find:
        MOV RAX, RDI
end:
        LEAVE                       ; Epilogue
        ;POPFQ
        RET                         ; Return