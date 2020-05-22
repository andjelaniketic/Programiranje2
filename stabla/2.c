#include "stabla.h"

int identitet(cvor *koren1, cvor *koren2){
	if(koren1 == NULL || koren2 == NULL)
		return 1;
	else if(koren1 == NULL || koren2 == NULL || koren1->vrednost != koren2->vrednost)
		return 0;
	else
		return identitet(koren1->levo, koren2->levo) && identitet(koren1->desno, koren2->desno);
	
}

int main(){
	cvor *koren1 = NULL;
	cvor *koren2 = NULL;
	ucitaj_stablo(&koren1, stdin);
	ucitaj_stablo(&koren2, stdin);
	
	int rez = identitet(koren1, koren2);
	if(rez == 1)
		printf("Da\n");
	else
		printf("Ne\n");
	
	oslobodi_stablo(koren1);
	oslobodi_stablo(koren2);
	return 0;
}
