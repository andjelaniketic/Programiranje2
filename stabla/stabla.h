#ifndef _STABLA_H_
#define _STABLA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct cvor_{
	int vrednost;
	struct cvor_ *levo;
	struct cvor_ *desno;
}cvor;

void greska();

cvor *napravi_cvor(int broj);
void dodaj_u_stablo(cvor **koren, int broj);
void ucitaj_stablo(cvor **koren, FILE *f);
void ispisi_stablo(cvor *koren, FILE *f);
void oslobodi_stablo(cvor *koren);

void ispisi_prefiksno(cvor *koren, FILE *f);
void ispisi_postfiksno(cvor *koren, FILE *f);

#endif
