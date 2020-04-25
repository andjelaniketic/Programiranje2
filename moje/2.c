#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}
//provera da li je niz[s] blizi x-u od niz[s+-1]
bool provera(int *niz, int n, int s, int x){
	int razlika = abs(niz[s] - x);
	
	if(s>0 && s<n-1)
		return razlika < abs(niz[s-1]-x) && razlika <= abs(niz[s+1]-x);
	else if(s > 0)
		return razlika < abs(niz[s-1]-x);
	else if(s < n-1)
		return razlika <= abs(niz[s+1]-x);
	
}

int bin_rek(int *niz, int l, int d, int x, int n){
	if(l > d)
		return -1;
	int s = l + (d-l)/2;
	
	if(provera(niz, n, s, x))
		return s;
	else if(niz[s] < x)
		return bin_rek(niz, s+1, d, x, n);
	else
		return bin_rek(niz, l, s-1, x, n);
	
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
	
	int poz = bin_rek(niz, 0, n-1, x, n);
	printf("%d\n", niz[poz]);
	
	free(niz);
	return 0;
}
