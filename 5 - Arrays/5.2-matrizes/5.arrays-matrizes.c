MATRIZES
	● Uma matriz é uma coleção homogênea, geralmente bidimensional, cujos elementos são distribuídos em linhas e colunas;
	● Se A é uma matriz m x n, então:
		-suas linhas são indexadas de 0 - (m-1);
		-suas coluna são indexadas de 0 - (n-1);
	● Para acessar um elemento particular de A, fazemos A[i][j] (i-linha; j-coluna);
	● Declarando uma matriz 3 x 4 de inteiros: int A[3][4];
		-Essa declaração cria um vetor A, cujos elementos A[0], A[1] e A[2] são também vetores.
		-Cada um deles, contendo 4 elementos do tipo int;
	● Para processarmos uma matriz, fazemos uso de for´s aninhados:
		-Armazenando valores em uma matriz:
			int A[3][4];
			for(int i=0; i<=2; i++){
				for(int j=0; j<=3; j++){
					printf(" Insira elemento A[%d][%d]: ",i,j);
					scanf("%d", &A[i][j]);
				}
			}			 
		-Mostrando a matriz:
			for(int i=0; i<=2; i++){
				for(int j=0; j<=3; j++){
					printf("%d", A[i][j]);
				}
				printf("\n");
			}	

Inicialização de matrizes 2 D:
	-> Alternativa 1:
		int A[2][4]={
			{10,11,12,13},
			{14,15,16,17}
		};
	-> Alternativa 2:	
		int B[2][4]={10,11,12,13,14,15,16,17};

	● Ambas as declarações são válidas, porém recomenda-se utilizar a 1°, que eh mais legivel (melhor vizualização das linhas/colunas);
	● Em vetores, não eh necessária a especificação do tamanho na declaração;
	● Em matrizes 2 D, essa especificação é sempre necessária para a 2ª dimensão;
	 -Exemplos://declaração valida
				int abc[2][2] = {1, 2, 3, 4};
			   //declaração valida
			    int abc[][2]  = {1, 2, 3, 4};	
			   //declaração INvalida
			    int abc[][]   = {1, 2, 3, 4};	
			   //declaração INvalida
			    int abc[2][]  = {1, 2, 3, 4};	 

Exercício:
	1.Crie um programa em C que preencha uma matriz 5 x 5 com valores aleatórios (0 a 9) e a mostre na tela. 
	  Em seguida, encontre a sua transposta.
      Obs.: matriz transposta é a matriz que se obtém da troca de linhas por colunas
      Ex.:
      	|1 2 3|t    |1 4 7|
      	|4 5 6|	 =  |2 5 8|
      	|7 8 9|     |3 6 9|
    Solução:
    	#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(void){
			int row=0,col=0;
			printf("Insira o tamanho da matriz (n x m): ");
			scanf("%d %d", &row, &col);
			printf("Tamanho: %dx%d \n\n", row, col);

		//Criando a matriz orignal
			int mat[row][col];
			srand(time(NULL));
			for(int i=0; i<=row-1; i++){
				for(int j=0; j<=col-1; j++){
					mat[i][j]=rand()%100;
				}		
			}

		//Imprimindo bonitinho a matriz original
			printf("Matriz Original: \n");	
			for(int i=0; i<=row-1; i++){
				printf("{");
				for(int j=0; j<=col-1; j++){
					if(mat[i][j]<10){
						if(j==col-1){printf(" %d}\n",mat[i][j]);}
						else		{printf(" %d, ", mat[i][j]);}
					}else{
						if(j==col-1){printf("%d}\n", mat[i][j]);}
						else        {printf("%d, ",  mat[i][j]);}
					}
				}
			}
			printf("\n\n\n");

		//Criando a matriz transposta:
			int rowt=col;
			int colt=row;
			int mat_trsp[rowt][colt];
			for(int i=0; i<=rowt-1; i++){
				for(int j=0; j<=colt-1; j++){
					mat_trsp[i][j]=mat[j][i];
				}		
			}

		//Imprimindo a matriz transposta
			printf("Matriz Transposta: \n");
			for(int i=0; i<=rowt-1; i++){
				printf("{");
				for(int j=0; j<=colt-1; j++){
					if(mat_trsp[i][j]<10){
						if(j==colt-1){printf(" %d}\n",   mat_trsp[i][j]);}
						else		 {printf(" %d, ", mat_trsp[i][j]);}
					}else{
						if(j==colt-1){printf("%d}\n",    mat_trsp[i][j]);}
						else         {printf("%d, ",  mat_trsp[i][j]);}
					}
				}
			}	
			return 0;
		} 

	2.Crie um programa em C para encontrar a multiplicação dos elementos da diagonal principal 
	  de uma matriz. Essa matriz deve ser 5 x 5 e preenchida com valores aleatórios.
	Solução:
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(void){
			int size=0;
			printf("Insira o tamanho da matriz quadrada: ");
			scanf("%d", &size);
			printf("Tamanho: %dx%d \n\n", size, size);

		//Criando a matriz orignal
			int mat[size][size];
			srand(time(NULL));
			for(int i=0; i<=size-1; i++){
				for(int j=0; j<=size-1; j++){
					mat[i][j]=rand()%100;
				}		
			}

		//Imprimindo bonitinho a matriz original
			printf("Matriz: \n");	
			for(int i=0; i<=size-1; i++){
				printf("{");
				for(int j=0; j<=size-1; j++){
					if(mat[i][j]<10){
						if(j==size-1){printf(" %d}\n",   mat[i][j]);}
						else		{printf(" %d, ",     mat[i][j]);}
					}else{
						if(j==size-1){printf("%d}\n",    mat[i][j]);}
						else        {printf("%d, ",      mat[i][j]);}
					}
				}
			}

		//Calculando o produtorio dos elementos da diagonal principal:
			double prod_dp=1;
			for(int i=0; i<=size-1; i++){
				for(int j=0; j<=size-1; j++){
					if(i==j){prod_dp*=mat[i][j];}
				}
			}
			printf("Produto elementos diagonal principal: %0.lf\n",prod_dp);	

		//Calculando o produtorio dos elementos da diagonal secundaria:
			double prod_ds=1;
			for(int i=0; i<=size-1; i++){
				for(int j=0; j<=size-1; j++){
					if(i+j==size-1){prod_ds*=mat[i][j];}
				}
			}
			printf("Produto elementos diagonal principal: %0.lf\n",prod_ds);	


			return 0; 
		}	 	
