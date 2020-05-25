/* Figure 3.17: Producer process illustrating POSIX shared memory API */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  /* The size of the shared memory object in bytes */
  const int SIZE = 4096;
  
  /* Name of the shared memory object */
  const char *name = "OS";

  /* Strings written to shared memory */
  const char *message_0 = "Hello";
  const char *message_1 = "World!";

  /* Share memory file descriptor */
  int shm_fd;

  /* Pointer to shared memory object */
  void *ptr;

  /* Create the shared memory object */
  shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

  /* Configure the size of the shared memory object */
  ftruncate(shm_fd, SIZE);

  /* Memory map the shared memory object */
  ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

  /* Write to the shared memory object */
  sprintf(ptr, "%s", message_0);
  ptr += strlen(message_0);
  sprintf(ptr, "%s", message_1);
  ptr += strlen(message_1);

  return 0;
}

