bits 64

extern	ft_memcpy

global ft_memmove

section .text

; void *ft_memmove(void *dest, const void *src, size_t n);
ft_memmove:
	mov		rax, rdi

	test	rdx, rdx
	jz		.done

	mov		rcx, rdx

	cmp		rdi, rsi
	jb		.backward

	lea		rdi, [rdi + rdx - 1]
	lea		rsi, [rsi + rdx - 1]

	std
	rep		movsb
	cld

	jmp		.done

.backward:
	rep		movsb

.done:
	ret
