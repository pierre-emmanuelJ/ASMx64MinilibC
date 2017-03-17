BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  memmove                   ; Export 'strlen'

memmove:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX
        XOR RDX, RDX                ; Initialize return value to 0
        mov RCX, RSI                ; Put int charactere in RCX 64 bits

        inc RDX
loop:
        cmp RDX, RBX

        mov Cl, byte [RDI]          ; Move s1 byte in 8 bit subregister of RCX

        inc RDI
        inc RCX
        inc RDX                     ; Increment s1
        jmp loop                    ; Loop jump to loop

end:
        mov RAX, RSI
        LEAVE                       ; Epilogue
        RET                         ; Return
