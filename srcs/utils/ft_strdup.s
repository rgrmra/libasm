bits 64

default rel
extern malloc

global ft_strdup

section .text

; char *ft_strdup(const char *s);
ft_strdup:
	push	rbx
	mov		rbx, rdi

	xor		al, al
	mov		rcx, -1
	repne 	scasb
	not		rcx

	push	rcx
	mov		rdi, rcx
	call	malloc wrt ..plt
	pop		rcx

	test	rax, rax
	jz		.done

	mov		rdi, rax
	mov		rsi, rbx
	rep		movsb

.done:
	pop		rbx
	ret
