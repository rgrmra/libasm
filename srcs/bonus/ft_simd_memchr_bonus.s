bits 64

global ft_simd_memchr

section .text

; void *ft_simd_memchr(const void *s, int c, size_t n)
ft_simd_memchr:
    test        rdx, rdx
    jz          .not_found

    ; Criar um vetor com 16 cópias do byte c
    movd        xmm1, esi
    punpcklbw   xmm1, xmm1
    punpcklwd   xmm1, xmm1
    pshufd      xmm1, xmm1, 0

.loop16:
    cmp         rdx, 16
    jb          .tail

    ; Carregar 16 bytes e comparar em paralelo
    movdqu      xmm0, [rdi]
    pcmpeqb     xmm0, xmm1
    pmovmskb    eax, xmm0

    test        eax, eax
    jnz         .found_mask

    add         rdi, 16
    sub         rdx, 16
    jmp         .loop16

.found_mask:
    ; Encontrar o primeiro bit marcado
    bsf         eax, eax
    add         rdi, rax
    mov         rax, rdi
    ret

.tail:
    ; Tratar os últimos 0 a 15 bytes sem leitura excessiva
    test        rdx, rdx
    jz          .not_found

	mov		rcx, rdx
	mov		al, sil
	cld
	repne	scasb
	jne		.not_found

	lea		rax, [rdi - 1]
	ret

.not_found:
    xor         eax, eax
    ret

.found_tail:
    mov         rax, rdi
    ret

section .note.GNU-stack noalloc noexec nowrite progbits
