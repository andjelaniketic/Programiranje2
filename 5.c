#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int izmeni(int n){
	if(n == 0)
		return 0;
	int c = n%10;
	if(c%2 == 0)
		return izmeni(n/10)*10 + c/2;
	else
		return izmeni(n/10)*10 +c;
}

int main(int argc, char **argv){
	if(argc != 2)
		greska();
	
	int n = atoi(argv[1]);
	
	printf("%d\n", izmeni(n));
	return 0;
}
