bits 64

global ft_atoi_base

section .text

ft_atoi_base:

	ret

; int ft_isspace(int c);
ft_isspace:

	cmp		rdi, 9
	jl		.not_space
	cmp		rdi, 13
	jle		.is_space
	cmp		rdi, 32
	je		.is_space

.not_space:
	mov		rax, 0
	ret

.is_space:
	mov		rax, 1
	ret
