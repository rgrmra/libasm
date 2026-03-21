bits 64

global ft_memchr

section .text

; void *ft_memchr(const void *s, int c, size_t n);
ft_memchr:
	test	rdx, rdx
	jz		.false

	mov		al, sil
	mov		rcx, rdx

	cld
	repne	scasb
	jnz		.false

	dec		rdi
	mov		rax, rdi
	ret

.false:
	xor		rax, rax
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
