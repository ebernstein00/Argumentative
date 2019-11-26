#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ** parse_args(char *line){
  char **args = malloc(5 * sizeof(char *));
  char *curr = line;
  int i = 0;
  while (*curr != '\0'){
    args[i++] = strsep(&curr, " \n");
  }
  args[i] = NULL;
  return args;
}

int main(){
  printf("Testing: ls -a -l\n");
  char c[100] = "ls -a -l\n";
  char **args = parse_args(c);
  execvp(args[0], args);
  free(args);
}
