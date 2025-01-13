#include <stdio.h>

int main(void){
	FILE *f1, *f2, *fr;
	f1=fopen("arquivo_4_1.txt", "r");
	f2=fopen("arquivo_4_2.txt", "r");
	fr=fopen("arquivo_4_r.txt", "w");
	if(f1==NULL || f2==NULL || fr==NULL){
		printf("Erro abertura arquivo!\n");
		return 0;
	}

	char temp[301];
	while(fgets(temp, 301, f1) != NULL){
		fputs(temp, fr);
	}
	fputs("\n", fr);
	while(fgets(temp, 301, f2) != NULL){
		fputs(temp, fr);
	}

	fclose(f1); fclose(f2); fclose(fr);
	return 0;	
}