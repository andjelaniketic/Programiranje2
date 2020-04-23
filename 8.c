#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void svaka_nta_rec(char *ime, int n){
	FILE *f = fopen(ime, "r");
	if(f == NULL)
		greska();
	char rec[10];
	int brojac = 0;
	
	while(fscanf(f, "%s", rec) != EOF){
		brojac++;
		if(brojac == n){
			printf("%s ", rec);
			brojac = 0;
		}
	}
	printf("\n");
	
}
int main(int argc, char **argv){
	if(argc != 3)
		greska();
	
	
	int n = atoi(argv[2]);
	if(n <= 0)
		greska();
	
	svaka_nta_rec(argv[1], n);
	
	return 0;
}
