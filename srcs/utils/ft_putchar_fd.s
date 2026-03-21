bits 64

default rel
extern __errno_location

global ft_putchar_fd

section .text

; void ft_putchar_fd(char c, int fd);
ft_putchar_fd:
	sub		rsp, 8
	mov		byte [rsp], dil

	mov		rax, 1
	mov		rdi, rsi
	lea		rsi, [rsp]
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

section .note-GNU-stack noalloc noexec nowrite progbits
