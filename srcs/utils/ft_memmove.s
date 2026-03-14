bits 64

global ft_memmove

section .text

; void *ft_memmove(void *dest, const void *src, size_t n);
ft_memmove:
	mov		rax, rdi
	test	rdx, rdx
	jz		.done

	cmp		rdi, rsi
	je		.done
	jl		.forward

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

	jmp		.done

.forward:
	mov		rcx, rdx
	rep		movsb

.done:
	ret
