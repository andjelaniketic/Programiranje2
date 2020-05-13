#include "liste.h"

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 0)
		greska();
	
	int broj;
	cvor* lista = NULL;
	
	ucitaj_listu(&lista, stdin);
	ispisi_listu(lista, stdout);
	
	oslobodi_listu(lista);
	return 0;
}
