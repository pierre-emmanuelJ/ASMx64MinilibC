BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  rindex                   ; Export 'strlen'

rindex:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX                ; Initialize return value to 0
        mov RCX, RSI                ; Put int charactere in RCX 64 bits

loop:
        mov CH, byte [RDI]          ; Move s1 byte in 8 bit subregister of RCX

        cmp  CH, byte 0x0            ; Compare byte of s1 to 0
        jz  checkend                     ; Flag 'jump is 0' if prev condition is verify then goto end

        cmp CH, CL                  ; Compare s1 and s2 byte
        jz save_addr
                                    ; Flag 'jump is not 0' if prev condition is not verify then goto end
back_inloop:

        inc RDI                     ; Increment s1
        jmp loop                    ; Loop jump to loop

checkend:
        cmp CL, 0x0
        jz save_end_addr
        jmp end

save_end_addr:
        mov RAX, RDI
        jmp end

save_addr:
        mov RAX, RDI
        jmp back_inloop


end:
        LEAVE                       ; Epilogue
        RET                         ; Return
