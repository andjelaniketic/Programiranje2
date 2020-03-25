#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 21

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	char s1[MAX];
	char s2[MAX];
	char c;
	
	scanf("%s %s %c", s1, s2, &c);
	
	if(c != 'u' && c != 'l') greska();
	
	FILE *prvi;
	FILE *drugi;
	
	prvi = fopen(s1, "r");
	if(prvi == NULL) greska();
	
	drugi = fopen(s2, "w");
	if(drugi == NULL) greska();
	
	char k;
	if(c == 'u'){
		while((k = fgetc(prvi)) != EOF)
			fputc(toupper(k), drugi);
	}else if(c == 'l'){
		while((k = fgetc(prvi)) != EOF)
			fputc(tolower(k), drugi);
	}
	
	fclose(prvi);
	fclose(drugi);
	return 0;
}
