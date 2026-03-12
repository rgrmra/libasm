bits 64

global ft_isascii

section .text

; int ft_isascii(int c);
ft_isascii:
	cmp		edi, 127
	setbe	al
	movzx	eax, al
	ret
