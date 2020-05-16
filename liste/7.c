#include "liste.h"

cvor *dodaj(cvor *lista, int k){
	if(lista == NULL || lista->sledeci == NULL)
		return lista;
	
	if((lista->vrednost + lista->sledeci->vrednost == k) ||
		(lista->vrednost - lista->sledeci->vrednost == k) ||
		(lista->sledeci->vrednost - lista->vrednost == k)){
		
		cvor *novi = napravi_cvor(-1);
		novi->sledeci = lista->sledeci;
		lista->sledeci = novi;
		
		novi->sledeci = dodaj(novi->sledeci, k);
		return lista;
	}else{
		lista->sledeci = dodaj(lista->sledeci, k);
		return lista;
	}
	
}

int main(){
	cvor *lista = NULL;
	int k;
	
	ucitaj_listu(&lista, stdin);
	scanf("%d", &k);
	
	cvor* lista2 = NULL;
	
	lista2 = dodaj(lista, k);
	ispisi_listu(lista2, stdout);
	
	oslobodi_listu(lista2);
	return 0;
}
