Estrutura geral de um programa em C
	#include <stdio.h>
	int main(){                        //Função a ser chamada quando a execução começa;						
		printf("Hello World\n");
		return 0;                      //Com retorno e passagem de parâmetro;  
	}
	//O int main indica que a função retorna um número, zero se terminou de maneira esperada;
	//O void main indica que a função não retorna nada;
	//Preferencialmente, deve usar o int main(): (em verdade, o void main() é uma prática antiga em sistemas ms-dos 16bits e tentando usar ele no meu pc atual win10 64bits acusou erro dizendo que: '::main' must return 'int')	
	//A escolha do tipo da função main depende se o seu programa irá retornar um número ou não, mas na prática int main() é melhor;

Variaveis:
	//Declaração de uma variavel
	  //tipo:          
		//o espaço de memoria alocado pra ela;
	  //identificador: 
		//permitir que a variavel seja referenciada no restante do programa;
	    //iniciar-se com letra (maiuscula ou minuscula) e ser composto exclusivamente por letras, digitos e sublinhas;
					    	
	//tipo   identificador                   espaço   escala
	  char   tecla; opção;                   1 byte   -128     a     +127
	  int    x,y,z;                          2 byte   -32768   a   +32767  
	  float  comissao, desconto, salario;    4 byte   3.4^-38  a  3.4^+38
	  double num_enorme;                     8 byte   1.7^-308 a 1.7^+308
	  void   sex;                            nenhum   nenhuma

	//tipos de dados modificados;
	  signed: padrão
	  unsigned:
	  	o bit mais a esquerda em char ou int é chamado de bit de sinal, ultilizado para indicar se o valor ASCII é positivo ou negativo;
	  	com o unsigned informamos ao computador que os valores serão positivos, portanto ganhamos mais 1 bit para representar valores a escala dobra;
	  short:  padrão
	  long:   maior

	//tipo          identificador  espaço   escala
	  unsigned char tecla;         1 byte   0              a            255
	  unsigned int  x,y,z;         2 byte   0              a          65535
	  long     int  x,y,z;         4 byte   -2.147.483.648 a +2.147.483.647

	//Tabela dados modificados:
		Palavra chave		Tipo										Tamanho	Intervalo
		char				Caracter									1		-128 a 127
		signed char			Caractere com sinal							1		-128 a 127
		unsigned char		Caractere sem sinal							1		0 a 255
		int					Inteiro										2		-32.768 a 32.767
		signed int			Inteiro com sinal							2		-32.768 a 32.767
		unsigned int		Inteiro sem sinal							2		0 a 65.535
		short int			Inteiro curto								2		-32.768 a 32 767
		signed short int	Inteiro curto com sinal						2		-32.768 a 32.767
		unsigned short int	Inteiro curto sem sinal						2		0 a 65.535
		long int			Inteiro longo								4		-2.147.483.648 a 2.147.483.647
		signed long int		Inteiro longo com sinal						4		-2.147.483.648 a 2.147.483.647
		unsigned long int	Inteiro longo sem sinal						4		0 a 4.294.967.295
		float				Ponto flutuante com precisão simples		4		3.4 E-38  a 3.4E+38
		double				Ponto flutuante com precisão simples		8		1.7 E-308 a 1.7E+308
		long double			Ponto flutuante com precisão dupla longo	16		3.4E-4932 a 1.1E+4932

Função scanf():
	permite que um valor seja lido do teclado e armazenado em uma variável
	sintaxe: scanf("formatação", arg1, arg2, ..., argn);

	int idade;
	char sexo;
	scanf("%d %c", &idade, &sexo); //O "&" indica que devemos armazenar no endereço alocado para a variavel idada, vale o mesmo para a variavel sexo;
	
	especificador representa
	   %c         Um único caracter
	%o %d %x 	  Um número inteiro em octal, decimal ou hexadecimal
	   %u         Um número inteiro em base decimal sem sinal
	   %ld        Um número inteiro longo em base decimal    
	 %f, %lf      Um número real de precisão simples ou dupla
	   %s         Uma cadeia de caracteres(string)
	   %%         Um único sinal de porcentagem

	-> Nomes de variaveis como idade e sexo, correspondem a locais na memória do computador
				 _________		
				 |Mémoria|
		idade -> |  30   |
		sexo  -> |  'M'  |
				 L_______J

Função printf():
	permite exibir informações formatadas na tela
	sintaxe: printf("formatação", arg1, arg2, ..., argn); -> Semelhante a scanf(), porém com a lista de argumentos contendo os valores e não os endereços das variaveis;
	--------------------------------------------------------------------------------------------------------------------		
	#include<stdio.h>

	#define pi 3.1415
	int main(){
	double raio, perim;
	printf("Qual a medida do raio? \n");
	scanf("%lf", &raio);
	perim = 2*pi*raio;
	printf("O perimetro da circunferencia é: %lf", perim);
	return 0; }			 	
	-----------------------------------------------------------------------------------------------------------

Operadores Aritméticos
	Operador Resultado
	   +     Soma de dois números quaisquer	   	
	   -     Diferença entre dois números quaisquer
	   *     Produto de dois números quaisquer
	   /     Quociente da divisão de dois números quaisquer
	   %     Resto da divisão de dois números inteiros	

	Exercício 1: Dada uma temperatura em graus Fahrenheit, informe o valor correspondente em graus Celsius. [Dica: C = (F – 32) ∗ (5 / 9)].
		#include<stdio.h>

		int main(){
		   double tf, tc;
		   scanf("%lf", &tf);
		   printf("A temperatura em graus Fahrenheit eh %lf \n", tf);
		   tc = (tf - 32); //Por algum motivo colocar direto: "tc = (tf-32)*(5/9);" Acusava tc como sendo 0 sempre;
		   tc = tc*5;
		   tc = tc/9;
		   printf("A temperatura em graus Celsius eh %lf", tc);
		   return 0;
		}
	Exercício 2: Dadas as medidas dos catetos de um triângulo retângulo, informe a medida da hipotenusa. [Dica: para calcular a raiz quadrada use a função sqrt(), definida na biblioteca math.h].	
		#include <stdio.h>
		#include <math.h>

		int main(){
			double cat_opt, cat_adj, hipotenusa;
			printf("Insira o valor do cateto oposto: ");
			scanf("%lf", &cat_opt);
			printf("Insira o valor do cateto adjace: ");
			scanf("%lf", &cat_adj);
			hipotenusa = sqrt(cat_opt*cat_opt + cat_adj*cat_adj);
			printf("O comprimento da hipotenusa eh %lf;", hipotenusa);
			return 0;
		}

Operadores Relacionais
	Não existe um tipo específico para a representação de valores lógicos.
	Entretanto, qualquer valor pode ser interpretado como um valor lógico: “zero representa falso e qualquer outro valor representa verdade”.
	Por exemplo, os valores 5, –3 , 1.2 e 'a' são verdadeiros, enquanto 0 e 4–4 são falsos
	Para gerar valores lógicos, usamos operadores relacionais ○ que quando usados para uma comparação, retornam ‘0’ se a mesma for falsa e ‘1’ se verdadeira

	Operador relacional					Resultado
			x==y   			Verdade se x for igual a y
			x!=y    	    Verdade se x for diferente de y    
			x<y     	    Verdade se x for menor que y
			x>y     	    Verdade se x for maior que y
			x<=y    	    Verdade se x for menor ou igual a y
			x>=y     	    Verdade se x for maior ou igual a y

	ex: printf("%d %d",5<6, 6<5)
		A saida produzida pela instrução será 1 0

Operadores Lógicos
	Operador Lógico Resultado				
		!x          verdade so e só se x for falso
		x&&y        verdade so e só se x e  y forem verdade
		x||y        verdade se e só se x ou y forem verdade

Prioridade dos operadores
	Numa expressão contendo operadores aritméticos, relacionais e lógicos, a avaliação é efetuada na seguinte ordem:
	- primeiro avaliam-se todos os operadores aritméticos;
	- em seguida, avaliam-se os operadores relacionais;
	- só então, avaliam-se os operadores lógicos.	

Decisão simples:
	A estrutura condicional (ou decisão simples), serve para escolher 1 entre 2 comandos alternativos
	Em C, é codificado da seguinte maneira:
		if(condição) comando1; else comando2;
	-----------------------------------------------------------------	
	#include <stdio.h>

	int main() {
	float a, b, m;
	printf("Informe as duas notas obtidas: ");
	scanf("%f %f", &a, &b);
	m = (a+b)/2;
	if( m >= 7.0 ) printf("\n Aprovado");
	else printf("\n Reprovado");
	return 0;
	}		
	---------------------------------------------------------------------
	#include <stdio.h>
	//#include <conio.h> //Aprensentou erro, então decidi comentar o codigo e seguir com a vida

	int main() {
		float a, b, m;
	 	printf("Informe as duas notas obtidas: ");
	 	scanf("%f %f", &a, &b);
	 	m = (a+b)/2;

		if( m >= 7.0 ) {
			//textcolor(BLUE);
		 	printf("\n Aprovado");  //antes: cprintf("\n Aprovado"); 
		}
		else {
			//textcolor(RED);
		 	printf("\n Reprovado"); //antes: cprintf("\n Reprovado"); 
		}
		return 0;
	------------------------------------------------------------------------	

Operadores Condicionais:
	proporciona uma maneira mais compacta para decisões simples
 	sintaxe: condição ? expressão1 : expressão2 ;
 					    (caso True)	 (Caso False)	
 	---------------------------------------------------------------------------------------------------				    
 	#include <stdio.h>

 	int main(){
 		double abs
 		abs = n>0 ? n : -n	
 		// A instrução acima atribui à variável abs o valor absoluto da variável n. 
 		 // A expressão n>0 é avaliada: se for verdadeira, abs recebe o próprio valor de n;
 		 // Caso contrário, abs recebe o valor de n com o sinal invertido.
 	}		
 	----------------------------------------------------------------------------------------------------

Exercício: 
	1. Desenvolver um algoritmo que leia um número inteiro e verifique se o número é divisível por 5 e por 3 ao mesmo tempo. 
		
		Soluçã0:
			#include <stdio.h>

			int main(){
				int num;
				printf("Digite um número inteiro: ");
				scanf("%d", &num);
				if ((num%5==0)&&(num%3==0)){
					printf("O número %d eh divisivel tanto por 5 como por 3.", num);
				} else {
					printf("O número %d NÃO eh divisivel tanto por 5 como por 3.", num);
				} 
				return 0;
			}
	-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------			
	2. Fazer um programa em C que dado três valores A, B e C, verificar se eles formam um triângulo ou não. Caso sim, informar se é triângulo equilátero, isósceles ou escaleno.
		- Condição para ser triângulo: a soma do comprimento de dois lados deve ser maior que o
		comprimento do terceiro lado.
		- Tipos de triângulos:
		- triângulo equilátero: todos os lados são iguais
		- triângulo isósceles: dois lados iguais
		- triângulo escaleno: todos os lados são diferentes	

		Solução:
			#include <stdio.h>

			int main(){
				float tt,l1,l2,l3;
				printf("Digite 3 valores: ");
				scanf("%f %f %f", &l1, &l2, &l3);
				tt = l1+l2+l3;
				if ((2*l1>=tt)||(2*l2>=tt)||(2*l3>=tt)){ 
					printf("nao é triângulo!");
				} else {
					if ((l1==l2)&&(l2==l3)){
						printf("triângulo equilatero!");
					} else {
						if ((l1==l2)||(l2==l3)||(l1==l3)){
							printf("triângulo isosceles!");	
						} else {
							printf("triangulo escaleno!");	
						}
					}
				}
				return 0;	
			}
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	3. Faça um programa em C que identifique se a raiz quadrada de um dado número inteiro X é inteira, ou seja, se X é um número quadrado perfeito.	
		Alternativa 1:
			#include <stdio.h>
			#include <math.h>

			int main(){
				float num,raiz;
				printf("Insira um numero: ");
				scanf("%f", &num);
				raiz = sqrt(num);
				
				int aux;
				aux = raiz
				if (aux==raiz){
					printf("A raiz quadrada de %f eh %f, que eh um numero inteiro", num, raiz);
				} else {
					printf("A raiz quadrada de %f eh %f, que nao eh um numero inteiro", num, raiz);
				}
				return 0;
			}
		Alternativa 2:
			#include <stdio.h>
			#include <math.h>

			int main(){
				float num,raiz;
				printf("Insira um numero: ");
				scanf("%f", &num);
				raiz = sqrt(num);

				if (raiz==(int)raiz){ //casting da variavel para inteiro - sei em python em c ainda n ensinaram;
					printf("A raiz quadrada de %f eh %f, que eh um numero inteiro", num, raiz);
				} else {
					printf("A raiz quadrada de %f eh %f, que nao eh um numero inteiro", num, raiz);
				}
				return 0;
			}			
	-------------------------------------------------------------------------------------------------------------------------------------------		
	4. Cada caracter é representado por um byte, e de acordo com o alfabeto ASCII um byte entre 00000000 e 01111111.
       No computador, cada caractere está representado em uma faixa de valores, que para nós pode ser visualizada como uma faixa de inteiros.
       Escreva um programa em C para checar se um caracter é uma letra, dígito ou caractere especial.
       DICA: façam o seguinte teste: printf("%d", 'a');

    		Solução:
    	#include <stdio.h>

		int main(){
			char ch;
			printf("Insira um caracter: ");
			scanf("%c", &ch);
			//printf("%c", ch);
			//printf("%d", ch); //imprime o valor corresondente na tabela ASCII, dito isso usei os valores decimais dela como base;

			if (((int)ch>=48)&&((int)ch<=57)){
				printf("O char \"%c\" eh um numeral.", ch);
			} else {
				if ( (((int)ch>=65)&&((int)ch<=90)) || (((int)ch>=97)&&((int)ch<=122)) ){
					printf("O char \"%c\" eh uma letra.", ch);
				} else {
					printf("O char \"%c\" eh um caractere especial.", ch);
				}
			}
			return 0;	
		}

Decisão Múltipla:
	O C oferece uma estrutura de decisão múltipla para precisamos escolher uma entre várias alternativas previamente definidas, por exemplo, em um menu;
		sintaxe: 
			switch( expressão ) {
				case constante_1 : comando_1; break;
				case constante_2 : comando_2; break;
				 ...
				case constante_n : comando_n; break;
				default:
				 comando; }
	O caso default é opcional e, embora seja geralmente posicionado no final do bloco switch, ele pode aparecer em qualquer posição entre os cases especificados;		 

Decisão Múltipla - Exemplo Com Erro!
	#include <stdio.h>

	int main(){										N 		Saída			
		int n;                                      1         A.
		printf("\n Digite um número: ");            2         *D.
		scanf("%d", &n);                            3         BC.
			switch( n ) {                           4         C.
			case 1: printf("A"); break;             5         D.
			case 3: printf("B");
			case 4: printf("C"); break;
			default: printf("*");
			case 5: printf("D"); }
		printf(".");
		return 0;
	}

Exercício:
	Usando o switch, crie uma calculadora simples (operações de +,-,*, e /). O usuário digita uma expressão na forma valor1 oper valor2, e o seu programa deve mostrar o resultado da expressão.

	Solução_Victor_01:
		#include <stdio.h>

		int main(){
			float num1, num2;
			char  opr_str;
			int   opr_int;
			printf("Insira Operation: ");
			scanf("%f %c %f", &num1,&opr_str,&num2);
			opr_int = int(opr_str);
			
			switch(opr_int){
				case (43): printf("%.2lf", num1+num2); break;
				case (45): printf("%.2lf", num1-num2); break;
				case (42): printf("%.2lf", num1*num2); break;
				case (47): printf("%.2lf", num1/num2); break;
				default: printf("Operação Invalida!");
			}
			return 0;
		}

	Solução_Victor_02:
		#include <stdio.h>

		int main(void){
			float num1, num2;
			char  opr_str;
			printf("Insira Operation: ");
			scanf("%f %c %f", &num1,&opr_str,&num2);
			
			switch(opr_str){
				case ('+'): printf("%.2f", num1+num2); break;
				case ('-'): printf("%.2f", num1-num2); break;
				case ('*'): printf("%.2f", num1*num2); break;
				case ('/'):
					if (num2!=0){
						printf("%.2lf", num1/num2);
						}
					else{
						printf("Divisão por zero!\n");
					}
					break;
				default: printf("Operação Invalida!");
			}
			return 0;
		}		









