#include "liste.h"

void obrisi_cvor(cvor **lista, int x){
	if(*lista == NULL)
		return;
	else if((*lista)->vrednost == x){
		cvor *tmp = *lista;
		*lista = (*lista)->sledeci;
		free(tmp);
		obrisi_cvor(lista, x);
	}
	else
		obrisi_cvor(&(*lista)->sledeci, x);
	
}

cvor *izbaci(cvor *lista){
	cvor *pom = lista;
	
	while(pom != NULL){
		int x = pom->vrednost;
		
		cvor *pom2 = pom->sledeci;
		while(pom2 != NULL){
			if(pom2->vrednost == x){
				while(pom!=NULL && pom->vrednost==x)
					pom = pom->sledeci;
				//pomeramo pom sa pocetka da pokazuje na prvi el koji nije x
				obrisi_cvor(&lista, x);
				//brisemo x iz glavne liste
				break;
			}
			pom2 = pom2->sledeci;
		}
		//ako pom nije stigao do kraja i ako je vrednost ostala ista nakon
		//unutrasnje petlje, znaci da nije brisan pa se pomeramo dalje
		if(pom!=NULL && pom->vrednost==x)
			pom = pom->sledeci;
	}
	
	return lista;
}

int main(){
	cvor *lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	lista = izbaci(lista);
	ispisi_listu(lista, stdout);
	
	oslobodi_listu(lista);
	return 0;
}
