bits 64

global ft_strlen

section .text

section .text

; size_t ft_strlen(const char *str);
ft_strlen:
	xor		al, al
	mov		rcx, -1

	repne	scasb
	not		rcx
	dec		rcx

	mov		rax, rcx
	ret
