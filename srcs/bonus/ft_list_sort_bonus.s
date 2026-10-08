bits 64

global ft_list_sort

section .text

; typedef struct	s_list
; {
; 	void			*data;
; 	struct s_list	*next;
; }					t_list;

; void ft_list_sort(t_list **begin_list, int (*cmp)());
ft_list_sort:
	push	rbp
	push	r12
	push	r13
	push	r14
	push	r15
	push	rbx
	sub		rsp, 8

	test	rdi, rdi
	jz		.end

	test	rsi, rsi
	jz		.end

	mov		rbp, rdi
	mov		r12, [rdi]
	mov		r15, rsi

	xor		rbx, rbx

.loop:
	test	r12, r12
	jz		.done

	mov		r13, r12
	mov		r12, [r12 + 8]

	test	rbx, rbx
	jz		.insert_head

	mov		rdi, [r13]
	mov		rsi, [rbx]

	call	r15

	test	eax, eax
	jl		.insert_head

	mov		r14, rbx

.find:
	mov		rax, [r14 + 8]
	test	rax, rax
	jz		.insert_after

	mov		rdi, [r13]
	mov		rsi, [rax]

	call	r15

	test	eax, eax
	jl		.insert_after

	mov		r14, [r14 + 8]

	jmp	.find

.insert_head:
	mov		[r13 + 8], rbx
	mov		rbx, r13

	jmp		.loop

.insert_after:
	mov		rax, [r14 + 8]
	mov		[r13 + 8], rax
	mov		[r14 + 8], r13
	
	jmp		.loop

.done:
	mov		[rbp], rbx

.end:
	add		rsp, 8
	pop		rbx
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		rbp
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
