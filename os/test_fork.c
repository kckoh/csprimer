#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();
    // code below is what gets run in child or parent

if (pid == 0) {
    // child process
    printf("Child running, PID=%d\n", getpid());
} else if (pid > 0) {
    // parent process
    printf("Parent running, PID=%d, child PID=%d\n", getpid(), pid);
} else {
    perror("fork failed");
}
    return 0;
}