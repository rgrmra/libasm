bits 64

global ft_isspace

section .text

; int ft_isspace(int c);
ft_isspace:
	cmp		edi, ' '
	je		.true

	cmp		edi, 9
	jl		.false

	cmp		edi, 13
	jle		.true

.false:
	xor		eax, eax
	ret

.true:
	mov		eax, 1
	ret
