#include <stdio.h>

void print_bits(unsigned x){
	unsigned mask = 1 << sizeof(int)*8-1;
	
	while(mask){
		mask&x? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

unsigned right_rotate(unsigned x, int n){
	unsigned m1 = 1;
	unsigned m2 = m1 << (sizeof(int)*8 -1);
	
	int i;
	for(i=0; i<n; i++){
		if(x & m1){
			x = x >> 1;
			x = x | m2;
		}
		else
			x = x >> 1;
	}
	return x;
}
int main(){
	unsigned x;
	int n;
	scanf("%u%d", &x, &n);
	
	if(n<0)
		printf("greska");
	
	unsigned rez = right_rotate(x, n);
	
	print_bits(x);
	print_bits(rez);
	
	return 0;
}
