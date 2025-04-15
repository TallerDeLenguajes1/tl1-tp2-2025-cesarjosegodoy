#include <stdio.h>
#include<stdlib.h>

#define N 20

int main () {

int i;
double vt[N];

double *punti = vt;


for(i = 0;i<N; i++) {

punti[i] = 1 + rand() % 100;

printf("\n %d - %f  ",i+1, punti[i]);

}

return 0;

}
