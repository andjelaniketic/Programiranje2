#include <stdio.h>
#include <stdlib.h>

#define max 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main (){
	char ime1[max];
	char ime2[max];
	
	scanf("%s %s", ime1, ime2);
	
	FILE *ulaz = fopen(ime1, "r");
	if(ulaz == NULL) greska();
	
	FILE *izlaz = fopen(ime2, "w");
	if(izlaz == NULL) greska();
	
	char c;
	int i = 1;
	while((c = fgetc(ulaz)) != EOF){
		if(i%2 == 0)
			fprintf(izlaz, "%c", c);
		i++;
	}
	
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
