// Take a look at some of the previous examples to create your own program!

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {

  char* myargv[16];
  myargv[0] = "/bin/ps";
  myargv[1] = "-uf";
  myargv[2] = NULL;

  char* myargv1[16];
  myargv1[0] = "/bin/echo";
  myargv1[1] = "--help";
  myargv1[2] = NULL;

  char* myargv2[16];
  myargv2[0] = "/bin/nl";
  myargv2[1] = "-b";
  myargv2[2] = "a";
  myargv2[3] = "example1.c";

  char* myargv3[16];
  myargv3[0] = "/bin/ls";
  myargv3[1] = "-a";
  myargv3[2] = NULL;

  char* myargv4[16];
  myargv4[0] = "/bin/top";
  myargv4[1] = "-help";
  myargv4[2] = NULL;


  if (fork() == 0) {
    execve(myargv4[0], myargv4, NULL);

    printf("Child: Should never get here\n");
  }
  else {
    wait(NULL);
    printf("This always prints last\n");
  }



  if (fork() == 0) {
    execve(myargv3[0], myargv3, NULL);

    printf("Child: Should never get here\n");
  }
  else {
    wait(NULL);
    printf("This always prints last\n");
  }



  if (fork() == 0) {
    execve(myargv2[0], myargv2, NULL);

    printf("Child: Should never get here\n");
  }
  else {
    wait(NULL);
    printf("This always prints last\n");
  }




  if (fork() == 0) {
    execve(myargv1[0], myargv1, NULL);

    printf("Child: Should never get here\n");
  }
  else {
    wait(NULL);
    printf("This always prints last\n");
  }



  if (fork() == 0) {
    execve(myargv[0], myargv, NULL);
    
    printf("Child: Should never get here\n");
    exit(1);
  }
  else {
    wait(NULL);
    printf("This always prints last\n");
  }
  
  return 0;
}


