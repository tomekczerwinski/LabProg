#include "licznik.h"
int licznik=0;

void policz(int drukowac){
	
	if (drukowac==1) printf("Funkcja zostala wywolala %i razy", licznik); else
	licznik++;
}




