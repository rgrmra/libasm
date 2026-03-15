bits 64

global ft_memchr

section .text

; void *ft_memchr(const void *s, int c, size_t n);
ft_memchr:
	mov		al, sil
	mov		rcx, rdx

	repne	scasb
	jnz		.false

	dec		rdi
	mov		rax, rdi
	ret

.false:
	xor		rax, rax
	ret
