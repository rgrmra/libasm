bits 64

default rel
extern malloc

global ft_calloc

section .text

; void *ft_calloc(size_t nmemb, size_t size);
ft_calloc:
	mov		rax, rdi

	imul	rax, rsi
	jo		.overflow

	mov		rdi, rax
	push	rax
	call	malloc wrt ..plt
	pop		rcx

	test	rax, rax
	jz		.done

	mov		r8, rax
	mov		rdi, rax
	xor		eax, eax
	cld
	rep		stosb

	mov		rax, r8
	ret

.overflow:
	xor		rax, rax

.done:
	ret

section .note.GNO-stack noalloc noexec nowrite progbits
