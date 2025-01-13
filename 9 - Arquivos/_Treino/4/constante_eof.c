#include <stdio.h>

int main(void){
	FILE * arq;
	arq = fopen("sexo_4.txt", "r");
	if(arq == NULL){
		printf("Erro na abertura arquivo");
	}

	char c = fgetc(arq);
	while(!feof(arq)){
		printf("%c", c);
		c = fgetc(arq);
	} 
	printf("\nFIM\n");
	fclose(arq);
	return 0;
}