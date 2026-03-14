bits 64

extern ft_memchr
extern ft_strlen

global ft_strchr

section .text

; char *ft_strchr(const char *s, int c);
ft_strchr:
;	push	rdi
;	push	rsi

	call	ft_strlen

;	pop		rsi
;	pop		rdi

	mov		rdx, rax
	inc		rdx

	jmp		ft_memchr
