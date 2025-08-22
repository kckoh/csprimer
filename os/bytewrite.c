#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // open requires three args: path, flags and mode
int fd = open("hello.txt", O_WRONLY | O_CREAT , 0644);
    if (fd == -1) {
        // handle error
        return 1;
    }
    struct stat st;
    if (stat("hello.txt", &st) ==-1){
        return 1;
    }

    blksize_t init_blksize = st.st_blksize;
    
    while (st.st_blksize <= 1,000,000) {
        stat("hello.txt", &st);

    }
    // printf("File size: %ld bytes\n", st.st_blksize);
    close(fd);
    return 0;
}
