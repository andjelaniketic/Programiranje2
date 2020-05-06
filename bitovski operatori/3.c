#include <stdio.h>

int postavi1(int x, unsigned int k){
	unsigned mask = 1 << k;
	return x|mask;
}

int main (){
	int x;
	unsigned int k;
	scanf("%d %u", &x, &k);
	
	if(k < 0 || k >= (int)(sizeof(int)*8)){
		printf("pozicija nije u dobrom opsegu\n");
		return -1;
	}
	
	printf("%d\n", postavi1(x, k));
	
	return 0;
}
