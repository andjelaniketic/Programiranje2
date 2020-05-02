#include <stdio.h>
#include <stdlib.h>

#define max 21

typedef struct{
	char ime[max];
	float cena;
	float kolicina;
	float vrednost;
}PROIZVODI;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void unos(PROIZVODI* niz, int n, FILE *f){
	int i;
	for(i=0; i<n; i++){
		fscanf(f, "%s %f %f", niz[i].ime, &niz[i].cena, &niz[i].kolicina);
		niz[i].vrednost = niz[i].cena * niz[i].kolicina;
	}
}

void ispis(PROIZVODI *p, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%s %.2f %.2f %.2f\n", p[i].ime, p[i].cena, p[i].kolicina, p[i].vrednost);
}

void razmeni(PROIZVODI *p, int i, int j){
	PROIZVODI tmp = p[i];
	p[i] = p[j];
	p[j] = tmp;
}

void insertion(PROIZVODI *p, int n){
	int i, j;
	for(i=1; i<n; i++)
		for(j=i; j>0 && p[j].vrednost > p[j-1].vrednost; j--)
			razmeni(p, j, j-1);
	
}
int main(){
	FILE *f = fopen("proizvodi.txt", "r");
	if(f == NULL)
		greska();
	
	int n;
	fscanf(f, "%d", &n);
	if(n<=0)
		greska();
	
	PROIZVODI* p = (PROIZVODI*)malloc(n*sizeof(PROIZVODI));
	if(p == NULL)
		greska();
	
	unos(p, n, f);
	
	insertion(p, n);
	
	ispis(p, n);
	
	fclose(f);
	return 0;
}
