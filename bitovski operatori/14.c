#include <stdio.h>

void print_bits(unsigned x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}


int main(){
	unsigned x;
	
	scanf("%d", &x);
	
	unsigned int mask = 0xF;
	//0000 0000 0000 0000 0000 0000 0000 1111
	
	char niska[8];
	int i=7;
	
	while(i >= 0){
		int vr = x & mask;
		if(vr < 10)
			niska[i] = vr + '0';
		else
			niska[i] = vr - 10 + 'A'; //10 - 10 = 0 + 'A' = A itd
		
		x = x >> 4;
		i--;
	}
	
	for(i=0; i<8; i++)
		printf("%c", niska[i]);
	printf("\n");
	
	return 0;
}
