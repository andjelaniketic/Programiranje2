#include <stdio.h>
#include <stdlib.h>

#define maxc 21
#define maxl 51
#define max 100

typedef struct{
	char bar_kod[maxc];
	char ime[maxl];
	char proizvodjac[maxl];
	float cena;
}artikli;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	char dat[maxc];
	scanf("%s", dat);
	FILE *f = fopen(dat, "r");
	if(f == NULL)
		greska();
	
	artikli *niz = malloc(max*sizeof(artikli));
	if(niz == NULL)
		greska();
	int i = 0;
	while(fscanf(f, "%s %s %s %f", niz[i].bar_kod, niz[i].ime, niz[i].proizvodjac, &niz[i].cena) != EOF){
		//realloc
		i++;
	}
	int n = i-1;
	char trazeni[maxc];
	
	while(1){
		scanf("%s", trazeni);
		if(strlen(trazeni) == 1)
			break;
		artikli *p = bsearch(trazeni, niz, n, sizeof(artikli), poredi);
		if(p == NULL){
			printf("Nepostojeci kod. Unesite ponovo\n");
			scanf(
		}
	}
	
	fclose(f);
	return 0;
}
