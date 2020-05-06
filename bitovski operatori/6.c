#include <stdio.h>

void print_bits(unsigned x){
	unsigned mask = 1 << sizeof(int)*8-1;
	
	while(mask){
		mask&x? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

unsigned set_bits(unsigned x, int p, int n, unsigned y){
	unsigned m1 = 0;
	m1 = ~(~m1 << n);
	
	unsigned izdvojeno_y = y & m1;
	izdvojeno_y <<= p;
	
	m1 <<= p;
	m1 = ~m1;
	
	return (x & m1)|izdvojeno_y;
}

int main(){
	unsigned int x, y;
	int p, n;
	scanf("%u%u", &x, &y);
	scanf("%d%d", &n, &p);
	
	if(p < 0 || p+n >= sizeof(int)*8)
		return -1;
	
	unsigned rez = set_bits(x, p, n, y);
	
	print_bits(x);
	print_bits(y);
	print_bits(rez);
	
	return 0;
}
