BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  my_strlen                   ; Export 'strlen'

my_strlen:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RCX, RCX
loop:
        cmp byte[RDI], 0
        jz  end
        inc RDI
        inc RCX
        jmp loop

end:
        mov RAX, RCX
        LEAVE                       ; Epilogue
        RET                         ; Return
