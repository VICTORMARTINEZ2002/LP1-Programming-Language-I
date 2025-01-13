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