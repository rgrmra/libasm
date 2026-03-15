bits 64

global ft_memcmp

section .text

; int ft_memcmp(const void *s1, const void *s2, size_t n)
ft_memcmp:
	xor		rax, rax
	mov		rcx, rdx

	repe	cmpsb
	je		.true

	movzx	eax, byte [rdi - 1]
	movzx	ecx, byte [rsi - 1]
	sub		eax, ecx

.true:
	ret
