#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51
#define maxime 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	char ime[maxime];
	scanf("%s", ime);
	
	FILE *ulaz;
	FILE *izlaz;
	
	ulaz = fopen(ime, "r");
	if(ulaz == NULL) greska();
	
	izlaz = fopen("rez.txt", "w");
	if(izlaz == NULL) greska();
	
	int n;
	fscanf(ulaz, "%d", &n);
	char niz[n][MAX];
	
	for(int i=0; i<n; i++){
		fscanf(ulaz, "%s", niz[i]);
		printf("%s ", niz[i]);
	}
	
	putchar('\n');
	
	int indikator = 0;
	
	for(int i=0; i<n; i++){
		indikator = 0;
		for(int k=0; k<i; k++){
			if(strcmp(niz[i], niz[k]) == 0){
				indikator = 1;
				break;
			}
		}
		if(!indikator){
			fprintf(izlaz, "%s\n", niz[i]);
		}
	
	}
	
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
