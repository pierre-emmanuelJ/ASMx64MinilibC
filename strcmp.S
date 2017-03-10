BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  my_strcmp                   ; Export 'strlen'

my_strcmp:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX
        XOR RCX, RCX

loop:
        mov AL, byte[RDI]
        mov CL, byte[RSI]

        cmp AL, 0x0            ; Compare byte of str to 0
        jz  end                     ; Flag if prev condition is verify then goto end
        cmp CL, 0x0           ; Compare byte of str to 0
        jz  end                     ; Flag if prev condition is verify then goto end

        cmp AL, CL
        jnz end

        inc RDI
        inc RSI                     ; Increment Counter
        jmp loop                    ; Loop jump to loop

end:
        sub RAX, RCX
        ; mov RAX, 0x0
        ; mov RAX, AL               ; Put counter to return value
        LEAVE                       ; Epilogue
        RET                         ; Return
