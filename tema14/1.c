#include <stdio.h>
#include <stdlib.h>

#define max 21

typedef struct{
	char ime[max];
	int n;
	float *koef;
	float vrx;
}POLY;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void razmeni(POLY *niz, int a, int b){
	POLY tmp = niz[a];
	niz[a] = niz[b];
	niz[b] = tmp;
}

void sortiraj_po_vrx(POLY *niz, int br){
	int i, j;
	for(i=1; i<br; i++){
		for(j=i; j>0 && niz[j].vrx > niz[j-1].vrx; j--)
			razmeni(niz, j, j-1);
	}
}

int main(int argc, char** argv){
	if(argc != 2)
		greska();
	
	float x = atof(argv[1]);
	
	FILE *f = fopen("polinomi.txt", "r");
	if(f == NULL)
		greska();
	
	int brpolinoma;
	fscanf(f, "%d", &brpolinoma);
	if(brpolinoma <= 0)
		greska();
	
	POLY *niz = malloc(brpolinoma*sizeof(POLY));
	if(niz == NULL)
		greska();
	
	int i, j;
	for(i=0; i<brpolinoma; i++){
		fscanf(f, "%s %d", niz[i].ime, &niz[i].n);
		
		niz[i].koef = malloc(niz[i].n*sizeof(float));
		if(niz[i].koef == NULL)
			greska();
		
		for(j=0; j<niz[i].n; j++){
			fscanf(f, "%f", &niz[i].koef[j]);
		}
		niz[i].vrx = 0;
	}
	
	for(i=0; i<brpolinoma; i++){
		for(j=niz[i].n-1; j>=0; j--){
			niz[i].vrx = niz[i].vrx * x + niz[i].koef[j];
		}
	}
	
	sortiraj_po_vrx(niz, brpolinoma);
	
	for(i=0; i<brpolinoma; i++){
		printf("%s ", niz[i].ime);
		
		/*for(j=0; j<niz[i].n; j++)
			printf("%.2f ", niz[i].koef[j]);*/
		printf("%.2f\n", niz[i].vrx);
	}
	
	
	for(i=0; i<brpolinoma; i++)
		free(niz[i].koef);
	free(niz);
	fclose(f);
	return 0;
}
