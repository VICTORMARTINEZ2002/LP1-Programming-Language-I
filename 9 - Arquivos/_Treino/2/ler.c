#include <stdio.h>

int main(void){
	FILE * arq;
	arq = fopen("sexo_2.txt", "r");
	if(arq == NULL){
		printf("Erro na abertura arquivo");
	}

	for(char c = fgetc(arq); c != EOF; c=fgetc(arq)){
		printf("%c", c);
	} 
	printf("\nFIM\n");
	fclose(arq);
	return 0;
}