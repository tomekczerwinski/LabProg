  #define MAX_DL_IM 11
  #define MAX_DL_NA 17
  #define DUZO 10000
#include <stdio.h>


  typedef  struct os {
    char imie[MAX_DL_IM];
    char nazwisko[MAX_DL_NA];
    int pensja;
  }  osoba;

  osoba tabl[DUZO];

  int czytanie(char nazwa[]){
  	int linie = 0, c;
  	FILE* plik = fopen(nazwa, "r");

  	while(c!= EOF){
  		fscanf(plik, "%s", tabl[linie].imie);
  		fscanf(plik, "%s", tabl[linie].nazwisko);
  		fscanf(plik, "%i", &tabl[linie].pensja);
  		c = fscanf(plik, "%i", &tabl[linie].pensja);
  		linie++;
	}
	fclose(plik);

  	return linie;
  }

void pisanie(char wyj[], int ile){
	FILE* plik = fopen(wyj, "w");
	int i;
	for (i=0; i<ile; i++){
		fprintf(plik, "%s", tabl[i].imie);
		fprintf(plik, "\t");
		fprintf(plik, "%s", tabl[i].nazwisko);
		fprintf(plik, "\t");
		fprintf(plik, "%i", tabl[i].pensja);
		fprintf(plik, "\n");

		
	}
	fclose(plik);

}


  int main (int arg_num, char* arg[]) {
    if (arg_num == 3) {
      int  ile = czytanie(arg[1]);
     if (ile > 0) {
        //sortowanie(0,ile);
       pisanie(arg[2], ile);
      }
    }
    else
      printf("\n Poprawne wywolanie: './sort dane wynik'\n\n");
    return 0;
  }
