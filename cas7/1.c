#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int linearna(int *niz, int n, int x){
	for(int i=0; i<n; i++){
		if(niz[i] == x)
			return i;
	}
	return -1;
}

int bin_it(int *niz, int n, int x){
	int l = 0;
	int d = n-1;
	int s;
	
	while(l <= d){
		s = l + (d-l)/2;
		if(niz[s] == x)
			return s;
		else if(niz[s] < x)
			l = s+1;
		else
			d = s-1;
	}
	return -1;
}

int bin_rek(int* niz, int l, int d, int x){
	if(l > d)
		return -1;
	
	int s = l + (d-l)/2;
	if(niz[s] == x)
		return s;
	else if(niz[s] < x)
		return bin_rek(niz, s+1, d, x);
	else
		return bin_rek(niz, l, s-1, x);
}

int poredi(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 0)
		greska();
	
	int *niz = malloc(n*sizeof(int));
	if(niz == NULL)
		greska();
	for(int i=0; i<n; i++)
		scanf("%d", &niz[i]);
	
	int x;
	scanf("%d", &x);
	
	printf("Linearna: %d\n", linearna(niz, n, x));
	printf("Binarna iterativno: %d\n", bin_it(niz, n, x));
	printf("Binarna rekurzivno: %d\n", bin_rek(niz, 0, n-1, x));
	int *p = bsearch(&x, niz, n, sizeof(int), &poredi);
	
	if(p == NULL)
		printf("bs: -1\n");
	else
		printf("bs: %ld\n", p-niz);
	
	free(niz);
	return 0;
}
