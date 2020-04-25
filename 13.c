#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void f11(int *a, int n, int x){
	if(n == 0 || n == 1)
		return;
	
	int *p = a;
	
	if(p[0] + p[1] == x){
		if(p[1] + p[2] != x){
			f11(p+2, n-2, x);
			a[0] = 0;
			a[1] = 0;
			a = a+2;
		}else{
			f11(p+2, n-2, x);
			a[0] = 0;
			a[1] = 0;
			a[2] = 0;
			a = a+2;
		}
	}else{
		f11(p+1, n-1, x);
		a = a+1;
	}
	
}

int main(){
	int x, n;
	scanf("%d %d", &x, &n);
	
	int *niz = malloc(n*sizeof(int));
	if(niz == NULL)
		greska();
	
	for(int i=0; i<n; i++)
		scanf("%d", &niz[i]);
	
	f11(niz, n, x);
	
	for(int i=0; i<n; i++)
		printf("%d ", niz[i]);
	
	printf("\n");
	
	free(niz);
	return 0;
}
