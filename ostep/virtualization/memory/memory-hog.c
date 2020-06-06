#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BYTES_PER_MB 1048576
#define FILL_CHAR 'A'

char* memfill(int mbytes);

int main(int argc, char *argv[])
{
        char *p;

        if (argc > 1) {
                printf("pid: %d\n", getpid());
                p = memfill(atoi(argv[1]));
                printf("Press any key to exit\n");
                getchar();
                free(p);
        } else {
                printf("usage: memory-hog <megabytes to fill>\n");
        }
}

char* memfill(int mbytes)
{
        char *p;
        int n = mbytes * BYTES_PER_MB;
        int i;

        p = (char*) malloc(n * sizeof(char));
        for (i = 0; i < n; i++)
                *(p+i) = FILL_CHAR;
        return p;
}

