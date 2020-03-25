#include <stdio.h>

int main(int argc, char** argv){

	for(int i=0; i<argc; i++){
		if(argv[i][0] == '-'){
			for(int j=1; argv[i][j] != '\0'; j++)
				printf("%c ", argv[i][j]);
		}
	}
	putchar('\n');
	return 0;
}
