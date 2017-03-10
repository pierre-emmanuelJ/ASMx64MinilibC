BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  my_rindex                   ; Export 'strlen'

my_rindex:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RAX, RAX
        mov RCX, RSI                ;                ;

loop:
        mov CH, byte [RDI]                 ; Move s1 byte in 8 bit subregister of RAX

        cmp CH, byte 0x0                 ; Compare byte of s1 to 0
        jz  end                     ; Flag 'jump is 0' if prev condition is verify then goto end

        cmp CH, CL                  ; Compare s1 and s2 byte
        jz saveaddr                     ; Flag 'jump is not 0' if prev condition is not verify then goto end

        inc RDI                     ; Increment s1
        jmp loop                    ; Loop jump to loop

saveaddr:
        mov RAX, RDI

end:
        LEAVE                       ; Epilogue
        RET                         ; Return
