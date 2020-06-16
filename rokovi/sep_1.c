#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21
#define korak 10

typedef struct{
	char grad[MAX];
	double plata;
	//int broj_pojavljivanja;
}STRUCT;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void swap(STRUCT *niz, int a, int b){
	STRUCT tmp = niz[a];
	niz[a] = niz[b];
	niz[b] = tmp;
}

void umetni(STRUCT *niz, int i){
	int j;
	for(j=i; j>0; j--){
		if((strcmp(niz[j].grad, niz[j-1].grad) < 0) || (strcmp(niz[j].grad, niz[j-1].grad) == 0 && niz[j].plata > niz[j-1].plata))
			swap(niz, j, j-1);
	}
}

void sort_1(STRUCT *niz, int n){
	int i;
	for(i=1; i<n; i++)
		umetni(niz, i);
}

int main(int argc, char** argv){
	if(argc != 2)
		greska();
	int k = atoi(argv[1]);
	if(k < 1)
		greska();
	
	FILE *f = fopen("plate.txt", "r");
	if(f == NULL)
		greska();
	
	STRUCT *niz = malloc(korak*sizeof(STRUCT));
	if(niz == NULL)
		greska();
	
	int i=0;
	int alocirano = korak;
	
	while(1){
		if(i == alocirano){
			alocirano+=korak;
			niz = realloc(niz, alocirano*sizeof(STRUCT));
			if(niz== NULL)
				greska();
		}
		if(fscanf(f, "%s %lf", niz[i].grad, &niz[i].plata) == EOF)
			break;
		i++;
	}
	
	int n = i;
	
	sort_1(niz, n);
	
	if(n!=0){
		char tmp_grad[MAX];
		strcpy(tmp_grad, niz[0].grad);
		int ispisano = 0;
		
		for(i=0; i<n; i++){
			if(ispisano < k){
				if(strcmp(tmp_grad, niz[i].grad) == 0){
					printf("%s %.3lf\n", niz[i].grad, niz[i].plata);
					ispisano++;
				}
				else{
					printf("%s %.3lf\n", niz[i].grad, niz[i].plata);
					strcpy(tmp_grad, niz[i].grad);
					ispisano = 1;
				}
			}
			else{
				if(strcmp(tmp_grad, niz[i].grad) == 0)
					continue;
				else{
					printf("%s %.3lf\n", niz[i].grad, niz[i].plata);
					strcpy(tmp_grad, niz[i].grad);
					ispisano = 1;
				}
			}
			
		}
		
	}
	
	
	free(niz);
	fclose(f);
	return 0;
}
