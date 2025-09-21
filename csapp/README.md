gcc -Og -S hello.c 

as -o hello.o hello.s && ld -o hello hello.o

ld -o hello hello.o

echo $?


	mov $60, %rax
	mov $42, %rdi
	syscall