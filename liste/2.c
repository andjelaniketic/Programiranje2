#include "liste.h"

cvor *umetni(cvor *lista, int x, int y, int z){
	cvor *glava = lista;
	
	while(lista->sledeci != NULL){
		if(lista->vrednost == x && lista->sledeci->vrednost == y){
			cvor* pom = lista->sledeci;
			cvor* novi = napravi_cvor(z);
			lista->sledeci = novi;
			novi->sledeci = pom;
			
			lista = pom;
		}
		else{
			lista = lista->sledeci;
		}
	}
	return glava;
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	
	lista = umetni(lista, x, y, z);
	ispisi_listu(lista, stdout);
	
	oslobodi_listu(lista);
	return 0;
}
