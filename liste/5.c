#include "liste.h"

cvor *naizmenicno(cvor *L1, cvor *L2){
	if(L1 == NULL)
		return L2;
	if(L2 == NULL)
		return L1;
	
	L1->sledeci = naizmenicno(L2, L1->sledeci);
	return L1;
	
}

int main(){
	cvor *L1 = NULL;
	cvor *L2 = NULL;
	
	ucitaj_listu(&L1, stdin);
	ucitaj_listu(&L2, stdin);
	
	cvor *L3 = naizmenicno(L1, L2);
	ispisi_listu(L3, stdout);
	
	
	oslobodi_listu(L3);
	return 0;
}
