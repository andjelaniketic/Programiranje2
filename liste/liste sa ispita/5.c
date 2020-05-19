#include "liste.h"

void umetni(cvor *lista){
	if(lista->sledeci == NULL || lista == NULL)
		return;
	
	cvor *pom = lista->sledeci;
	cvor *novi = napravi_cvor(lista->vrednost - lista->sledeci->vrednost);
	lista->sledeci = novi;
	novi->sledeci = pom;
	
	umetni(novi->sledeci);
	return;
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	umetni(lista);
	ispisi_listu(lista, stdout);
	
	oslobodi_listu(lista);
	return 0;
}
