#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
	if(argc != 4)
		greska();
	
	int n = atoi(argv[1]);
	int a = atoi(argv[2]);
	int b = atoi(argv[3]);
	
	if(n> 200 || a >= b)
		greska();
	
	srand(time(NULL));
	
	for(int i=0; i<n; i++){
		printf("%d ", (int)(a + (b-a)*((float)rand()/RAND_MAX)));
	}
	return 0;
}
