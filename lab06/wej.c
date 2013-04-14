#include<stdio.h>

int main(){
	int n,k,i,j;


	printf("Podaj n: ");
	scanf("%i", &n);
	printf("Podaj k: ");
	scanf("%i", &k);

	int tab[n][k];


	for(i=0; i<n; i++){
		tab[0][i]=1;

	}

	for(i=0; i<k; i++){
		tab[i][0]=1;
	}

	for(i=1; i<n; i++){
		for(j=1; j<k; j++){

			tab[i][j]=(tab[i-1][j]+tab[i][j-1]);
		}
	}



	printf("%i", tab[n-1][k-1]);

	return 0;
}