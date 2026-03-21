bits 64

default rel
extern ft_strlen

global ft_strrchr

section .text

; char *ft_strrchr(const char *s, int c);
ft_strrchr:
	push	rdi
	push	rsi
	call	ft_strlen wrt ..plt

	pop		rsi
	pop		rdi

	add		rdi, rax

.loop:
	cmp		byte [rdi], sil
	je		.found

	test	rax, rax
	jz		.not_found

	dec		rdi
	dec		rax
	jmp		.loop

.found:
	mov		rax, rdi
	ret

.not_found:
	xor		rax, rax
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
