#ifndef _LISTE_H_
#define _LISTE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _cvor{
	int vrednost;
	struct _cvor* sledeci;
}cvor;

void greska();

cvor* napravi_cvor(int broj);

void dodaj_na_pocetak(cvor **lista, int broj);
cvor* dodaj_na_pocetak_v2(cvor *lista, int broj);

void ispisi_listu(cvor *lista, FILE *f);

void dodaj_na_kraj(cvor **lista, int broj);
cvor* dodaj_na_kraj_v2(cvor *lista, int broj);

void ucitaj_listu(cvor **lista, FILE* f);

void oslobodi_listu(cvor *lista);
#endif
