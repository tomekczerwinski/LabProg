  #define MAX_DL_IM 11
  #define MAX_DL_NA 17
  #define DUZO 10000
#include <stdio.h>


  typedef struct os {
    char imie[MAX_DL_IM];
    char nazwisko[MAX_DL_NA];
    int pensja;
  } osoba;

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

void sortowanie(int ile){
    int i,j, pomp;
    char pom[MAX_DL_NA];
    for (i=0; i<ile; i++){
        for (j=0; j<ile; j++){
            if(strcmp(tabl[j-1].nazwisko,tabl[j].nazwisko) > 0){
            strcpy(pom,tabl[j-1].nazwisko);
            strcpy(tabl[j-1].nazwisko,tabl[j].nazwisko);
            strcpy(tabl[j].nazwisko,pom);
            strcpy(pom,tabl[j-1].imie);
            strcpy(tabl[j-1].imie,tabl[j].imie);
            strcpy(tabl[j].imie,pom);
            pomp=tabl[j-1].pensja;
            tabl[j-1].pensja=tabl[j].pensja;
            tabl[j].pensja=pomp;
            }
            }
        }
}



  int main (int arg_num, char* arg[]) {
    if (arg_num == 3) {
      int ile = czytanie(arg[1]);
     if (ile > 0) {
        sortowanie(ile);
       pisanie(arg[2], ile);
      }
    }
    else
      printf("\n Poprawne wywolanie: './sort dane wynik'\n\n");
    return 0;
  }
