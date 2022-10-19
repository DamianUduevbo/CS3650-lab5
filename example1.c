#include <stdio.h>
#include <sys/types.h>  // Includes some new data types (e.g. pid_t)
#include <unistd.h>  // This is a new library that includes various unix system calls.

int main(int argc, char **argv) {

  pid_t pid;
  int x = 1;

  pid = fork();

  if (pid == 0) {
    printf("child: x = %d\n", ++x);
    return 0;  
  }

  printf("parent: x = %d\n", --x);
  return 0;

  //Prediction: prints either the "child" or "parent" but not both
}
