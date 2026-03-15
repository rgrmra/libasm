bits 64

extern	ft_memcpy

global ft_memmove

section .text

; void *ft_memmove(void *dest, const void *src, size_t n);
ft_memmove:
	mov		rax, rdi
	test	rdx, rdx
	jz		.done

	cmp		rdi, rsi
	je		.done
	jl		ft_memcpy

.backward:
	add		rdi, rdx
	dec		rdi

	add		rsi, rdx
	dec		rsi

.loop:
	mov		cl, byte [rsi]
	mov		byte [rdi], cl

	dec rsi
	dec	rdi

	dec	rdx
	jnz		.loop

.done:
	ret
