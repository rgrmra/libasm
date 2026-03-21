bits 64

extern ft_strlen
extern ft_memcpy

global ft_strlcpy

section .text

; size_t ft_strlcpy(char *dst, const char *src, size_t n);
ft_strlcpy:
	mov		r8, rdi
	mov		r9, rsi

	mov		rdi, rsi
	mov		rcx, -1
	xor		al, al
	cld
	repne	scasb
	not		rcx
	dec		rcx

	mov		rax, rcx

	test	rdx, rdx
	jz		.done

	mov		r10, rdx
	dec		r10
	cmp		rcx, r10
	jb		.copy

	mov		rcx, r10

.copy:
	mov		rdi, r8
	mov		rsi, r9
	rep		movsb

	mov		byte [rdi], 0

.done:
	ret
