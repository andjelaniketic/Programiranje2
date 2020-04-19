#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void tabela(int n, double a, double b, double (*fja)(double)){
	int i;
  double x;

  for(i=0; i<n; i++){
    x = a+i*(b-a)/(n-1);
    printf("| %8.5f | %8.5f |\n",x,(*fja)(x));
  }
}

int main (int argc, char **argv){
	if(argc != 2)
		greska();
	
	char ime_funkcije[6];
	strcpy(ime_funkcije, argv[1]);
	
	double a, b;
	int n;
	scanf("%lf %lf", &a, &b);
	if(a >= b)
		greska();
	
	scanf("%d", &n);
	if(n < 2)
		greska();
	
	double (*pokazivac_na_fju) (double);
 	if(strcmp(ime_funkcije,"sin")==0)
		pokazivac_na_fju=&sin;
 	else if(strcmp(ime_funkcije,"cos")==0)
		pokazivac_na_fju=&cos;
  	else if(strcmp(ime_funkcije,"tan")==0)
   		pokazivac_na_fju=&tan;
  	else if(strcmp(ime_funkcije,"atan")==0)
		pokazivac_na_fju=&atan;
	else if(strcmp(ime_funkcije,"asin")==0)
		pokazivac_na_fju=&asin;
	else if(strcmp(ime_funkcije,"acos")==0)
		pokazivac_na_fju=&acos;
	else if(strcmp(ime_funkcije,"exp")==0)
		pokazivac_na_fju=&exp;
	else if(strcmp(ime_funkcije,"log")==0)
		pokazivac_na_fju=&log;
	else if(strcmp(ime_funkcije,"log10")==0)
		pokazivac_na_fju=&log10;
	else if(strcmp(ime_funkcije,"sqrt")==0)
		pokazivac_na_fju=&sqrt;
	else if(strcmp(ime_funkcije,"floor")==0)
		pokazivac_na_fju=&floor;
	else if(strcmp(ime_funkcije,"ceil")==0)
		pokazivac_na_fju=&ceil;
	else if(strcmp(ime_funkcije,"sqr")==0)
		pokazivac_na_fju=&sqrt;
	else
		greska();
	
	tabela(n, a, b, pokazivac_na_fju);
	
	return 0;
}
