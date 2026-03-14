bits 64

global ft_memchr

section .text

; void *ft_memchr(const void *s, int c, size_t n);
ft_memchr:
	mov		rax, rsi
	mov		rcx, rdx
	repne	scasb

	jnz		.not_found
	lea		rax, [rdi - 1]
	ret

.not_found:
	xor		rax, rax
	ret
