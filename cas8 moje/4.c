#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 21

typedef struct{
	char ime[max];
	char prezime[max];
	char smer;
	float prosek;
}STUDENTI;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void unos(STUDENTI *niz, int n, FILE *f){
	int i;
	for(i=0; i<n; i++)
		fscanf(f, "%s %s %c %f", niz[i].ime, niz[i].prezime, &niz[i].smer, &niz[i].prosek);
	
}

void ispis(STUDENTI *niz, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%s %s %c %.1f\n", niz[i].prezime, niz[i].ime, niz[i].smer, niz[i].prosek);
}

void razmeni(STUDENTI *niz, int i, int j){
	STUDENTI tmp = niz[i];
	niz[i] = niz[j];
	niz[j] = tmp;
}

void insertion(STUDENTI *niz, int n){
	int i, j;
	for(i=1; i<n; i++)
		for(j=i; j>0; j--){
			if(niz[j].prosek > niz[j-1].prosek || 
				(niz[j].prosek == niz[j-1].prosek && strcmp(niz[j].prezime, niz[j-1].prezime) <0)
			)
				razmeni(niz, j, j-1);
			else break;
		}
	
}

int pozmin(STUDENTI *niz, int n, int i){
	int minp = i;
	int k;
	for(k=i+1; k<n; k++)
		if(niz[k].prosek < niz[minp].prosek ||
			(niz[k].prosek == niz[minp].prosek && niz[k].smer > niz[minp].smer)
		)
			minp = k;
			
	return minp;
}

void selection(STUDENTI *niz, int n){
	int i;
	for(i=0; i<n-1; i++)
		razmeni(niz, i, pozmin(niz, n, i));

}

int main(int argc, char ** argv){
	if(argc != 2)
		greska();
	
	FILE *f = fopen("studenti.txt", "r");
	if(f == NULL)
		greska();
	
	int n;
	fscanf(f, "%d", &n);
	if(n <= 0)
		greska();
	
	STUDENTI *niz = (STUDENTI*)malloc(n*sizeof(STUDENTI));
	if(niz == NULL)
		greska();
	
	unos(niz, n, f);
	
	if(!strcmp(argv[1], "-i"))
		insertion(niz, n);
	else if(!strcmp(argv[1], "-s"))
		selection(niz, n);
	else
		greska();
	
	ispis(niz, n);
	
	free(niz);
	fclose(f);
	return 0;
}
