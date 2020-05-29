#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int x = 100;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("-------------------------------------\n");
    printf("child process (pid: %d)\n", (int) getpid());
    printf("x (original): %d\n", x);
    x = 5;
    printf("x (modified): %d\n", x);
    printf("-------------------------------------\n");
  } else {
    int rc_wait = wait(NULL);
    printf("-------------------------------------\n");
    printf("parent process (pid: %d)\n",  getpid());
    printf("x (original): %d\n", x);
    x = 25;
    printf("x (modified): %d\n", x);
    printf("-------------------------------------\n");
  }
}
