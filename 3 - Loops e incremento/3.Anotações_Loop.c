Comandos de repetição e operadores de incremento:

Tópicos obordados:
	-operadores aritméticos de atribuição, de incremento e decremento;
	-comandos de repetição e interrupção de laço;

Expressões compactas:
	-operadores aritméticos de atribuição;
		->combinam em um único operador, uma operação aritmética e uma atribuição;
			Expressão	Forma Compacta
			x = x + y   	x += y
			x = x - y   	x -= y
			x = x * y   	x *= y
			x = x / y   	x /= y
			x = x % y   	x %= y		

	-incremento e decremento
		->se uma expressão incrementa ou decrementa o valor de uma variável, podemos escrevê-la de uma forma mais compacta com os operadores ++ ou --;
		->podem ser usados na forma prefixa ou posfixa:
			++variavel, --variavel;
			variavel++, variavel--; 

		int x=5, y=5;
		++x;
		y--;
		printf("\n x=%d y=%d", x, y);									

		->diferença entre prefixa e posfixa:
			na forma prefixa, a variável é alterada e, depois seu valor é usado;
			na forma posfixa, o valor da variável é usado e, depois ela é alterada;

			int main(void) {
				int x=5, y=5, v, w;
				v = ++x;
				w = y--;
				printf("x=%d y=%d v=%d w=%d \n",x,y,v,w);
				return 0; 
			}

			saída: x=6 y=4 v=6 w=5

	-Exercício:
		Seja x=5 e considere a instrução y = x++ + ++x. Quais os valores das variáveis x
		e y após a execução dessa instrução? Por quê?
		Solução:
		x++ -> passa o valor de 5 e incrementa x pra 6;
		++x -> incrementa x pra 7 e retorna 7;
		y = x++ + ++x = 5 + 7 = 12

Repetição com contador:
	-Em C, um laço de repetição pode ser controlado por um contador:
		->Contador: variável que contabiliza quantas vezes um comando é executado;
		->sintaxe:	for(inicialização; condição; alteração) comando;
		int main() {
			int c;
			for(c=1;c<=9;c++) printf("%d ", c);
			return 0;
		}	A saída produzida pelo código será 1 2 3 4 5 6 7 8 9;
	
	-o for em C é bem flexivel:
		->Omite a primeira e a última expressão:
			int max = 5;
			int c = 0;
			for(; c < max;){
				c++;
				printf("c = %d\n",c);
			}

		->Omitindo todas as expressões (loop infinito):
			int i = 0;
			for(;;){
				i++;
				if(i > max) break;  // Usando break para escapar do loop;
			printf("i = %d\n",i);
			}	

	-for aninhados:
		int main() {
			int n=0;								// variable declaration
			printf("Enter the value of n :");
			scanf("%d", &n);
			// Displaying the n tables.
			for(int i=1;i<=n;i++) {  // outer loop
				for(int j=1;j<=10;j++) { // inner loop
					printf("%d\t",(i*j)); // printing the value.
					}
				printf("\n");
				}
			return 0; }	
		Saída:		
		Enter the value of n :3
		1       2       3       4       5       6       7       8       9       10
		2       4       6       8       10      12      14      16      18      20
		3       6       9       12      15      18      21      24      27      30

	-Exercício:
		1.Escreva um programa em C para calcular o fatorial de um dado número;
		solução_1:
			int main(void){
				int num=0;
				printf("Insira um numero: \n");
				scanf("%d", &num);
				printf("O numero inserido foi %d.\n", num);

				if (num<0){
					printf("Insira um numero não negativo!");			
				} else {
					if (num==1 || num==0){
						printf("fatorial: 1");	
					} else {
						int fatorial=num;
						for(;;){
							fatorial = fatorial*(num-1);
							num = num-1;
							if (num<=1) {break;}
						} 
						printf("fatorial: %d", fatorial);
					}
				}
				return 0;	
			}
		solução_2:
			#include <stdio.h>

			int main(void){
				int num=0;
				printf("Insira um numero: \n");
				scanf("%d", &num);
				printf("O numero inserido foi %d.\n", num);

				int j=1;
				for (int i=1; i<=num; i++){
					j*=i;
				}
				printf("%d", j);
				return 0;	
			}	

		2.Dado um inteiro x, desenhe um padrão de tamanho x utilizando ‘*’. 
		Por exemplo: se x=4 o padrão é:
		****
		***
		**
		*
		solução_1:
			#include <stdio.h>

			int main(void){
				int num=0;
				printf("Inserir numero: ");
				scanf("%d", &num);
				printf("O numero inserido foi %d.\n\n", num);

				int aux=num;

				for (;;){
					if (aux>=1){ 
						num = aux;

						for (;;){
							if (num>=1){
								printf("*");
								num=num-1;
							} else {
								printf("\n");
								aux=aux-1;
								break;
							}
						}

					} else {break;}	
				}	
				return 0;
			}
		solução_2:
			#include <stdio.h>

			int main(void){
				int num=0;
				printf("Inserir numero: ");
				scanf("%d", &num);
				printf("O numero inserido foi %d.\n\n", num);

				for(int j=num; j>=1; j--){ 
					for(int i=j; i>=1; i--){
						printf("X");
					}
					printf("\n");
				}	
				return 0;
			}	

Repetição com pré-condição:
	-O C possui uma estrutura de repetição mais genérica que o for
	-sintaxe: while(condição) comando;
	int main () {
		int a = 10;
		/* while loop execution */
		while( a < 20 ) {
		printf("value of a: %d\n", a);
		a++;
		}
		return 0; 
	}	

Do...while:
	-Testa a condição de continuação depois de o corpo do loop ser executado;
	-Sempre será executado pelo menos uma vez;
	int main(void){
		int i = 1;	
		do {
			printf("%d", i);
			i++;
		} while (i<=10);
		return 0;					
	}

Instruções break e continue:	
	-são usadas para alterar o fluxo de controle em estruturas como while, for, do...while ou switch;
	-break : quando executada em uma estrutura, faz com que aconteça a saída imediata dessa estrutura;
	-continue : ignora (salta sobre) as instruções restantes no corpo da estrutura e realiza a próxima iteração do loop;

	#include <stdio.h>
	int main( ) {
		int x;
		for (x = 1; x <= 10; x++) {
			if (x == 5) break; /* sai do loop somente se x == 5 */
			printf ("%d ", x);
		}
		printf ("\n Saiu do loop em x == %d\n", x); 
		return 0; 
	}

	-Exercício:
		1.Escreva um programa em C que receba um valor inteiro X e mostre a quantidade de dígitos.
			Solução:
			#include <stdio.h>

			int main(void){
				int num=0;
				printf("Insira um valor: \n");
				scanf("%d", &num);
				printf("O valor inserido eh %d.\n", num);

				int cont=0;
				while ((num/10)>=1){
					num=num/10;
					cont+=1;
				}
				cont+=1;
				
				printf("%d", cont);
				return 0;
			}

		2.Crie um programa que leia um número inteiro de entrada X e o mostre na ordem inversa.
			Solução:
			#include <stdio.h>

			//Eu decidi criar uma função pra facilitar minha vida:
			int qts_digitos(int num){  
				int cont=0;
				while ((num/10)>=1){
					num=num/10;
					cont+=1;
				}
				cont+=1;
				return cont;
			}

			int main(void){
				int num=0;
				printf("Insira um valor: \n");
				scanf("%d", &num);
				printf("O valor inserido eh %d.\n", num);

				int dgts = qts_digitos(num);
				//printf("%d", dgts);

				int lst = -1;
				int div = num;
				while(dgts>=1){
					lst = div%10;
					div = (div - lst)/10;
					//printf("div:%d\n", div);
					printf("%d", lst);
					dgts--;
				}
				return 0;
			}

		3.Crie um programa em C para contar a quantidade de ocorrências de um dígito específico em um número, ambos valores fornecidos como entrada
			Solução:
			#include <stdio.h>

			int qts_digitos(int num){  
				int cont=0;
				while ((num/10)>=1){
					num=num/10;
					cont+=1;
				}
				cont+=1;
				return cont;
			}

			int main(void){
				int num=0;
				printf("Insira um valor: \n");
				scanf("%d", &num);
				printf("O valor inserido eh %d.\n\n", num);

				int dgt=0;
				printf("Insira um digito: \n");
				scanf("%d", &dgt);
				printf("O digito inserido eh %d.\n\n", dgt);


				int digitos = qts_digitos(num);
				int cont = 0;

				int lst = -1;
				int div = num;
				while (digitos>=1){
					lst = div%10;
					div = (div - lst)/10;
					if(lst==dgt) cont++;
					digitos--;
				}
				printf("Ocorrências de %d em %d: %d", dgt,num,cont);
				return 0;
			}

	
