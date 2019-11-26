#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ** parse_args(char *line){
  char **args = malloc(100);
  char *curr = line;
  char *token;
  int i = 0;
  while (*curr != '\0'){
    //token = strsep(&curr, " ");
    args[i++] = strsep(&curr, " ");
  }
  args[i] = NULL;
  return args;
}

int main(){
  char ** args = parse_args("ls -a -l");
  execvp(args[0], args);
  free(args);
}
