#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

/****************************************************************/
// DEFINICJA TYPU LICZB ZESPOLONYCH:

typedef struct {
  double rea, ima;
}  zespol;

/****************************************************************/
// POMOCNICZE:

void  err(char s[]) {  // -- sygnalizacja bledu wejscia
  printf("\n !!! FUNKCJA zesp_get: %s !!!\n\n", s);
  exit(1);
}

/****************************************************************/
// INICJALIZACJE oraz WEJSCIE-WYJSCIE:

zespol  zesp_zestawic (double r, double i) {
    // zestawienie liczby zespolonej z dwoch rzeczywistych
  zespol z;
  z.rea = r;  z.ima = i;
  return z;
}

zespol  zesp_get (void) {
    /* wczytanie liczby zespolonej; powinna skladac sie z dwoch
       rzeczywistych, oraz plusa lub minusa miedzy nimi, zaczynac sie od
       nawiasu otwierajacego, konczyc siê litera i oraz nawiasem
       zamykajacym;
       np.  (123.45 + 67.89i)
    */
  char ch;  zespol z;  int znak_im;
  do { ch = getchar(); } while (isspace(ch));
  if (ch == '(') {
    if (scanf("%lf", &(z.rea)) == 1) {
      do { ch = getchar(); } while (isspace(ch));
      if (ch == '+' || ch == '-') {
  if (ch == '+')  znak_im = 1;
  else  znak_im = -1;
  if (scanf("%lf", &(z.ima)) == 1) {
    do { ch = getchar(); } while (isspace(ch));
    if (ch == 'i') {
      do { ch = getchar(); } while (isspace(ch));
      if (ch == ')') {
        if (znak_im == -1)  z.ima = -z.ima;
      } else err("brak koncowego nawiasu");
    } else err("brak 'i' na koncu czesci urojonej");
  } else err("niepoprawna czesc urojona");
      } else err("po czesci rzeczywistej brak znaku '+' lub '-'");
    } else err("niepoprawna czesc rzeczywista");
  } else err("brak rozpoczynajacego nawiasu");
  return z;
}

void  zesp_print (zespol z) { // drukowanie liczby zespolonej
  if (z.ima >= 0)
    printf("(%.25lf+%.25lfi)", z.rea, z.ima);
  else
    printf("(%.25lf-%.25lfi)", z.rea, -z.ima);
}

zespol jedynka(){
  zespol jeden;
  jeden.rea = 1;
  jeden.ima = 0;

  return jeden;
}
/****************************************************************/
// DZIALANIA:

zespol  zesp_dodac (zespol z1, zespol z2){
  zespol wynik;
  wynik.rea = z1.rea + z2.rea;
  wynik.ima = z1.ima + z2.ima;
  return wynik;
  }

zespol  zesp_odjac (zespol z1, zespol z2){
  zespol wynik;
  wynik.rea = z1.rea - z2.rea;
  wynik.ima = z1.ima - z2.ima;
  return wynik;
}

zespol  zesp_razy (zespol z1, zespol z2){
  zespol wynik; double pom;
  wynik.rea = (z1.rea * z2.rea);
  pom = z2.ima * z1.ima;
  pom *= -1;
  wynik.rea += pom;
  wynik.ima = (z1.rea * z2.ima) + (z1.ima * z2.rea);

return wynik;
}

zespol  zesp_sprzez (zespol z){
  z.ima *= -1;
  return z;
}

double  zesp_abs (zespol z){
    return sqrt(pow(z.rea,2) + pow(z.ima,2));
}

zespol euler(zespol z){
  z.rea = cos(M_PI);
  z.ima = sin(M_PI);
  return z;
}

zespol zesp_dziel(zespol z, int a){
  zespol wynik;
  wynik.rea = z.rea / a;
  wynik.ima = z.ima / a;
  return wynik;
}

zespol zesp_exp(zespol z){
  zespol suma = {0.0, 0.0}, skl = {1.0, 0.0};
  int i;
  for(i = 1; i<10000; i++){
    suma = zesp_dodac(suma, skl);
    skl = zesp_dziel(zesp_razy(skl,z),i);
  }
  return suma;
}

/****************************************************************/


int main () {
  zespol  z1, z2;
  zespol eul,jed;
  eul = euler(z1);
  jed =  jedynka();
  zespol jedd = {1.0 , 0.0};
  zespol pi_i = {0.0 , M_PI};
  /*
  printf("\n z1 == "); z1 = zesp_get();
  printf(" z2 == "); z2 = zesp_get();

  zesp_print(z1);
  printf("\n Wynik Dodawania = ");
  zesp_print(zesp_dodac(z1,z2));
  printf("\n Wynik Odejmowania = ");
  zesp_print(zesp_odjac(z1,z2));
  printf("\n Wynik Mnozenia = ");
  zesp_print(zesp_razy(z1,z2));
  printf("\n Wynik Sprzezenia = ");
  zesp_print(zesp_sprzez(z1));
  printf("\n |z1+z2| == %.4lf\n\n", zesp_abs(zesp_dodac(z1, z2)));
  printf("\n Euler = ");
  zesp_print(zesp_dodac(eul,jed));
  */
  printf("\n Wynik zesp_exp = ");
  zesp_print(zesp_dodac(zesp_exp(pi_i), jedd));


  return 0;
}
