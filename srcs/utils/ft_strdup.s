bits 64

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
	call	malloc

	test	rax, rax
	jz		.malloc_error

	pop		rcx
	mov		rsi, rbx
	mov		rdi, rax
	rep		movsb

	pop		rbx
	ret

.malloc_error:
	pop		rcx
	pop		rbx
	ret
