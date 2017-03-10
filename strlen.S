BITS 64                             ; 64-bit mode

SECTION .text                       ; Code section

GLOBAL  my_strlen                   ; Export 'strlen'

my_strlen:
        PUSH RBP                    ; Prologue:
        MOV RBP, RSP                ; Stack frame setup

        XOR RCX, RCX                ; Initialize counter to 0
loop:
        cmp byte[RDI], 0            ; Compare byte of str to 0
        jz  end                     ; Flag if prev condition is verify then goto end
        inc RDI                     ; Increment str
        inc RCX                     ; Increment Counter
        jmp loop                    ; Loop jump to loop

end:
        MOV RAX, RCX                ; Put counter to return value
        LEAVE                       ; Epilogue
        RET                         ; Return
