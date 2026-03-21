bits 64

global ft_bzero

section .text

; void *ft_bzero(void *s, size_t n);
ft_bzero:
	xor		al, al
	mov		rcx, rsi
	cld
	rep		stosb
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
