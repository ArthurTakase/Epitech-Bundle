bits 64
global strcmp
section .text

return:
    sub bl, cl              ; bl -= cl
    movsx rax, bl           ; movsx pour stocker 8bits (bl) dans 64bits (rax)
    ret


strcmp:
    mov bl, byte [rdi]      ; bl = str[i]
    mov cl, byte [rsi]      ; cl = str2[j]

    cmp bl, 0               ; if str[i] == '\0'
    je return               ; return
    cmp cl, 0               ; if str2[j] == '\0'
    je return               ; return
    cmp bl, cl              ; if str[i] != str2[j]
    jne return              ; return

    inc rdi                 ; i++
    inc rsi                 ; j++

    jmp strcmp