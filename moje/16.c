#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	char ime1[MAX];
	char ime2[MAX];
	scanf("%s%s", ime1, ime2);
	
	FILE *ulaz = fopen(ime1, "r");
	if(ulaz == NULL) greska();
	FILE *izlaz = fopen(ime2, "w");
	if(izlaz == NULL) greska();
	
	char c;
	while((c = fgetc(ulaz)) != EOF){
		if(isdigit(c)){
			fprintf(izlaz, "0");
		}else if(isalpha(c)){
			fprintf(izlaz, "1");
		}else{
			fprintf(izlaz, "2");
		}
	}
	return 0;
}
