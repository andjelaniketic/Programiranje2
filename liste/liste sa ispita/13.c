#include "liste.h"

cvor *dodaj_u_listu(cvor *lista, cvor *novi, int n){
	int i;
	cvor *glava = lista;
	for(i=0; i<n-1; i++){
		if(lista->sledeci == NULL){
			lista->sledeci = novi;
			return glava;
		}
		lista = lista->sledeci;
	}
	if(i==n-1 && lista->sledeci!= NULL){
		cvor *tmp = lista->sledeci;
		lista->sledeci = novi;
		novi->sledeci = tmp;
		return glava;
	}
}
int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	cvor *novi = NULL;
	ucitaj_listu(&novi, stdin);
	
	int n;
	scanf("%d", &n);
	
	lista = dodaj_u_listu(lista, novi, n);
	ispisi_listu(lista, stdout);
	
	oslobodi_listu(lista);
	return 0;
}
