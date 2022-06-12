bits 64
global memset
section .text

memset:
    mov rcx, 0                  ; i = 0
    jmp check

loop:
    mov byte [rdi + rcx], sil  	; ptr[i] = char // sil -> char stocké dans 8bits, donc sil 8 bits low
    inc rcx				        ; i++

check:
    cmp rdx, rcx			    ; if (i < n) // rdx = size // rcx = emplacement actuel
    jg loop                     ; branchement à l’adresse si op1 > op2
    mov rax, rdi			    ; return (ptr)
    ret
