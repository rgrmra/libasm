bits 64

global ft_strcpy

section .text

; char	*ft_strcpy(char *dst, const char *src);
ft_strcpy:
	mov		rax, rdi

.loop:
	mov		bl, [rsi]
	mov		[rdi], bl

	inc		rsi
	inc		rdi

	test	bl, bl
	jne		.loop

	ret
