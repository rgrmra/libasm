bits 64

global ft_strncmp

section .text

; int ft_strncmp(const char *s1, const char *s2, size_t n);
ft_strncmp:
	xor		rax, rax

.loop:
	test	rdx, rdx
	jz		.true

	mov		al, byte [rdi]
	mov		cl, byte [rsi]

	cmp		al, cl
	jne		.false

	test	al, al
	jz		.true

	inc		rdi
	inc		rsi
	dec		rdx

	jmp		.loop

.false:
	movzx	eax, al
	movzx	ecx, cl
	sub		eax, ecx
	ret

.true:
	xor		eax, eax
	ret
