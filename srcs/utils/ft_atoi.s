bits 64

global ft_atoi

section .text

; int ft_atoi(const char *nptr);
ft_atoi:
	xor		rax, rax
	mov		edx, 1

.check_space:
	mov		cl, byte [rdi]

	cmp		cl, ' '
	je		.skip_space

	sub		cl, 9
	cmp		cl, 4
	ja		.check_sign

.skip_space:
	inc		rdi
	jmp		.check_space

.check_sign:
	mov		cl, byte [rdi]

	cmp		cl, '+'
	je		.skip_sign

	cmp		cl, '-'
	jne		.check_number

	mov		edx, -1

.skip_sign:
	inc		rdi

.check_number:
	movzx		rcx, byte [rdi]

	sub		rcx, '0'
	cmp		rcx, 9
	ja		.done

	imul	rax, rax, 10
	add		rax, rcx

	inc		rdi
	jmp		.check_number

.done:
	cmp		edx, 1
	je		.ret
	neg		rax

.ret:
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
