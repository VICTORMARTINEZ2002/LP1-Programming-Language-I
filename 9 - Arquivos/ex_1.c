#include <stdio.h>
#define MAX_SIZE 100

int main(){
	FILE * arq;

	int cont=0;
	arq = fopen("arquivo_1.txt", "r");
	if(arq==NULL){
		printf("ERRO AO ABRIR O ARQUIVO!");
	}

	for(char c=getc(arq); c!=EOF; c=getc(arq)){	
		cont++;
	}
	fclose(arq);

	printf("%d", cont);
}
