#include <stdio.h>
#include <stdlib.h>

#define MAX 81

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	FILE *ulaz;
	FILE *izlaz;
	
	char linija[MAX];
	
	ulaz = fopen("ulaz.txt", "r");
	if(ulaz == NULL) greska();
	
	izlaz = fopen("izlaz.txt", "w");
	if(izlaz == NULL) greska();
	
	//char by char
	/*char c;
	while(fscanf(ulaz, "%c", &c) == 1)
		fprintf(izlaz,"%c", c);
	*/
	//line by line
	while(fgets(linija, MAX, ulaz) != NULL)
		fprintf(izlaz, "%s", linija);
		
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
