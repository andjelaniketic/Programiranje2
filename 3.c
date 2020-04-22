#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

double sqr(double a){
	return a*a;
}

double limes(double (*fp)(double), int n, double a){

	return (*fp)(a + 1.0/n);

}

int main(){
	char ime_funkcije[6];
	int n;
	double a;
	double (*fp)(double);
	
	scanf("%s %d %lf", ime_funkcije, &n, &a);
	
	
	if(strcmp(ime_funkcije,"sin")==0)
    fp=&sin;
  else if(strcmp(ime_funkcije,"cos")==0)
    fp=&cos;
  else if(strcmp(ime_funkcije,"tan")==0)
    fp=&tan;
  else if(strcmp(ime_funkcije,"atan")==0)
    fp=&atan;
  else if(strcmp(ime_funkcije,"asin")==0)
    fp=&asin;
  else if(strcmp(ime_funkcije,"acos")==0)
    fp=&acos;
  else if(strcmp(ime_funkcije,"exp")==0)
    fp=&exp;
  else if(strcmp(ime_funkcije,"log")==0)
    fp=&log;
  else if(strcmp(ime_funkcije,"log10")==0)
    fp=&log10;
  else if(strcmp(ime_funkcije,"sqrt")==0)
    fp=&sqrt;
  else if(strcmp(ime_funkcije,"floor")==0)
    fp=&floor;
  else if(strcmp(ime_funkcije,"ceil")==0)
    fp=&ceil;
  else if(strcmp(ime_funkcije,"sqr")==0)
    fp=&sqr;
  else
    greska();
	
	printf("Limes fje %s u tacki %lf je: %.2lf \n", ime_funkcije, a, limes(fp, n, a));
	
	return 0;
}
