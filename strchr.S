BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  strchr:function                   ; Export 'strlen'

strchr:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX                ; Initialize return value to 0
        mov RCX, RSI                ; Put int charactere in RCX 64 bits

loop:
        mov CH, byte [RDI]          ; Move s1 byte in 8 bit subregister of RCX

        cmp  CH, byte 0x0           ; Compare byte of s1 to 0
        jz  end_string              ; Flag 'jump is 0' if prev condition is verify then goto end

        cmp CH, CL                  ; Compare s1 and s2 byte
        jz end
                                    ; Flag 'jump is not 0' if prev condition is not verify then goto end
        inc RDI                     ; Increment s1
        jmp loop                    ; Loop jump to loop

end_string:
        cmp CL, 0x0
        jz end
        LEAVE                       ; Epilogue
        RET                         ; Return


end:
        mov RAX, RDI
        LEAVE                       ; Epilogue
        RET                         ; Return
