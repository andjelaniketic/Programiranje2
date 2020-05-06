#include <stdio.h>

void print_bits(unsigned x){
	unsigned mask = 1 << sizeof(int)*8-1;
	
	while(mask){
		mask&x? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

unsigned invert_bits(unsigned x, int p, int n){
	unsigned mask = 0;
	mask = (~((~mask)<<n))<<p;
	
	return x^mask;
}

int main (){
	unsigned x;
	int p, n;
	
	scanf("%u %d %d", &x, &n, &p);
	if(p<0 || p+n >= sizeof(int)*8)
		return -1;
	
	unsigned rez = invert_bits(x, p, n);
	
	print_bits(x);
	print_bits(rez);
	
	return 0;
}
