#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	int n;
	scanf("%d", &n);
	
	int niz[n];
	for(int i=0; i<n; i++)
		scanf("%d", &niz[i]);
	
	for(int i=1; i<n; i++){
		if(niz[i-1] > niz[i]){
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}
