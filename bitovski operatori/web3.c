#include <stdio.h>

unsigned invertuj_k(unsigned x, unsigned k){
	int i=0;
	unsigned mask = 1;
	while(mask){
		if(x&mask){
			i++;
			if(i==k){
				x = x ^ mask;
				i = 0;
			}
		}
		mask <<= 1;
	}
	
	return x;
}
int main (){
	unsigned x, k;
	scanf("%u%u", &x, &k);
	
	unsigned rez = invertuj_k(x, k);
	printf("%u\n", rez);
	return 0;
}
