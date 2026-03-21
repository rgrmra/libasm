bits 64

extern	ft_memcpy

global ft_memmove

section .text

; void *ft_memmove(void *dest, const void *src, size_t n);
ft_memmove:
	mov		rax, rdi

	test	rdi, rdi
	jnz		.check

	test	rsi, rsi
	jnz		.check

	ret

.check:
	cmp		rdi, rsi
	je		.done

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
	cld
	rep		movsb

.done:
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
