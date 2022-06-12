bits 64
global strchr
section .text

strchr:
	mov rcx, 0		            ; rcx = 0
	jmp loop

increment:
	inc rcx			            ; rcx++

loop:
	mov al, byte [rdi + rcx] 	; al = rdi[rcx] // al -> 8bits -> char
	cmp al, 0		            ; if al == '\0'
	je null		                ; return NULL
	cmp al, sil		        	; if ebx != esi, alors ++ // sil est le premier arg de type 8bits
	jne increment
	mov rax, rdi		        ; rax = "coucou"
	add rax, rcx		        ; rax = "coucou" + 2 = "ucou"
	ret		                    ; return rax

null:
	mov rax, 0		            ; set return to NULL
    ret