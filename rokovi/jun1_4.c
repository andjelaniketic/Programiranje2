#include "stabla.h"

int proveri_decu(Cvor* otac, int vrednost_oca){
	if(otac == NULL)
		return 0;
	int vrednost_levo = 0;
	int vrednost_desno = 0;
	
	if(otac->levo != NULL)
		vrednost_levo = otac->levo->vrednost;
	if(otac->desno != NULL)
		vrednost_desno = otac->desno->vrednost;
	if(vrednost_oca == (vrednost_desno + vrednost_levo))
		return 1;
	else
		return 0;
	
}

void jednaki_zbiru_potomaka(Cvor *koren){
	if(koren == NULL)
		return;
	
	jednaki_zbiru_potomaka(koren->levo);
	
	if(proveri_decu(koren, koren->vrednost))
		printf("%d ", koren->vrednost);
	
	jednaki_zbiru_potomaka(koren->desno);
	
}

int main(){
	Cvor *koren = NULL;
	ucitaj_stablo(&koren, stdin);
	
	jednaki_zbiru_potomaka(koren);
	printf("\n");
	
	oslobodi_stablo(koren);
	return 0;
}
