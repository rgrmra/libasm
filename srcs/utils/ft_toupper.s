bits 64

global ft_toupper

section .text

; int ft_toupper(int c);
ft_toupper:
	mov		al, dil
	cmp		al, 'a'
	jb		.end
	cmp		al, 'z'
	ja		.end
	xor		al, 32

.end:
	movzx	eax, al
	ret
