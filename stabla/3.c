#include "stabla.h"

int broj_cvorova(cvor *koren){
	if(koren == NULL)
		return 0;
	return 1 + broj_cvorova(koren->levo) + broj_cvorova(koren->desno);
}

int broj_listova(cvor *koren){
	if(koren == NULL)
		return 0;
	
	if(koren->levo == NULL && koren->desno == NULL)
		return 1;
	
	return broj_listova(koren->levo) + broj_listova(koren->desno);
}

void stampaj_poz_listove(cvor *koren){
	if(koren == NULL)
		return;
	if(koren->levo == NULL && koren->desno == NULL && koren->vrednost > 0)
		printf("%d ", koren->vrednost);
	
	stampaj_poz_listove(koren->levo);
	stampaj_poz_listove(koren->desno);
}

int zbir_cvorova(cvor *koren){
	if(koren == NULL)
		return 0;
	return koren->vrednost + zbir_cvorova(koren->levo) + zbir_cvorova(koren->desno);
}

int najveci(cvor *koren){
	if(koren == NULL)
		return -1;
	if(koren->desno == NULL)
		return koren->vrednost;
	else
		return najveci(koren->desno);
}

int dubina(cvor *koren){
	if(koren == NULL)
		return 0;
	
	int dubina_levo = dubina(koren->levo);
	int dubina_desno = dubina(koren->desno);
	
	if(dubina_levo < dubina_desno)
		return dubina_desno + 1;
	else
		return dubina_levo + 1;
	
}

int main(int argc, char **argv){
	if(argc != 2)
		greska();
	
	int i = atoi(argv[1]);
	
	cvor *koren = NULL;
	ucitaj_stablo(&koren, stdin);
	
	printf("Broj cvorova: %d\n", broj_cvorova(koren));
	
	printf("Broj listova: %d\n", broj_listova(koren));
	
	printf("Pozitivni listovi: ");
	stampaj_poz_listove(koren);
	printf("\nZbir cvorova: %d\n", zbir_cvorova(koren));
	
	printf("Najveci element: %d\n", najveci(koren));
	
	printf("Dubina stabla: %d\n", dubina(koren));
	
	oslobodi_stablo(koren);
	return 0;
}
