#include <stdio.h>
#include <stdlib.h>

#define KOEFS 11

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

float nula(float *poly, float l, float d){
	if(l > d)
		return -1;
	float s = l+(d-l)/2;
	float vr = vrednost(poly, s);
	
	if(fabs(vr) < EPS)
		return s;
	else
		//TODO pogledaj video
	
}

int main(int argc, char **argv){
	if(argc != 3)
		greska();
	float a = atof(argv[1]);
	float b = atof(argv[2]);
	if(a > b)
		greska();
	
	float poly[KOEFS];
	
    for(int i=0; i<n; i++){
        scanf("%f", &poly[i]);
    }
    
    printf("%.2f\n", nula(poly, a, b));
	
	return 0;
}
