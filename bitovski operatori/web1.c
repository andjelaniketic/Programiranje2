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

unsigned invertujSvakiTreci(unsigned x){
	unsigned mask = 1;
	
	while(mask){
		x = x ^ mask;
		mask <<= 3;
	}
	return x;
}
int main(){
	unsigned x;
	scanf("%u", &x);
	
	unsigned rez = invertujSvakiTreci(x);
	
	//print_bits(x);
	//print_bits(rez);
	
	printf("%u\n", rez);
	
	return 0;
}
