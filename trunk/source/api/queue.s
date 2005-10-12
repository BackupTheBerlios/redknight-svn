	.file	"queue.c"
	.text
	.align 2
.globl _ctk_queue_create
	.def	_ctk_queue_create;	.scl	2;	.type	32;	.endef
_ctk_queue_create:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	subl	$12, %esp
	pushl	$12
	call	_malloc
	addl	$16, %esp
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movw	$0, (%eax)
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	movw	%ax, 2(%edx)
	movl	-4(%ebp), %edx
	movl	-4(%ebp), %eax
	movl	$0, 8(%eax)
	movl	$0, 4(%edx)
	movl	-4(%ebp), %eax
	leave
	ret
	.align 2
.globl _ctk_queue_push
	.def	_ctk_queue_push;	.scl	2;	.type	32;	.endef
_ctk_queue_push:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	cmpl	$0, 8(%ebp)
	jne	L5
	movl	$-1, -8(%ebp)
	jmp	L4
L5:
	movl	8(%ebp), %eax
	movl	8(%ebp), %edx
	movw	(%eax), %ax
	cmpw	2(%edx), %ax
	jb	L6
	movl	$-3, -8(%ebp)
	jmp	L4
L6:
	subl	$12, %esp
	pushl	$8
	call	_malloc
	addl	$16, %esp
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%eax, (%edx)
	movl	8(%ebp), %eax
	cmpw	$0, (%eax)
	jne	L7
	movl	8(%ebp), %ecx
	movl	8(%ebp), %edx
	movl	-4(%ebp), %eax
	movl	%eax, 8(%edx)
	movl	%eax, 4(%ecx)
	jmp	L8
L7:
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%eax, 4(%edx)
	movl	8(%ebp), %edx
	movl	-4(%ebp), %eax
	movl	%eax, 8(%edx)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	$0, 4(%eax)
L8:
	movl	8(%ebp), %eax
	movw	(%eax), %dx
	andl	$65535, %edx
	incw	(%eax)
	movl	%edx, -8(%ebp)
L4:
	movl	-8(%ebp), %eax
	leave
	ret
	.align 2
.globl _ctk_queue_peep
	.def	_ctk_queue_peep;	.scl	2;	.type	32;	.endef
_ctk_queue_peep:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	cmpl	$0, 8(%ebp)
	jne	L10
	movl	$-1, -4(%ebp)
	jmp	L9
L10:
	movl	8(%ebp), %eax
	cmpw	$0, (%eax)
	jne	L11
	movl	$-2, -4(%ebp)
	jmp	L9
L11:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
L9:
	movl	-4(%ebp), %eax
	leave
	ret
	.align 2
.globl _ctk_queue_pop
	.def	_ctk_queue_pop;	.scl	2;	.type	32;	.endef
_ctk_queue_pop:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	cmpl	$0, 8(%ebp)
	jne	L13
	movl	$-1, -8(%ebp)
	jmp	L12
L13:
	movl	8(%ebp), %eax
	cmpw	$0, (%eax)
	jne	L14
	movl	$-2, -8(%ebp)
	jmp	L12
L14:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %edx
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%edx)
	subl	$12, %esp
	pushl	-4(%ebp)
	call	_free
	addl	$16, %esp
	movl	8(%ebp), %eax
	movw	(%eax), %dx
	andl	$65535, %edx
	decw	(%eax)
	movl	%edx, -8(%ebp)
L12:
	movl	-8(%ebp), %eax
	leave
	ret
	.align 2
.globl _ctk_queue_size
	.def	_ctk_queue_size;	.scl	2;	.type	32;	.endef
_ctk_queue_size:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	cmpl	$0, 8(%ebp)
	jne	L16
	movl	$-1, -4(%ebp)
	jmp	L15
L16:
	movl	8(%ebp), %eax
	movw	(%eax), %ax
	andl	$65535, %eax
	movl	%eax, -4(%ebp)
L15:
	movl	-4(%ebp), %eax
	leave
	ret
	.align 2
.globl _ctk_queue_isempty
	.def	_ctk_queue_isempty;	.scl	2;	.type	32;	.endef
_ctk_queue_isempty:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	cmpl	$0, 8(%ebp)
	jne	L18
	movl	$-1, -4(%ebp)
	jmp	L17
L18:
	movl	8(%ebp), %eax
	cmpw	$0, (%eax)
	setne	%al
	andl	$255, %eax
	movl	%eax, -4(%ebp)
L17:
	movl	-4(%ebp), %eax
	leave
	ret
	.align 2
.globl _ctk_queue_delete
	.def	_ctk_queue_delete;	.scl	2;	.type	32;	.endef
_ctk_queue_delete:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L20
	movl	$-1, -12(%ebp)
	jmp	L19
L20:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -8(%ebp)
L21:
	movl	-8(%ebp), %eax
	cmpl	$0, 4(%eax)
	jne	L23
	jmp	L22
L23:
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -8(%ebp)
	subl	$12, %esp
	pushl	-4(%ebp)
	call	_free
	addl	$16, %esp
	jmp	L21
L22:
	subl	$12, %esp
	pushl	-8(%ebp)
	call	_free
	addl	$16, %esp
	subl	$12, %esp
	pushl	8(%ebp)
	call	_free
	addl	$16, %esp
	movl	$0, -12(%ebp)
L19:
	movl	-12(%ebp), %eax
	leave
	ret
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
