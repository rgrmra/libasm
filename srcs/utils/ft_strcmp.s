bits 64

global ft_strcmp

section .text

; int ft_strcmp(const char *s1, const char *s2);
ft_strcmp:

.loop:
	movzx	eax, byte [rdi]
	movzx	edx, byte [rsi]

	cmp		eax, edx
	jne		.end

	test	eax, eax
	je		.end

	inc		rdi
	inc		rsi
	jmp		.loop

.end:
	sub		eax, edx
	ret
