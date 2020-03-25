#include <stdio.h>
#include <stdlib.h>

#define MAX 81

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	FILE *knjiga;
	char linija[MAX];
	int brojlinija = 0;
	
	knjiga = fopen("knjiga.txt", "r");
	if(knjiga == NULL) greska();
	
	while(fgets(linija, MAX, knjiga) != NULL)
		brojlinija++;
	
	printf("%d\n", brojlinija);	
	return 0;
}
