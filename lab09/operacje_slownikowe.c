#include "operacje_slownikowe.h"

#define MAX_HASEL 100

typedef struct{
  char pol[MAX_DL_SLOWA];
  char ang[MAX_DL_SLOWA];
} slowo;

slowo slownik[MAX_HASEL];
int licznik=0;

void  inicjuj_slownik(void){
	licznik=0;
}




Logiczne  dodaj(char a[MAX_DL_SLOWA], char p[MAX_DL_SLOWA]){
	if (licznik<MAX_HASEL){
		strcpy (slownik[licznik].ang , a);
		strcpy (slownik[licznik].pol , p);
		licznik++;
		return PRAWDA;
		else return FALSZ;
	}

}
  /* dodaje do slownika pare <a,p>
   * wynik  PRAWDA  oznacza, ze sie udalo dodac,
   * wynik  FALSZ  oznacza, ze slownik juz byl pelny
   */


void  usun(char a[MAX_DL_SLOWA]){
	int i=0;
	while (i < licznik && strcmp(a, slownik[i].ang) != 0)
		i++;
	if (i < licznik){
		strcpy(slownik[licznik].ang, slownik[licznik-1].ang);
		strcpy(slownik[licznik].pol, slownik[licznik-1].pol);
	}licznik--;

}
  /* usuwa ze slownika pare slow, zlozona z angielskiego slowa  a
   * i jego polskiego odpowiednika
   */

void  ang_pol(char zrodlo[MAX_DL_SLOWA], char cel[MAX_DL_SLOWA]){
	 int i=0;
	 while (i < licznik && strcmp(zrodlo, slownik[i].ang) !=0)  
	 	i++;
 	 if (i < licznik)  
 	 	strcpy(cel, slownik[i].pol);
  	 	else  strcpy(cel, "");

 
}
  /* do angielskiego slowa  zrodlo
   * wyszukuje w slowniku polski odpowiednik  cel
   * jesli takiego nie ma, to pod  cel  podstawia slowo puste
   */

void  pol_ang(char zrodlo[MAX_DL_SLOWA], char cel[MAX_DL_SLOWA]){
	int i=0;
	while (i < licznik && strcmp(zrodlo, slownik[i].pol) != 0)
		i++;
	if (i < licznik)
		strcpy(cel, slownik[i].ang);
		else strcpy(cel, "");

}
  /* do polskiego slowa  zrodlo
   * wyszukuje w slowniku angielski odpowiednik  cel
   * jesli takiego nie ma, to pod  cel  podstawia slowo puste
   */