bits 64
global strrchr
section .text

strrchr:
	mov rcx, 0		            ; rcx = 0
	jmp strlen					; rcx = strlen(rdi)

decrement:
	dec rcx			            ; rcx-- 

loop:
	mov al, byte [rdi + rcx] 	; al = rdi[rcx] // al -> 8bits -> char
	cmp al, 0		            ; if al == \0
	je null		                ; return NULL
	cmp al, sil			        ; if al != sil, alors ++
	jne decrement
	mov rax, rdi		        ; rax = "coucou"
	add rax, rcx		        ; rax = "coucou" + 2 = "ucou"
	ret		                    ; return rax

null:
	mov rax, 0		            ; set return to NULL
    ret

incrementStrlen:                ; boucle de strlen
    inc rcx                     ; ajout 1 à rcx

strlen:
    cmp byte [rdi + rcx], 0     ; if (str[i] != '\0)
    jne incrementStrlen         ; lancement du rcx++
    dec rcx						; on baisse rcx de 1 sinon ça fonctionne pas
    jmp loop                    ; lancement du strrchr