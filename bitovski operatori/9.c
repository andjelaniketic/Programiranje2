#include <stdio.h>

void print_bits(unsigned x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

unsigned mirror(unsigned x){
	unsigned m1 = 1;
	unsigned m2 = m1 << (sizeof(int)*8 -1);
	unsigned rez = 0;
	
	while(m1){
		if(m1 & x){
			rez = rez | m2;
		}
		m1 <<= 1;
		m2 >>= 1;
	}
	
	return rez;
}
int main(){
	unsigned int x;
	scanf("%u", &x);
	
	unsigned rez = mirror(x);
	
	print_bits(x);
	print_bits(rez);
	
	return 0;
}
