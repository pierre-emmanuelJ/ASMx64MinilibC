BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  strcspn

strcspn:
        ;PUSHFQ
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX
        XOR R9, R9
        XOR R8, R8                ; Initialize return value to 0

loop:
        cmp byte [RDI], 0x0
        jz end

        MOV cl, byte [RDI]
loop2:
        cmp byte [RSI + R8], 0x0
        jz endloop2

        MOV dl, byte [RSI + R8]

        cmp cl, dl
        jz end

        INC R8
        jmp loop2

endloop2:

        XOR R8, R8
        INC R9
        INC RDI
        jmp loop                    ; Loop jump to loop

end:
        MOV RAX, R9
        LEAVE                       ; Epilogue
        ;POPFQ
        RET                         ; Return
