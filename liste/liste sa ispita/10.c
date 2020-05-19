#include "liste.h"

int pozicija(cvor *lista, int broj){
	int poz = 0;
	while(lista){
		if(lista->vrednost == broj){
			poz++;
			return poz;
		}
		poz++;
		lista = lista->sledeci;
	}
	return -1;
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	int broj;
	scanf("%d", &broj);
	
	int rez = pozicija(lista, broj);
	printf("%d\n", rez);
	
	oslobodi_listu(lista);
	return 0;
}
