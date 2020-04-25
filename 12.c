#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int rastuce(char *a){
	int n = strlen(a);
	int i;
	for(i=1; i<n; i++){
		if((a[i-1]-'0') >= (a[i]-'0'))
			return 0;
	}
	return 1;
}

int main(int argc, char **argv){
	
	int n = argc;
	int brojac=0;
	
	for(int i=0; i<n; i++){
		if(rastuce(argv[i])){
			brojac++;
		}
	}
	
	printf("%d\n", brojac);
	
	return 0;
}
