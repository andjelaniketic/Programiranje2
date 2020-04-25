#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int fact(int n){
	int rez = n;
	for(int i=n; i>0; i--){
		rez += i;
	}
	return rez;
}
int main(int argc, char **argv){
	if(argc != 2)
		greska();
	
	int n = strlen(argv[1]);
	int duzina = fact(n);
	char *niska = malloc(duzina*sizeof(char));
	if(niska == NULL)
		greska();
	
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			niska = strncat(niska, argv[1]+i, 1);
		}
	}
	
	printf("%s\n", niska);
	
	free(niska);
	return  0;
}
