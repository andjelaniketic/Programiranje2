#include <stdio.h>

unsigned izmeni(unsigned x){
	unsigned mask = 0xF;
	while(mask != 0){
		x = x | mask;
		mask <<= 2*sizeof(unsigned);
	}
	return x;
}

int main(){
	unsigned x;
	scanf("%x", &x);
	
	unsigned rez = izmeni(x);
	printf("0x%x\n", rez);
	return 0;
}
