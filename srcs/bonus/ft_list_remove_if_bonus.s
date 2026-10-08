bits 64

global ft_list_remove_if
extern free

section .text

; typedef struct	s_list
; {
; 	void			*data;
; 	struct s_list	*next;
; }					t_list;

; void ft_list_remove_if(
; 	t_list	**begin_list,
; 	void	*data_ref,
; 	int		(*cmp)(),
; 	void	(*free_fct)(void *)
; );
ft_list_remove_if:
	push	rbx
	push	r12
	push	r13
	push	r14
	push	r15
	sub		rsp, 8

	test	rdi, rdi
	jz		.end

	test	rdx, rdx
	jz		.end

	mov		r12, rdi
	mov		r13, rsi
	mov		r14, rdx
	mov		r15, rcx

.loop:
	cmp		qword [r12], 0
	je		.end

	mov		rbx, [r12]

	mov		rdi, [rbx]
	mov		rsi, r13

	call	r14

	test	eax, eax
	jnz		.next_node

	mov		rax, [rbx + 8]
	mov		[r12], rax

	test	r15, r15
	jz		.free_node

	mov		rdi, [rbx]

	call	r15

.free_node:
	mov		rdi, rbx

	call	free wrt ..plt

	jmp		.loop

.next_node:
	lea		r12, [rbx + 8]

	jmp		.loop

.end:
	add		rsp, 8
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		rbx
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
