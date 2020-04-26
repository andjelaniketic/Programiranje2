#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxl 21

typedef struct{
	char ime[maxl];
	char prezime[maxl];
	char smer;
	float prosek;
}STUDENTI;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int poredi(const void *a, const void *b){
	char *pr = (char*)a;
	STUDENTI s = *(STUDENTI*)b;
	
	return strcmp(pr, s.prezime);
}

int bin_rek(STUDENTI *niz, int l, int d, char *pr){
	if(l > d)
		return -1;
	
	int s = l+(d-l)/2;
	int rez = strcmp(niz[s].prezime, pr);
	if(rez == 0)
		return s;
	else if(rez < 0)
		return bin_rek(niz, s+1, d, pr);
	else
		return bin_rek(niz, l, s-1, pr);
	
}

int main(){
	FILE *f = fopen("studenti.txt", "r");
	if(f == NULL)
		greska();
	
	char unos[maxl];
	scanf("%s", unos);
	
	int n;
	fscanf(f, "%d", &n);
	if(n <= 0)
		greska();
	
	STUDENTI *niz = malloc(n*sizeof(STUDENTI));
	if(niz == NULL)
		greska();
	
	for(int i=0; i<n; i++){
		fscanf(f, "%s %s %c %f", niz[i].ime, niz[i].prezime, &niz[i].smer, &niz[i].prosek);
	}
	
	STUDENTI *s = bsearch(unos, niz, n, sizeof(STUDENTI), poredi); 
	
	if(s == NULL)
		printf("bs: nema\n");
	else
		printf("bs: %s %s %c %.2f\n", s->ime, s->prezime, s->smer, s->prosek);
	
	int p = bin_rek(niz, 0, n-1, unos);
	
	if(p == -1)
		printf("bin: nema\n");
	else{
		printf("Svi studenti sa prezimenom %s: \n", unos);
		while(1){
			if(strcmp(niz[p].prezime, unos) != 0 || p == n)
				break;
			printf("%s %s %c %.2f\n", niz[p].ime, niz[p].prezime, niz[p].smer, niz[p].prosek);
			p++;
		}
	}
	
	free(niz);
	fclose(f);
	return 0;
}
