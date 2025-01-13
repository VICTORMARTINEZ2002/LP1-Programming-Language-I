MACROS E FUNÇÕES

Pré-processamento:
	-Todo programa C, antes de chegar ao compilador é tratado por um módulo adicional denominado pré-processador.
	-o pré-processador realiza várias modificações no código antes que seja analisado pelo compilador;
	-Essas modificações são feitas por diretivas, que são embutidas no código-fonte;
	-As duas principais diretivas são:
	 #include
	 #define

	programa.c -> pre-processador -> programa.obj -> linkeditor (adiconar as bibliotecas.lib)-> programa.exe;

A diretiva #define:
	#include <stdio.h>
	#define diga printf
	#define oi "\nOlá, tudo bem?"

	int main(void){
	 diga(oi);
	 return 0;
	}

	Quando o programa passa pelo pré-processador, a diretiva #define é executada e, então, toda ocorrência da palavra diga é substituída por printf e toda ocorrência da palavra oi é substituída por “\nOlá, tudo bem?”.

	Exercício:
		Inclua diretivas #define no programa a seguir de modo que ele possa ser compilado corretamente:
			#include <stdio.h>
			programa
			inicio
				diga("Olá!");
			fim
		Solução:
			#include <stdio.h>
			#define programa main(void)
			#define inicio {
			#define fim }
			#define diga printf	

			programa
			inicio
			diga("Oi!");
			fim	

Macros:
	É possível substituições parametrizadas, ou seja Macros. 
	Por ex.: #define quad(n) n∗n
	Ao passar pelo pré-processador, as ocorrências desse macro são substituídas pela expressão n∗n, com o parâmetro n devidamente instanciado;

	ocorrência      Instancia
	quad(x)		       x*x	
	quad(2)			   2*2	
	quad(f(x-3))  f(x-3)*f(x-3)
	quad(x+4)        x+4*x+4

	!Note que não pode haver espaço entre o identificador do macro e o parêntese que delimita a lista de parâmetros; caso haja, teremos um erro de substituição;
	!Nenhum cálculo é realizado durante o pré-processamento. Ocorre apenas uma simples substituição. Portanto, resultados inesperados podem surgir:
		 ocorrência     esperado     instância     obtido
		 quad(2+3)         25         2+3*2+3        11
		100/quad(2)        25 		  100/2*2		 100

	Exercício:
		Defina e teste os seguintes macros:
		- eh_maiuscula(c): informa se o caractere c é uma letra maiúscula
		- minuscula(c): converte a letra c para minúscula
		- dica: verificar a diferença entre uma letra minúscula e maiúscula
		- mod(a): retorna o módulo de a
		- dica: utilizar operador condicional
		- min(a,b): retorna o valor mínimo entre a e b
		- dica: utilizar operador condicional
	Solução:
			#include <stdio.h>
			#define eh_maiuscula(c) ( (int)c >= 65 && (int)c <=  90 ? "Yes"          : "No"                )
			#define minuscula(c)    ( (int)c >= 97 && (int)c <= 122 ? (char)((int)c) : char(((int)c) + 32) )
			#define mod(a)          ( (a>0) ? a:(-a))
			#define min(a,b)        ( (a<b) ? a:b   )

			int main(void){
				char letra='@';
				printf("Insira uma letra:       ");
				scanf ("%c", &letra);
				printf("A letra escolhida foi:  %c\n", letra);
				printf("Eh maiuscula?           %s\n", eh_maiuscula(letra));
				printf("Minuscula de %c:         \"%c\"\n", letra, minuscula(letra));

				printf("\n");

				double num1=-1;
				printf("Insira o numero 1:       ");
				scanf("%lf", &num1);
				printf("O numero escolhido foi:  %lf\n", num1);
				double num2=-1;
				printf("Insira o numero 2:       ");
				scanf("%lf", &num2);
				printf("O numero escolhido foi:  %lf\n\n", num2);
				printf("Modulo de %lf:  %lf     \n", num1, mod(num1));
				printf("Modulo de %lf:  %lf     \n", num2, mod(num2));
				printf("Menor de %lf e %lf: %lf \n", num1, num2, min(num1,num2));
				return 0;
			}

A diretiva #include
	-Faz com que uma cópia do arquivo cujo nome eh dado entre <> seja incluido no código-fonte;
	-Por exemplo, se criarmos o arquivo macros.h com os seguintes macros: 
		#define quad(n)  ((n)*(n))
	    #define abs(n)   ((n)<0 ? -(n) : (n))
		#define max(x,y) ( (x)>(y) ? (x) : (y) )
		-> Não precisaremos digita-las toda vez que precisarmos usa-las.
		-> Basta pedir para o pré-processador incluir uma cópia de macros.h no nosso codigo-fonte;

	- A convenção em C eh que se use: nome_arquivo.h    ;  	
	- <> eh utilizado para inclusão de headers padrões do C;
	- O pré-processador irá buscar o header em caminho padrão;
	- Ao criar seus proprios headers, deve-se usar ""    ;
	- O pré-processador irá buscar o header no próprio local do codigo fonte;

	#include <stdio.h>
	#include "macros.h"
	void main() {
		int a, b;
		printf("\nDigite 2 núm-eros: ");
		scanf("%d %d", &a, &b);
		printf("\nO máximo é %d!", max(a,b));
	}

	Exercício:
		Crie um cabeçalho (header) com o nome macros.h, que contenha todos os
		macros do exercício anterior. Em seguida faça um programa em C que inclua
		macros.h e teste todos os macros implementados.
	Solução:
		C:\Users\VICTOR\Desktop\_UFMA\2° Período\LP1\4 - Macros e Funções

Funções:
	->Introdução:
		● Funções são usadas para modularizar programas
		● Os programas C são normalmente escritos combinando novas funções que você escreve com funções predefinidas disponíveis na biblioteca padrão C.			
		● A biblioteca padrão C fornece uma rica coleção de funções para realizar:
			-Cálculos matemáticos comuns, manipulações de strings, manipulações de caracteres, entrada / saída e muitas outras operações úteis.
	
	->Definição de função:
		● Até agora, sempre usamos uma função em todos os programas: main(), scanf(), printf(), ...	
		● Mas podemos criar nossas próprias funções e utilizá-las da mesma maneira
		● Para definir uma função básica, empregamos a seguinte forma básica:
			tipo nome(parâmetro){
				declarações
				parâmetros
			}
		● O tipo deve ser void (vazio) se a função não tem valor de resposta;
		● Para que uma função seja reconhecida durante a compilação devemos declará-la 
		ou defini-la antes de qualquer referência que é feita a ela no resto do programa.
			int quadrado(int x){
				return x*x; 
			}

			int main(){
				int y;
				for(y=1;y<=10;y++)
				 printf("%d ", quadrado(y));
				return 0; 
			}

		● No exemplo, a passagem de parâmetro é por cópia;
		● Dentro da função é criada uma cópia de “x”, que inicia e termina seu ciclo de vida no contexto da função;
		● Nenhuma modificação em “x” surtirá efeito fora da função;

	->Erros comuns:
		● Omitir o tipo-do-valor-de-retorno em uma definição de função causa um erro
		  de sintaxe se o protótipo da função especificar um tipo de retorno diferente de int.
		● Se nenhum retorno é definido, assume-se int	
		● Declarar parâmetros da função do mesmo tipo como float x, y em vez de
		  float x, float y. A declaração de parâmetros float x, y tornaria na realidade y
		  um parâmetro do tipo int porque int é o default.
 		● Definir um parâmetro de função novamente como variável local dentro de função é um erro de sintaxe.
 
 	-> Protótipo de função:
 		-ANSI C: conj. de padrões para a linguagem C, publicados pela American National Standards Institute; 
		-Um dos recursos mais importantes do ANSI C é o protótipo de função:
			■ protótipo de função diz ao compilador o tipo do dado retornado pela função, o
			número de parâmetros que a função espera receber, os tipos dos parâmetros e a
			ordem na qual esses parâmetros são esperados.
			■ O compilador usa protótipos de funções para validar as chamadas de funções.
		-Exemplo de protótipos:
			#include <stdio.h>

			int raiz_quadrada(int);

			int main(){
				int y;
				for(y=1;y<=10;y++)
			 		printf("%d ", raiz_quadrada(y));
				return 0;
			}

			int raiz_quadrada( int x){
			return x*x;
			}

			● O protótipo do exemplo é: int raiz_quadrada(int);
			● Algumas vezes, os nomes dos parâmetros são incluídos nos protótipos de funções para fins de documentação. 
			● O compilador ignora esses nomes.

	-> Função main()
		● Observe que main tem um tipo de retorno int.
		● O valor de retorno de main é usado para indicar se o programa foi executado corretamente.
		● Em versões anteriores de C, colocamos explicitamente return 0;
		● no final de main — 0 indica que um programa foi executado com sucesso.
		● O padrão C indica que main implicitamente retorna 0 se você omitir a instrução anterior.
		● Você pode retornar explicitamente valores diferentes de zero de main para indicar que ocorreu um problema durante a execução do seu programa.
		● Para obter informações sobre como relatar uma falha de programa, consulte a documentação de seu ambiente de sistema operacional específico.
	
	-> Exercício função:
		1: Crie uma função double ajuste(double salario, double x), que receba o salário de um funcionário e retorne o salário ajustado (aumento). 
		Se o salário for menor que R$ 900, o reajuste será de 1,5 * x% caso contrário será de apenas x%
		Solução:
			#include <stdio.h>

			double ajuste(double salario, double x){
				double novo_salario  =-1;
				double novo_reajuste = x;
				if (salario<900){novo_reajuste=(1.5 * x);}
				novo_salario = salario * (1+(novo_reajuste/100));
				return novo_salario;
			}

			int main(void){
				double salario=0, reajuste=0;
				printf("Insira respectivamente um salario e um reajuste: ");
				scanf("%lf %lf", &salario, &reajuste);
				printf("Salario:      %lf\n", salario);
				printf("Reajuste:     %lf\n", reajuste);
				printf("Novo Salario: %lf\n", ajuste(salario,reajuste));
				return 0;
			}

		2: Crie uma função em C void inverter(int x), que mostra na tela o número x invertido.	
		Solução:
			#include <stdio.h>
			#include <math.h>

			int qts_digitos(int num){  
				int cont=0;
				while ((num/10)>=1){
					num=num/10;
					cont+=1;
				}
				cont+=1;
				return cont;
			}

			int inverso_num(int num){
				int dgts = qts_digitos(num);
				int lst = -1;
				int div = num;
				double sex=0;
				while(dgts>=1){
					lst = div%10;
					div = (div - lst)/10;
					//printf("%d", lst); 			//saida: um conjunto de strings talvez; A função virá void;
					sex += (pow(10, dgts-1)*lst);   //saida: um número, que se não for pelo menos float vai apresentar resultados 1 unidade menor que o esperado;
					dgts--;
				}
				return sex;
			}

Argumentos de linha de comando em C:
	-O C permite o seus programas receberem argumentos por linha de comando:
		int main(int argc, char *argv[]) {}
		ou
		int main(int argc, char **argv) {}				
	● argc (ARGument Count) é int e armazena o número de argumentos de linha de
	comando passados pelo usuário, incluindo o nome do programa;
	● argv (ARGument Vector) é um vetor de ponteiros de caractere listando todos os argumentos.
	Basicamente, uma lista de strings de tamanho variavel;	
	● Argv[0] é o nome do programa, depois disso até argv [argc-1] cada elemento é argumento de linha de comando;

	-> Ver: C:\Users\VICTOR\Desktop\_UFMA\2° Período\LP1\4 - Macros e Funções\3.argumento linha comando
	-> Obs: compilar pelo cmd(estando na pasta do programa(comando cd)): gcc -o nome_executavel nome_programa.c
			executar pelo cmd(estando na pasta do programa(comando cd)): nome_executavel argumento1 argumento2 argumento3 ... argumentoN

Gerando números aleatórios:
	● Para gerar valores aleatórios, podemos usar a função rand()
		■ retorna valores entre 0 e RAND_MAX (constante definida em <stdlib.h>)
		■ RAND_MAX representa o valor máximo de um inteiro de 2 bytes (16 bits)
	● Exemplo para produzir número aleatórios entre intervalos:	
		#include <stdio.h>
		#include <stdlib.h>

		int main() {
			int i;
			for(i=0;i<=20;i++){
		 		printf("%d ", 1+(rand()%6));
		 		if(i%5==0)
		 			printf("\n"); }
		return 0; }
	● O código anterior gera a mesma sequência de nºs aleatórios, em cada execução;
	● Para gerar nºs aleatórios diferentes, devemos usar a função SRAND(unsigned int);
		-Atribui um valor inteiro sem sinal à função rand(), como forma de semente;
		-Com sementes diferentes, a função rand() gera nºs diferentes
		-Semente recomendada: time(NULL)
			■retorna o tempo acumulado (segundos) desde à meia-noite de 1 de janeiro de 1970 	

	-> Executando um exemplo com rand() e srand(): faça 2 programas que simulem um dado de 6 lados;
		-1º programa deve usar apenas rand();
		-2º deve usar srand();
		Solução:
			#include <stdio.h>
			#include <stdlib.h> // contém a função rand()&srand()
			#include <time.h>   // contém time()		

			int dado_rand(int lados){
				if (lados<=0){return -1;}
				return 1+(rand()%lados);
			}

			int dado_srand(int lados){
				if (lados<=0){return -1;}
				srand(time(NULL));
				return 1+(rand()%lados);
			}

			int main(void){
				int lados=-1;
				do{
				printf("Insira um numero de lados: ");
				scanf("%d", &lados);
				printf("\tLados: %d\n", lados);
				printf("\tRand:  %d\n", dado_rand(lados));
				printf("\tSrand: %d\n", dado_srand(lados));
				printf("\n");
				} while(lados!=0);				
				return 0;
			}

	-> Revisão minha: 
		#include <stdio.h>
		#include <stdlib.h> // contém a função rand()&srand()
		#include <time.h>   // contém time()	

		int main(void){
			int num=0;
			printf("Insira um limite do sorteio: ");
			scanf("%d", &num);
			printf("Numero: %d\n", num);

			printf("Time: %d\n",   time(NULL));
			srand(time(NULL)); // -> Faz com que cada vez que iniciamos o programa, não obtemos os mesmo exatos números da execução anterior;
			for(int i=1; i<=1000; i++){
				srand(time(NULL));				   // -> Faz com que todo número calculado no mesmo time() seja igual, pois fornece uma mesma semente;
								 				   // -> Na prática, gera intervalos enormes de mesmo números aléatorios;
				printf("%d\n", 1+rand()%num);
				printf("Time: %d\n",   time(NULL));// -> Com essa linha de codígo, percebemos que o número só varia se o time() variar, o que implica no que foi dito anteriormente;
			}

			return 0;
		}

	-> Exercício: Em um dado de 10 lados, cada lado possui 10% de chance de ser sorteado.
				  Crie um programa em C para simular um dado viciado de 10 lados, em que:
				  ○ O lado 1 possui 30% de chance de ser sorteado;
				  ○ O lado 5 possui 2 vezes mais chances de ser sorteado que o lado 3;
		Solução:
			#include <stdio.h>
			#include <stdlib.h>
			#include <time.h>   	

			int main(void){
				int num=10;
				printf("Time: %d\n", time(NULL));

				int cont1 = 0;
				int cont2 = 0;
				int cont3 = 0;
				int cont4 = 0;
				int cont5 = 0;
				int cont6 = 0;
				int cont7 = 0;
				int cont8 = 0;
				int cont9 = 0;
				int contX = 0;				

				srand(time(NULL)); 
				for(int i=1; i<=1000; i++){
					int intv = 1+(rand()%80);
					int outp = -1;

					if (intv<=24){ 					// Intervalo do 1
					 	outp=1;
					 	cont1++;
						 }
					else if (intv<=38){       	    // Intervalo do 5
						outp=5;
						cont5++;
						}
					else{
						do{
							outp = 1+(rand()%10);
							if(outp==2 ){cont2++;}
							if(outp==3 ){cont3++;}
							if(outp==4 ){cont4++;}
							if(outp==6 ){cont6++;} 
							if(outp==7 ){cont7++;} 
							if(outp==8 ){cont8++;} 
							if(outp==9 ){cont9++;} 
							if(outp==10){contX++;}  					 	
						} while(outp==1 || outp==5);
					}
				printf("%d: O dado viciado resultou em: %d.\n", i, outp);
				}	
				printf("\n");
				printf("Contador do  1: %d\n", cont1);
				printf("Contador do  2: %d\n", cont2);
				printf("Contador do  3: %d\n", cont3);
				printf("Contador do  4: %d\n", cont4);
				printf("Contador do  5: %d\n", cont5);
				printf("Contador do  6: %d\n", cont6);
				printf("Contador do  7: %d\n", cont7);
				printf("Contador do  8: %d\n", cont8);
				printf("Contador do  9: %d\n", cont9);
				printf("Contador do 10: %d\n", contX);
				int soma = cont1+cont2+cont3+cont4+cont5+cont6+cont7+cont8+cont9+contX;
				printf("Soma dos contadores: %d", soma);

				return 0;
			}					  

Classes de armazenamento:
	-As classes de armazenamento são usadas para descrever os recursos de uma variavel/função;
	-Esses recursos incluem basicamente o escopo, a visibilidade e o tempo de vida que nos ajudam a rastrear a existencia de uma
	 determinada varriável durante o tempo de execução de um programa;
	-C ultiliza 4 classes de armazenamento: auto, extern, static, register;
	
	> auto :
		● É a classe de armazenamento padrão para todas as variáveis declaradas dentro de uma função ou bloco;
		● Tempo de vida: são conhecidas como automáticas, pois são automaticamente criadas com o início da execução da função/bloco,
						 e automaticamente destruidas ao término da função/bloco;
		● Escopo: local, acessivel apenas dentro da função/bloco em que foi declarada;
		● Para explicar uma classe desse tipo, basta por auto antes do nome da variável;
		● Porém como essa classe é default, raramente eh usada;
		● Recebem um valor de lixo por padrão sempre que são declaradas;
			#include <stdio.h>
			#include <math.h>

			int sex(int n){											
			    auto int produto = pow(n,n); 
			    return produto;   
			}

			int main(void){
			    auto int num=0;
			    printf("Insira num: ");
			    scanf("%d", &num);
			    printf("Num: %d\n", num);

			    printf("Produto: %d", sex(num));
			    return 0;
			}   

	> extern :
		● nos diz que a variável é definida em outro lugar e não dentro do mesmo bloco onde	é usada;
		● pode ser considerada uma variável global, inicializada com um valor válido onde é declarada para ser usada em outro lugar;
		● Escopo: pode ser acessada em qualquer função/bloco;
		● Tempo de vida: todo o programa;
		● Para explicitar uma variável global, de forma mais segura, pode ser usada a palavra extern, mas não eh necessário;
		● O objetivo principal de usar variáveis externas é que elas podem ser acessadas entre dois arquivos diferentes que fazem parte de um grande programa
		● a palavra-chave extern é usada para estender a visibilidade de variáveis/funções.
		● Como as funções são visíveis em todo o programa por padrão, o uso de extern não é necessário em declarações ou definições de funções. Seu uso é implícito.
		● Exemplo: "C:\\Users\\VICTOR\\Desktop\\_UFMA\\2° Período\\LP1\4 - Macros e Funções\\4.classes de armazenamento - extern\\"

	> register :
		Uma variável register é armazenada diretamente em um registrador da CPU (caso haja registrador livre);
			- registrador: é a memória dentro da própria CPU que armazena n bits; 
						   É o tipo de memória mais rápida, mas também a mais cara;
						   Portanto, seu acesso é mais rápido;
		● Apenas variáveis char e int podem ser dessa classe;
		● Recomendadas quando se usa um variável várias vezes, por ex.: um contador dentro de um loop;
			#include <stdio.h>
			int eh_primo(int num);
			int main(void){
				register int cont=0;
				for(int i=0; i<=10000; i++){
					if(eh_primo){++cont;}
				}	printf("%d", cont);
				return 0;
			}
		● É raramente utilizada, porque os compiladores modernos já fazem essa otimização automaticamente;
		● A palavra-chave register só pode ser usada com variáveis de tempo de armazenamento automático (auto);
			● Escopo: Local, dentro do bloco/função;
			● Tempo de vida: término da função/bloco;

	> static :
		● uma variável estática tem o escopo de uma local e a duração de uma global;
			-só são acessíveis ao seu respectivo bloco, mas existem durante toda a execução do programa;
		● variáveis normais são sobrescritas sempre que 'redeclaradas', por exemplo em funções;
			-variáveis estáticas sempre mantém o seu valor, mesmo em chamadas diferentes da mesma função;
		● para uma variável ser estática, deve ser antecedida por static;
			#include <stdio.h>

			void teste() {
				int a = 10;
				static int sa = 10;
				a += 5;
				sa += 5;
				printf("a = %d, sa = %d\n", a, sa);
			}

			int main() {
				int i;
				for (i = 0; i <= 3 ; ++i)
					teste();
				return 0;
			}

Recursividade:
	-> Ideia geral:
		● É um termo usado para descrever o processo de repetição de um objeto, de um jeito similar ao que já foi mostrado;
		● Por exemplo: quando 2 espelhos são apontados um para o outro;

	-> Recursividade na resolução de problemas:
		● É um princípio que nos permite obter a solução de um problema, por meio de versões menores de si mesmo;
		● Para aplicar esse princípio, devemos supor que sabemos a solução do problema menor;
		● Por exemplo: desejamos calcular a potência de 2^11
		○ uma instância menor desse problema é 2^10, e para essa instância, “sabemos” a sua solução. 1024.
		○ como então concluímos que 2^11 = 2.2^10 = 2048;

	-> Recursividade(resumo):
		(1): Simplificamos o problema original, transformando-o numa instância menor;
		(2): Obtemos a solução para essa instância menor, e a usamos para construir a solução final;

	-> Funções Recursivas:
		● Em computação, o uso de recursividade se dá pelas funções recursivas, i.e. funções que chamam a si mesmas.
			void loop(void){
				printf("loop\n");  // Aqui temos uma função recursiva descontrolada;
				loop();			   // o programa só mostra "loop" por infinitas vezes;
			}
		● Para ser útil, uma função recursiva deve ter um ponto de parada, ou seja, deve ser capaz de interromper as chamadas recursivas e executar em tempo finito;
		● Ao definir funções recursivas:
			1º: a base de recursão, i.e, a instancia mais simples do problema em questão;
			2º: o passo da recursão, i.e, como simplificar o problema em questão;	
			-A base trata do caso mais simples, para o qual temos uma solução trivial;
		    -O passa trata os caso mais dificeis, que requerem novas chamadas recursivas;

		-> Voltando ao exemplo da potência:
			-No exemplo da potência temos a seguinte definição recursiva:
				x^n={1, se n=0;                }
				x^n={x.x^(n-1), caso contrário;}	    
				-- O caso base é aquele em que o expoente é 0. Qualquer nº elevado a 0 é 1
				-- Se diferente de 0, temos a função recursiva que garante chegarmos no caso base
			-Uma maneira de entender o funcionamento das funções recursivas é através de simulação por substituição:
				double pot(double x, unsigned n){            		p =   pot(2,3);
					if(n=0){return 1;}								p = 2*por(2,2);	
					return x*pot(x,n-1);							p = 2*2*pot(2,1);
				}													p = 2*2*2*pot(2,0);	
																	p = 2*2*2*1 = 8;

		-> Exercício:
		● Crie uma função recursiva que que leia um inteiro n e mostre o n-ésimo termo da sequência fibonacci.																		
			solução: 	double fib(int n){
							if(n==1){return 1;}
							return (fib(n-1)+fib(n-2));
						}
		● Crie uma função recursiva para ler um inteiro n e calcular n!.
			solução:	double fatorial(int n){
							if(n==0||n==1){return 1;}
							return (n*fatorial(n-1));
						}
		● Crie uma função recursiva que leia um inteiro n, e indique quantos dígitos possui n.
			obs.: utilize uma variável estática como contador.
			solução:	double digts(int n){
							static int i=0;
							if((num/10)<1){return i+1;}
							else{
								i++;
								return (digts(num/10));
							}
						}				









