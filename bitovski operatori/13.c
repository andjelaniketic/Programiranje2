#include <stdio.h>

union broj{
	int intvr;
	float flvr;
};

void print_bits(int x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}


int main(){
	union broj a;
	
	scanf("%f", &a.flvr);
	
	print_bits(a.intvr);
	
	return 0;
}
