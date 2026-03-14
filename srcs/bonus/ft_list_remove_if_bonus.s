bits 64

global ft_list_remove_if

section .text

; void ft_list_remove_if(
;    t_list **begin_list,
;    void *data_ref,
;    int (*cmp)(),
;    void (*free_fct)(void *)
; );
ft_list_remove_if:
	xor		rax, rax
	ret
