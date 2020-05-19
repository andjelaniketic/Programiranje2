#include "liste.h"

int veci_od(cvor* lista, int broj){
	if(lista == NULL)
		return 0;
	if(lista->vrednost > broj){
		return 1 + veci_od(lista->sledeci, broj);
	}else{
		return veci_od(lista->sledeci, broj);
	}
	
}

int main (){
	cvor* lista = NULL;
	ucitaj_listu(&lista, stdin);
	int broj;
	printf("Unesi broj: ");
	scanf("%d", &broj);
	
	printf("%d\n", veci_od(lista, broj));
	
	oslobodi_listu(lista);
	return 0;
}
