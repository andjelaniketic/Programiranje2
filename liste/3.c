#include "liste.h"

cvor* dodaj_element(cvor* lista, int broj){
	if(lista == NULL){
		cvor* novi = napravi_cvor(broj);
		return novi;
	}
	
	if(lista->vrednost > broj){
		cvor* novi = napravi_cvor(broj);
		novi->sledeci = lista;
		return novi;
	}
	else
		lista->sledeci = dodaj_element(lista->sledeci, broj);
	
}
int main(int argc, char **argv){
	/*if(argv != 2)
		greska();
	*/
	cvor* lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	int broj;
	scanf("%d", &broj);
	
	cvor* rez = dodaj_element(lista, broj);
	ispisi_listu(rez, stdout);
	
	oslobodi_listu(lista);
	return 0;
} 
