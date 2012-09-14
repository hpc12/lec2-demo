#include <stdio.h>


int main(){

int sum = 0;
int a[100],i;

#pragma omp parallel for shared(sum) 
for (i=0;i<100;i++) a[i]=i;

#pragma omp parallel for \
                     reduction(+:sum)
  for(i=0;i<100;i++)
      sum += a[i];

printf("sum of first 100 numbers %d\n",sum);

}
