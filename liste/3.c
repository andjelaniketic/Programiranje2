#include "liste.h"

int u_listi(int x, cvor *lista){
	while(lista){
		if(lista->vrednost == x)
			return 1;
		lista = lista->sledeci;
	}
	return 0;
}
int suma(cvor *lista1, cvor *lista2){
	int suma = 0;
	cvor *glava1 = lista1;
	while(glava1){
		if(!u_listi(glava1->vrednost, lista2))
			suma += glava1->vrednost;
		glava1 = glava1->sledeci;
	}
	return suma;
}

int main(){
	cvor *lista1 = NULL;
	cvor *lista2 = NULL;
	ucitaj_listu(&lista1, stdin);
	ucitaj_listu(&lista2, stdin);
	
	int rez = suma(lista1, lista2);
	printf("%d\n", rez);
	
	oslobodi_listu(lista1);
	oslobodi_listu(lista2);
	return 0;
}
