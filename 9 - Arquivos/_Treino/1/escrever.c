#include <stdio.h>
#include <string.h>

int main(void){
	FILE * arq;
	arq = fopen("sexo_1.txt", "w");
	if(arq==NULL){
		printf("Erro na abertura\n");
	}

	char texto[20] = "Meu programa em C";
	for(int i=0; i<=strlen(texto)-1; i++){
		fputc(texto[i], arq);
		fputc('_', arq);
	}
	fclose(arq);
	return 0;
}