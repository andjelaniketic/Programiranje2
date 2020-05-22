#include "stabla.h"

cvor *pretrazi_stablo(cvor *koren, int broj){
	if(koren == NULL)
		return NULL;
	if(koren->vrednost == broj)
		return koren;
	else if(broj <= koren->vrednost)
		return pretrazi_stablo(koren->levo, broj);
	else
		return pretrazi_stablo(koren->desno, broj);
	
}

cvor *pronadji_najmanji(cvor *koren){
	if(koren == NULL)
		return NULL;
	if(koren->levo == NULL)
		return koren;
	return pronadji_najmanji(koren->levo);
}

cvor *pronadji_najveci(cvor *koren){
	if(koren == NULL)
		return NULL;
	if(koren->desno == NULL)
		return koren;
	return pronadji_najveci(koren->desno);
}

int main(){
	cvor *koren = NULL;
	ucitaj_stablo(&koren, stdin);
	
	int broj;
	scanf("%d", &broj);
	
	cvor *rez = pretrazi_stablo(koren, broj);
	if(rez == NULL)
		printf("Broj se ne nalazi u stablu.\n");
	else
		printf("Broj se nalazi u stablu.\n");
	
	rez = pronadji_najmanji(koren);
	printf("Najmanji: %d\n", rez->vrednost);
	rez = pronadji_najveci(koren);
	printf("Najveci: %d\n", rez->vrednost);
	
	oslobodi_stablo(koren);
	return 0;
}
