bits 64

global ft_strlen

section .text

section .text

; size_t ft_strlen(const char *str);
ft_strlen:
	xor		al, al
	mov		rcx, -1

	cld
	repne	scasb
	not		rcx
	dec		rcx

	mov		rax, rcx
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
