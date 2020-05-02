#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
	float aX;
	float aY;
	float bX;
	float bY;
	float d;
}DUZI;

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void unos(DUZI *niz, int n, FILE *f)
{
	int i;
	for(i=0; i<n; i++){
		fscanf(f, "%f %f %f %f", &niz[i].aX, &niz[i].aY, &niz[i].bX, &niz[i].bY);
		niz[i].d = sqrtf(pow(niz[i].bX-niz[i].aX, 2) + pow(niz[i].bY-niz[i].aY, 2));
	}
}

void ispis(DUZI *niz, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%.2f %.2f %.2f %.2f %.2f\n", niz[i].aX, niz[i].aY, niz[i].bX, niz[i].bY, niz[i].d);
}

void razmeni(DUZI *niz, int i, int j)
{
	DUZI tmp = niz[i];
	niz[i] = niz[j];
	niz[j] = tmp;
}

void insertion(DUZI *niz, int n)
{
	int i, j;
	for(i=1; i<n; i++)
		for(j=i; j>0 && niz[j].d > niz[j-1].d; j--)
			razmeni(niz, j, j-1);
}

int main(int argc, char **argv)
{
	/*if(argc != 2)
		greska();
	*/
	FILE *f = fopen("duzi.txt", "r");
	if(f == NULL)
		greska();
	
	int n;
	fscanf(f, "%d", &n);
	if(n<=0)
		greska();
	
	DUZI *niz = (DUZI*)malloc(n*sizeof(DUZI));
	if(niz == NULL)
		greska();
	
	unos(niz, n, f);
	
	//if(!strcmp(argv[1], "-i"))
		insertion(niz, n);
	//else
	//	greska();
	
	ispis(niz, n);
	
	free(niz);
	fclose(f);
	return 0;
}
