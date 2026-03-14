bits 64

extern ft_isalpha
extern ft_isdigit

global ft_isalnum

section .text

; int ft_isalnum(int c);
ft_isalnum:
	push	rbx
	mov		ebx, edi

	call	ft_isalpha
	test	eax, eax
	jnz		.done

	mov		edi, ebx
	call	ft_isdigit

.done:
	pop		rbx
	ret
