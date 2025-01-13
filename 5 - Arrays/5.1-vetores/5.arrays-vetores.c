Arrays
	● Um Array (ou vetor) é uma coleção de variáveis de um mesmo tipo, que compartilham o mesmo nome
	  e que ocupam posições consecutivas de memória.
	● Cada uma dessas variáveis é identificada por um índice.
	 -Se v é um vetor com n posições, seus elementos são v[0],v[1],v[2],...,v[n-2],v[n-1].
	 	nome do vetor	0 1 2      n-1  <-- Indices
	 			vet:  	□ □ □  ...  □   			
	 					\___________/
	 					  elementos
	 -Em C, so vetores são sempre indexados a partir de zero e, portanto, o último elemento de um vetor
	  de tamanho n ocupa a posição n-1 do vetor.

Declarando vetores
	● Um vetor para armazenas 5 números inteiros pode ser criado da seguinte maniera: int v[5];
	● Um vetor pode ser indexado com qualquer expressão cujo valor seja inteiro:
	 -Por exemplo, considere i=5:
		 (1) w[0]      = 17;
		 (2) w[i/2]    = 9;
		 (3) w[2*i-2]  = 95;
		 (4) w[i-1]    = w[8]/2;
		 (5) w[i]      = w[2];
		 (6) w[i+1]    = w[i]+w[i-1];
		 (7) w[w[2]-2] = 78;
		 (8) w[w[i]-1] = w[i]*w[i];
	● C não verifica a consistência dos valores usados como índices.
	 -Qualquer valor pode ser usado como índice, mesmo que seja inadequada;
	 -É responsavilidade do programador definir corretamente os índices;

Inicializando um vetor
	● Inicializando um vetor sem especificar a quantidade de elementos:
		int valores[] = {3,5,7};
	● Inciando apenas alguns elementos do vetor:
		int valores[5]= {2,4,6}; será equivalente: int valores[5]= {2,4,6,0,0};	

Operador sizeof()
	● Retorna i tamanho em bytes que uma variável está utilizando na memória;
	 -Também retorna o tamanho de tipos (int, float, long int, ...);
	 -Ex: int v[]={3,4,6,7}
	  	+ O número de elementos de v será: sizeof(v)/sizeof(int);
	  	+ Uma variável inteira equivalente a 4 bytes, então, o número de elementos em v será 4: (4+4+4+4)/4;

Vetores como argumento de funções
	#include <stdio.h>
	void func(int v[]); //protótipo, não necessita explicitar o tamanho do vetor;
	int main(void){
		int v[3];
		v[0]=12;
		v[1]=13;
		func(v);
		return 0;
	}	
	void funcao(int v[3]){
		printf("1º Elemento de v: %d\n", v[0]);
		printf("2º Elemento de v: %d\n", v[1]);		
	}

	-> Assim como nas outras variaveis, a cada chamada de função, é criada uma cópia do vetor passado como parâmetro;
	-> Assim, a função não manipula o vetor original, mas uma cópia dele;
	-> Para manipular o vetor original, esse deve ser passado por referência (estudaremos isso em ponteiros);]

Exercícios:
	1. Escreva um programa em C para contar o número total de elementos duplicados em um array.
		● Dados de teste :
			Insira o número de elementos a serem armazenados no array: 3
			Insira 3 elementos no array:
				elemento - 0: 5
				elemento - 1 : 1
				elemento - 2 : 1
		● Saída esperada:
			O número total de elementos duplicados encontrados no array é: 1
	Solução:
		#include <stdio.h>

		//Passar um vetor como parametro passa apenas o endereço do 1 termo e nesse ponto o tamanho eh perdido;
		int pertence(int n, int vet[], int size){
		    for(int i=0; i<=size-1; i++){
		        if(n==vet[i]){return 1;}
		    }return 0;
		}

		int main(void){
		    int num=0;
		    printf("Insira o numero de elementos a serem armazenados no array:  ");
		    scanf("%d", &num);
		    printf("Tamanho do array: %d\n\n", num);

		    //Criando vetor e recebendo entradas:
		    int vetor[num];

		    printf("Insira %d elementos no array: \n", num);  
		    int i=0;
		    while(i<=(num-1)){
		    printf("Elemento %d: ", i);
		    scanf("%d", &vetor[i]);
		    i++;
		    } printf("Vetor Completamente cheio!\n\n");
		    i=0;

		    //Imprimindo o vetor:
		    printf("vetor   = {");
		    for(i=0; i<=num-1; i++){
		        if(i==num-1){printf("%d}\n",vetor[i]);}else
		        printf(" %d, ", vetor[i]);
		    }
		    i=0;  

		    //criando vetor auxiliar e imprimindo-o:
		    int vet_aux[num];
		    for(i=0; i<=num-1; i++){vet_aux[i]=-1;}

		    printf("vet_aux = {");
		    for(i=0; i<=num-1; i++){
		        if(i==num-1){printf(" %d}\n",vet_aux[i]);}else
		        printf(" %d,", vet_aux[i]);
		    }
		    i=0;     

		    //checarem de repetidos:
		    for(int i=0; i<=num-1; i++){
		        for(int j=0; j<=num-1; j++){
		            if(vetor[i]==vetor[j] && i!=j && !(pertence(vetor[i],vet_aux, sizeof(vet_aux)/sizeof(int)))){
		                vet_aux[i]=vetor[i];
		            }
		        }
		    }

		    //re-impressão do vetor aux:
		    printf("vet_aux = {");
		    for(i=0; i<=num-1; i++){
		        if(i==num-1){printf(" %d}\n",vet_aux[i]);}else
		        printf(" %d,", vet_aux[i]);
		    }
		    i=0;    

		    //contagem repetidos:
		    int cont=0;
		    for(int i=0; i<=num-1; i++){
		        if(vet_aux[i]!=-1){  
		            for(int j=0; j<=num-1; j++){
		                if(vet_aux[i]==vetor[j]){
		                    printf("%d ",vet_aux[i]);
		                    cont++;}
		            }
		                
		        }
		    }
		    printf("\n");
		    printf("Numeros repetidos (orig): %d\n", cont); 

		    //fazendo com que o primeiro numero que vai ser repetido não seja contado:
		    int nums_rept=0;
		    for(int i=0; i<=num-1; i++){
		        if(vet_aux[i]!=-1){nums_rept++;}
		    }
		    cont -= nums_rept;

		    printf("Numeros repetidos: %d\n", cont);
		    return 0;
		}   


	2. Escreva um programa que ordene um vetor (inteiros) de maneira não-decrescente, utilizando o método bolha.	
	Solução:
		#include <stdio.h>

		int main(void){
			int vetor[10]={3, 3, 8, 14, 2, 1, 3, 57, 99, 0};
			int tamn = sizeof(vetor)/sizeof(int);

			printf("vetor   = {");
		    for(int i=0; i<=tamn-1; i++){
		        if(i==tamn-1){printf("%d}\n",vetor[i]);}else{
		        printf(" %d, ", vetor[i]);}
		    }	

			for(int i=0; i<=tamn-1; i++){
				for(int j=0; j<=tamn-1; j++){ //No geral, podemos alterar se queremos o vetor crescente ou decrescente iniciando j=i;
					if(vetor[i]>vetor[j]){    // e/ou alterando o sinal < ou > ; 	
						int aux=vetor[j];
						vetor[j]=vetor[i];
						vetor[i]=aux;

					    printf("vetor   = {");
					    for(int i=0; i<=tamn-1; i++){
					        if(i==tamn-1){printf("%d}\n",vetor[i]);}else{
					        printf(" %d, ", vetor[i]);}
					    }	
					}
				}
				printf("Fim for;\n");
			}

		    printf("vetor   = {");
		    for(int i=0; i<=tamn-1; i++){
		        if(i==tamn-1){
		        	printf("%d}\n",vetor[i]);
		        }else{
		        printf(" %d, ", vetor[i]);
		    	}
		    }
		 

			return 0;
		}

	
	3. Escreva um programa em C para rotacionar à esquerda um vetor em n
		posições.
		○ Ex: n = 3
		○ Array inicial: 1 2 3 4 5 6 7 8 9 10
		○ Array rotacionado: 4 5 6 7 8 9 10 1 2 3	
	Solução:
		#include <stdio.h>

		int main(void){
			int pos = 6;
			int vetor[10]={1,2,3,4,5,6,7,8,9,10};
			int tam = sizeof(vetor)/sizeof(int);

			// Imprimindo o vetor:
			printf("vetor   = {");
		    for(int i=0; i<=tam-1; i++){
		        if(i==tam-1){printf("%d}\n",vetor[i]);}else
		        printf(" %d, ", vetor[i]);
		    } 

			//Fazer função que retorna vetor precisa de ponteiro (e a void deu ruim), então vamo deixar assim:

			/* -- ALTERNATIVA 01 -------------------------------------------------------------------------------------
					int aux=0;

					for(int i=0; i<=pos-1; i++){
						for(int j=0;j<=tam;j++){
							aux=vetor[j];
							vetor[j]  = vetor[j+1];
							vetor[j+1]= aux;
						}
					}
			--------------------------------------------------------------------------------------------------------*/

			/* -- ALTERNATIVA 02 -------------------------------------------------------------------------------------

			    int vet_aux[pos-1];
			    for(int i=0; i<=pos-1; i++){
			    	vet_aux[i]=vetor[i];
			    }

			    for(int i=0; i<=tam-pos-1; i++){vetor[i]=vetor[pos+i];}
			   	int j=0;
			    for(int i=tam-pos; i<=tam-1; i++){
			    	vetor[i]=vet_aux[j];
			    	j++;
			    }	
			--------------------------------------------------------------------------------------------------------*/



			    //Imprimindo o resultado:
			    int i=0;
			    printf("vetor   = {");
			    for(int i=0; i<=tam-1; i++){
			        if(i==tam-1){printf("%d}\n",vetor[i]);}else
			        printf(" %d, ", vetor[i]);
			    }  
				return 0;
			}	



























































