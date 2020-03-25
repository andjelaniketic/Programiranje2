#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 51
#define maxime 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	char ime[maxime];
	scanf("%s", ime);
	
	FILE* ulaz = fopen(ime, "r");
	if(ulaz == NULL) greska();
	
	FILE* izlaz = fopen("6_rez.txt", "w");
	if(izlaz == NULL) greska();
	
	int n;
	fscanf(ulaz, "%d", &n);
	
	char niz[n][max];
	for(int i=0; i<n; i++){
		fscanf(ulaz, "%s", niz[i]);
		printf("%s ", niz[i]);
	}
	putchar('\n');
	
	for(int i=1; i<n; i++){
		if(strstr(niz[i], niz[0]) != NULL && strchr(niz[i], '_') != NULL)
			fprintf(izlaz, "%s\n", niz[i]);
	}
	
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
