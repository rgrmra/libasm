bits 64

extern __errno_location

global ft_write

section .text

; ssize_t	ft_write(int fd, const void *buf, size_t count);
ft_write:
	mov		rax, 1
	syscall

	test	rax, rax
	js		.set_errno

	ret

.set_errno:
	neg		rax
	mov		rdi, rax
	call	__errno_location
	mov		[rax], edi
	mov		rax, -1
	ret
