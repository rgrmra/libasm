bits 64

global ft_isdigit

section .text

; int ft_isdigit(int c);
ft_isdigit:
	cmp		edi, '0'
	jl		.false

	cmp		edi, '9'
	jg		.false

	mov		rax, 1
	ret

.false:
	xor		rax, rax
	ret
