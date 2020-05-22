#include "stabla.h"

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

cvor *napravi_cvor(int broj){
	cvor *novi = (cvor*) malloc(sizeof(cvor));
	if(novi == NULL)
		greska();
	novi->vrednost = broj;
	novi->levo = NULL;
	novi->desno = NULL;
	
	return novi;
}

void dodaj_u_stablo(cvor **koren, int broj){
	if(*koren == NULL){
		*koren = napravi_cvor(broj);
		return;
	}
	if(broj > (*koren)->vrednost)
		dodaj_u_stablo(&(*koren)->desno, broj);
	else
		dodaj_u_stablo(&(*koren)->levo, broj);
}

void ucitaj_stablo(cvor **koren, FILE *f){
	int broj;
	while(fscanf(f, "%d", &broj) != EOF)
		dodaj_u_stablo(koren, broj);
}

void ispisi_stablo(cvor *koren, FILE *f){
	if(koren != NULL){
		ispisi_stablo(koren->levo, f);
		fprintf(f, "%d ", koren->vrednost);
		ispisi_stablo(koren->desno, f);
	}
}

void oslobodi_stablo(cvor *koren){
	if(koren){
		oslobodi_stablo(koren->levo);
		oslobodi_stablo(koren->desno);
		free(koren);
	}
}

void ispisi_prefiksno(cvor *koren, FILE *f){
	if(koren != NULL){
		fprintf(f, "%d ", koren->vrednost);
		ispisi_prefiksno(koren->levo, f);
		ispisi_prefiksno(koren->desno, f);
	}
	
}

void ispisi_postfiksno(cvor *koren, FILE *f){
	if(koren != NULL){
		ispisi_postfiksno(koren->levo, f);
		ispisi_postfiksno(koren->desno, f);
		fprintf(f, "%d ", koren->vrednost);
	}
	
}
