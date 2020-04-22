#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

double integral(double (*fp)(double), int n, double a, double b){
	double h = (b-a)/n;
	double suma = 0;
	int i;
	
	for(i=1; i<=n; i++)
		suma+= (*fp)(a + i*h);
	
	return h*(((*fp)(a)+(*fp)(b))/2 + suma);

}

int main(){
	char ime_fje[6];
	int n;
	double a, b;
	
	double (*fp)(double);
	
	scanf("%s %d %lf %lf", ime_fje, &n, &a, &b);
	
	if(strcmp(ime_fje, "sin") == 0)
		fp = &sin;
	else if(strcmp(ime_fje, "cos") == 0)
		fp = &cos;
	else if(strcmp(ime_fje, "tan") == 0)
		fp = &tan;
	else if(strcmp(ime_fje, "atan") == 0)
		fp = &atan;
	else if(strcmp(ime_fje, "asin") == 0)
		fp = &asin;
	else if(strcmp(ime_fje, "acos") == 0)
		fp = &acos;
	else if(strcmp(ime_fje, "exp") == 0)
		fp = &exp;
	else if(strcmp(ime_fje, "log") == 0)
		fp = &log;
	else if(strcmp(ime_fje, "log10") == 0)
		fp = &log10;
	else if(strcmp(ime_fje, "sqrt") == 0)
		fp = &sqrt;
	else if(strcmp(ime_fje, "floor") == 0)
		fp = &floor;
	else if(strcmp(ime_fje, "ceil") == 0)
		fp = &ceil;
	else 
		greska();
		
	printf("vrednost integrala ja: %lf\n", integral(fp, n, a, b));

	return 0;
}
