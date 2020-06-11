#include <stdio.h>

unsigned zameni(unsigned x){
	unsigned mask = 0xffff;
	mask = x & mask;
	mask <<= 4*sizeof(unsigned);
	x >>= 4*sizeof(unsigned);
	x = mask | x;
	return x;
}

int main(){
	unsigned x;
	scanf("%x", &x);
	
	x = zameni(x);
	
	printf("0x%x\n", x);
	
	return 0;
}
