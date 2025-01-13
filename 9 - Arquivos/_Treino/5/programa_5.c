#include <stdio.h>

int main(void){
	FILE * f1;
	f1=fopen("arquivo.txt", "w");
	if(f1==NULL){
		printf("Erro na abertura\n");
		return 0;
	}

	char texto[20] = "Meu programa em C\n";

	int retorno = fputs(texto, f1);
	if(retorno==EOF){
		printf("Erro na gravação\n");
	}

	fputs("Hello", f1);
	fputs("World", f1);

	fclose(f1);
	return 0;
}