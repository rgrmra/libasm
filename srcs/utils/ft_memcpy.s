bits 64

global ft_memcpy

section .text

; void *ft_memcpy(void *dest, const void *src, size_t n);
ft_memcpy:
	mov		rax, rdi

	test	rdi, rdi
	jnz		.copy

	test	rsi, rsi
	jnz		.copy

	ret

.copy:
	mov		rcx, rdx
	cld
	rep		movsb
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
