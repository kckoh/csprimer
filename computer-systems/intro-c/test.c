#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter a line: ");    
    read = getline(&line, &len, stdin);
    while (line != "end"){
        printf("You entered: %s", line);
        getline(&line, &len, stdin);
    }

    free(line);
    
    return 0;
}