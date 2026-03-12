bits 64

extern ft_isalpha
extern ft_isdigit

global ft_isalnum

section .text

; int ft_isalnum(int c);
ft_isalnum:
	push	edi

	call	ft_isalpha
	test	eax, eax
	jne		.return

	pop		edi
	call	ft_isdigit

.return:
	ret
