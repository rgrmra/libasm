bits 64

global ft_isspace

section .text

; int ft_isspace(int c);
ft_isspace:
	cmp		edi, ' '
	je		.true

	cmp		edi, 9
	jb		.false

	cmp		edi, 13
	ja		.false

.true:
	mov		eax, 1
	ret

.false:
	xor		eax, eax
	ret
