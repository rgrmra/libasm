bits 64

global ft_tolower

section .text

; int ft_tolower(int c);
ft_tolower:
	mov		al, dil
	cmp		al, 'A'
	jb		.end
	cmp		al, 'Z'
	ja		.end
	or		al, 32

.end:
	movzx	eax, al
	ret
