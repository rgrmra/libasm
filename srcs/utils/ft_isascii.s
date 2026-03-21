bits 64

global ft_isascii

section .text

; int ft_isascii(int c);
ft_isascii:
	cmp		edi, 127
	ja		.false

	mov		rax, 1
	ret

.false:
	xor		rax, rax
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
