bits 64

global ft_list_push_front
extern malloc

section .text

; typedef struct	s_list
; {
; 	void			*data;
; 	struct s_list	*next;
; }					t_list;

; void	ft_list_push_front(t_list **begin_list, void *data);
ft_list_push_front:
	test	rdi, rdi
	jz		.end

	push	rdi
	push	rsi
	sub		rsp, 8

	mov		rdi, 16
	call	malloc wrt ..plt

	add		rsp, 8
	pop		rsi
	pop		rdi

	test	rax, rax
	jz		.end

	mov		[rax], rsi
	mov		rcx, [rdi]
	mov		[rax + 8], rcx
	mov		[rdi], rax

.end:
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
