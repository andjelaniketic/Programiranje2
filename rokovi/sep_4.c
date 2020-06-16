#include "stabla.h"

int simetricno_deca(Cvor *koren1, Cvor *koren2){
	if(koren1 == NULL && koren2 == NULL)
		return 1;
	if(koren1 == NULL || koren2 == NULL)
		return 0;
	
	return simetricno_deca(koren1->desno, koren2->levo) && simetricno_deca(koren1->levo, koren2->desno);
}

int simetricno(Cvor *koren){
	if(koren == NULL)
		return 1;
	return simetricno_deca(koren->levo, koren->desno);
}

int main(){
	Cvor *koren1 = NULL;
	Cvor *koren2 = NULL;
	Cvor *koren3 = NULL;
	
	FILE *f1 = fopen("dat1.txt", "r");
	if(f1 == NULL) greska();
	FILE *f2 = fopen("dat1.txt", "r");
	if(f2 == NULL) greska();
	FILE *f3 = fopen("dat1.txt", "r");
	if(f3 == NULL) greska();
	
	ucitaj_stablo(&koren1, f1);
	ucitaj_stablo(&koren2, f2);
	ucitaj_stablo(&koren3, f3);
	
	printf("%d %d %d\n", simetricno(koren1), simetricno(koren2), simetricno(koren3));
	
	oslobodi_stablo(koren1);
	oslobodi_stablo(koren2);
	oslobodi_stablo(koren3);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	return 0;
}
