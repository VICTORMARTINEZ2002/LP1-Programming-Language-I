#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX_SIZE 100

static int cont=0;

void addProduto(char** carrinho, char produto[]){
	carrinho[cont] = (char*)malloc((strlen(produto)+1)*sizeof(char)); // ir até o '\0'; 
	for(int i=0; i<=strlen(produto); i++){ 							   // ir até o '\0';
		carrinho[cont][i] = produto[i];
	}
	cont++;	
}

void delProduto(char** carrinho, int num){
	for(int i=num-1; i<=cont-2; i++){
		carrinho[i]=carrinho[i+1];
	}
	carrinho[cont-1]=NULL;		

	cont--;
	carrinho = (char**)realloc(carrinho, (cont+1)*sizeof(char*));	
}

void printCarrinho(char** carrinho){
	if(cont==0){
		printf("Carrinho Vazio!\n\n\n");
		return;
	}
	printf("-> Carrinho: --------------------------------\n");
	for(int i=0; i<=cont-1; i++){  //cont-1 pra compensar o cont aumentar no addproduto;
		int j=0;
		while(carrinho[i][j]!='\0'){
			if(j==0){printf("	%d. ", i+1);}
			printf("%c", carrinho[i][j]);
			j++;
		}	printf(";\n");
	}		printf("---------------------------------------------\n\n");
}

int main(void){
	char **carrinho = NULL;
	carrinho = (char **)malloc(0*sizeof(char *));
	char produto[MAX_SIZE]="\0";	
	int num=-1;

	char aws = '0';
	printf("----------C A R R I N H O----------\n");
	while(1){
		fflush(stdin); //Se eu coloco uma palavra, na linha abaixo o loop reinicia com o buffer cheio;
		printf("Deseja adicionar/remover um produto? (a/r) ");
		scanf("%c", &aws); getchar();						//tirar o \n do buffer;
		if(aws=='a' || aws=='A'){
			printf("	Insira produto %d: ", cont+1);
			fgets(produto, MAX_SIZE, stdin);
			produto[strlen(produto)-1]='\0';

			carrinho = (char **)realloc(carrinho, (cont+1)*sizeof(char *)); // Se eu tento colocar essa linha dentro da função, dá merda;
			addProduto(carrinho, produto);
		}

		if(aws=='r' || aws=='R'){
			if(cont==0){
				;
			}else{
				do{
					printf("	Insira o numero do item a ser removido: ");
					scanf("%d", &num);
					fflush(stdin);  // Se eu coloco uma palavra, o programa não entra em loop;
				}while(num>cont || num<=0);
				delProduto(carrinho, num);
			}
		}	
		//system("cls"); -> Funciona, mas deixa o programa lento;
		printCarrinho(carrinho);

	}

	return 0;
}
