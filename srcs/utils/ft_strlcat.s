;bits 64
;
;global ft_strlcat
;
;default rel
;extern ft_strlen
;extern ft_strlcpy
;
;section .text
;
;ft_strlcat:
;	push	rbx
;	push	r12
;	push	r13
;	push	r14
;
;	mov		rbx, rdi
;	mov		r12, rsi
;	mov		r13, rdx
;
;	xor		rax, rax
;
;	test	rdi, rdi
;	jz		.skip
;
;	test	rdx, rdx
;	jz		.skip
;
;	mov		rcx, -1
;	repne	scasb
;	not		rcx
;	dec		rcx
;
;	mov		r14, rcx
;
;.skip:
;	mov		rdi, r12
;	mov		rcx, -1
;	repne	scasb
;	not		rcx
;	dec		rcx
;
;	cmp		r14, rcx
;	ja		.ret_size
;
;
;
;
;.ret_size
;	add		rcx, rdx
;	mov		rax, rcx
;
;.done:
;	pop		r14
;	pop		r13
;	pop		r12
;	pop		rbx
;	ret
	



;    push rbx
;    push r12
;    push r13
;    push r14
;
;    mov r14, rdi    ; salvar dst
;    mov rbx, rsi    ; salvar src
;    mov r12, 0      ; dlen = 0
;
;    test r14, r14
;    jz .skip_dlen
;    test rdx, rdx
;    jz .skip_dlen
;
;    mov rdi, r14
;    call ft_strlen wrt ..plt
;    mov r12, rax
;
;.skip_dlen:
;
;    mov rdi, rbx
;    call ft_strlen wrt ..plt
;    mov r13, rax    ; slen
;
;    mov rax, rdx
;    cmp r12, rax
;    ja .ret_size_plus_slen
;
;    ; ft_strlcpy(dst + dlen, src, size - dlen)
;    mov rdi, r14
;    add rdi, r12    ; dst + dlen
;
;    mov rsi, rbx    ; src
;
;    mov rcx, rdx
;    sub rcx, r12    ; size - dlen
;    mov rdx, rcx
;
;    call ft_strlcpy wrt ..plt
;
;    add rax, r12    ; return dlen + result
;    jmp .end
;
;.ret_size_plus_slen:
;    add rax, r13    ; size + slen
;
;.end:
;    pop r14
;    pop r13
;    pop r12
;    pop rbx
;    ret

section .note.GNU-stack noalloc noexec nowrite progbits
