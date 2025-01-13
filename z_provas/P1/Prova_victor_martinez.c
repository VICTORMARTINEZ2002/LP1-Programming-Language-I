//LP1 2022.2;
//Aluno: Victor José Beltrão Almajano Martinez;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Considerações:
	//1. Uma possivel solução para o problema eh colocar câmeras em todas as salas;
	//2. Considere que uma câmera instalada em uma sala grava também a sala na qual ela está instalada;

//Conta quantas salas são filmadas pela câmera na sala fornecida; 
int cont_1(int vetor[], int size){
	int cont=0;
	for(int i=0; i<=size-1; i++){
		if(vetor[i]==1){cont++;}
	}
	return cont;
}

//Printar recursivamente as salas nas quais foram instaladas câmeras;
void print_recursivo(int vetor[], int size,int indice){
	if(size<=0){return;} 					//vetor vazio;
	if(indice> size-1){return;}             //caso tenhamos passado por todo o vetor;
	if(vetor[indice]!=-1){printf("%d, ",vetor[indice]);}       
	print_recursivo(vetor, size, ++indice);	
}

int main(void){
	int size=5;
	//Naturalmente, percebe-se que essa eh uma matriz simetrica, i,e, (A=A^t);
	int mat[5][5] ={{0, 0, 1, 1, 0},
				    {0, 0, 1, 1, 1},
				    {1, 1, 0, 1, 0},
			  	    {1, 1, 1, 0, 0},
			  	    {0, 1, 1, 0, 0}};

//Caso eu quisse-se fazer o teste com uma matriz de entradas pseudo-aleatórias e tamanho qualquer:
 //    srand(time(NULL));
 //    int salas=0;
 //    printf("Insira Quantas salas existem: ");
 //    scanf("%d", &salas);
 //    printf("Total de Salas: %d\n", salas);
 //    int size=salas;

	// //Criando a matriz das salas:
 //    int mat[size][size];
 //    for(int i=0; i<=size-1; i++){
 //        for(int j=0; j<=size-1; j++){
 //            if(j>i){mat[i][j]=rand()%2;}
 //            if(i<j){mat[j][i]=mat[i][j];}
 //            if(i==j){mat[i][j]=1;}
 //        }
 //    }	


//Ajustando a matriz para se adequar a CONSIDERAÇÃO 2 (filmagem na própria sala);
	for(int i=0; i<=size-1; i++){
		for(int j=0; j<=size-1; j++){
			if(i==j){mat[i][j]=1;}
		}
	}					  	    

//Imprimindo a matriz (para fins de facilitar a vizualização do desenvolvimento do problema):
	printf("matriz original= {");
    for(int i=0; i<=size-1; i++){
        if(i==0){printf("{");}
        else{printf("\t\t  {");}
        for(int j=0; j<=size-1; j++){
			if(mat[i][j]<10 &&mat[i][j]!=-1){
                if(i<size-1){
                    if(j==size-1){printf(" %d},\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}
                }else{
                    if(j==size-1){printf(" %d}};\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}}
            }else{
                if(i<size-1){
                    if(j==size-1){printf("%d},\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}
                }else{
                    if(j==size-1){printf("%d}};\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}}
            	}
    		}   
    	}	 
    printf("\n");		  	    

  //Criar os vetores que armazenam as salas com câmera e as salas filmadas;    
    int vet_salas_c_camera[size];
	for(int i=0; i<=size-1; i++){
		vet_salas_c_camera[i]=-1;
	}	 	   
	int vet_salas_filmadas[size];
	for(int i=0; i<=size-1; i++){
		vet_salas_filmadas[i]=-1;
	}					 
	
	int cont=0;
//Criando o loop que vai se repetir até que todas as salas estajam sendo filmadas; 
	while(1){
		//checar se ainda há alguma sala sem ser filmada;
		if(cont_1(vet_salas_filmadas, size)==size){break;}	

		int _1melhor  =0;
		int pos_melhor=0;
		//Detectar a sala que mais possui corredores
		for(int i=0; i<=size-1; i++){
			if(cont_1(mat[pos_melhor],size)<cont_1(mat[i],size)){
				pos_melhor=i;
				_1melhor=cont_1(mat[i],size);
			}
		}

		//coloco uma câmera na sala com mais corredores:
		vet_salas_c_camera[cont]=pos_melhor;
		cont++;
		printf("Melhor sala (0 - %d) para a proxima camera: sala %d;\n",size-1, pos_melhor);

		//Atribuir as salas filmadas em um vetor e printa-lo:
		printf("Vetor salas filmadas: {");
		for(int i=0; i<=size-1; i++){
			if(mat[pos_melhor][i]==1){
				vet_salas_filmadas[i]=1;
			}
			if(i>=size-1){printf("%d}\n\n", vet_salas_filmadas[i]);}
			else         {printf("%d, ",  vet_salas_filmadas[i]);}
		}

		//Alterando a matriz inicial para que na proxima identificação da melhor sala,
		//não seja considerado salas que já estão sendo filmadas;
		for(int i=0; i<=size-1; i++){
			for(int j=0; j<=size-1; j++){
				if(vet_salas_filmadas[j]==1){
					mat[i][j]=-1;
				}
			}
		}

		//Imprimir a nova matirz
		printf("matriz Alterada = {");
	    for(int i=0; i<=size-1; i++){
	        if(i==0){printf("{");}
	        else{printf("\t\t    {");}
	        for(int j=0; j<=size-1; j++){
                if(i<size-1){
                    if(j==size-1){printf("%d},\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}
                }else{
                    if(j==size-1){printf("%d}};\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}}
	        	}
	    	}    
	    printf("\n");		

	}

	int temp;
	//Ordenando pelo método bolha o vetor das salas com câmera;
	for(int i=0; i<=size-1; i++){
		for(int j=0; j<=size-1; j++){
			if(vet_salas_c_camera[i]<vet_salas_c_camera[j]){
				temp=vet_salas_c_camera[j];
				vet_salas_c_camera[j]=vet_salas_c_camera[i];
				vet_salas_c_camera[i]=temp;
			}
		}			
	}


	//imprimindo as salas com câmeras;
	printf("Para monitorar todos os pontos, deve-se utilizar %d cameras, nos pontos: ", cont);
	print_recursivo(vet_salas_c_camera, size, 0);
	printf("\nLembre-se, a contagem das salas se inicia no zero :)");

	return 0;
}

//Professor,
//Tenho motivos para crer que esse código feito por mim não fornece sempre o melhor resultado possivel para todos os casos,
//pois escolhas individual subsequentes da melhor câmera nem sempre fornecem a solução mais vantajosa, de maneira que escolhas
//visando o cenário geral podem vir a se tornar preferiveis. Porém não encontro, em meus conhecimentos, solução para tal
//problema que não envolva a realização de caso-a-caso (força bruta);
	//Especulação da solução F.B.I.:
		// double bin(int n){
		//     static int i=0;
		//     if(n<=1){return (n%2)*pow(10,i);}
		//     i++;
		//     return ( (n%2)*pow(10,i-1) + bin((n-(n%2))/2 ));
		// }
	//usar a função bin para obter todas as possibilidades de uma câmera estar sim ou não numa sala (semelhante a ideia da tabela verdade);
	//criar um vetor com tamanho pow(2,salas) e armazenar cada possibilidade de distribuir câmeras;
	//usar loops para percorrer todas as possibilidade e excluir aquelas que não conseguem filmar todas as salas;
	//usar mais 1 loop para ver qual das soluções oferece menor uso de câmeras: sequencia binaria que deverar associar
	//os 1´s com as salas em que devem ser instaladas câmeras, e, finalmente, imprimir a saída na tela.	
//O mesmo problema me ocorreu visando maximização dos lucros em um investimento de X reais e N ações disponiveis - Desafio 1(lista);
//Entretanto, a solução acima fornece na maioria dos casos resultados, se não ideais, bem próximos do ideal;
