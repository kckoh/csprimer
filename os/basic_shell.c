#include <stdio.h>
#include <unistd.h>
// create a shell like program that executes the built-in program
// get the input from the users
// run until any signals come through
// create a child process to run -> learn about how to create a process

int main(){
    char buffer[100];
    printf("# Enter a line of text: ");
    while(fgets(buffer, sizeof(buffer), stdin)){
        printf("# %s", buffer);
        pid_t pid = fork();
        
        if (pid < 0){
            
        }
        else if(pid == 0){
            
        }

        printf("# Enter a line of text: ");

    }
    
    return 0;
}