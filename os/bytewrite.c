#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // open requires three args: path, flags and mode
int fd = open("hello.txt", O_WRONLY | O_CREAT , 0644);
    if (fd == -1) {
        // handle error
        return 1;
    }
    printf("hello world");
    write(fd, "Hello World\n", 12);
    close(fd);
    return 0;
}
