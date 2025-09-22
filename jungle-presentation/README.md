## Hello World Assembly

print -> i/o -> system call
string -> ascii -> 어디에 저장?
exit status -> system call

* System CAlls
* write
* exit

steps:
1. exit code -> 0
2. print hello world

assembly -> linker -> executable
.s -> .o -> executable


as -o hello.o hello.s && ld -o hello hello.o