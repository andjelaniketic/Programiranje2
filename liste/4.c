#include "liste.h"

void obrisi_cvor(cvor **lista1, int x){
	if(*lista1 == NULL)
		return;
	else if((*lista1)->vrednost == x){
		cvor *tmp = *lista1;
		*lista1 = (*lista1)->sledeci;
		free(tmp);
		obrisi_cvor(lista1, x);
	}
	else
		obrisi_cvor(&(*lista1)->sledeci, x);
}
cvor *izbaci(cvor *lista1, cvor *lista2){
	if(lista2 == NULL)
		return lista1;
	
	while(lista2){
		obrisi_cvor(&lista1, lista2->vrednost);
		lista2 = lista2->sledeci;
	}
	return lista1;
}

int main(){
	cvor *lista1 = NULL;
	cvor *lista2 = NULL;
	
	ucitaj_listu(&lista1, stdin);
	ucitaj_listu(&lista2, stdin);
	
	lista1 = izbaci(lista1, lista2);
	ispisi_listu(lista1, stdout);
	
	oslobodi_listu(lista1);
	oslobodi_listu(lista2);
	return 0;
}
