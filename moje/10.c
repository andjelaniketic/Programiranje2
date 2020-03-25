#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxlinija 201

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	if(argc != 3) greska();
	
	FILE *prva = fopen(argv[1], "r");
	if(prva == NULL) greska();
	
	FILE *druga = fopen(argv[2], "r");
	if(druga == NULL) greska();
	
	char linija[maxlinija];
	char linija2[maxlinija];
	int n = 1;
	
	while(fgets(linija, maxlinija, prva) != NULL && fgets(linija2, maxlinija, druga) != NULL){
		if(strcmp(linija, linija2) != 0)
			printf("%d\n", n);
		n++;
	}
	while(fgets(linija, maxlinija, prva)!= NULL){
		printf("%d ", n);
		n++;
	}
	while(fgets(linija2, maxlinija, druga) != NULL){
		printf("%d ", n);
		n++;
	}	
	fclose(prva);
	fclose(druga);
	return 0;
}
