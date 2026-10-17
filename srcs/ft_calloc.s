bits 64

default rel
extern malloc
extern __errno_location

global ft_calloc

section .text

; void *ft_calloc(size_t nmemb, size_t size);
ft_calloc:
	test	rdi, rdi
	jz		.no_overflow

	mov		rax, -1
	xor		edx, edx
	div		rdi

	cmp		rsi, rax
	ja		.overflow

.no_overflow:
	mov		rax, rdi
	imul	rax, rsi

	mov		rdi, rax
	push	rax
	call	malloc wrt ..plt
	pop		rcx

	test	rax, rax
	jz		.end

	mov		r8, rax
	mov		rdi, rax
	xor		eax, eax
	cld
	rep		stosb

	mov		rax, r8
	ret

.overflow:
	call	__errno_location wrt ..plt
	mov		dword [rax], 12
	xor		rax, rax

.end:
	ret

section .note.GNO-stack noalloc noexec nowrite progbits
