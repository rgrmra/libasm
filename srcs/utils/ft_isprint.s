bits 64

global ft_isprint

section .text

; int ft_isprint(int c);
ft_isprint:
	sub		edi, ' '
	cmp		edi, 94
	setbe	al
	movzx	eax, al
	ret
