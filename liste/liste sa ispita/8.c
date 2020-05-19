#include "liste.h"

int f7(cvor *lista){
	if(lista->sledeci == NULL)
		return lista->vrednost;
	if(lista == NULL)
		return 0;
	
	if(lista->vrednost % 2 == 0){
		lista->sledeci->vrednost += 1;
		return f7(lista->sledeci);
	}else{
		lista->sledeci->vrednost -= 1;
		return f7(lista->sledeci);
	}
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	int rez = f7(lista);
	printf("%d\n", rez);
	
	oslobodi_listu(lista);
	return 0;
}
