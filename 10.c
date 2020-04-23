#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void neopadajuce(int **matrica, int n){
	int i;
	int j, k;
	int ispis = 0;
	for(i=0; i<n; i++){
		ispis = 0;
		for(j=1; j<n; j++){
			if(matrica[i][j-1] > matrica[i][j]){
				ispis = -1;
				break;
			}
		}
		if(ispis == 0)
			printf("%d ", i);
	}
	
}

int main(){
	
	FILE *f = fopen("matrica.txt", "r");
	if(f == NULL)
		greska();
	
	int n;
	fscanf(f, "%d", &n);
	if(n <= 0)
		greska();
	int **matrica = (int**)malloc(n*sizeof(int*));
	if(matrica == NULL)
		greska();
	
	int i;
	for(i=0; i<n; i++){
		matrica[i] = (int*)malloc(n*sizeof(int));
		if(matrica[i] == NULL)
			greska();
	}
	
	int j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			fscanf(f, "%d", &matrica[i][j]);
	}
	
	neopadajuce(matrica, n);
	/*
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			printf("%d ", matrica[i][j]);
	*/	
	for(i=0; i<n; i++)
		free(matrica[i]);
	free(matrica);
	return 0;
}
