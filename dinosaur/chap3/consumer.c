/* Consumer process illustrating POSIX shared-memory API */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
  /* The size of shared memory object in bytes */
  const int SIZE = 4096;

  /* Name of the shared memory object */
  const char *name = "OS";

  /* Share memory file descriptor */
  int shm_fd;

  /* Pointer to shared memory object */
  void *ptr;

  /* Open the shared memory object */
  shm_fd = shm_open(name, O_RDONLY, 0666);

  /* Memory map the shared memory object */
  ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

  /* Read from the shared memory object */
  printf("%s", (char *) ptr);

  /* Remove the shared memory object */
  shm_unlink(name);

  return 0;
}
