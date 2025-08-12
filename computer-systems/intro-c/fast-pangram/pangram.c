#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool ispangram(char *s) {
  // TODO implement this!
  // loop through every character and find if it is in the ascii
  printf("%s", s);
  while (*s != '\0'){
    unsigned int ch = (unsigned int) *s;
    // 65 A 90: Z
    // 97:a 122: z
    // Upper case
    // convert it to lower case
    if (ch >= 65 && ch <= 90 ){
      ch += 22;
    }
    // do something here
    if (ch >= 97 && ch <= 122 ){
      
    }
    // Lower case
    s++; // move to next character
  }
  return false;
}

int main() {
  size_t len;
  ssize_t read;
  char *line = NULL;
  while ((read = getline(&line, &len, stdin)) != -1) {
    if (ispangram(line))
      printf("%s", line);
  }

  if (ferror(stdin))
    fprintf(stderr, "Error reading from stdin");

  free(line);
  fprintf(stderr, "ok\n");
}
