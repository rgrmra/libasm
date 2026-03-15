bits 64

extern ft_strcpy
extern ft_strlen
extern malloc

global ft_strdup

section .text

; char *ft_strdup(const char *s);
ft_strdup:
	push	rdi
	call	ft_strlen

	mov		rdi, rax
	inc		rdi
	call	malloc wrt ..plt
	test	rax, rax
	je		.end

	mov		rdi, rax
	pop		rsi
	call	ft_strcpy

.end:
	ret
