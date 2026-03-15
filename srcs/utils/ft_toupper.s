bits 64

global ft_toupper

section .text

; int ft_toupper(int c);
ft_toupper:
	mov		eax, edi
	cmp		al, 'a'
	jb		.end
	cmp		al, 'z'
	ja		.end
	xor		al, 32

.end:
	ret
