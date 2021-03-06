
#include <stdio.h>
#include <stdlib.h>
#include "timing.h"
#include <omp.h>
#include <math.h>
  
 int main(int argc, char *argv[]) {
 
 double sum = 0;
 int  i,j;
 size_t n;
 timestamp_type time1, time2;

  if (argc != 2){
    printf("Must enter integer for array size on command line\n");
    exit(-1);
  }
  else {  
    n = atoi(argv[1]);
    printf("Using array size %ld and %d threads\n",n,omp_get_num_threads());
  }
  
  double *x = (double *) malloc(sizeof(double) * n);
  if (!x) { perror("alloc x"); abort(); }
  double *y = (double *) malloc(sizeof(double) * n);
  if (!y) { perror("alloc y"); abort(); }
 
  for (i=0;i<n;i++){
    x[i] = i;
    y[i] = 2*i;
  }


 get_timestamp(&time1);

#pragma omp parallel for default(none) shared(x,y,n,sum) 
   for(i=0;i<n;i++){
     double a = x[i] * y[i];
#pragma omp atomic
     sum +=  a;
   }

  get_timestamp(&time2);
  double elapsed = timestamp_diff_in_seconds(time1,time2);
  printf("%f s\n", elapsed);

  printf("sum = %15.7e\n",sum);
         
 return 0;
 
 }


