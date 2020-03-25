#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	if(argc != 3)
		greska();
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	if(a > b)
		greska();
		
	for(int i=a; i<=b; i++)
		printf("%d ", i);
	putchar('\n');
	return 0;
}
