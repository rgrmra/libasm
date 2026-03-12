bits 64

global ft_isdigit

section .text

; int ft_isdigit(int c);
ft_isdigit:
	sub		edi, '0'
	cmp		edi, 9
	setbe	al
	movzx	eax, al
	ret
