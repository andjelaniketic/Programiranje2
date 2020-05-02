#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void unos(double *niz, int n){
	int i;
	for(i=0; i<n; i++)
		scanf("%lf", &niz[i]);
}

void ispis(double *niz, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%.2lf ", niz[i]);
	printf("\n");
}

void razmeni(double *niz, int a, int b){
	double tmp = niz[a];
	niz[a] = niz[b];
	niz[b] = tmp;
}

void insertion(double *niz, int n){
	int i, j;
	for(i=0; i<n; i++)
		for(j=i; j>0 && niz[j]<niz[j-1]; j--)
			razmeni(niz, j, j-1);
}

int pozmin(double *niz, int n, int i){
	int minp = i;
	int j;
	for(j=i; j<n; j++)
		if(niz[j] < niz[minp])
			minp = j;
	return minp;
}

void selection(double *niz, int n){
	int i;
	for(i=0; i<n-1; i++)
		razmeni(niz, i, pozmin(niz, n, i));
	
	
}

void merge(double *a, int m, double *b, int n, double *c){
	int i=0; int j=0; int k=0;
	while(i<m && j<n)
		c[k++] = a[i]<b[j]?a[i++]:b[j++];
	while(i<m)
		c[k++] = a[i++];
	while(j<n)
		c[k++] = b[j++];
}

void mergesort_(double *niz, int l, int d, double *tmp){
	if(l<d){
		int i, j;
		int n = d-l+1;
		int s = l+n/2;
		int n1 = n/2;
		int n2 = n - n/2;
		
		mergesort_(niz, l, s-1, tmp);
		mergesort_(niz, s, d, tmp);
		
		merge(niz+l, n1, niz+s, n2, tmp);
		
		for(i=l, j=0; i<=d; i++, j++)
			niz[i] = tmp[j];
		
	}
}

void mergesort(double *niz, int n){
	double *tmp = (double*)malloc(n*sizeof(double));
	if(tmp == NULL)
		greska();
	
	mergesort_(niz, 0, n-1, tmp);
	free(tmp);
}

int izbor_pivota(double *niz, int l, int d){
	return l;
}

int particionisanje(double *niz, int l, int d){
	int pivot = l;
	int j;
	
	for(j=l+1; j<=d; j++)
		if(niz[j] < niz[l])
			razmeni(niz, ++pivot, j);
	razmeni(niz, l, pivot);
	return pivot;
}

void quicksort(double *niz, int l, int d){
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
	
	int n;
	scanf("%d", &n);
	if(n <= 0)
		greska();
	
	double *niz = (double*)malloc(n*sizeof(double));
	if(niz == NULL)
		greska();
	
	unos(niz, n);
	
	if(!strcmp(argv[1], "-i"))
		insertion(niz, n);
	else if(!strcmp(argv[1], "-s"))
		selection(niz, n);
	else if(!strcmp(argv[1], "-m"))
		mergesort(niz, n);
	else if(!strcmp(argv[1], "-q"))
		quicksort(niz, 0, n-1);
	else
		greska();
	
	ispis(niz, n);
	
	free(niz);
	return 0;
}
