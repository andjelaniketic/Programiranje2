#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define k 10
#define cifre 17

typedef struct{
	char card[cifre];
	float iznos;
} STRUCT;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int postoji(STRUCT *niz, char *kartica, int n){
	int i;
	for(i=0; i<n; i++){
		if(!strcmp(niz[i].card, kartica))
			return i;
	}
	return -1;
}

void swap(STRUCT *niz, int i, int j){
	STRUCT tmp = niz[i];
	niz[i] = niz[j];
	niz[j] = tmp;
}

void umetni(STRUCT *niz, int i){
	int j;
	for(j=i; j>0; j--){
		if(strcmp(niz[j].card, niz[j-1].card) < 0)
			swap(niz, j, j-1);
	}
}

void sort1(STRUCT *niz, int n){
	int i;
	for(i=1; i<n; i++){
		umetni(niz, i);
	}
}


void umetni2(STRUCT *niz, int i){
	int j;
	for(j=i; j>0 && niz[j].iznos > niz[j-1].iznos; j--)
		swap(niz, j, j-1);
}

void sort2(STRUCT *niz, int n){
	int i;
	for(i=1; i<n; i++)
		umetni2(niz, i);
	
}

int main(int argc, char** argv){
	if(argc != 4)
		greska();
	
	int n = strlen(argv[1]) + strlen(argv[2]) + 6;
	
	char *ime_datoteke = malloc(n*sizeof(char));
	if(ime_datoteke == NULL)
		greska();
	
	ime_datoteke = strcat(ime_datoteke, argv[1]);
	ime_datoteke = strcat(ime_datoteke, "_");
	ime_datoteke = strcat(ime_datoteke, argv[2]);
	ime_datoteke = strcat(ime_datoteke, ".txt");
	
	FILE *f = fopen(ime_datoteke, "r");
	if(f == NULL)
		greska();
	
	STRUCT *niz = malloc(k*sizeof(STRUCT));
	if(niz == NULL)
		greska();
	
	int alocirano = k;
	int i = 0;
	int j;
	
	char kartica[cifre];
	float iznos_tmp;
	
	if(fscanf(f, "%s %f", kartica, &iznos_tmp) == 2){
		strcpy(niz[i].card, kartica);
		niz[i].iznos = iznos_tmp;
		i++;
	}
	
	while(fscanf(f, "%s %f", kartica, &iznos_tmp) == 2){
		if(i == alocirano){
			alocirano += k;
			niz = realloc(niz, alocirano*sizeof(STRUCT));
			if(niz == NULL)
				greska();
		}
		int rez = postoji(niz, kartica, i);
		if(rez == -1){
			strcpy(niz[i].card, kartica);
			niz[i].iznos = iznos_tmp;
			i++;
		}else{
			niz[rez].iznos += iznos_tmp;
		}
	}
	
	n = i;
	
	if(!strcmp(argv[3], "-kartica"))
		sort1(niz, n);
	else if(!strcmp(argv[3], "-suma"))
		sort2(niz, n);
	else
		greska();
	
	
	for(i=0; i<n; i++)
		printf("%s %.2f\n", niz[i].card, niz[i].iznos);
	
	free(niz);
	free(ime_datoteke);
	fclose(f);
	return 0;
}
