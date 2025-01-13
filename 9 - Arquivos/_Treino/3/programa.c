#include <stdio.h>

#include <ctype.h>

int main(void){
	FILE *f1, *f2;
	f1 = fopen("minusculo.txt", "r");
	f2 = fopen("maiusculo.txt", "w");
	if(f1==NULL || f2==NULL){printf("Erro abertura!\n"); return 0;}

	for(char c=fgetc(f1); c!=EOF; c = fgetc(f1)){
		fputc(toupper(c), f2); //função que converte char pra maiusculo;
	}

	fclose(f1);
	fclose(f2);
	return 0;
}