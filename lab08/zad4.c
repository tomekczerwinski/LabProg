#define PETLA(k1,w,k2) \
{ k1; while(w){k2; k1;}}

#include <stdio.h>
int main(){
	int a=0, b=0, i=0;

	PETLA(a++,i<5,b++;i++);
	printf("a: %i , b: %i \n", a,b );
	return 0;

	}




