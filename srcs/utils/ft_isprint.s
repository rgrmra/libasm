bits 64

global ft_isprint

section .text

; int ft_isprint(int c);
ft_isprint:
	cmp		edi, ' '
	jb		.false

	cmp		edi, '~'
	ja		.false

	mov		rax, 1
	ret

.false:
	xor		rax, rax
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
