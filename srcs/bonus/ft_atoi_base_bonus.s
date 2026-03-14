bits 64

global ft_atoi_base

section .text

; int ft_atoi_base(char *str, char *base);
ft_atoi_base:
	xor		rax, rax
	ret
