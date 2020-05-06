#include <stdio.h>

void print_bits(unsigned x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

void ispow2(int x){
	unsigned mask = 1;
	int brojac = 0;
	
	while(mask){
		if(x&mask)
			brojac++;
	
		mask <<=1;
	}
	
	if(brojac == 1)
		printf("jeste\n");
	else
		printf("nije\n");
}

int main(){
	int x;
	scanf("%d", &n);
	
	ispow2(x);
	
	return 0;
}
