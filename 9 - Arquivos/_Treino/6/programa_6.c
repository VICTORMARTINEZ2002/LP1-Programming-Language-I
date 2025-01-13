#include <stdio.h>

int main(void){
	FILE * arq;
	arq=fopen("arquivo_6.txt", "r");
	if(arq==NULL){
		printf("Erro na abertura doa arquivo!\n");
		return 0;
	}

	char str[300];
	char * resultado = fgets(str, 300, arq); 
	if(resultado==NULL){printf("Erro na leitura\n");}else{
		printf("%s", str);
	}

	fgets(str, 300, arq);
	printf("%s", str);

	fclose(arq);
	return 0;
}