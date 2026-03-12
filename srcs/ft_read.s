bits 64

extern __errno_location

global ft_read

section .text

; ssize_t read(int fd, void *buf, size_t count);
ft_read:
	xor		rax, rax
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
