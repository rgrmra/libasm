bits 64

extern ft_strlen
extern ft_memcpy

global ft_strlcpy

section .text

; size_t ft_strlcpy(char *dst, const char *src, size_t n);
ft_strlcpy:
	push	rdi
	push	rsi
	push	rdx

	mov		rdi, rsi
	call	ft_strlen

	pop		rdx
	pop		rsi
	pop		rdi

	test	rdx, rdx
	jz		.done

	mov		rcx, rdx
	dec		rcx
	cmp		rcx, rax
	jle		.copy
	mov		rcx, rax
	
.copy:
	push 	rax
	push	rcx
	push	rdi

	mov		rdx, rcx
	call	ft_memcpy
	
	pop		rdi
	pop		rcx
	pop		rax

	mov		byte [rdi + rcx], 0

.done:
	ret
