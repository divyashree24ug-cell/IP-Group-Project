	.file	"bfs.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"\nBFS Traversal: "
.LC1:
	.string	"%d "
	.text
	.globl	BFS
	.type	BFS, @function
BFS:
.LFB0:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	add	rsp, -128
	mov	DWORD PTR -116[rbp], edi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	pxor	xmm0, xmm0
	movaps	XMMWORD PTR -96[rbp], xmm0
	movaps	XMMWORD PTR -80[rbp], xmm0
	movq	QWORD PTR -64[rbp], xmm0
	mov	DWORD PTR -112[rbp], 0
	mov	DWORD PTR -108[rbp], 0
	mov	eax, DWORD PTR -116[rbp]
	cdqe
	mov	DWORD PTR -96[rbp+rax*4], 1
	mov	eax, DWORD PTR -108[rbp]
	lea	edx, 1[rax]
	mov	DWORD PTR -108[rbp], edx
	cdqe
	mov	edx, DWORD PTR -116[rbp]
	mov	DWORD PTR -48[rbp+rax*4], edx
	lea	rax, .LC0[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	jmp	.L2
.L6:
	mov	eax, DWORD PTR -112[rbp]
	lea	edx, 1[rax]
	mov	DWORD PTR -112[rbp], edx
	cdqe
	mov	eax, DWORD PTR -48[rbp+rax*4]
	mov	DWORD PTR -100[rbp], eax
	mov	eax, DWORD PTR -100[rbp]
	mov	esi, eax
	lea	rax, .LC1[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	DWORD PTR -104[rbp], 0
	jmp	.L3
.L5:
	mov	eax, DWORD PTR -104[rbp]
	movsx	rcx, eax
	mov	eax, DWORD PTR -100[rbp]
	movsx	rdx, eax
	mov	rax, rdx
	sal	rax, 2
	add	rax, rdx
	add	rax, rax
	add	rax, rcx
	lea	rdx, 0[0+rax*4]
	lea	rax, adj[rip]
	mov	eax, DWORD PTR [rdx+rax]
	cmp	eax, 1
	jne	.L4
	mov	eax, DWORD PTR -104[rbp]
	cdqe
	mov	eax, DWORD PTR -96[rbp+rax*4]
	test	eax, eax
	jne	.L4
	mov	eax, DWORD PTR -104[rbp]
	cdqe
	mov	DWORD PTR -96[rbp+rax*4], 1
	mov	eax, DWORD PTR -108[rbp]
	lea	edx, 1[rax]
	mov	DWORD PTR -108[rbp], edx
	cdqe
	mov	edx, DWORD PTR -104[rbp]
	mov	DWORD PTR -48[rbp+rax*4], edx
.L4:
	add	DWORD PTR -104[rbp], 1
.L3:
	mov	eax, DWORD PTR n[rip]
	cmp	DWORD PTR -104[rbp], eax
	jl	.L5
.L2:
	mov	eax, DWORD PTR -112[rbp]
	cmp	eax, DWORD PTR -108[rbp]
	jl	.L6
	nop
	mov	rax, QWORD PTR -8[rbp]
	sub	rax, QWORD PTR fs:40
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	BFS, .-BFS
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
