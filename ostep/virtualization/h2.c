#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  close(STDOUT_FILENO);
  open("./h2.out", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("-------------------------------------\n");
    printf("child process (pid: %d)\n", (int) getpid());
    printf("-------------------------------------\n");
  } else {
    wait(NULL);
    printf("-------------------------------------\n");
    printf("parent process (pid: %d)\n", (int) getpid());
    printf("-------------------------------------\n");
  }
}

