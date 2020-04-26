#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int bin_rek(char **niz, int l, int d, char *trazena){
	if(l > d)
		return -1;
	int s = l + (d-l)/2;
	
	if(strcmp(niz[s], trazena) == 0)
		return s;
	else if(strcmp(niz[s], trazena) > 0)
		return bin_rek(niz, l, s-1, trazena);
	else
		return bin_rek(niz, s+1, d, trazena);
	
}

int poredi(const void* a, const void *b){
	
	return strcmp((char*)a, *(char**)b);
}

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 0)
		greska();
	
	char **reci;
	reci = (char**)malloc(n*sizeof(char*));
	if(reci == NULL)
		greska();
	
	for(int i=0; i<n; i++){
		reci[i] = (char*)malloc(max*sizeof(char));
		if(reci[i] == NULL)
			greska();
	}
	for(int i=0; i<n; i++)
		scanf("%s", reci[i]);
	
	char trazena[max];
	scanf("%s", trazena);
	
	int poz = bin_rek(reci, 0, n-1, trazena);
	printf("bin_rek: %d\n", poz);
	
	char **p = bsearch(trazena, reci, n, sizeof(char*), poredi);
	printf("bs: %ld\n", p-reci);
	
	for(int i=0; i<n; i++)
		free(reci[i]);
	free(reci);
	return 0;
}
