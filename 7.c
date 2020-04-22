#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv){
	if(argc != 3)
		greska();
	int n = strlen(argv[2]);
	int i;
	char *rec = malloc(n*sizeof(char));
	if(rec == NULL)
		greska();
	strcpy(rec, argv[2]);
	
	if(strcmp(argv[1], "-m") == 0){
		for(i=0; i<n; i++){
			if(isalpha(rec[i]))
				rec[i] = tolower(rec[i]);
		}
	}
	else if(strcmp(argv[1], "-v") == 0){
		for(i=0; i<n; i++){
			if(isalpha(rec[i]))
				rec[i] = toupper(rec[i]);
		}
	}
	else if(strcmp(argv[1], "-mv") == 0){
		for(i=0; i<n; i++){
			if(isupper(rec[i]))
				rec[i] = tolower(rec[i]);
			else if(islower(rec[i]))
				rec[i] = toupper(rec[i]);
		}
	
	}else
		greska();
	
	printf("%s\n", rec);
	

	return 0;
}
