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

int cvorovi_na_nivou_i(cvor * koren, int i){
	//slucaj praznog stabla
	if(koren == NULL)
		return 0;
	//slucaj kad je u pitanju koren
	if(i==0)
		return 1;
	else
		return cvorovi_na_nivou_i(koren->levo, i-1) + cvorovi_na_nivou_i(koren->desno, i-1);
}

void stampaj_cvorove_na_nivou_i(cvor *koren, int i){
	if(koren == NULL)
		return;
	if(i==0)
		printf("%d ", koren->vrednost);
	else{
		stampaj_cvorove_na_nivou_i(koren->levo, i-1);
		stampaj_cvorove_na_nivou_i(koren->desno, i-1);
	}
	
}

int max_na_nivou_i(cvor *koren, int i){
	//prazno stablo
	if(koren == NULL)
		return -1;
	//slucaj korena
	if(i == 0)
		return koren->vrednost;
	else{
		int max_levo = max_na_nivou_i(koren->levo, i-1);
		int max_desno = max_na_nivou_i(koren->desno, i-1);
		
		return max_desno>max_levo?max_desno:max_levo;
	}
}

int suma_nivoa_i(cvor *koren, int i){
	//prazno stablo
	if(koren == NULL)
		return 0;
	//nivo je nivo korena
	if(i == 0)
		return koren->vrednost;
	return suma_nivoa_i(koren->levo, i-1) + suma_nivoa_i(koren->desno, i-1);
	
}

int suma_manjih_od_x(cvor *koren, int x){
	if(koren == NULL)
		return 0;
	if(koren->vrednost <= x)
		return koren->vrednost + suma_manjih_od_x(koren->levo, x) + suma_manjih_od_x(koren->desno, x);
	else
		//koren > x
		//znaci manje elemente necemo naci u desnom podstablu
		//te ima smisla samo traziti u levom
		return suma_manjih_od_x(koren->levo, x);
	
	
}
int main(int argc, char **argv){
	if(argc != 3)
		greska();
	
	int i = atoi(argv[1]);
	int x = atoi(argv[2]);
	
	cvor *koren = NULL;
	ucitaj_stablo(&koren, stdin);
	
	printf("Broj cvorova: %d\n", broj_cvorova(koren));
	
	printf("Broj listova: %d\n", broj_listova(koren));
	
	printf("Pozitivni listovi: ");
	stampaj_poz_listove(koren);
	printf("\nZbir cvorova: %d\n", zbir_cvorova(koren));
	
	printf("Najveci element: %d\n", najveci(koren));
	
	printf("Dubina stabla: %d\n", dubina(koren));
	
	printf("Broj cvorova na nivou %d: %d\n", i, cvorovi_na_nivou_i(koren, i));
	stampaj_cvorove_na_nivou_i(koren, i);
	
	printf("\nMax element na nivou %d: %d\n", i, max_na_nivou_i(koren, i));
	
	printf("Zbir elemenata na nivou %d: %d\n", i, suma_nivoa_i(koren, i));
	
	printf("Zbir elemenata <= vrednosti od %d: %d\n", x, suma_manjih_od_x(koren, x));
	
	oslobodi_stablo(koren);
	return 0;
}
