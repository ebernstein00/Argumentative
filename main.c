#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char ** parse_args(char *line){
  char **args = malloc(100);
  char *curr = line;
  char *token;
  int i = 0;
  while (curr != NULL){
    token = strsep(&curr, " ");
    args[i] = token;
    i += sizeof(token) + 1;
  }
}

int main(){
  char ** args = parse_args("ls -a -l");
  execvp(args[0], args);
  free(args);
}
