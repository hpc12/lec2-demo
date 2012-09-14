

 #include <omp.h>
 #include <stdio.h>
 #include <stdlib.h>

int main(int argc, char *argv[]) {

   int nThreads;

   if (2 != argc){
     printf("Must enter integer for number threads on command line\n");
     exit(-1);
   }
   else{
     nThreads = atoi(argv[1]);
     printf("Using %d threads\n",nThreads);
   }

#ifdef _OPENMP
   int my_threadNum = omp_get_thread_num();
   int numThreads = omp_get_num_threads();
#else
   int my_threadNum = 0;
   int numThreads = 1;
#endif   

   
#pragma omp parallel num_threads(nThreads)
 printf("Hello world from thread %d\n",my_threadNum);

 return 0;
 }
