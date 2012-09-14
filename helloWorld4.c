
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {

  //#ifdef _OPENMP
#if 1  
  int my_threadNum = omp_get_thread_num();
  int numThreads = omp_get_num_threads();
#else
  int my_threadNum = 0;
  int numThreads = 1;
#endif

  
#pragma omp parallel 
  printf("Hello world from thread %d of %d\n",my_threadNum, numThreads);

 return 0;
}
