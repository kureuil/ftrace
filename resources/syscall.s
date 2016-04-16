[BITS 64]			;3409;0c

section .data
	msg     db  'Hello, world!',0xa	;our dear string
	len     equ $ - msg		;length of our dear string
	
section .text
	extern syscallmemaybe
	global _start:function
	global syscallexit:function
	
_start:
	push rbp
	mov rbp, rsp
	call syscallmemaybe wrt ..plt
	call syscallexit
	mov rsp, rbp
	pop rbp
	ret

syscallexit:
	push rbp,
	mov rbp,rsp
	mov rax, 60
	syscall
	mov rsp, rbp
	pop rbp
	ret
