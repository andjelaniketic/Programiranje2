#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void f12(int *niz, int n){
	if(n == 0 || n == 1 || n == 2)
		return;
	int *p = niz;
	
	if(niz[0] + niz[2] == niz[1]){
		f12(p+1, n-1);
		niz[1] = 0;
	}else{
		f12(p+1, n-1);
	}
	
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
	
	f12(niz, n);
	
	for(int i=0; i<n; i++)
		printf("%d ", niz[i]);
	printf("\n");
	
	free(niz);
	return 0;
}
