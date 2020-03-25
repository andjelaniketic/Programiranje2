#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	char ime[MAX];
	scanf("%s", ime);
	
	FILE *ulaz = fopen(ime, "r");
	if(ulaz == NULL) greska();
	
	int n = 10;
	int niz[n];
	
	for(int i=0; i<n; i++)
		niz[i]=0;
	
	char c;
	while((c = fgetc(ulaz)) != EOF){
		if(isdigit(c)){
			niz[c-'0']++;
		}
	}
	int max = niz[0];
	int maxc = 0;
	for(int i=1; i<n; i++){
		if(niz[i] > max){
			max = niz[i];
			maxc = i;
		}
	}
	if(max == 0)
		greska();
	
	printf("%d %d\n", maxc, max);
	fclose(ulaz);
	return 0;
}
