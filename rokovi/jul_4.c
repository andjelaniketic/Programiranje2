#include "stabla.h"

int suma_po_dijagonali(Cvor *koren, int k){
	if(koren == NULL)
		return 0;
	if(k == 1){
		return koren->vrednost + suma_po_dijagonali(koren->desno, k);
	}
	return suma_po_dijagonali(koren->levo, k-1) + suma_po_dijagonali(koren->desno, k);
}
int main(){
	int k;
	scanf("%d", &k);
	
	Cvor *koren = NULL;
	ucitaj_stablo(&koren, stdin);
	
	int rez = suma_po_dijagonali(koren, k);
	printf("%d\n", rez);
	
	oslobodi_stablo(koren);
	return 0;
}
