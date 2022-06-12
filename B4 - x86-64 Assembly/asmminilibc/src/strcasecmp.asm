bits 64
global strcasecmp
section .text


checkMaj:
    mov r8b, bl             ; Modifications des chars en Maj
    add r8b, 32
    mov r9b, cl
    add r9b, 32

    cmp r8b, cl             ; Comparaison des Maj avec les originaux
    je increment
    cmp r9b, bl
    je increment

    mov r8b, bl             ; Modifications des chars en Min
    sub r8b, 32
    mov r9b, cl
    sub r9b, 32

    cmp r8b, cl             ; Comparaison des Min avec les originaux
    je increment
    cmp r9b, bl
    je increment

    jmp return              ; Les lettres sont différentes, fin

return:
    sub bl, cl              ; bl -= cl
    movsx rax, bl           ; movsx pour stocker 8bits (bl) dans 64bits (rax)
    ret


strcasecmp:
    mov bl, byte [rdi]      ; bl = str[i]
    mov cl, byte [rsi]      ; cl = str2[j]

    cmp bl, 0               ; if str[i] == '\0'
    je return               ; return
    cmp cl, 0               ; if str2[j] == '\0'
    je return               ; return
    cmp bl, cl              ; if str[i] != str2[j]
    jne checkMaj
    jmp increment           ; Nouveau tour de boucle

increment:
    inc rdi                 ; i++
    inc rsi                 ; j++

    jmp strcasecmp