#include <stdio.h>

int main(void){
	FILE *f1, *f2;
	f1 = fopen("arquivo_2i.txt", "r");
	f2 = fopen("arquivo_2f.txt", "w");
	if(f1==NULL || f2==NULL){printf("Erro Abrir arquivo\n");}



	int linha_ex=-1;
	printf("Insira linha a ser deletada: ");
	scanf("%d", &linha_ex);

	char texto[301];
	int linha_atual=1;
	while(fgets(texto, 301, f1)!=NULL){
		if(linha_atual != linha_ex){
			fputs(texto, f2);
		}
		linha_atual++;
	}	

	fclose(f1);
	fclose(f2);

	// remove("arquivo_2i"); //apagar o arquivo 2 inicial;
	// rename("arquivo_2f", "arquivo_2");
	return 0;
}