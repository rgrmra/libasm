bits 64

global ft_memcmp

section .text

; int ft_memcmp(const void *s1, const void *s2, size_t n)
ft_memcmp:
	xor		rax, rax
	mov		rcx, rdx

	repe	cmpsb
	je		.equal

	movzx	eax, byte [rdi - 1]
	movzx	rcx, byte [rsi - 1]
	sub		eax, ecx

.equal:
	ret
