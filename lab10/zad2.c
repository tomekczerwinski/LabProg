#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n,k,i,j,m;
    printf("Podaj n: \n");
    scanf("%i", &n);
    printf("Podaj k: \n");
    scanf("%i", &k);
    printf("Podaj m: \n");
    scanf("%i", &m);
    double a[n*m], b[m*k], c[n*k];
    int s=n*m, t=m*k, u=n*k;

    for(i=0; i<s; i++){
        printf("Podaj a %i: ", i);
        scanf("%i", &a[i]);
        }
    for(i=0; i<t; i++){
        printf("Podaj b %i: ", i);
        scanf("%i", &b[i]);
        }
    
    



    return 0;
}
