#include "liste.h"

cvor* izbaci1(cvor *lista, int broj){
	if(lista == NULL)
		return lista;
	if(lista->vrednost == broj){
		cvor* pom = lista->sledeci;
		free(lista);
		return pom;
	}else{
		lista->sledeci = izbaci1(lista->sledeci, broj);
		return lista;
	}
	
}

int postoji(cvor *lista, int broj){
	if(lista == NULL)
		return 0;
	
	if(lista->vrednost == broj)
		return 1;
	
	return postoji(lista->sledeci, broj);
}

cvor* izbaci2(cvor *lista, int broj){
	if(lista == NULL)
		return lista;
	if(lista->vrednost == broj && !postoji(lista->sledeci, broj)){
		cvor* pom = lista->sledeci;
		free(lista);
		return pom;
	}else{
		lista->sledeci = izbaci2(lista->sledeci, broj);
		return lista;
	}
	
}

cvor *izbaci3(cvor *lista, int broj){
	if(lista == NULL)
		return NULL;
	
	cvor* pom = NULL;
	if(lista->vrednost == broj){
		pom = lista->sledeci;
		free(lista);
		return izbaci3(pom, broj);
	}else{
		lista->sledeci = izbaci3(lista->sledeci, broj);
		return lista;
	}
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	int broj;
	scanf("%d", &broj);
	
	//cvor* rez = izbaci1(lista, broj);
	cvor* rez = izbaci3(lista, broj);
	
	ispisi_listu(rez, stdout);
	
	oslobodi_listu(rez);
	return 0;
}
