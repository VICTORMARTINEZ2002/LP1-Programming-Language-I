// Eu podia fazer igual a questão 3 e implementar que o mesmo livro não pudesse ter o mesmo registro, mas eh mais do mesmo;
// Eu podia com funções de maximo e tamanho formatar colunas pra titulo - autor usando um while e printf(" ") - ESPAÇOS, mas eh um pouco demais pra esse problema;
// Alugando livro: uma vez que o usuario encontra o livro eu podia fazer que ele confirmasse se quer alugar, mas isso eh simples e isso eh so uma questão;

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE 30

struct _livro{
	int num_registro;
	char autor[MAX_SIZE];
	char titulo[MAX_SIZE];
	int alugado;
};

void concerta_string(char* texto){
	int tam = strlen(texto);
	texto[tam-1]='\0';

	//Tirar os espaços no inicio da string;
	while(texto[0]==' '){
		for(int i=0; i<=(tam-1)+1; i++){
			texto[i]=texto[i+1];
		}
		tam--;
	}

	//Tirar os espaços no fim da string;
	while(texto[(tam-1)-1]==' '){
		texto[(tam-1)-1]='\0';
		tam--;
	}

	//Tirar os espaços duplos no meio da string;
	for(int i=0; i<=tam-1; i++){
		if(texto[i]=='\0'){break;}
		if(texto[i]==' ' && (texto[i+1]==' ' ||texto[i+1]=='\0')){
			tam--;
			for(int j=i; j<=tam-1; j++){
				texto[j]=texto[j+1];		
			}
			i--;
		}
	}

	//Passando tudo pra caixa alta;
	int z=0;
	while(texto[z]!='\0'){
		if(((int)texto[z]>=97) && ((int)texto[z]<=122)){
			texto[z] -= 32;
		}
		z++;
	}
}

int menu(void){
	int num=0;
	printf("---------------------------------------------\n");
	printf("                      MENU                   \n");
	printf("---------------------------------------------\n");	
	printf("\t1. Exibir Information Sobre Um Livro;\n");
	printf("\t2. Adicionar Novo Livro;\n");	
	printf("\t3. Exibir todos os livros de um autor;\n");
	printf("\t4. Exibir todos os livros disponiveis;\n");		
	printf("\t5. Exibir toda a biblioteca;\n");	
	printf("\t6. Alugar um livro;\n");		
	printf("Entre com sua option: ");
	scanf("%d", &num);
	return num;
}

// Todo livro novo adicionado está disponivel para alugar;
void addLivro(struct _livro *biblioteca, int qtd_livros){
	struct _livro umLivro;
	printf("Adicionando novo livro:\n");
	printf("\tInsira numero de registro: ");
	scanf("%d", &umLivro.num_registro); getchar();
	printf("\tInsira Autor: ");
	fgets(umLivro.autor,  MAX_SIZE, stdin); concerta_string(umLivro.autor);
	printf("\tInsira titulo: ");
	fgets(umLivro.titulo, MAX_SIZE, stdin); concerta_string(umLivro.titulo);

	biblioteca[qtd_livros].num_registro = umLivro.num_registro;
	strcpy(biblioteca[qtd_livros].autor,  umLivro.autor);	
	strcpy(biblioteca[qtd_livros].titulo, umLivro.titulo);
	biblioteca[qtd_livros].alugado = 0;
}



int main(void){
	int qtd_livros=0;
	struct _livro *biblioteca = (struct _livro*)malloc(qtd_livros*sizeof(struct _livro));
	struct _livro umLivro;


	int option=0;
	// Variaveis busca livro
	int tipo_temp=0;
	char temp_titulo[MAX_SIZE]= "\0";
	char temp_autor[MAX_SIZE] = "\0";
	int flag=0;
	int cont=0;
	int  temp_num_registro=0;

	while(1){
		fflush(stdin);
		option=menu();
		switch(option){
		case 1:
			printf("Como deseja buscar seu livro?\n");
			printf("\t1. Titulo; \n");
			printf("\t2. num_registro; -> ");
			scanf("%d", &tipo_temp);
			switch(tipo_temp){
				case 1:
					fflush(stdin);
					printf("Insira titulo: ");
					fgets(temp_titulo, MAX_SIZE, stdin); concerta_string(temp_titulo);
					for(int i=0; i<=qtd_livros-1; i++){
						if(strcmp(biblioteca[i].titulo, temp_titulo)==0){
							printf("Livro encontrado!\n");
							printf("\tTitulo: %s\n", biblioteca[i].titulo);
							printf("\tAutor:  %s\n", biblioteca[i].autor);
							printf("\tNum registro: %d\n", biblioteca[i].num_registro);
							printf("\tAlugado? "); biblioteca[i].alugado? printf("YES\n") : printf("NOPE\n");
							flag=1;
							break; //quebra loop for;
						}
					}	
					if(flag==0){printf("Livro Não encontrado!\n");}
					flag=0;
					break;

				case 2:
					fflush(stdin);
					printf("Insira num de registro: ");
					scanf("%d", &temp_num_registro);
					for(int i=0; i<=qtd_livros-1; i++){
						if(biblioteca[i].num_registro == temp_num_registro){
							printf("Livro encontrado!\n");
							printf("\tTitulo: %s\n", biblioteca[i].titulo);
							printf("\tAutor:  %s\n", biblioteca[i].autor);
							printf("\tNum registro: %d\n", biblioteca[i].num_registro);
							printf("\tAlugado? "); biblioteca[i].alugado? printf("YES\n") : printf("NOPE\n");
							flag=1;
							break;
						}
					}	
					if(flag==0){printf("Livro Não encontrado!\n");}	
					flag=0;
					break;	

				default:
					printf("Option Invalida!\n");
					break;	
			}
			break;

		case 2:
			do{ 
				biblioteca = (struct _livro*)realloc(biblioteca, (qtd_livros+1)*sizeof(struct _livro));
				if(biblioteca==NULL){printf("Erro de alocação!\n");}
			}while(biblioteca==NULL);	
			addLivro(biblioteca, qtd_livros);
			qtd_livros++;
			break;

		case 3:
			fflush(stdin);
			printf("Insira o autor: ");
			fgets(temp_autor, MAX_SIZE, stdin); concerta_string(temp_autor);
			for(int i=0; i<=qtd_livros-1; i++){
				if(strcmp(biblioteca[i].autor, temp_autor)==0){
					if(flag==0){
						printf("Livros de %s\n", biblioteca[i].autor);
						flag=1;
					}
					printf("(%d): %s\n", cont+1, biblioteca[i].titulo);
					cont++;
				}
			}
			if(flag==0){printf("Nenhum livro encontrado!\n");}
			flag=0;
			cont=0;
			break;

		case 4:
			printf("\nImprimindo todos os livros da disponiveis: \n");
			for(int i=0; i<=qtd_livros-1; i++){
				if(biblioteca[i].alugado){continue;}
				printf("\t(%d): %s - %s\n", cont+1, biblioteca[i].titulo, biblioteca[i].autor);
				cont++;
			}	
			printf("End Impression!\n");	
			cont=0;		
			break;	

		case 5:
			printf("\nImprimindo todos os %d livros da biblioteca: \n", qtd_livros);
			for(int i=0; i<=qtd_livros-1; i++){
				printf("\t(%d): %s - %s\n", cont+1, biblioteca[i].titulo, biblioteca[i].autor);
				cont++;
			}	
			printf("End Impression!\n");
			cont=0;
			break;

		case 6:
			printf("Como deseja alugar seu livro? \n");
			printf("\t1. Titulo; \n");
			printf("\t2. num_registro; -> ");
			scanf("%d", &tipo_temp);
			switch(tipo_temp){
				case 1:
					printf("Insira titulo: ");
					fgets(temp_titulo, MAX_SIZE, stdin); concerta_string(temp_titulo);
					for(int i=0; i<=qtd_livros-1; i++){
						if(strcmp(biblioteca[i].titulo, temp_titulo)==0){
							printf("Livro encontrado!\n");
							printf("\t(%d): %s - %s\n", cont, biblioteca[i].titulo, biblioteca[i].autor);
							if(biblioteca[i].alugado){printf("Livro Indisponivel!");}
							else{
								printf("Livro Alugado Com Sucesso!\n");
								biblioteca[i].alugado = 1;
							}
						}
					}	
					break;

				case 2:
					printf("Insira num de registro: ");
					scanf("%d", &temp_num_registro);
					for(int i=0; i<=qtd_livros-1; i++){
						if(biblioteca[i].num_registro == temp_num_registro){
							printf("Livro encontrado!\n");
							printf("\t(%d): %s - %s\n", cont, biblioteca[i].titulo, biblioteca[i].autor);
							if(biblioteca[i].alugado){printf("Livro Indisponivel!");}
							else{
								printf("Livro Alugado Com Sucesso!");
								biblioteca[i].alugado = 1;
							}
						}
					}	
					break;	

				default:
					printf("Option Invalida!\n");
					break;	
			}
			break;

		default:
			printf("Entrada Invalida!\n");
			break;
		}

		printf("\n");
	}
	return 0;
}