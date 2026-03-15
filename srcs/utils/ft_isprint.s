bits 64

global ft_isprint

section .text

; int ft_isprint(int c);
ft_isprint:
	cmp		edi, ' '
	jl		.false

	cmp		edi, '~'
	jg		.false

	mov		rax, rax
	ret

.false:
	xor		rax, rax
	ret
