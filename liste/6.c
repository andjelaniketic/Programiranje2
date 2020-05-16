#include "liste.h"

cvor *spoji(cvor *l1, cvor *l2){
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;
	
	if(l1->vrednost < l2->vrednost){
		l1->sledeci = spoji(l1->sledeci, l2);
		return l1;
	}else{
		l2->sledeci = spoji(l1, l2->sledeci);
		return l2;
	}
	
}
int main(){
	cvor *l1 = NULL;
	cvor *l2 = NULL;
	
	ucitaj_listu(&l1, stdin);
	ucitaj_listu(&l2, stdin);
	
	cvor *l3 = spoji(l1, l2);
	ispisi_listu(l3, stdout);
	
	oslobodi_listu(l3);
	return 0;
}
