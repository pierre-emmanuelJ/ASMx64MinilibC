BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  strncmp                   ; Export 'strlen'

strncmp:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX                ;
        XOR RCX, RCX
        XOR R8, R8                  ;

loop:
        cmp R8, RDX
        jz end
        
        mov AL, byte[RDI]           ; Move s1 byte in 8 bit subregister of RAX
        mov CL, byte[RSI]           ; Move s2 byte in 8 bit subregister of RCX

        cmp AL, 0x0                 ; Compare byte of s1 to 0
        jz  end                     ; Flag 'jump is 0' if prev condition is verify then goto end
        cmp CL, 0x0                 ; Compare byte of s2 to 0
        jz  end                     ; Flag 'jump is 0' if prev condition is verify then goto end

        cmp AL, CL                  ; Compare s1 and s2 byte
        jnz end                     ; Flag 'jump is not 0' if prev condition is not verify then goto end

        inc RDI                     ; Increment s1
        inc RSI
        inc R8                    ; Increment s2
        jmp loop                    ; Loop jump to loop

end:
        sub RAX, RCX                ; Substract for result
        LEAVE                       ; Epilogue
        RET                         ; Return
