#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int ispalindrom(char *niska){
	int i;
	int n = strlen(niska);
	
	for(i=0; i<n/2; i++){
		if(niska[i] != niska[n-1])
			return 0;
		n--;
	}
	return 1;
}

int main(int argc, char **argv){
	int n = argc;
	if(n == 1)
		printf("0\n");
	
	int i;
	int brojac = 0;
	for(i=1; i<n; i++){
		if(ispalindrom(argv[i])){
			brojac++;
		}
	}
	
	printf("%d\n", brojac);

	return 0;
}
