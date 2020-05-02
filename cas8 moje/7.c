#include <stdio.h>
#include <stdlib.h>

#define korak 10

typedef struct{
	double x;
	double y;
}tacke;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void ispis(tacke *niz, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%.2lf %.2lf\n", niz[i].x, niz[i].y);
}

void razmeni(tacke *niz, int i, int j){
	tacke tmp = niz[i];
	niz[i] = niz[j];
	niz[j] = tmp;
}

int izbor_pivota(tacke *niz, int l, int d){
	return l;
}

int particionisanje(tacke *niz, int l, int d){
	int pivot = l; int j;
	for(j=l+1; j<=d; j++)
		if(niz[j].x < niz[l].x || (niz[j].x == niz[l].x && niz[j].y > niz[l].y))
			razmeni(niz, ++pivot, j);
	razmeni(niz, l, pivot);
	return pivot;
}

void quicksort(tacke *niz, int l, int d){
	if(l<d){
		razmeni(niz, l, izbor_pivota(niz, l, d));
		
		int p = particionisanje(niz, l, d);
		
		quicksort(niz, l, p-1);
		quicksort(niz, p+1, d);
		
	}
}

int main(int argc, char **argv){
	if(argc != 2)
		greska();
	FILE *f = fopen(argv[1], "r");
	if(f == NULL)
		greska();
	
	tacke *niz = malloc(korak*sizeof(tacke));
	if(niz == NULL)
		greska();
	int alocirano = korak;
	int i=0;
	while(1){
		if(i == alocirano){
			alocirano += korak;
			niz = realloc(niz, alocirano*sizeof(tacke));
			if(niz == NULL)
				greska();
		}
		if(fscanf(f, "%lf %lf", &niz[i].x, &niz[i].y) != 2)
			break;
		i++;
	}
	
	int n = i;
	
	quicksort(niz, 0, n-1);
	
	ispis(niz, n);
	
	free(niz);
	fclose(f);
	return 0;
}
