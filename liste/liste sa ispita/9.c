#include "liste.h"

int broj_pojavljivanja(cvor *lista, int broj){
	int rez = 0;
	while(lista){
		if(lista->vrednost == broj){
			rez++;
		}
		lista = lista->sledeci;
	}
	return rez;
}
int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	int broj;
	scanf("%d", &broj);
	
	int rez = broj_pojavljivanja(lista, broj);
	printf("%d\n", rez);
	
	oslobodi_listu(lista);
	return 0;
}
