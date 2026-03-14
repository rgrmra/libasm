bits 64

global ft_memcpy

section .text

; void *ft_memcpy(void *dest, const void *src, size_t n);
ft_memcpy:
	mov		rax, rdi
	mov		rcx, rdx
	rep		movsb
	ret
