bits 64

global ft_strlen

section .text

section .text

; size_t ft_strlen(const char *str);
ft_strlen:
	mov		rax, rdi

.loop:
	cmp		byte [rax], 0
	je		.end

	inc		rax

	jmp		.loop

.end:
	sub		rax, rdi
	ret
