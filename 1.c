#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int uvecaj(int n){
	return n+1;
}

int kvadrat(int n){
	return n*n;
}

int negativan(int n){
	return -1*n;
}

void modifikuj(int* niz, int n, int (*modifikacija)(int)){
	int i;
	for(i=0; i<n; i++)
		niz[i] = modifikacija(niz[i]);
}

void ispis(int n, int* niz){
	int i;
	for(i=0; i<n; i++)
		printf("%d ", niz[i]);
	printf("\n");
}

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 0)
		greska();
		
	int *niz = NULL;
	niz = malloc(n*sizeof(int));
	if(niz == NULL)
		greska();
		
	for(int i=0; i<n; i++)
		scanf("%d", &niz[i]);
		
	printf("Uvecano za 1: ");
	modifikuj(niz, n, &uvecaj);
	ispis(n, niz);
	
	printf("Kvadrirano: ");
	modifikuj(niz, n, &kvadrat);
	ispis(n, niz);
	
	printf("Promenjen znak: ");
	modifikuj(niz, n, &negativan);
	ispis(n, niz);
	
	free(niz);

	return 0;
}
