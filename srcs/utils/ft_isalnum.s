bits 64

global ft_isalnum

section .text

; int ft_isalnum(int c);
ft_isalnum:
	cmp		edi, '0'
	jl		.false
	cmp		edi, '9'
	jle		.true

	or		edi, 32
	cmp		edi, 'a'
	jl		.false
	cmp		edi, 'z'
	jg		.false

.true:
	mov		rax, 1
	ret

.false:
	xor		rax, rax
	ret
