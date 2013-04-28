#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n,k,i,j;
    printf("Podaj n: \n");
    scanf("%i", &n);
    printf("Podaj k: \n");
    scanf("%i", &k);
    double a[n*k], b[n*k];
     int s = n*k;
printf("Podaj %i x %i liczb w tablice a: \n",n,k);

for(i=0;i<s;i++){
printf("Liczba %i: ",i);
scanf("%i",&a[i]);
}

printf("Wyswietlanie: \n");
for(i=0;i<k;i++){
for(j=0;j<n;j++){
printf("%i ", a[i*k+j]);
}
printf("\n");
}
    return 0;
}
