useful links
https://cs.lmu.edu/~ray/notes/nasmtutorial/
https://ncase.me/remember/
youtube video: https://www.youtube.com/watch?v=jPDiaZS-2ok
syscall reference: https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md


.global -> Linker에게 전역 심볼로 등록

.global _start -> _start CPU가 처음 시작하는 starting entry

nasm vs. GAS -> Syntax가 다르다 -> Intel vs. AT&T 
확장자: .asm and .s
GAS -> GCC와 연계가 좋고 시스템 + 커널 프로그래밍에서 많이 사용한다
NASM -> 윈도우에서 개발시 필수

simple build + execute
nasm -f elf64 hello.asm -o hello.o
ld hello.o -o hello
./hello

