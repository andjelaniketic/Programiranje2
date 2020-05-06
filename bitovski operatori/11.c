#include <stdio.h>

void print_bits(unsigned x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

int broj11(int x){
	unsigned mask = 3 << (sizeof(int)*8 -2);
	int brojac = 0;
	
	while(mask != 1){
		if((x & mask) == mask){
			brojac ++;
		}
		mask >>= 1;
	}
	return brojac;
}

int main(){
	int x;
	scanf("%d", &x);
	
	print_bits(x);
	printf("%d\n", broj11(x));
	return 0;
}
