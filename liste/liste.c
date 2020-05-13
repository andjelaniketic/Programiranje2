#include "liste.h"

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

cvor* napravi_cvor(int broj){
	cvor* novi = malloc(sizeof(cvor));
	if(novi == NULL)
		greska();
	
	novi->vrednost = broj;
	novi->sledeci = NULL;

	return novi;
}

void dodaj_na_pocetak(cvor** lista, int broj){
	cvor* novi = napravi_cvor(broj);
	
	novi->sledeci = *lista;
	*lista = novi; //nova glava;
}

cvor* dodaj_na_pocetak_v2(cvor* lista, int broj){
	cvor* novi = napravi_cvor(broj);
	
	novi->sledeci = lista;
	return novi;
}

void ispisi_listu(cvor* lista, FILE *f){
	fprintf(f, "[");
	while(lista != NULL){
		fprintf(f, "%d", lista->vrednost);
		if(lista->sledeci != NULL)
			fprintf(f, ", ");
		lista = lista->sledeci;
	}
	fprintf(f, "]\n");
}

void dodaj_na_kraj(cvor **lista, int broj){
	if(*lista == NULL)
		*lista = napravi_cvor(broj);
	else{
		while((*lista)->sledeci != NULL){
			*lista = (*lista)->sledeci;
		}
		(*lista)->sledeci = napravi_cvor(broj);
	}
	
}

cvor* dodaj_na_kraj_v2(cvor *lista, int broj){
	cvor* pom = lista;
	if(lista == NULL){
		lista = napravi_cvor(broj);
		return lista;
	}else{
		while(pom->sledeci != NULL)
			pom = pom->sledeci;
		pom->sledeci = napravi_cvor(broj);
		return lista;
	}
	
}
void ucitaj_listu(cvor **lista, FILE* f){
	if(f == NULL)
		greska();
	int broj;
	while(fscanf(f, "%d", &broj) != EOF){
		*lista = dodaj_na_kraj_v2(*lista, broj);
	}
	
}

void oslobodi_listu(cvor *lista){
	cvor* pom;
	while(lista != NULL){
		pom = lista;
		lista = lista->sledeci;
		free(pom);
	}
}
