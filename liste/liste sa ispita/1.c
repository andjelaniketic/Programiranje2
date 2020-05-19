#include "liste.h"

void obrisi_sa_pocetka(cvor **lista){
	cvor *pom = *lista;
	*lista = (*lista)->sledeci;
	
	free(pom);
}
int main(){
	FILE *f = fopen("izraz.txt", "r");
	
	if(f == NULL)
		greska();
	
	cvor *lista = NULL;
	int c;
	int ind = 1;
	
	while((c = fgetc(f)) != EOF){
		if(c == '{' || c == '[' || c == '(')
			dodaj_na_pocetak(&lista, c);
		if((c == '}' || c == ']' || c == ')') && lista == NULL){
			ind = 0;
			break;
		}
		
		if(c == '}'){
			if(lista->vrednost != '{'){
				ind = 0;
				break;
			}else{
				obrisi_sa_pocetka(&lista);
			}
		}
		if(c == ']'){
			if(lista->vrednost != '['){
				ind = 0;
				break;
			}else{
				obrisi_sa_pocetka(&lista);
			}
		}
		if(c == ')'){
			if(lista->vrednost != '('){
				ind = 0;
				break;
			}else{
				obrisi_sa_pocetka(&lista);
			}
		}
		
	}
	
	if(ind && lista == NULL){
		printf("Zagrade su dobro uparene.\n");
	}else
		printf("Zagrade nisu dobro uparene.\n");
	
	
	oslobodi_listu(lista);
	fclose(f);
	return 0;
}
