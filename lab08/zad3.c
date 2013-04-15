#define CZYT(zmienna, typ) \
{ printf(" Podaj wartosc a: "); scanf("%"#typ, &zmienna); } 
#include <stdio.h>

int main(){
	double a;
	CZYT(a,lf);
	printf("%lf \n", a);
	return 0;

}