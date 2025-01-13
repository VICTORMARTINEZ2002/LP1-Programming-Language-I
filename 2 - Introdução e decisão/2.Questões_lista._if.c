1. Comandos de decisão:
	//1.1:
		#include <stdio.h>
		#include <math.h>

		int main(void){
			float x1=0.0,y1=0.0,x2=0.0,y2=0.0;
			double dst=0.0;
			printf("Insira as coordenadas do ponto 1: \n");
			scanf("%f %f", &x1,&y1);
			printf("As coordenadas do ponto 1 sao (%.4f, %.4f)\n\n", x1,y1);
			printf("Insira as coordenadas do ponto 2: \n");
			scanf("%f %f", &x2,&y2);
			printf("As coordenadas do ponto 1 sao (%.4f, %.4f)\n\n", x2,y2);

			dst = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
			printf("A distancia entre os pontos (%f, %f) e (%f, %f) eh igual a %lf.\n", x1,y1,x2,y2,dst);
			return 0;
		}
	//1.2:
		#include <stdio.h>

		int main(void){
			float num=0.0;
			float flr=0.0;
			printf("Insira um numero qualquer: \n");
			scanf("%f", &num);

			flr=int(num);
			//printf("%f", flr);

			if (flr==num){                                       // Testar se o número é inteiro;
				if ((int)num%2==0){
					printf ("O numero %.2f eh par.", num);
				} else {
					printf ("O numero %.2f eh impar.", num);
				}
			} else {
					printf ("O numero %.2f eh impar.", num);
			}
			return 0;
		}
	//1.3:
		#include <stdio.h>
		#include <math.h>

		int main(){
			float  a = 0.0;
			double b = 0.0;
			a = sqrt(27.0);
			b = sqrt(27.0);
			printf("%f \n", a);
			printf("%lf\n",b);
			if (a==b)                 // a==b retorna False porque ambos são de tipos diferente, b carrega mais casas decimais que a;
			printf("Sao iguais");
			else
			printf("Sao diferentes");
			return 0;
		}   // ao final do programa vamos nos deparar com "Sao diferentes", apesar do programa não estar completamente identado ou indicado por {}, ele ainda funcina;
			// isso decorre do fato que o tanto o if/else implicam em apenas um comando;
	//1.4:
		#include <stdio.h>

		int main(void){
			float num1=0.0,num2=0.0,num3=0.0;
			float maior=0.0,meio=0.0,menor=0.0;
			printf("Insira 3 numeros quaisquer: \n");
			scanf("%f %f %f", &num1,&num2,&num3);

			maior = num1;
			if (num2>maior) {maior = num2;}
			if (num3>maior) {maior = num3;}
			menor = num1;
			if (num2<menor) {menor = num2;}
			if (num3<menor) {menor = num3;}
			meio = (num1+num2+num3)-(maior+menor);

			printf("O maior dos 3 numeros dados eh: %f\n", maior);
			printf("O numero do meio eh           : %f\n", meio);
			printf("O menor dos 3 numeros dados eh: %f\n", menor);
			return 0;
		}
	//1.5:
		#include <stdio.h>

		int main(){
		if (printf("0"))
		printf("dentro do bloco if");
		else
		printf("dentro do bloco else");
		return 0;
		} // O resultado do programa sera "dentro do bloco if", haja vista que ao testar a condição "0", temos uma string não vazia, assim retornando True;
		  // Aparentemente em C puro, pelo que eu vi, uma string vazia também retorna 1, diferentemente do que ocorria no python 3.8;
	//1.6:
		#include <stdio.h>

		int main(void){
			float num=0.0;
			float anos=0.0, messes=0.0, dias=0.0;
			printf("Informe o numero de dias: \n");
			scanf("%f", &num);

			float resto_ano=0.0;
			resto_ano = (int)num%365;
			anos = (num - resto_ano)/365;
			//printf("%.0f anos.\n", anos);

			float resto_mes=0.0;
			resto_mes = (int)resto_ano%30;
			messes = (resto_ano - resto_mes)/30;
			dias = resto_mes;
			//printf("%.0f messes.\n", messes);
			//printf("%.0f dias.\n", dias);

			printf("%.0f anos, %.0f messes, %.2f dias.", anos, messes, dias);
			return 0;
		}
	//1.7:
		#include <stdio.h>
		#include <string.h>

		int main(){
			char vitamina='z';
			int num=0.0;
			printf("Insira uma letra correspondente a uma vitamina: ");
			scanf("%c", &vitamina);
			printf("A vitamina escolhida foi %c;\n", vitamina);

			num = (int)vitamina;
		 	// pra evitar comparar strings vou usar "casting" e a tabela ASCII; printf("%d\n", 'a');;
			switch(num){
				case 65: 
					printf("A vitamina escolhida foi %c, cujo nome eh retinol.\n", vitamina);
					break;
				case 97: 
					printf("A vitamina escolhida foi %c, cujo nome eh retinol.\n", vitamina);
					break;	
				case 66: 
					printf("A vitamina escolhida foi %c, que pode ser b1, b2, b6, b12.\n", vitamina);
					break;
				case 98: 
					printf("A vitamina escolhida foi %c, que pode ser b1, b2, b6, b12.\n", vitamina);
					break; 	 
				case 67:
					printf("A vitamina escolhida foi %c, cujo é o acido ascorbico.\n", vitamina); 
					break;
				case 99:
					printf("A vitamina escolhida foi %c, cujo é o acido ascorbico.\n", vitamina); 
					break;	
				case 68: 
					printf("A vitamina escolhida foi %c, cujo nome eh calcifenol.\n", vitamina); 
					break;
				case 100: 
					printf("A vitamina escolhida foi %c, cujo nome eh calcifenol.\n", vitamina); 
					break;   
				case 69: 
					printf("A vitamina escolhida foi %c, cujo nome eh tocofenol.\n", vitamina); 
					break;
				case 101: 
					printf("A vitamina escolhida foi %c, cujo nome eh tocofenol.\n", vitamina); 
					break; 	  
				case 75: 
					printf("A vitamina escolhida foi %c, presente na alface.\n", vitamina);
					break; 
				case 107: 
					printf("A vitamina escolhida foi %c, presente na alface.\n", vitamina);
					break;
				default:  printf("A vitamina (%c) não foi reconhecida!\n", vitamina);
			return 0;	
			}
		}
	//1.8:
		#include <stdio.h>

		int main(void){
			float temp=0.0;
			printf("Insira aqui uma temperatura em graus centigrados: ");
			scanf("%f", &temp);
			printf("A temperatura inserida foi de aproximadamente %.2f graus.\n", temp);

			if (temp<0) {printf("Temp < 0, entao Tempo congelante;\n");} else
			if (temp<10){printf("Temp 0-10, entao, tempo muito frio;\n");} else
			if (temp<20){printf("Temp 10-20, entao, tempo frio;\n");} else
			if (temp<30){printf("Temp 20-30, entao, Normal;\n");} else
			if (temp<40){printf("Temp 30-40, entao, esta quente;\n");} else
			printf("Temp >= 40, entao, esta muito quente;\n");
			return 0;
		}
	//1.9:
		#include <stdio.h>

		int x=0;
		int main(void){
			if (x==x)
				printf("if")
			else
				printf("else")
			return 0;
		} // aparentemente mostrou o if, o C considerou o x como tendo sido declarado ainda que não fazendo parte da função main;
		  // Nessa caso, o x, declarado antes da função main se torna uma variavel global;
