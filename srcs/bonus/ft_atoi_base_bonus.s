bits 64

global ft_atoi_base

section .text

; int ft_atoi_base(char *str, char *base);
ft_atoi_base:
    test    rdi, rdi
	je      .error

    test    rsi, rsi
	je      .error

    mov     rax, rsi
    dec     rax

    mov     r8, rdi
    mov     r9, rsi

.check_base_invalid_characters:
    inc     rax

    cmp     byte [rax], 0
    je      .check_base_size

    cmp     byte [rax], '+'
    je      .error

    cmp     byte [rax], '-'
    je      .error

    cmp     byte [rax], ' '
    je      .error

    cmp     byte [rax], 9
    jb      .check_base_invalid_characters

    cmp     byte [rax], 13
    ja      .check_base_invalid_characters

    jmp     .error

.check_base_size:
    sub     rax, r9
    cmp     rax, 2
    jl      .error

    mov     r10, rax
    xor     r11, r11

.check_base_double_characters:
    cmp     r11, r10
    jge     .end

    mov     al, [r9 + r11]

    lea     rdi, [r9 + r11 + 1]

    mov     rcx, r10
    sub     rcx, r11
    dec     rcx

    repne   scasb
    je      .error

    inc     r11
    jmp     .check_base_double_characters

.check_number:
    mov rax, r8

.error:
    xor     rax, rax

.end:
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
