bits 64

default rel
extern __errno_location

global ft_putendl_fd

section .text

; void ft_putendl_fd(char *s, int fd);
ft_putendl_fd:
	sub		rsp, 8
	mov		byte[rsp], 10

	mov		r8, rdi
	mov		r9, rsi

	xor		al, al
	mov		rcx, -1
	cld
	repne	scasb
	neg		rcx
	sub		rcx, 2

	mov		rax, 1
	mov		rdi, r9
	mov		rsi, r8
	mov		rdx, rcx
	syscall

	mov		rax, 1
	mov		rdi, r9
	mov		rsi, rsp
	mov		rdx, 1
	syscall
	
	cmp		rax, 0
	jge		.done

	neg		eax
	mov		dword [rsp], eax
	call	__errno_location wrt ..plt
	mov		edi, dword [rsp]
	mov		dword [rax], edi

.done:
	add		rsp, 8
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
