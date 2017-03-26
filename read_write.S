	global read:function

read:
	mov rax, 0
	syscall
	ret


	global write:function
write:
	mov rax, 1
	syscall
	ret
