bits 64

global ft_isalpha

section .text

; int ft_isalpha(int c);
ft_isalpha:
	or		edi, 32
	cmp		edi, 'a'
	jl		.false

	cmp		edi, 'z'
	jg		.false

	mov		rax, 1
	ret

.false:
	xor		rax, rax
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
