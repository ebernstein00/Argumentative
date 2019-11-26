#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ** parse_args(char *line){
  printf("test\n");
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
  //printf("> ");
  char buf[128] = "ls -a -l";
  //fgets(buf,128,stdin);
  char **args = parse_args(buf);
  //char c[100] = "ls -a -l";
  //char **args = parse_args(c);
  execvp(args[0], args);
  free(args);
}

 /*

int main(){
  printf("> ");
  char buf[128];
  fgets(buf,128,stdin);
  char **args = parse_args(buf);
  execvp(args[0],args);
  free(args);
}
*/
