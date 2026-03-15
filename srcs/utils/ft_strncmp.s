bits 64

global ft_strncmp

section .text

; int ft_strncmp(const char *s1, const char *s2, size_t n);
ft_strncmp:
	xor		rax, rax
	mov		rcx, rdx

	repe	cmpsb
	je		.true

	movzx	eax, byte [rdi - 1]
	movzx	ecx, byte [rsi - 1]
	sub		eax, ecx

.true:
	ret
