#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	printf("Qtd argumentos passados: %d\n", argc);
	printf("Nome do programa: %s\n", argv[0]);
	printf("\n");

	printf("Lista dos Argumentos passados: \n");
	for(int i=0; i<argc; i++){
		printf("%d. %s\n", i, argv[i]);
	}
	return 0;
}