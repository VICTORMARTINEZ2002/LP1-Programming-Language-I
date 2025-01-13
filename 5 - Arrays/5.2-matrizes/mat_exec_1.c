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
				if(j==col-1){printf(" %d}\n",   mat[i][j]);}
				else		{printf(" %d, ", mat[i][j]);}
			}else{
				if(j==col-1){printf("%d}\n",    mat[i][j]);}
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
				if(j==colt-1){printf(" %d}\n", mat_trsp[i][j]);}
				else		 {printf(" %d, ",  mat_trsp[i][j]);}
			}else{
				if(j==colt-1){printf("%d}\n",  mat_trsp[i][j]);}
				else         {printf("%d, ",   mat_trsp[i][j]);}
			}
		}
	}	
	return 0;
}