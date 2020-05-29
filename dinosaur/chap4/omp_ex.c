#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;
  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = {1, 2, 3, 4, 5};
  int c[5];

  #pragma omp parallel for
  for (i=0; i<5; i++) {
    c[i] = a[i] + b[i];
  }

  /* Print results */
  for (i=0; i<5; i++) {
    printf("c[%d] = %d\n", i, c[i]);
  }
}

