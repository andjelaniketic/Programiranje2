#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define korak 10

typedef struct{
	double x;
	double y;
	double d;
}tacke;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void ispis(tacke *niz, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%.2lf %.2lf %.2lf\n", niz[i].x, niz[i].y, niz[i].d);
}

void razmeni(tacke *niz, int i, int j){
	tacke tmp = niz[i];
	niz[i] = niz[j];
	niz[j] = tmp;
}

void insertion(tacke *niz, int n){
	int i, j;
	for(i=1; i<n; i++)
		for(j=i; j>0 && niz[j].d < niz[j-1].d; j--)
			razmeni(niz, j, j-1);
	
}

int main(){
	FILE *f = fopen("tacke.txt", "r");
	if(f == NULL)
		greska();
	
	double ax, ay;
	scanf("%lf %lf", &ax, &ay);
	
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
		else{
			niz[i].d = sqrt(pow(ax-niz[i].x, 2)+pow(ay-niz[i].y, 2));
		}
		i++;
	}
	
	int n = i;
	
	insertion(niz, n);
	
	ispis(niz, n);
	
	free(niz);
	fclose(f);
	return 0;
}
