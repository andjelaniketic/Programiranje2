#include <stdio.h>
#include <stdlib.h>

#define max 32

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
	scanf("%d", &n);
	
	if(n <= 0 || n > 32)
		greska();
	
	unsigned int niz[max];
	
	int i;
	for(i=0; i<n; i++)
		scanf("%u", &niz[i]);
	
	unsigned rez = 0;
	unsigned mask = 1;
	
	for(i=0; i<n; i++){
		if(mask & niz[i]){
			rez = rez | mask;
		}
		mask <<= 1;
		
	}
	printf("%u\n", rez);
	
	return 0;
}
