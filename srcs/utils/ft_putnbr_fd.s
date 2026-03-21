bits 64

global ft_putnbr_fd

section .text

ft_putnbr_fd:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16

	movsx	r8, edi
	mov		r9, rsi
	
	cmp		r8, 0
	jge		.check

	mov		byte [rsp], '-'

	mov		rax, 1
	mov		rdi, r9
	mov		rsi, rsp
	mov		rdx, 1
	syscall

	neg		r8

.check:
	cmp		r8, 10
	jl		.print_digit

	mov		rax, r8
	cqo
	mov		rcx, 10
	idiv	rcx

	push	rdx
	mov		edi, eax
	mov		rsi, r9
	call	ft_putnbr_fd
	pop		rdx

	mov		r8, rdx

.print_digit:
	add		r8b, '0'
	mov		[rsp], r8b

	mov		rax, 1
	mov		rdi, r9
	mov		rsi, rsp
	mov		rdx, 1
	syscall

	mov		rsp, rbp
	pop		rbp
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
