#include "liste.h"

void obrisi_cvor(cvor **lista){
	cvor *tmp = (*lista)->sledeci;
	(*lista)->sledeci = tmp->sledeci;
	free(tmp);
}

void f4(cvor *lista){
	if(lista == NULL || lista->sledeci == NULL)
		return;
	obrisi_cvor(&lista);
	f4(lista->sledeci);
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	f4(lista);
	ispisi_listu(lista, stdout);
	
	oslobodi_listu(lista);
	return 0;
}
