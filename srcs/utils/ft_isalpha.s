bits 64

global ft_isalpha

section .text

; int ft_isalpha(int c);
ft_isalpha:
	or		edi, 32
	sub		edi, 97
	cmp		edi, 25
	setbe	al
	movzx	eax, al
	ret
