[BITS 64]

section .data
	msg     db  'Hello, world!',0xa	;our dear string
	len     equ $ - msg		;length of our dear string
	
section .text
	global _start:function
	global helloworld:function

_start:
	push rbp
	mov rbp, rsp
	call helloworld
	mov rax, 60
	mov rdi, 0
	syscall

helloworld:
	push rbp
	mov rbp, rsp
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, len
	syscall
	mov rsp, rbp
	pop rbp
