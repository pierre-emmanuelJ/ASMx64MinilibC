BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  strstr                   ; Export 'strlen'

strstr:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX
        XOR R8, R8                ; Initialize return value to 0

        inc R8
        mov [RDI], sil
loop:
        cmp R8, RDX          ; Move s1 byte in 8 bit subregister of RCX
        jz end

        mov [RDI + r8], sil
        inc R8
        jmp loop                    ; Loop jump to loop

end:
        mov RAX, RDI
        LEAVE                       ; Epilogue
        RET                         ; Return
