bits 64

global ft_list_size

section .text

; typedef struct	s_list
; {
; 	void			*data;
; 	struct s_list	*next;
; }					t_list;

; int ft_list_size(t_list *begin_list);
ft_list_size:
	xor		eax, eax

.loop:
	test	rdi, rdi
	jz		.end

	inc		eax

	mov		rdi, [rdi + 8]

	jmp		.loop

.end:
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
