#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void unos(int *niz, int n){
	for(int i=0; i<n; i++)
		scanf("%d", &niz[i]);
}

void ispis(int *niz, int n){
	for(int i=0; i<n; i++)
		printf("%d ", niz[i]);
	printf("\n");
}

void insertion(int *niz, int n){
	int i, j;
	for(i=0; i<n; i++){
		int tmp = niz[i];
		for(j=i; j>0 && tmp < niz[j-1]; j--)
			niz[j] = niz[j-1];
		niz[j] = tmp;
	}
}
void razmeni(int *niz, int i, int j){
	int tmp = niz[i];
	niz[i] = niz[j];
	niz[j] = tmp;
}
int poz_min(int *a, int n, int i){
	int min = i;
	int j;
	for(j=i+1; j<n; j++)
		if(a[j] < a[min])
			min = j;
	return min;
}

void selection(int *niz, int n){
	int i;
	for(i=0; i<n-1; i++)
		razmeni(niz, i, poz_min(niz, n, i));
	
}

void merge(int *a, int n, int *b, int m, int *c){
	int i, j, k;
	i=0; j=0; k=0;
	
	while(i<n && j<m) c[k++] = a[i] < b[j]? a[i++] : b[j++];
	while(i<n) c[k++] = a[i++];
	while(j<m) c[k++] = b[j++];
	
}

void mergesort_(int *niz, int l, int d, int *tmp){
	if(l < d){
		int i, j;
		int n = d - l+1; //br elemenata
		int s = l + n/2; //pozicija srednjeg
		int n1 = n/2;
		int n2 = n - n/2;
		
		mergesort_(niz, l, s-1, tmp); //n1
		mergesort_(niz, s, d, tmp); //n2
		//spajanje
		merge(niz+l, n1, niz+s, n2, tmp); 
		//prepisivanje
		for(i=l, j=0; i<=d; i++, j++)
			niz[i] = tmp[j];
	}
}

void mergesort(int *niz, int n){
	int *tmp = (int*)malloc(n*sizeof(int));
	if(tmp == NULL)
		greska();
	
	mergesort_(niz, 0, n-1, tmp);
	free(tmp);
}

int izbor_pivota(int *niz, int l, int d){
	return l;
}

int particionisanje(int *niz, int l, int d){
	int p = l;
	int j;
	for(j=l+1; j<=d; j++)
		if(niz[j] < niz[l])
			razmeni(niz, ++p, j);
	razmeni(niz, l, p);
	return p;
}

void quicksort(int *niz, int l, int d){
	if(l < d){
		razmeni(niz, l, izbor_pivota(niz, l, d));
		
		int p = particionisanje(niz, l, d);
		
		quicksort(niz, l, p-1);
		quicksort(niz, p+1, d);
	}
	
}

int poredi(const void *pa, const void *pb){
	int a = *(int*)pa;
	int b = *(int*)pb;
	if(a < b) return -1;
	else if(a > b) return 1;
	else return 0;
	
}

int poredi_opadajuce(const void *pa, const void *pb){
	int a = *(int*)pa;
	int b = *(int*)pb;
	if(a<b) return 1;
	else if(a>b) return -1;
	else return 0;
}

void insertion_opadajuce(int *niz, int n){
	int i, j;
	for(i=0; i<n; i++){
		int tmp = niz[i];
		for(j=i; j>0 && tmp > niz[j-1]; j--) 
			niz[j] = niz[j-1];
		niz[j] = tmp;
	}
}

void selection_opadajuce(int *niz, int n){
	int i, j;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(niz[j] > niz[i])
				razmeni(niz, i, j);
}

int main(int argc, char** argv){
	if(argc != 2)
		greska();
	
	int n;
	scanf("%d", &n);
	if(n <= 0)
		greska();
	int *niz = malloc(n*sizeof(int));
	if(niz == NULL)
		greska();
	
	unos(niz, n);
	
	if(strcmp(argv[1], "-i") == 0)
		insertion(niz, n);
	else if(strcmp(argv[1], "-s") == 0)
		selection(niz, n);
	else if(strcmp(argv[1], "-m") == 0)
		mergesort(niz, n);
	else if(strcmp(argv[1], "-q") == 0)
		quicksort(niz, 0, n-1);
	else if(strcmp(argv[1], "-qsort") == 0)
		qsort(niz, n, sizeof(int), poredi);
	else if(strcmp(argv[1], "-ir") == 0)
		insertion_opadajuce(niz, n);
	else if(strcmp(argv[1], "-sr") == 0)
		selection_opadajuce(niz, n);
	else if(strcmp(argv[1], "-qsortr") == 0)
		qsort(niz, n, sizeof(int), poredi_opadajuce);
	else
		greska();
	
	ispis(niz, n);
	
	free(niz);
	return 0;
}
