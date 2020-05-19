#include "liste.h"

//obrce listu
cvor *f2(cvor *L){
	cvor *novaL = NULL;
	while(L){
		dodaj_na_pocetak(&novaL, L->vrednost);
		L = L->sledeci;
	}
	return novaL;
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	cvor *obrnuta = f2(lista);
	ispisi_listu(obrnuta, stdout);
	
	oslobodi_listu(lista);
	oslobodi_listu(obrnuta);
	return 0;
}
