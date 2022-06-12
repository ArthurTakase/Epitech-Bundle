bits 64
global strstr
section .text

end:
    mov rax, rdi
    add rax, r8
    ret

null:
    mov rax, 0
    ret

strstr:
    mov r8, 0                       ; int r8 = 0
    mov r9, 0                       ; int r9 = 0

firstLoop:
    cmp byte [rdi + r8], 0          ; if (rdi[r8] == '\0')
    je null                         ; return NULL

startSecondLoop:
    mov r9, 0                       ; r9 = 0

secondLoop:
    mov r10, r9
    add r10, r8
    mov al, byte [rdi + r10]
    cmp al, byte [rsi + r9]         ; if (rdi[r9 + r8] != rsi[r9])
    jne restartLoop                 ; r8++ && restart
    cmp byte [rsi + r9 + 1], 0      ; if (rsi[r9 + 1] == '\0')
    je end                          ; return rdi + r8
    inc r9                          ; r9++
    jmp secondLoop                  ; continue

restartLoop:
    inc r8
    jmp firstLoop