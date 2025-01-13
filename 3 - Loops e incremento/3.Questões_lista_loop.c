2. Comandos de repetição:
	//2.1:
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
				//printf("%d", lst); 			//saida: um conjunto de strings talvez;
				sex += (pow(10, dgts-1)*lst);   //saida: um número, que se não for pelo menos float vai apresentar resultados 1 unidade menor que o esperado;
				dgts--;
			}
			return sex;
		}

		int main(void){
			int num=-1;
			printf("Insira um valor: \n");
			scanf("%d", &num);
			printf("O valor inserido eh %d.\n", num);

			double inv = inverso_num(num);
			printf("%.0lf", inv);
			return 0;
		}
	//2.2:
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

		double inverso_num(int num){
			int dgts = qts_digitos(num);
			int lst = -1;
			int div = num;
			double sex=0;
			while(dgts>=1){
				lst = div%10;
				div = (div - lst)/10;
				//printf("%d", lst); 			//saida: um conjunto de strings talvez;
				sex += (pow(10, dgts-1)*lst);   //saida: um número, que se não for pelo menos float vai apresentar resultados 1 unidade menor que o esperado;
				dgts--;
			}
			return sex;
		}

		int palindromo(int num){
			int dgts = qts_digitos(num);
			double inv = inverso_num(num);

			float lst_num=-1, div_num=num;
			float lst_inv=-1, div_inv=inv;
			while (dgts>=1){
				lst_num = (int)div_num%10;
				lst_inv = (int)div_inv%10;
				div_num = (div_num - lst_num)/10;
				div_inv = (div_inv - lst_inv)/10;
				if (lst_num!=lst_inv){return 0;}	
				dgts--;	
			}
			return 1;
			//Depois de terminar eu percebi que eu poderia só subtrair os 2 números pra ver se dava igual a zero, mas agora já foi;
		}


		int main(void){
			int num=-1;
			printf("Insira um valor: \n");
			scanf("%d", &num);
			printf("O valor inserido eh %d.\n", num);

			int pldm = palindromo(num);
			if (pldm==1) {printf("O numero %d EH PALINDROMO, pois eh igual ao seu reverso %.0lf.", num, inverso_num(num));}
			else {printf("O numero %d NAO EH PALINDROMO, pois nao eh igual ao seu reverso %.0lf.", num, inverso_num(num));}	
			return 0;
		}	
	//2.3:
		#include <stdio.h>

		int main(void){
			double num=-1;
			printf("Insira um número: \n");
			scanf("%lf", &num);
			printf("O número inserido foi: %lf\n\n", num);

			int i=1,j=1,z=1;
			for(i=1;i<=num;i++){
				for(j=num;j>i-1;j--){
					printf(" ");
				}
				for(j=1;j<=i;j++){
					printf(" %d",z);
					z++;
				}
				printf("\n");	
			}
			return 0;
		}	
	//2.4:
		#include <stdio.h>

		int main(void){
			double num=-1;
			printf("Insira um número: \n");
			scanf("%lf", &num);
			printf("O número inserido foi: %lf\n\n", num);

			int i=1,j=1;
			for(i=1;i<=num;i++){
				for(j=num;j>i-1;j--){
					printf(" ");
				}
				for(j=1;j<=i;j++){
					printf(" %d",i);
				}
				printf("\n");	
			}
			return 0;
		}
	//2.5:
		#include <stdio.h>

		//fibonacci embora relacionado com o triangulo de pascal não se mostrou ultil para a resolução do problema;
		double fibonacci(double num){
			if (num==0||num==1||num==2||num==3){return 1;}
			int cont=0;
			double antr=0;
			double prox=1;
			while (cont<(num-1)){
				prox = antr+prox;
				antr = prox-antr;
				printf(" %0.lf", prox);
				cont++;	
			}
			return prox;
		}

		double fatorial(double num){
			if (num==0||num==1) return 1;
			double cont=num;
			while(cont>1){
				num = num*(cont-1);
				cont--;
			}
			return num;
		}

		//Retornar a posição linha/coluna do n-esimo número;
			double line_cord(double n){
				int i=1,j=1,z=1;
				for(i=0;i<=n;i++){
					for(j=0;j<=i;j++){
						if (z==n) return i;
						z++;
			}}}
			double coll_cord(double n){
				int i=1,j=1,z=1;
				for(i=0;i<=n;i++){
					for(j=0;j<=i;j++){
						if (z==n) return j;
						z++;
			}}}

		double valor_pos(double n){
			double linha = line_cord(n);
			double colun = coll_cord(n);
			double num = (fatorial(linha)) / (  (fatorial(colun)) * (fatorial(linha-colun)) );
			return num;
		}

		int main(void){
			double num=-1;
			printf("Insira um numero: \n");
			scanf("%lf", &num);
			printf("O numero inserido foi: %0.lf.\n\n", num);

			int i=1,j=1,z=1;
			for(i=0;i<=num;i++){
				for(j=num;j>i-1;j--){
					printf(" ");
				}
				for(j=1;j<=i;j++){
					printf(" %0.lf", valor_pos(z));
					z++;
				}
				printf("\n");	
			}

			printf("\nO %0.lf° termo possui: \n", num);
			printf("Fatorial: %0.lf! = %0.lf\n", num,fatorial(num));
			printf("Cord linha:        %0.lf\n", line_cord(num));
			printf("Cord colun:        %0.lf\n", coll_cord(num));
			printf("Valor:             %0.lf\n", valor_pos(num));
			return 0;
		}			
	//2.6:
		#include <stdio.h>

		int main(void){
			int i,j;
			for(i=1; i<=5; i++){
				for(j=1; j<i; j++){
				printf(" ");
				}
				for(j=i; j<=5; j++){
				printf("*");
				}
				printf("\n");
			}	
			return 0;
		}
		//Simplesmente olhando o codigo, e o "debugando" mentalmente, eh possivel notar que ira formar o seguinte padrão:
		*****
		 ****
		  ***
		   **
		    *
	//2.7:
		#include <stdio.h>

		int main(void){
			int i=0,j=0;
			for(i=0;i<4;i++){ 
				for(j=0;j<=i;j++){
					printf("X");
				}
				printf("\n");
			}	
			return 0;
		}
	//2.8:
		#include <stdio.h>

		int main(void){
			int i=0,j=0;
			for(i=1;i<=4;i++){
				for(j=1;j<=i;j++){
					printf("%d",i);
				}
				printf("\n");
			}
			return 0;
		}		  
	//2.9:
		#include <stdio.h>

		int main(void){
			int num=-1;
			printf("Insira um numero: ");
			scanf("%d", &num);
			printf("O numero inserido foi %d.\n",num);

			int i=0,j=0,z=1;
			for(i=1;i<=num;i++){
				for(j=1;j<=i;j++){
					printf("%d",z);
					z++;
				}
				printf("\n");
			}

			return 0;
		}	  
	//2.10:
		#include <stdio.h>
		//Fazer ultilizando loops, embora eu já tenha feito anteriormente usando só if´s;
		int main(void){
			char crt='0';
			do{
				printf("Insira um caractere: ");
				scanf("%c", &crt);
				printf("O caractere inserido foi %c.\n",crt);	
				getchar(); //Serve pra limpar a entrada do teclado, o prof ainda não explicou, mas sem isso tava dando merda;

				if (crt=='+'){
					printf("Encerrado o programa pelo usuario.");
					break;
				}

				int asc=crt;	
				if(asc>=48 && asc<=57){printf("Numero.\n");}
				else if( (asc>=65 && asc<=90)||(asc>=97 && asc<=122) ){printf("Letra.\n");}
				else printf("Especial.\n");
				printf("Insira '+' para encerrar o programa.\n\n");
			} while (1);

			return 0;
		}	
	//2.11:
		#include <stdio.h>

		int main(void){
			int i=0;
			while(i<=9){
				printf("%d\n",i);
				i++;
			}
			return 0;
		}	
	//2.12:
		#include <stdio.h>

		int main(){
			int i;
				if(true)
					printf("Isso funciona");
				else
					printf("Isso nao funciona");
			return 0;
		}//Por incrivel que pareça, mas o C apesar de não ter variavel do tipo bool entendo o true tal como no python;
		// Saida: Isso funciona ;