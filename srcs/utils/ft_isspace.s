bits 64

global ft_isspace

section .text

; int ft_isspace(int c);
ft_isspace:
	cmp		edi, 9
	jl		.not_space
	cmp		edi, 13
	jle		.is_space
	cmp		edi, 32
	je		.is_space

.not_space:
	xor		eax, eax
	ret

.is_space:
	mov		eax, 1
	ret

