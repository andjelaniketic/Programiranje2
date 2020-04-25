#include <stdio.h>
#include <stdlib.h>
#define korak 10
#define max 21

typedef struct{
	char ime[max];
	int zaduzenje;
} tip;

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	FILE *f = fopen("saldo.txt", "r");
	if(f == NULL)
		greska();
	
	tip *korisnici = NULL;
	korisnici = malloc(100*sizeof(tip));
	if(korisnici == NULL)
		greska();
	
	int i = 0;
	int prosek = 0;
	int zaduzeni = 0;
	while(fscanf(f, "%s %d", korisnici[i].ime, &korisnici[i].zaduzenje) != EOF){
		if(korisnici[i].zaduzenje < 0){
			zaduzeni++;
			prosek += korisnici[i].zaduzenje;
		}
		i++;
	}
	
	prosek /= zaduzeni;
	int n = i;
	for(i=0; i<n; i++){
		if(korisnici[i].zaduzenje < prosek){
			printf("%s\n", korisnici[i].ime);
		}
	}
	
	free(korisnici);
	fclose(f);
	return 0;
}
