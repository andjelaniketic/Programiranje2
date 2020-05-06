#include <stdio.h>
#include <stdlib.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void print_bits(unsigned x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}


int main(){
	int n;
	unsigned int x;
	scanf("%d%u", &x, &n);
	
	if(n<=0 || n>32)
		greska();
	
	int *niz = malloc(n*sizeof(int));
	if(niz == NULL)
		greska();
	
	int i;
	for(i=0; i<n; i++)
		scanf("%d", &niz[i]);
	
	unsigned rez = 0;
	unsigned mask = 1;
	
	for(i=0; i<n; i++){
		if((x&mask) == (mask&niz[i])){
			rez = rez | mask;
		}
		mask <<= 1;
	}
	
	for(; i<32; i++){
		if((mask & x) == 0  )
			rez = rez | mask;
		mask <<= 1;
	}
	printf("%u\n", rez);
	
	free(niz);
	return 0;
}
