bits 64

default	rel
extern __errno_location

global ft_write

section .text

; ssize_t	ft_write(int fd, const void *buf, size_t count);
ft_write:
	mov		rax, 1
	syscall

	test	rax, rax
	jns		.done

	neg		rax
	mov		rdi, rax
	call	__errno_location wrt ..plt
	mov		dword [rax], edi
	mov		rax, -1

.done:
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
