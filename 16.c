#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}
int svi_parni(int *niz, int n){
	int rez = 1;
	for(int i=0; i<n; i++){
		if(abs(niz[i]) % 2 == 1){
			rez = 0;
			return rez;
		}
	}
	return rez;
	
}

int f16(int *a, int n){
	if(n == 0)
		return 1;
	if(a[n-1] % 2 != 0){
		return a[n-1]*f16(a, n-1);
	}else{
		return f16(a, n-1);
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
	
	int rez = f16(niz, n);
	if(svi_parni(niz, n)){
		printf("-\n");
	}else
		printf("%d\n", rez);
	
	free(niz);
	return 0;
}
