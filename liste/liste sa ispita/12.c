#include "liste.h"

cvor *umetni(cvor *lista, int n, int p){
	cvor *novi = napravi_cvor(n);
	cvor *glava = lista;
	
	while(lista){
		if(lista->vrednost == p){
			cvor *pom = lista->sledeci;
			lista->sledeci = novi;
			novi->sledeci = pom;
			return glava;
		}
		lista = lista->sledeci;
	}
	return glava;
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	int n, p;
	scanf("%d %d", &n, &p);
	
	lista = umetni(lista, n, p);
	ispisi_listu(lista, stdout);
	
	oslobodi_listu(lista);
	return 0;
}
