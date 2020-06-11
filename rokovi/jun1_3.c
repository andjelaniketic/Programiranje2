#include "liste.h"

void izmeni(Cvor **lista){
	if((*lista) == NULL || (*lista)->sledeci == NULL)
		return;
	
	if((*lista)->vrednost % 2 == 0 && (*lista)->sledeci->vrednost %2 == 0){
		Cvor *tmp = (*lista)->sledeci;
		Cvor *novi = napravi_cvor(0);
		(*lista)->sledeci = novi;
		novi->sledeci = tmp;
		
		izmeni(&tmp);
	}else{
		izmeni(&(*lista)->sledeci);
	}
	
}

int main(){
	Cvor *lista = ucitaj_listu_v2(stdin);
	
	izmeni(&lista);
	
	ispisi_listu(lista, stdout);
	
	oslobodi_listu(lista);
	return 0;
}
