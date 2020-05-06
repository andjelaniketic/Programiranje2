#include <stdio.h>

int suma_bitova(int x){
	unsigned mask = 1 << sizeof(int)*8 -1;
	int suma = 0;
	while(mask){
		if(x & mask)
			suma+=1;
		mask >>= 1;
	}
	return suma;
}

int main(){
	int x;
	scanf("%d", &x);
	
	printf("%d\n", suma_bitova(x));
	return 0;
}
