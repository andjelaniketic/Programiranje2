#include <stdio.h>

/*void print_bits(unsigned x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		x&mask? printf("1") : printf("0");
	
		mask >>= 1;
	}
	printf("\n");
}*/

unsigned invertovanje(unsigned x, unsigned k, unsigned p){
	unsigned mask = 1;
	unsigned m2 = mask << (sizeof(int)*8-1);
	
	while(p > 0){
		x = x ^ m2;
		m2 >>= 1;
		p--;
	}
	while(k > 0){
		x = x ^ mask;
		mask <<= 1;
		k--;
	}
	return x;
}

int main(){
	unsigned x, k, p;
	scanf("%u%u%u", &x, &k, &p);
	
	unsigned rez = invertovanje(x, k, p);
	printf("%u\n", rez);
	
	//print_bits(x);
	//print_bits(rez);
	return 0;
}
