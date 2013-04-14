#include <stdio.h>
#include <stdlib.h>


void funk(int n, int k, int *q, int *r)
    {
        *q = n / k;
        *r = n % k;

    }


int main()
{
    int a, q, r;
    int b;
    scanf("%i",&a);
    scanf("%i",&b);
    funk(a,b, &q, &r);

    printf("Iloraz = %i \nReszta = %i\n", q, r);
    return 0;
}
