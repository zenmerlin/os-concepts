#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid;

  /* Fork a child process */

  pid = fork();

  if (pid < 0) { /* error occurred */
    fprintf(stderr, "Fork failed.");
    printf("Child PID: %d\n", pid);
    return 1;
  }
  else if (pid == 0) { /* child process */
    printf(
        "Value of pid from child: %d\n"
        "Value of getpid() from child: %d\n",
        pid, getpid()
    );
    execlp("/bin/ls", "ls", NULL);
  }
  else { /* parent process */
    /* Parent will wait for the child to complete */
    pid_t child_pid;
    int status;

    child_pid = wait(&status);
    printf(
        "Child complete.\n"
        "Value of pid from parent: %d\n"
        "Value of getpid() from parent: %d\n"
        "Child pid returned: %d\n"
        "Child status: %d\n",
        pid, getpid(), child_pid, status
    );
  }
  return 0;
}

