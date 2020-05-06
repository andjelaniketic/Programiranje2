#include <stdio.h>

void print_bits(int x){
	unsigned mask = 1 << sizeof(int)*8 -1;
	
	while(mask){
		mask & x? printf("1") : printf("0");
		mask >>=1;
	}
	printf("\n");
}
unsigned get_bits(int x, int p, int n){
	unsigned m1 = 1;
	unsigned m2 = 0;
	int i;
	//u m2 cemo imati n jedinica od pozicije p
	for(i=0; i<n; i++){
		m2 = m1 | m2;
		m1 <<= 1;
	}
	m2 <<= p;
	//ostaje samo uraditi operaciju & nad m2 i x
	//to ce sacuvati samo bitove gde su jedinice u m2
	return m2&x;
	
}
unsigned get_bits_bez_petlje(int x, int p, int n){
	unsigned mask = 0;
	
	mask = (~(~mask << n)) << p;
	
	return x & mask;
}

int main(){
	int x, p, n;
	scanf("%d%d%d", &x, &p, &n);
	
	unsigned tmp = get_bits(x, p, n);
	
	print_bits(x);
	print_bits(tmp);
	return 0;
}



