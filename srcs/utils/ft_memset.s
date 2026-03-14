bits 64

global ft_memset

section .text

; void *ft_memset(void *s, int c, size_t n);
ft_memset:
	mov		r8, rdi
	mov		rcx, rdx
	mov		al, sil
	rep		stosb
	mov		rax, r8
	ret
