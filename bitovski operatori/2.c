#include <stdio.h>

void isone(int x, unsigned int k){
	unsigned mask = 1 << k;
	
	if(mask & x)
		printf("jeste\n");
	else
		printf("nije\n");
}

int main(){
	int x;
	unsigned int k;
	scanf("%d %u", &x, &k);
	
	if(k < 0 || k >= (int)(sizeof(int)*8)){
		printf("pozicija nijeu dobrom opsegu\n");
		return -1;
	}
	
	isone(x, k);
	return 0;
}
