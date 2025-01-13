#include <stdio.h>
#include <malloc.h>

#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 100 // O maior elemento que pode ser escolhido ao acaso para preencher um vetor:

// Criar e Encher uma matriz:
	int** cria_mat(int lin, int col){
		int ** mat = (int**)malloc(lin*sizeof(int*));

		for(int i=0; i<=lin-1; i++){
			mat[i] = (int*)malloc(col*sizeof(int));
		}

		return mat;
	}

	int** expd_mat(int** mat, int lin, int col){
		do{	
			mat = (int**)realloc(mat, lin*sizeof(int*));
		}while(mat==NULL);

		for(int i=0; i<=lin-1; i++){
			do{
				mat[i] = (int*)realloc(mat[i], col*sizeof(int));
			}while(mat[i]==NULL);
		}
		
		return mat;
	}

	// Enche uma matriz do zero
	void ench_mat(int** mat, int lin, int col){
		for(int i=0; i<=lin-1; i++){
			for(int j=0; j<=col-1; j++){
				mat[i][j] = 1+(rand()%MAX_SIZE);
			}
		}
	}

	// Completa uma matriz já preenchida
		/*	Exemplo de matriz:
			1 1 1 1 3 3 3			Legenda:
			1 1 1 1 3 3 3				1 - matriz original	
			1 1 1 1 3 3 3				2 - parte de baixo da matriz nova
			2 2 2 2 2 2 2				3 - parte espelhada a direita da matriz original
			2 2 2 2 2 2 2
		*/
	void comp_mat(int** mat, int old_lin, int old_col, int new_lin, int new_col){
		// Completa a parte de baixo inteira (2):
		for(int i=old_lin; i<=new_lin-1; i++){
			for(int j=0; j<=new_col-1; j++){
				mat[i][j] = 1+(rand()%MAX_SIZE); //2;
			}
		}
		// Completa a parte espelhada a direita da matriz inicial (3):
		for(int i=0; i<=old_lin-1; i++){
			for(int j=old_col; j<=new_col-1; j++){
				mat[i][j] = 1+(rand()%MAX_SIZE); //3;
			}
		}
	}

// Impressão Formatada Matriz:
	// Retorna o maior elemento de uma matriz de inteiros;
	int max_mat(int** mat, int lin, int col){
		int max = mat[0][0];
		for(int i=0; i<=lin-1; i++){
			for(int j=0; j<=col-1; j++){
				if(mat[i][j]>max){max=mat[i][j];}
			}
		}

		return max;
	}

	// Calcula a qtd de casas de um número inteiro
	int size_int(float num){
		int cont=0;
		while((num/10) >= 1){
			num = num/10;
			cont++;
		}
		return cont+1;
	}

	// Adiciona espaços conforme diferença entre o tamanho de 2 numeros;
	void espc_mat(int size_max, int size_num){
		int cont=0;
		while(size_max > (size_num)+cont){
			printf(" ");
			cont++;
		}
	}

	// Imprime a matriz formada
	void prtn_mat(int** mat, int lin, int col){
		printf("Matriz:  {");
		for(int i=0; i<=lin-1; i++){
			for(int j=0; j<=col-1; j++){
				if(j==0){printf("{");}
				espc_mat( size_int(max_mat(mat, lin, col)), size_int(mat[i][j])); // dar o espaçamento adequado
				if(j!=col-1){
					printf("%d, ", mat[i][j]);
				}else{
					printf("%d}", mat[i][j]);
				}
			}	

			if(i!=lin-1){
				printf("\n          ");
			}else{
				printf("}");
			}
		}	printf("\n\n");
	}

int main(void){
	srand(time(NULL));

	int linhas=3, colunas=4;
	// printf("Insira linhas: ");
	// scanf("%d", &linhas);
	// printf("Insira colunas: ");
	// scanf("%d", &colunas);

	int ** mat =NULL;
	mat = cria_mat(linhas, colunas);
	ench_mat(mat, linhas, colunas);
	prtn_mat(mat, linhas, colunas);

	// OBSERVAÇÕES:
		// Custuma dar certo para pequenos valores de linha; e no geral aceita valores grande para colunas, eu fui até 800;
		// Se tentar colocar muitas linhas acaba resultando em erro;	
	int n_linhas=6, n_colunas=8;
	mat = expd_mat(mat, n_linhas, n_colunas);
	comp_mat(mat, linhas, colunas, n_linhas, n_colunas);
	prtn_mat(mat, n_linhas, n_colunas);

	int n_n_linhas=8, n_n_colunas=10;
	mat = expd_mat(mat, n_n_linhas, n_n_colunas);
	comp_mat(mat, n_linhas, n_colunas, n_n_linhas, n_n_colunas);
	prtn_mat(mat, n_n_linhas, n_n_colunas);

	free(mat);
	for(int i=0; i<=n_n_linhas-1; i++){
		free(mat[i]);
	}


	return 0;
}