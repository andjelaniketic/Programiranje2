#include <stdio.h>

void print_bits(unsigned x){
	unsigned mask = 1 << (sizeof(int)*8 -1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

int najveci(int x){
	unsigned m1 = 1;
	int rez = 0;
	unsigned m2 = m1 << (sizeof(int)*8 -2); //0 na pocetku za znak
	while(m1){
		if(m1 & x){
			rez = rez | m2;
			m2 >>= 1;
		}
		m1 <<= 1;
	}
	return rez;
}

int najmanji(int x){
	unsigned m1 = 1;
	unsigned m2 = m1;
	
	int rez = 0;
	while(m1){
		if(m1 & x){
			rez = rez | m2;
			m2 <<= 1;
		}
		m1 <<= 1;
	}
	return rez;
}

int main(){
	int x;
	scanf("%d", &x);
	
	int rez = najveci(x);
	int rez2 = najmanji(x);
	print_bits(x);
	print_bits(rez);
	print_bits(rez2);
	printf("%d %d\n", rez, rez2);
	return 0;
}
