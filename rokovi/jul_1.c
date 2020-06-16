#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21
#define korak 10

typedef struct{
	char ime[MAX];
	char prezime[MAX];
	int indeks;
	int godina;
	int poeni;
}STRUCT;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void ispisi(STRUCT *niz, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%s %s %d/%d %d\n", niz[i].ime, niz[i].prezime, niz[i].indeks, niz[i].godina, niz[i].poeni);
}

void swap(STRUCT *niz, int a, int b){
	STRUCT tmp = niz[a];
	niz[a] = niz[b];
	niz[b] = tmp;
}

void umetni(STRUCT *niz, int i){
	int j;
	for(j=i; j>0; j--){
		if(niz[j].poeni > niz[j-1].poeni)
			swap(niz, j, j-1);
		else if(niz[j].poeni == niz[j-1].poeni){
			if(strcmp(niz[j].prezime, niz[j-1].prezime) < 0)
				swap(niz, j, j-1);
		}
		
	}
}

void sort(STRUCT *niz, int n){
	int i;
	for(i=1; i<n; i++){
		umetni(niz, i);
	}
	
}

int main(int argc, char** argv){
	if(argc != 2)
		greska();
	
	FILE *f = fopen(argv[1], "r");
	if(f == NULL)
		greska();
	
	STRUCT *niz = malloc(korak*sizeof(STRUCT));
	if(niz == NULL)
		greska();
	
	int i=0;
	int alocirano = korak;
	
	while(fscanf(f, "%s %s %d/%d %d", niz[i].ime, niz[i].prezime, &niz[i].indeks, &niz[i].godina, &niz[i].poeni) == 5){
		if(i == alocirano){
			alocirano += korak;
			niz = realloc(niz, alocirano);
			if(niz == NULL)
				greska();
		}
		i++;
	}
	
	int n = i;
	sort(niz, n);
	
	ispisi(niz, n);
	
	free(niz);
	fclose(f);
	return 0;
}
