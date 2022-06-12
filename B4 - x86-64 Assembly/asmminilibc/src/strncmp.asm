bits 64
global strncmp
section .text

return:
    sub bl, cl              ; bl -= cl
    movsx rax, bl           ; movsx pour stocker 8bits (bl) dans 64bits (rax)
    ret


strncmp:
    cmp rdx, 0              ; if (n == 0) // la limite est atteinte
    je return               ; return

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
    dec rdx                 ; n--

    jmp strncmp