bits 64

global ft_strncmp

section .text

; int ft_strncmp(const char *s1, const char *s2, size_t n);
ft_strncmp:
	xor		rax, rax
	test	rdx, rdx
	jz		.done

.loop:
	movzx	eax, byte [rdi]
	movzx	ecx, byte [rsi]

	cmp		al, cl
	jne		.finish

	test	al, al
	jz		.finish

	dec		rdx
	jz		.finish

	inc		rdi
	inc		rsi
	jmp		.loop

.finish:
	sub		eax, ecx

.done:
	ret
