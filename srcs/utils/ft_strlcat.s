bits 64

extern ft_strlcpy
extern ft_strlen

global ft_strlcat

section .text

; size_t ft_strlcat(char *dst, const char *src, size_t n);
ft_strlcat:
	mov		r8, rdi
	mov		r9, rsi
	mov		r10, rdx

	test	rdi, rdi
	jz		.copy

	test	rdx, rdx
	jz		.copy

	mov		rdi, r8
	call	ft_strlen
	mov		r11, rax

.copy:
	mov		rdi, r9
	call	ft_strlen
	cmp		r11, rax
	jg		.done

	mov		rdi, r8
	mov		rsi, r9
	mov		rdx, r10

	add		rdi, rax
	sub		rdx, rax
	
	jmp		ft_strlcpy

.done:
	add		r11, r10
	mov		rax, r11
	ret
