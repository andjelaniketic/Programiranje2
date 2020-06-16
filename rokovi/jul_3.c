#include "liste.h"

void podeli(Cvor *lista, Cvor **poz, Cvor **neg){
	if(lista == NULL)
		return;
	
	//pomocni koji prate trenutno poslednji el u listama
	Cvor *atm_poz = *poz;
	Cvor *atm_neg = *neg;
	
	while(lista){
		if(lista->vrednost >= 0){
			if(*poz == NULL){
				*poz = lista;
				atm_poz = *poz;
			}else{
				atm_poz->sledeci = lista;
				atm_poz = atm_poz->sledeci;
			}
		}else{
			if(*neg == NULL){
				*neg = lista;
				atm_neg = *neg;
			}else{
				atm_neg->sledeci = lista;
				atm_neg = atm_neg->sledeci;
			}
			
		}
		lista = lista->sledeci;
	}
	//poslednji elementi
	atm_poz->sledeci = NULL;
	atm_neg->sledeci = NULL;
}

int main(){
	Cvor *lista = ucitaj_listu_v2(stdin);
	
	Cvor *neg = NULL;
	Cvor *poz = NULL;
	podeli(lista, &poz, &neg);
	
	ispisi_listu(poz, stdout);
	ispisi_listu(neg, stdout);
	oslobodi_listu(lista);
	return 0;
}
