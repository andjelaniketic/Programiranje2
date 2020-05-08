#include <stdio.h>

int sekv010(unsigned x){
	unsigned m1 = 1;
	unsigned m2 = m1 << 1;
	unsigned m3 = m2 << 1;
	
	int rez = 0;
	
	while(m3){
		if(!(m1&x) && (m2&x) && !(m3&x))
			rez++;
		m1 <<= 1;
		m2 <<= 1;
		m3 <<= 1;
	}
	return rez;
}

int main(){
	unsigned x;
	scanf("%u", &x);
	
	int rez = sekv010(x);
	printf("%d\n", rez);
	
	return 0;
}
