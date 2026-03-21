bits 64

global ft_strchr

section .text

; char *ft_strchr(const char *s, int c);
ft_strchr:
	cld

	mov		r8, rdi
	mov		rcx, -1
	xor		al, al
	repne	scasb
	not		rcx

	mov		rdi, r8
	mov		al, sil
	repne	scasb
	jnz		.false

	dec		rdi
	mov		rax, rdi
	ret

.false:
	xor		rax, rax
	ret
