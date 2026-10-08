bits 64

global ft_atoi_base

section .text

; int ft_atoi_base(char *str, char *base);
ft_atoi_base:
	push	r12
	
	test	rdi, rdi
	je		.error
	
	test	rsi, rsi
	je		.error
	
	mov		rax, rsi
	dec		rax
	
	mov		r8, rdi
	mov		r9, rsi
	
.check_base_invalid_characters:
	inc		rax
	
	cmp		byte [rax], 0
	je		.check_base_size
	
	cmp		byte [rax], '+'
	je		.error
	
	cmp		byte [rax], '-'
	je		.error
	
	cmp		byte [rax], ' '
	je		.error
	
	cmp		byte [rax], 9
	jb		.check_base_invalid_characters
	
	cmp		byte [rax], 13
	ja		.check_base_invalid_characters
	
	jmp		.error
	
.check_base_size:
	sub		rax, r9
	cmp		rax, 2
	jl		.error
	
	mov		r10, rax
	xor		r11, r11
	
.check_base_double_characters:
	cmp		r11, r10
	jge		.check_number
	
	movzx	eax, byte [r9 + r11]
	
	lea		rdi, [r9 + r11 + 1]
	
	mov		rcx, r10
	sub		rcx, r11
	dec		rcx
	
	jz		.next_base_character
	
	cld
	repne   scasb
	je		.error
	
.next_base_character:
	inc		r11
	jmp		.check_base_double_characters
	
.check_number:
	dec		r8
	
	mov		r11, 1
	xor		r12, r12
	
.skip_space:
	inc		r8
	
	cmp		byte [r8], 0
	je		.error
	
	cmp		byte [r8], ' '
	je		.skip_space
	
	cmp		byte [r8], 9
	jb		.check_sign
	
	cmp		byte [r8], 13
	ja		.check_sign
	
	jmp		.skip_space
	
.check_sign:
	cmp		byte [r8], '+'
	je		.plus_sign
	
	cmp		byte [r8], '-'
	je		.minus_sign
	
	jmp		.convert_number
	
.plus_sign:
	mov		r11, 1
	inc		r8
	jmp		.check_sign
	
.minus_sign:
	mov		r11, -1
	inc		r8
	jmp		.check_sign
	
.convert_number:
	movzx	eax, byte [r8]
	
	mov		rdi, r9
	mov		rcx, r10
	
	cld
	repne	scasb
	jne		.end
	
	sub		rdi, r9
	dec		rdi
	
	imul	r12, r10
	add		r12, rdi
	
	inc		r8
	
	cmp		byte [r8], 0
	je		.end
	
	jmp		.convert_number
	
.error:
	xor		rax, rax
	
	pop		r12
	ret
	
.end:
	mov		rax, r12
	imul	rax, r11
	
	pop		r12
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
