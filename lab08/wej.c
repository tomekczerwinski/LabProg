#include<stdio.h>
   
   #define ILE_WIERZCH 4
   
   
   // Definicja wierzcholka grafu:
   typedef  struct ww {
     int numer;
     struct ww * lewy;
     struct ww * prawy;
   }  wierzch;
   
   // Graf jest tablica wierzcholkow:
   wierzch graf[ILE_WIERZCH];
   
   
   int main () {
   
     // Numerowanie wierzcholkow w grafie:
     for (int i=0; i<ILE_WIERZCH; i++)
       graf[i].numer = i;

   
     // Polaczenia miedzy wierzcholkami w grafie

     graf[0].prawy = &graf[1];
     graf[0].lewy = &graf[3];

     graf[1].prawy = &graf[3];
     graf[1].lewy = &graf[0];

     graf[2].prawy = &graf[1];
     graf[2].lewy = &graf[1];

     graf[3].prawy = &graf[3];
     graf[3].lewy = &graf[2];




     // Tablicowa reprezentacja grafu:
     int tab[ILE_WIERZCH][2];
     for (int i=0; i<ILE_WIERZCH; i++) {
       tab[i][0] = (graf[i].lewy)->numer;
       tab[i][1] = (graf[i].prawy)->numer;
     }
   
     // Wydruk tablicy:
     printf("\n    || L | P\n");
     printf(" ===++===+===\n");
     for (int i=0; i<ILE_WIERZCH; i++) {
       if (i!=0)  printf(" ---++---+---\n");
       printf("  %i || %i | %i\n",
              graf[i].numer, tab[i][0], tab[i][1]);
     }
     printf("\n");
   
     return 0;
   }
  