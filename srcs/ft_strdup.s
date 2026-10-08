bits 64

default rel
extern malloc

global ft_strdup

section .text

; char *ft_strdup(const char *s);
ft_strdup:
	push	rbx
	sub		rsp, 8

	mov		rbx, rdi

	xor		al, al
	mov		rcx, -1
	cld
	repne 	scasb
	not		rcx

	push	rcx

	mov		rdi, rcx
	call	malloc wrt ..plt

	pop		rcx

	test	rax, rax
	jz		.end

	mov		rdi, rax
	mov		rsi, rbx
	cld
	rep		movsb

.end:
	add		rsp, 8
	pop		rbx
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
