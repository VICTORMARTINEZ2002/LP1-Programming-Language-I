#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct _carro{
	char modelo[100];
	int ano;
};

void addCarro(struct _carro *catalogo, struct _carro umCarro, int qtd_carros){
	strcpy(catalogo[qtd_carros].modelo, umCarro.modelo);	
	catalogo[qtd_carros].ano = umCarro.ano;	
}

int main(void){
	int qtd_carros=0;
	struct _carro *catalogo;
	catalogo = (struct _carro*)malloc(qtd_carros*sizeof(struct _carro));

	struct _carro umCarro;	
	while(1){
		printf("Insira carro %d:\n", qtd_carros+1);
		printf("\tModelo: ");
		fgets(umCarro.modelo, sizeof(umCarro.modelo), stdin);
		printf("\tAno: ");
		scanf("%d", &(umCarro.ano)); getchar();
		if(umCarro.ano<0){break;}
		do{
			catalogo = realloc(catalogo, ((qtd_carros)+1)*sizeof(struct _carro));
			if(catalogo==NULL){printf("Erro Alocação");}
		}while(catalogo==NULL);
		addCarro(catalogo, umCarro, qtd_carros); 
		qtd_carros++;	
	}

	printf("\n\nCATALOGO: \n");
	for(int i=0; i<=qtd_carros-1; i++){ 
		printf("Carro %d:\n", i+1);
		printf("\tModelo: %s", catalogo[i].modelo);
		printf("\tAno:    %d\n", catalogo[i].ano);	
	}

	return 0;
}