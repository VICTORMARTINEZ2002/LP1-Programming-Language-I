	S T R U C S    A N D   U N I O N
STRUCS:
		● Strucs (estruturas) são conjuntos de variáveis agrupada que possuem um mesmo nome;
			- as variaveis são as partes de um todo (struct);
			- podem conter variaveis de vários tipos: int, char, double, int*, char[10], ...
		● Um "tipo" de variavel criado pelo programador;
		● São utilizadas na criação de estruturas mais complexas de dados, como:
			- listas encadeadas;
			- filas;
			- pilhas; 
			- arvores;

	Definições
		● Considere a seguinte definição de struct:
			struct carta {           ● struct:               palavra reservada para se criar uma estrutura;
				char face[25];       ● carta:                nome da struct criada. Usada para declarar variàveis do tipo da struct; 
				char naipe[25];		 ● face[25] e naipe[25]: são menbros da struct; 	
			};			
		->  OBS: Cada definição deve ser encerrada com ; (ponto e virgulo)	
			
	Declaração:
		● Uma variável pode ser declarada juntamente com a struct:
			struct ponto {
				int x, y;
			}	p1;										
		Ou como em tipos básicos do C:	
			struct ponto{
				int x, y;
			};

	 Inicialização:
	 	● Menbro não podem ser inicializados junto com a declaração da struct:
	 		struct ponto{
	 			int x=0;   // ERRO DE COMPILAÇÃO
	 			int y=0;   // ERRO DE COMPILAÇÃO
	 		};			   // não há memória alocada para a atribuição de valores				
	 	● Exemplo de declaração (dentro da main) válida:
	 		- struct ponto p1 = {0,1};	

	Estruturas Auto-Referenciais
		● Uma estrutura NÃO PODE CONTER UMA INSTÂNCIA DE SI MESMA
			- por exemplo, uma variavel do tipo struct
				struct empregado {
					primeiroNome[20];
					sobrenome[20];
					unsigned int age;
					char genero;
					double salario;
					struct empregado pessoa; // ERRO
					struct empregado *ePtr;  // ponteiro
				};  // fim da struct empregado
			- empregado não pode ser declarado na definição de struct empregado;
			- um ponteiro para a estrutura de funcionário, no entanto, pode ser incluido;	

	Acesso a menbros da struct
		● Menbros de estruturas são acessadas utilizando o operador ponto (.)
			struct ponto{
				int x,y;
			};

			int main(void){
				struct ponto p1 = {0, 1};
				// acessando menbros do ponto p1
				p1.x = 20;
				printf("x = %d, y = %d", p1.x, p1.y);
				return 0;
			}   // Saida: x=20, y=1;

	Vetores de struct
		● Assim como outros tipos primitivos, podemos criar vetores de structs:
			struct ponto{
				int x,y;
			};

			int main(void){
				struct ponto arr[10];    // Cria um vetor de ponto

				// Acessando os menbros da 1º possição do vetor:
				arr[0].x = 10;
				arr[0].y = 20;
				printf("%d %d", arr[0].x, arr[0].y]);
				return 0;
			}		 

	Ponteiro de struct
		● Como em tipos primitivos, podemos ter ponteiros para struct:
			- nesse caso, os menbros são acessados pelo operador (->)
			- Ou pelo operador ponto (.), desde que faça (*ptr).membro da struct;
				struct ponto{
					int x,y;
				};

				int main(void){
					struct ponto p1 = {1,2};

					// p2 é um ponteiro para struct p1
					struct ponto *ptrP1 = &p1;

					// acessando menbros da struct usando ponteiro
					printf(" %d %d ", *ptrP1.x, ptrP1->y);
					return 0;
				}
		● No exemplo anterior: (*p2).x equivale a p2->x		
		● esse (parenteses) é obrigatorio, porque o operador ponto "." tem preferencia sobre o operador conteudo "*"; 	

	typedef:
		● É um comando que cria um "sinonimo" ou "apelido" para tipos de dados existentes;
		● Renomeia um tipo de dado, que pode facilitar a organização e o entendimento do código;
		● sintaxe: typedef <nome do tipo de dado> <novo nome>;
		● exemplo 1: 
			struct ponto{
				int x,y;
			};

			typedef struct ponto Ponto;

			int main(void){
				ponto p1 = {1,2};
				return 0;
			}
		● exemplo 2: 
			typedef struct{
				int x,y;
			}Ponto;

			int main(void){
				Ponto p1 = {1,2};
				return 0;
			}		
		-> Não se faz necessário o uso de struct toda vez que for usar a estrutura;
			
	Exercicio:
		1. Crie uma struct para representar uma Pessoa, com nome (até 100 caracteres) e telefone; em seguida, crie uma agenda para armazenar o contato de até 3 pessoas;
		2. Crie uma função void addPessoa(Pessoa *agenda, Pessoa pessoa, int indice) que adicione uma pessoa à agenda, por vez;
		3. Use a função para adicionar 3 pessoas e mostre o conteúdo da agenda na main;
		4.  A partir do exercício anterior, crie uma função para buscar uma pessoa na agenda (pelo nome) e retornar o número do seu telefone;

	Solução:
		#include <stdio.h>
		#include <string.h>
		#include <malloc.h>

		struct _data{
			int dia;
			int mes;
			int ano;
		};

		struct _pessoa{
			char nome[101];
			int  telefone;
			struct _data nasc;
		};

		void addPessoa(struct _pessoa *agenda, struct _pessoa umaPessoa, int indice){
			strcpy(agenda[indice].nome, umaPessoa.nome);
			agenda[indice].telefone = umaPessoa.telefone;
			agenda[indice].nasc     = umaPessoa.nasc;
		}

		void buscaPessoa(struct _pessoa *agenda, char* nomeBuscado, int tam){
			for(int i=0; i<=tam-1; i++){
				if(strcmp(agenda[i].nome, nomeBuscado)==0){
					printf("Encontrado!\n Telefone: %d\nNascimento: %d/%d/%d", agenda[i].telefone, agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
					return;
				}
			}
			printf("Não Encontrado!");
		}

		int main(void){
			int n=2;
			struct _pessoa *agenda;
			agenda = malloc(n*sizeof(struct _pessoa));

			for(int i=0; i<=n-1; i++){
				struct _pessoa umaPessoa;
				printf("Nome da pessoa %d: ", i+1);
				fgets(umaPessoa.nome, sizeof(umaPessoa.nome)-1, stdin);
				printf("Telefone da pessoa %d: ", i+1);
				scanf("%d", &(umaPessoa.telefone));
				getchar();

				printf("dia nasc da pessoa %d: ", i+1);
				scanf("%d", &(umaPessoa.nasc.dia));
				getchar();	
				printf("mes nasc da pessoa %d: ", i+1);
				scanf("%d", &(umaPessoa.nasc.mes));
				getchar();		
				printf("ano nasc da pessoa %d: ", i+1);
				scanf("%d", &(umaPessoa.nasc.ano));
				getchar();							
				addPessoa(agenda, umaPessoa, i);
			}

			for(int i=0; i<=n-1; i++){
				printf("Nome da pessoa %d = %s", i+1, agenda[i].nome);
				printf("Telf da pessoa %d = %d\n", i+1, agenda[i].telefone);
				printf("Nascimento da pessoa %d: %d/%d/%d\n", i+1, agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
			}

			char name[101];
			printf("Insira nome para ser buscado: ");
			fgets(name, sizeof(name), stdin);
			buscaPessoa(agenda, name, n);

			return 0;
		}

UNIONS:
		● Uma união é um tipo derivado de dados (como uma struct);
			- porem, os menbros compartilham o mesmo espaço de armazenamento;
		● Por que usa-las?
			- as vezes algumas variaveis podem não ser apropriadas, mas outras, não.
			- portanto, uma união compartilha o espaço em vez de desperdiçar armazenamento me variaveis que não estão sendo usadas.
		● os menbros de uma união podem ser de qualquer tipo.
		● o Numero de bytes usado para armazenar uma união deve ser pelo menos o suficiente para conter o maior menbro.

		● Apenas um menbro e, portanto, um tipo de dado, pode ser referenciado por vez;
		● É sua responsabilidade assegurar que os dados de uma união sejam referenciados com o tipo apropriado.

	Declaração:
		● Uma definição de union tem o mesmo formato que uma definição de struct:
			union number {
				int x;
				double y;
			}; // end union number

	Inicialização:
		● Em uma declaração, uma união pode ser inicializada com um valor do mesmo tipo do primeiro membro da união.
			- union number value = {10};
		● Se dizessemos union number value = {1.43};
			- a declaração truncaria a parte de ponto flutuante e seria produzido um aviso do compilador;

	Exemplo de utilização:
		union number{
			int x;
			double y;
		}			

		int main(){
			union number value; //definição da variavel union
			value.x=100;        //colocando um inteiro na union
			printf("x=%d y=%lf", value.x, value.y);
			value.y=100.0;      //colocando um double na union
			printf("\nx=%d y=%lf", value.x, value.y);
			return 0;
		}		

	Exercicio: qual será a saida do seguinte programa em C?
		typedef union{
			float salary;
			int workerNo;
		} Job;


		int main(){
			Job j;
			j.salary =12.3;
			j.workerNo=100;
			printf("Salario = %.1f\n", j.salary);
			printf("Num de trabalhadores = %d\n", j.workerNo);
			return 0;
		}   // Saida: 
			// Salario = 0.0
			// Num de trabalhadores = 100


















































































