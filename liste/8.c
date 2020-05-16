#include "liste.h"

cvor* zbir_datog_broja(cvor *lista, int k){
	if(lista == NULL || lista->sledeci == NULL)
		return lista;
	
	cvor* pom = lista->sledeci;
	
	if(lista->vrednost + lista->sledeci->vrednost == k){
		lista->sledeci = zbir_datog_broja(pom, k);
		if(lista->sledeci == pom){
			//nije izbacen pom u narednom zbiru i onda
			//brisem i njega i glavu liste
			cvor *pov = pom->sledeci;
			free(lista);
			free(pom);
			return pov;
		}else{
			//pom je izbrisan, ostaje jos glava liste
			cvor *pov = lista->sledeci;
			free(lista);
			return pov;
		}
		
	}else{
		//ne brise se nista, idemo dalje
		lista->sledeci = zbir_datog_broja(lista->sledeci, k);
		return lista;
	}
	
}

int main(){
	cvor *lista = NULL;
	int k;
	
	ucitaj_listu(&lista, stdin);
	scanf("%d", &k);
	
	cvor *lista2 = NULL;
	lista2 = zbir_datog_broja(lista, k);
	
	ispisi_listu(lista2, stdout);
	
	oslobodi_listu(lista2);
	return 0;
}
