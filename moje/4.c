#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void greska(){
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main(){
	FILE *ulaz;
	float matrix[MAX][MAX];
	
	ulaz = fopen("matrica.txt", "r");
	if(ulaz == NULL) greska();
	
	int n, m;
	fscanf(ulaz, "%d%d", &n, &m);
	
	if(n <= 0 || n > MAX || m <= 0 || m > MAX) greska();
	
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			fscanf(ulaz, "%f", &matrix[i][j]);
		}
	}
	
	int k, l;
	float suma = 0;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			suma = 0;
			for(k=i-1; k<=i+1; k++){
				for(l=j-1; l<=j+1; l++){
					if(k>=0 && k<n && l>=0 && l<m)
						suma+= matrix[k][l];
				}
			}
			suma-=matrix[i][j];
			if(suma == matrix[i][j])
				printf("(%d, %d, %f)\n", i, j, matrix[i][j]);
		}
	}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			printf("%.2f ", matrix[i][j]);
	printf("%d %d", n, m);
	fclose(ulaz);
	return 0;
}
