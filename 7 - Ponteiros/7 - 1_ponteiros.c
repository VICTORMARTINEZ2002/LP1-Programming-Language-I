PONTEIROS E ALOCAÇÃO DINANICA
-> Introdução:
	● Ponteiro são um dos recursos mais poderosos da linguagem C; e um dos mais difíceis de dominar;
	● Permitem simular chamadas por referência;
	● Permitem criar e manipular estruturas dinâmicas de dados (que podem crescer ou diminuir), como:
		-Listas encadeadas;
		-Filas;
		-Pilhas;
		-Arvores;

-> Declaração e Inicialização de Variáveis Ponteiros:
	● São Variáveis que contem endereços de memória como valor;
	● Uma variável faz referencia direta a um valor especificado;
	● Um ponteiro, por outro lado, contém um endereço de uma variável que contém um valor específico;
		int *contPtr, cont;
		-cont faz uma referência direta a uma variável;
		cont    -> valor;
		-contPtr faz uma referência indireta a uma variável;
		contPtr	-> cont -> valor;	

		Obs-1: "*" indica que a variavel é um ponteiro;
		Obs-2: o ponteiro deve ser do mesmo tipo que a variavel apontada;

-> Boas práticas de programação:
	1. Incluir as letra "ptr" em nomes de variáveis de ponteiro para tornar claro que essas variáveis são ponteiros e precisam ser manipuladas apropriadamente;
	2. Inicialize ponteiros para evitar resultados inesperados:
		-Podem ser inicializados com um endereço, 0 ou NULL
		-O mais recomendado é NULL, quando um ptr recebe NULL, ele não está apontando para lugar algum;

-> Operadores de ponteiros:
	● "&" é um operador unário que retorna o endereço do seu operando;
		-exemplo:
			int y=5;
			int* y_ptr=&y;
			// y_ptr recebe o endereço de y;
			// y_ptr "aponta" para y;

			y_ptr -> y -> valor;
			y: 	   conteúdo: 5;
			       endereço: 600000;
			y_ptr: conteudo: 600000;
				   endereço: 700000;  	

	● "*" operador que retorna o valor do objeto ao qual o seu operando aponta
		-exemplo:
			int a, *a_ptr=NULL;
			a=7;
			a_ptr=&a;

			-> OBS: %p mostra o endereço na memória como inteiro hexadecimal

			//endereço de "a" e valor de "a_ptr"
			printf("%p e %p", &a, aptr); 
			saída: FFF4 e FFF4		   

			//valor de "a" e valor de "*a_ptr"
			printf("%d e %d", a, *a_ptr);
			saída: 7 e 7;

			//Note que: "*" e "&" cancelam-se
			printf("%p e %p", &*a_ptr, *&a_ptr);
			saída: FFF4 e FFF4

-> Exercício 1: Qual será a saída do seguinte programa em C?
	int main(){
		int *ptr_c, c=5;
		ptr_c = &c;
		c = 1;
		printf("%d e %d", c, *pc);
		return 0;
	}   //Saída: 1 e 1

-> Relação entre vetor e endereços
	● Conside a seguinte leitura de string:
		char str[20];
		scanf("%s", str);
		//Obs: como os endereços de cada posição são consecutivos, basta saber a posição 0;
	● o "&" é utilizado no scanf para fornecer o endereço da varável;
	● Observe que o vetor é passado para o scanf() sem o "&";
	● O nome de um vetor é o endereço do inicio do vetor:
		- Portanto, o "&" não é necessário;
		- str equivale a &str[0];
		- nome de um vetor é um "ponteiro" que aponta para o seu início;	

-> Chamando Funções
	● Há 2 maneiras de passar argumento à uma função: por valor e por referência;
	- Passagem por valor:
		- Como são todas as chamadas de função em C;
		- No momento em que a função é chamada, uma variável local é criada, na qual é copiado o valor da variável passada como parâmetro;
		- Alterações na variável local não refletem na variável "original";
			void funcao(int a, int b){
				a += b;
				printf("Na função, a=%d e b=%d\n", a, b);
			}

			int main(void){
				int x=5; y=7;
				funcao(x,y);
				printf("Na main, x=%d e y=%d\n", x, y);
				return 0;
			}	//Saída:
						Na função: a=12 e b=7;
						Na main:   x=5  e y=7;

		-> Desvantagens da passagem por valor:
			- Uso ineficiente da memória, pois a cada argumento tem-se uma variável consumindo memória;
				- A situação piora quando argumentos são vetores;
			- Para vetores, o processo de cópia é custoso
				- Imagine um vetor de 100 posições;
				- A cada chamada da função, 100 operações de cópias serão realizadas;

	- Passagem por referência
		- O C fornece um emio de simular chamadas por referência, utilizando ponteiros;
		- Em vez de valor, é passado um ponteiro com o endereço da variável;
			- permitindo a manipulação direta da variável, e não de um cópia;
		- exemplo:
			void troca(int *i. int *j){
				int temp = *i;
				*i = *j;
				*j = temp;
			}			

			int main(void){
				int *ptr_a, *ptr_b, a=10, b=20;
				ptr_a = &a;
				ptr_b = &b;
				troca(ptr_a, ptr_b);
				printf("a é %d e b é %d\n", a, b);
				return 0;
			}	

-> Expressões Aritmética de Ponteiros
	● Operações Aritmética podem ser realizadas com ponteiros. Um ponteiro pode ser:
		- Incrementado (++) ou decrementado(--);
		- adicionado a um inteiro (+ or +=);
		- subtraido  a um inteiro (- or -=);
		- um ponteiro pode ser somado/subtraido de outro;

	● Pergunta: Considere um int vet[100] no qual o seu início tem endereço 3000;
	//Considere que sizeof(int) = 4 bytes;
		int *ptr, vet[100]; // Considere que &vet[0]=3000;
		ptr = vet           // ou ptr = &vet[0];
		printf("%d", ptr);  // mostra 3000;
		ptr +=2;      
		printf("%d", ptr);	// Qual a saída?
	-> Resposta: 3008;
		- O operador aritmético do ponteiro funciona de acordo com o tipo de dado;
		- Ptr += 2, o faz apontar para v[2], 8 bytes a mais na memória;
		// 3008    = 3000 + 2*4;
		// (ptr+n) = 3000 + n*sizeof(type);

-> Exercício 2: Qual será a saída do seguinte programa em C?
	#include <stdio.h>

	int main(void){
		int a=30, b=5;
		int *ptr_a = &a;
		int *ptr_b = &b;
		printf("%d ", ptr_a);
		printf("%d ", ptr_b);				
		printf("%d ", ptr_a-ptr_b);
		printf("%d ", sizeof(int));
		return 0;
	}   //Saída: 1;

	-> Resposta: 1;
		- A declaração consecutiva de Variáveis do mesmo tipo, são em endereços também consecutivos;
		- A diferença de endereços é expressa em escala de sizeof(type), nesse caso, sizeof(int)=4;
		- Compilando, obtemos: 6422292 6422288 1 4;

-> Exercício 3: Qual será a saída do seguinte programa em C?
	int main(void){
		char *ptr="Ponteiro-para-String", i;
		printf("%s", ++ptr);
		return 0;
	}	//Saída: "onteiro-para-String"

-> Ponteiro para Ponteiro
	● Na linguagem C, um ponteiro pode apontar para outro ponteiro, permitindo:
		- passagem de matrizes por referência;
		- alocação dinâmica de matrizes;
		- operações de manipulação em estrutura de dados: insersão e remoção em arvores/listas encadeadas;

	●	ptr_a -> ptr_b -> variavel;		

			 	    ptr2    ptr1      var
    	conteudo:  (4020)⇘  (2008)⇘  (10)
		endereço:  {3096}  ⇒{4020} ⇒{2008}

		- O primeiro ponteiro (ptr1) armazena o endereço da variável;
		- O segundo  ponteiro (ptr2) armazena o endereço do primeiro ponteiro;	

	● Sintaxe: int **ptr; //Declaração de um ponteiro de ponteiro;

	● Exemplo:
		int var=10;
		int *ptr1;
		int **ptr2;  //   *ptr2 == ptr1 
		ptr1=&var;
		ptr2=&ptr1;
		printf("%d %d %d", var, *ptr1, **ptr2);
		// Saída: 10 10 10

-> Exercício 4: Crie uma função em C para tocar o valor de duas variavel do tipo int, utilizando chamada pro referência;
	#include <stdio.h>

	void troca(int *ptr_x, int *ptr_y){
		int temp; 
		temp   = *ptr_x;     // A variavel temp recebe o conteudo apontado pelo ponteiro x, que é o conteudo da variavel num1;
		*ptr_x = *ptr_y;     // O conteudo apontado pelo ponteiro x (num1) recebe o conteudo apontado pelo ponteiro y (num2);
		*ptr_y =   temp;     // O conteudo apontado pelo ponteiro y (num2) recebe o conteudo apontado pelo ponteiro x (num1), armazenado na variavel temp;  
	}


	int main(void){
		int num1,num2;
		printf("Insira Num 1: ");
		scanf("%d", &num1);
		printf("Insira Num 2: ");
		scanf("%d", &num2);
		printf("Num 1: %d e Num 2: %d;\n", num1, num2);	

		int *ptr1; 		// Mesmo que:	
		int *ptr2;		// int *ptr1=&num1;
		ptr1 = &num1;	// int *ptr2=&num2;	
		ptr2 = &num2;	

		troca(ptr1, ptr2); // Mesmo que: troca(&num1, &num2);
		printf("A funcao troca foi executada!\n");
		printf("Num 1: %d e Num 2: %d;\n", num1, num2);	

		return 0;
	}

-> Exercício 5: Crie um programa em C para mostrar na tela todas as letras do alfabeto ultilizando ponteiros;
	#include <stdio.h>

	void printf_alfabeto(char *ptr){
		int i=0;
		char *ponteiro=NULL;
		while(i<=25){
			ponteiro = (i+ptr);        // O ponteiro recebe o endereço alphabet[0]+contador;
			printf("%c", *ponteiro);
			i++;
		}
	}

	int main(void){
		//Brincando de criar a string de um modo mais legal;
		char alphabet[27];
		int ascii=97;
		for(int i=0; i<=26-1; i++){
			alphabet[i]= (char)(i+ascii);
		}	alphabet[26]='\0';

		// O tamanho de um char é 1byte;
		//printf("%d ", &alphabet[0]);
		//printf("%d ", &alphabet[1]);


		printf_alfabeto(alphabet);
		return 0;
	}	

-> Exercício 6: Escreva um programa em C para calcular a soma de todos os elementos em um array usando ponteiros;
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	void soma(int *ptr, int tamanho){
		int sum=0;
		int *temp_ptr=NULL;

		for(int i=0; i<=tamanho-1; i++){
			temp_ptr = ptr + i; //pq não é i*sizeof(int)? não sei, mas funciona aparentemente assim;

			printf("%d ", temp_ptr);
			sum += *temp_ptr;
		}

		printf("Soma: %d", sum);

	}

	int main(void){
		int tam;
		printf("Insira o tamanho do vetor: ");
		scanf("%d", &tam);

		int vet[tam];
		srand(time(NULL));
		for(int i=0; i<=tam-1; i++){
			vet[i]=(1+rand()%20);
			printf("%d ", vet[i]);
		}	printf("\n");

		// printf("Endereço da posição 0 do vetor: %d\n", vet);
		// printf("Endereço da posição 1 do vetor: %d\n", &vet[1]);
		soma(vet, tam);
		
	}	

-> Alocação DINÂMICA: 
	● É uma das aplicações mais interessantes de ponteiros;
	● Permite a um programa requisitar memória adicional para o armazenamento de dados durante sua execução;
		programa:		  memória livre
						  ______________								
		p:▭------------> |____________|

-> Função malloc:
	● Antes de mais nada, para usar a a função malloc é necessario incluir a biblioteca <malloc.h>;
	● Para requisitar mais espaço de memória, utilizamos a função malloc();
	● void *malloc(unsigned int size):
		- recebe como argumento o tamanho, em bytes, da área a ser alocada;
		- se houver memória disponivel, o endereço dessa área é retornado, SENÃO, é retornado NULL;
		- como malloc não sabe o tipo dos dados a serem armazenados, é retornado um ponteiro void*;
	
	● Exemplo: vetores dinâmicos
		#include <stdio.h>
		#include <malloc.h>	

		int main(void){
			//Criar o vetor:
			int *vet_din=NULL;
			int tam=0;

			printf("Tamanho do vetor? ");
			scanf("%d", &tam);
			vet_din = malloc(tam*sizeof(int));  // Como o retorno de malloc é void*, o C faz cast automático para int*;
												// Então na compilação ocorre: vet_din = (int*)malloc(tam*sizeof(int));				
			if(vet_din==NULL){return -1;}

			// preencher o vetor:
			int i=0;
			for(i=0; i<=tam-1; i++){
				printf("%d valor: ", i+1);
				scanf("%d", &vet_din[i]);
			}

			//Imprimir o vetor:
			for( i=0; i<=tam-1; i++){
				printf(" %d", vet_din[i]);
			}

			// Liberar o vetor:
			free(vet_din); //libera memória alocada para vet_din;
			return 0;
		}
			
	● A partir do C99, é permitido declarar o tamanho de um vetor, por meio de uma variavel;
	Exemplo:
		int tam=0;
		printf("Tamanho do vetor\n");
		scanf("%d", &tam);
		int v[tam];
	● Isso não é boa prática de alocação dinâmica!
		- uma vez declarado, "v" não pode alterar de tamanho;
			+ com ponteiros isso é possivel usando realloc();
		- não fornece nenhum mecanismo para detecção de falhas;
			+ se "tam" ultrapassar o espaço de memória disponivel, um erro inesperado pode ocorrer:
			char v[tam];
			char *v = (*char)malloc(tam*sizeof(char));	
			if(v==NULL){
				// Alocação falhou, abortar ou tomar uma ação corretiva;
			}

	● Exemplo: Matrizes dinâmicas
		#include <stdio.h>

		#include <stdlib.h>
		#include <time.h>
						
		#include <malloc.h> // o stdlib inclui o malloc, mas enfim...

		int main(void){
			// Criando a matriz dinâmica:
				int **ptr_ptr_mat = NULL;
				int linhas=3, colunas=5;

				// malloc aloca espaço para "linhas" ponteiros do tipo int: "um vetor int* com "Linhas" posições";
				// "ptr_ptr_mat" aponta para a 1º possição desse vetor
				ptr_ptr_mat = (int**)malloc(linhas*sizeof(int*));

				// para cada ponteiro ptr_ptr_mat[i], malloc aloca espaço para "colunas" inteiros: "um vetor int com "colunas" posições"		
				// ptr_ptr_mat[i] aponta para a 1º possição desse vetor
				for(int i=0; i<=linhas-1; i++){
					ptr_ptr_mat[i] = (int*)malloc(colunas*sizeof(int));
				}	

			// Preenchendo a matriz dinâmica:
				srand(time(NULL));
				for(int i=0; i<=linhas-1; i++){
					for(int j=0; j<=colunas-1; j++){
						ptr_ptr_mat[i][j] = rand()%100;
					}
				}

			// Imprimindo a matriz dinâmica:
				for(int i=0; i<=linhas-1; i++){
					for(int j=0; j<=colunas-1; j++){
						printf("%d ",ptr_ptr_mat[i][j]);
					} printf("\n");
				}

			return 0;
		}				

	-> Visualmente o codigo acima se traduz da seguinte forma:
		int **ptr_ptr_mat=NULL;
			ptr_ptr_mat ------------>	NULL;

		ptr_ptr_mat = (int**)malloc(linhas*sizeof(int*));
			ptr_ptr_mat ------------>	▭ 0
										▭ 1
										▭ 2
										▭ ...
										▭ linhas-1			

		for(int i=0; i<=linhas-1; i++){
			ptr_ptr_mat[i] = (int*)malloc(colunas*sizeof(int));
		}	
												  0	 1  2     colunas-1
			ptr_ptr_mat ------------>	0 		  ▭ ▭ ▭ ...   ▭
										1 		  ▭ ▭ ▭ ...   ▭
										2         ▭ ▭ ▭ ...   ▭
										... 	  ▭ ▭ ▭ ...   ▭
										linhas -1 ▭ ▭ ▭ ...   ▭

-> Exercício 7: Crie uma agenda em C para armazenar telefones de N (entrada) pessoas;
			  Crie uma função void addTelefone(int *agenda, int numero)
			   que adiciona um número ao 1º espaço em branco da agenda;
			   dica: ultiliza um contador passado por referência para guardar o num de registros;
	#include <stdio.h>
	#include <malloc.h>

	void addTelefone(double *agenda, int tlf, int *cont){
	    agenda[*cont]=tlf;
	    (*cont)++;
	}

	int main(void) {
	    int qtd=0;
	    printf("Insira a qtd de contatos: ");
	    scanf("%d", &qtd);
	    printf("QTD: %d\n", qtd);

	    double *agenda = NULL;
	    agenda = (double*)malloc(qtd_ini*sizeof(double));
	    if(agenda==NULL){printf("Erro na Alocação!");}

	    int cont=0;
	    int *ptr_cont=&cont;
	    
	    int tlf=0;
	    while(cont<qtd){
	        printf("    Insira o numero de telefone %d: ", cont+1);
	        scanf("%d", &tlf);
	        addTelefone(agenda, tlf, ptr_cont);
	    }

	    printf("-----AGENDA-----\n");
	    for(int i=0; i<=qtd-1; i++){
	        printf("Telefone %d: %.0lf\n", i+1, agenda[i]);
	    }
	    printf("----------------\n\n\n");

	    printf("Fim do programa!");
	    return 0;
	} 
	
-> Realocação de memória:
	● O C permite dinamicamente alterar a alocação de memória previamente alocada;
	● Para isso, faz-se uso da função void* realloc(void* ptr, unsigned size);
		- Altera o tamanho do bloco de memória apontado por ptr;
		- movendo o bloco para um novo local (junto com seu conteudo);
			+ o endereço desse local é retornado pela função;
		- se a realocação falhar, NULL é retornado;
  	{I} PTR              {ÌI} PTR pós realloc
	|'a'|_|'b'|_|'c'|    |'a'|_|'b'|_|'c'|_|   |_|  | 
	#301  #302  #303 	 #750   #751  #752  #753 #754	

	● OBS MINHA: ao realocar um vetor de inteiros, as novas posições recebem 0; 		
		   
-> Requisitando aumento de um vetor de inteiros:
	#include <stdio.h>
	#include <malloc.h>

	#include <time.h>
	#include <stdlib.h>

	int main(void){
		int *vet=NULL, tam_ini=0;
		printf("Insira o tamanho original: ");
		scanf("%d", &tam_ini);



		//alocando t_inicial int:
		vet = (int*)malloc(tam_ini*sizeof(int));

		//preenchendo com valores random:
		srand(time(NULL));
		for(int i=0; i<=tam_ini; i++){
			vet[i]=rand()%100;
		}

		//mostrando vet inicial:
		for(int i=0; i<=tam_ini-1; i++){
			printf("%d ", vet[i]);
		}	printf("\n");

		int tam_ext=0;
		printf("Insira o tamanho a ser adicionado: ");
		scanf("%d", &tam_ext);

		//realocando vet - tam_fim int
		int tam_fim = tam_ext + tam_ini;
		vet = (int*)realloc(vet, tam_fim*sizeof(int));

		//preenchendo o novo espaço do vetor:
		for(int i=tam_ini; i<=tam_fim-1; i++){
			vet[i]=rand()%100;
		}

		//mostrando vetor final:
		for(int i=0; i<=tam_fim-1; i++){
			printf("%d ", vet[i]);
		}
		return 0;
	}

-> Exercício 8: A partir do exercicio anterior, suponha que a agenda necessite suportar k telefones a mais
			  que a sua capacidade atual. utilizando a função realloc(), aumente o tamanho da agenda
			  e adicione mais "K" telefones nela;	
	#include <stdio.h>
	#include <malloc.h>

	void addTelefone(double *agenda, int tlf, int *cont){
	    agenda[*cont]=tlf;
	    (*cont)++;
	}

	int main(void) {
		// PRATICAMENTE INALTERADO:
	    int qtd_ini=0;
	    printf("Insira a qtd de contatos: ");
	    scanf("%d", &qtd_ini);
	    printf("QTD: %d\n", qtd_ini);

	    double *agenda = NULL;
	    agenda = (double*)malloc(qtd_ini*sizeof(double));
	    if(agenda==NULL){printf("Erro na Alocação!");}

	    int cont=0;
	    int *ptr_cont=&cont;
	    
	    int tlf=0;
	    while(cont<qtd_ini){
	        printf("    Insira o numero de telefone %d: ", cont+1);
	        scanf("%d", &tlf);
	        addTelefone(agenda, tlf, ptr_cont);
	    }

	    printf("-----AGENDA-----\n");
	    for(int i=0; i<=qtd_ini-1; i++){
	        printf("Telefone %d: %.0lf\n", i+1, agenda[i]);
	    }
	    printf("----------------\n\n\n");

	    // EXPANDINDO A AGENDA:
	    int qtd_extra=0;
	    printf("Expandindo a agenda em quantas unidades? ");
	    scanf("%d", &qtd_extra);

	    int qtd_fim= qtd_ini + qtd_extra;
	    agenda = (double*)realloc(agenda, qtd_fim*sizeof(double));

	    while(cont<qtd_fim){
	        printf("    Insira o numero de telefone %d: ", cont+1);
	        scanf("%d", &tlf);
	        addTelefone(agenda, tlf, ptr_cont);
	    }

	    printf("-----AGENDA-----\n");
	    for(int i=0; i<=qtd_ini-1; i++){
	        printf("Telefone %d: %.0lf\n", i+1, agenda[i]);
	    }
	    printf("----------------\n\n\n");

	    printf("Fim do programa!");
	    return 0;
	} 


