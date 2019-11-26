#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ** parse_args(char *line){
  printf("test");
  int arsize = 6;
  char **args = malloc(arsize * sizeof(char *));
  char *curr = line;
  int i = 0;
  while (*curr != '\0'){
    args[i++] = strsep(&curr, " \n");
    if (i > arsize){
      arsize *= 2;
      args = realloc(args, arsize * sizeof(char *));
    }
  }
  args[i] = NULL;
  return args;
}

int main(){
  //char **args = malloc(sizeof(parse_args("ls -a -l")));
  //printf("> ");
  //char buf[128];
  //fgets(buf,128,stdin);
  //char **args = parse_args(buf);
  char *c = "ls -a -l";
  char **args = parse_args(c);
  execvp(args[0], args);
  free(args);
}

 /*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

char ** parse_args(char *line) {
  unsigned short i;
  unsigned short ary_size = 6; // originally i missed the specified max size, this works for larger amounts too
  char **args = malloc(ary_size * sizeof(char *));
  char *cur = line;
  i = 0;
  while(*cur != '\0') {
    args[i++] = strsep(&cur," \t\n");
    if(i >= ary_size) {
      ary_size *= 2;
      args = realloc(args,ary_size * sizeof(char *));
    }
  }
  args[i] = NULL;
  return args;
}

int main(){
  printf("> ");
  char buf[128];
  fgets(buf,128,stdin);
  char **args = parse_args(buf);
  execvp(args[0],args);
  free(args);
}
*/
