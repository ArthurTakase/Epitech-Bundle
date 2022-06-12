bits 64
global strlen
section .text

strlen:
    mov rax, 0              ; Initialisation de rax (valeur de retour) à 0
    jmp check               ; début de la fonction

increment:                  ; rejoue le programme à partir d'ici (c'est notre boucle)
    inc rax                 ; ajout 1 à rax

check:
    cmp byte [rdi + rax], 0 ; if (str[i] != '\0) // byte [rdi + rax] -> premier char de "coucou" + 2 -> "ucou" -> 'u' 
    jne increment           ; lancement du rax++, on relance la boucle si on est pas au bout
    ret                     ; return rax