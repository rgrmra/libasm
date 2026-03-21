bits 64

global ft_strnstr

section .text

; char *ft_strnstr(const char big, const char *little, size_t len);
ft_strnstr:
	mov		r8, rdi
	mov		r9, rsi
	mov		r10, rdx

	xor		al, al
	mov		rdi, rsi
	mov		rcx, -1
	cld
	repne	scasb
	neg		rcx
	sub		rcx, 2

	cmp		rcx, 0
	jbe		.found

	mov		r11, rcx

.loop:
	cmp		byte [r8], 0
	je		.not_found

	cmp		r10, r11
	jb		.not_found

	mov		rdi, r8
	mov		rsi, r9
	mov		rcx, r11
	cld
	repe	cmpsb
	je		.found

	inc		r8
	dec		r10
	jmp		.loop

.found:
	mov		rax, r8
	ret

.not_found:
	xor		rax, rax
	ret
