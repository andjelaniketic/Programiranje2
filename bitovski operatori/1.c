#include <stdio.h>

void printf_bits(int x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

int main(){
	int x;
	scanf("%d", &x);
	
	printf_bits(x);
	
	return 0;
}
