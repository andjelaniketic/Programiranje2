#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 51

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void ispis(char **niske, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%s ", niske[i]);
	printf("\n");
	
}

void razmeni(char**niske, int i, int j){
	char tmp[max];
	strcpy(tmp, niske[i]);
	strcpy(niske[i], niske[j]);
	strcpy(niske[j], tmp);
}

void insertion(char **niske, int n){
	int i, j;
	for(i=1; i<n; i++){
		for(j=i; j>0 && strcmp(niske[j], niske[j-1]) <=0; j--)
			razmeni(niske, j, j-1);
	}
}

int pozmin(char **niske, int n, int i){
	int minpoz = i;
	int j;
	for(j=i+1; j<n; j++)
		if(strcmp(niske[j], niske[minpoz])<0)
			minpoz = j;
	
	return minpoz;
}

void selection(char **niske, int n){
	int i;
	for(i=0; i<n-1; i++)
		razmeni(niske, i, pozmin(niske, n, i));
	
}

void insertion_opadajuce(char **niske, int n){
	int i,j;
	for(i=0; i<n; i++){
		for(j=i; j>0 && strcmp(niske[j], niske[j-1])>0; j--)
			razmeni(niske, j, j-1);
	}
}

int pozmax(char **niske, int n, int i){
	int maxp = i;
	int j;
	for(j=i+1; j<n; j++)
		if(strcmp(niske[j], niske[maxp])>0)
			maxp = j;
	return maxp;
}
void selection_opadajuce(char **niske, int n){
	int i;
	for(i=0; i<n-1; i++)
		razmeni(niske, i, pozmax(niske, n, i));
	
}

int main(int argc, char **argv){
	if(argc != 2)
		greska();
	
	int n;
	scanf("%d", &n);
	if(n <= 0)
		greska();
	
	char **niske = (char**)malloc(n*sizeof(char*));
	if(niske == NULL)
		greska();
	int i;
	for(i=0; i<n; i++){
		niske[i] = (char*)malloc(max*sizeof(char));
		if(niske[i] == NULL)
			greska();
	}
	
	for(i=0; i<n; i++)
		scanf("%s", niske[i]);
	
	if(!strcmp(argv[1], "-i"))
		insertion(niske, n);
	else if(!strcmp(argv[1], "-s"))
		selection(niske, n);
	else if(!strcmp(argv[1], "-ir"))
		insertion_opadajuce(niske, n);
	else if(!strcmp(argv[1], "-sr"))
		selection_opadajuce(niske, n);
	else
		greska();
	
	ispis(niske, n);
	
	for(i=0; i<n; i++)
		free(niske[i]);
	free(niske);
	return 0;
}
