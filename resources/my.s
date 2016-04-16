[BITS 64]

section .data
	msg     db  'Hello, world!',0xa	;our dear string
	len     equ $ - msg		;length of our dear string
	
section .text
	global syscallmemaybe:function

syscallmemaybe:
	push rbp,
	mov rbp,rsp
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, len
	syscall
	mov rsp, rbp
	pop rbp
	ret
