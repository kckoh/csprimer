#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sum(int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}

int main() {


    // get the input and print out example
    // char *line = NULL;
    // size_t len = 0;
    // ssize_t read;

    // printf("Enter a line: ");    
    // while ((read = getline(&line, &len, stdin)) != -1) {

    //     if (strcmp(line, "end\n\0") == 0) {
    //         break;
    //     }

    //     printf("You entered: %s\n", line);
    // }
    // free(line);

    // use struct
    printf("hello world\n");
    // struct rectangle {
    //     int width;
    //     int height;
    // };
    // struct rectangle r = { 1, 2 };
    // printf(r.height); 

    // struct DA {
    //     int *arr;
    //     int size;
    // };
    // struct DA test = {malloc(8 * sizeof(int)), sizeof(int)};
    // printf("%p\n",&test);
    int arr[] = {5, 20, 3};
    int total = sum(arr, sizeof(arr) / sizeof(int));
    printf("Total: %d\n", total);
    exit(0);
    
    return 0;
}