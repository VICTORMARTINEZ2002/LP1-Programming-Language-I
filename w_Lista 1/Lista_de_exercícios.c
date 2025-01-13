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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
3. Macros e Funções:
	//3.1:
		#include <stdio.h>

		int soma_cr(int n){
			static int sum=0;
			if(n>=3){
				sum += n;
				soma_cr(n-1);
			}	
			else{return sum+2;}	
		}

		int soma_sr(int n){
			int soma=0;
			int i=0;
			while(i<=n){
				soma+=i;
				i++;
			}
			return (soma-1);
		}

		int main(void){
			int num=0;
			printf("Insira numero a ser somado: ");
			scanf("%d", &num);
			printf("Número inserido: %d\n\n", num);
			printf("Soma de 1 ate %d: %d (sr).\n", num, soma_sr(num));
			printf("Soma de 1 ate %d: %d (cr).\n", num, soma_cr(num));
			return 0;
		}

	//3.2: Qual o resultado?
		//ORIGINAL: 				// Alternativa 1:    			// Alternativa 2:
		#include<stdio.h>			.	#include<stdio.h>			.	#include <stdio.h>
		int main(){					.	void function(){			.	void function();
			function();				.		printf("Aula de lp");	.	
			return 0;				.	}							.	int main(){
		}							.  								.		function();
									.   int main(){					.		return 0;
		void function(){			.	function();					.	}
			printf("Aula de lp");	.	return 0;					.
		}							.   }							.	void function(){printf("Aula de lp");}
		// -> Resulta em um erro de compilação, haja vista que a função não foi declarada previamente a sua chamada. 

	//3.3:
		double fatorial(int n){
			if(n==0||n==1){return 1;}
			return (n*fatorial(n-1));
		}

	//3.4:
		double pot(int x, int n){
		if(n==1){return x;}
		else {return (x*pot(x,n-1));}
		}

	//3.5:
		#include<stdio.h> 

		int conta_vogais(char palavra[]){
		    int vogais=0;
		    for(int i=0; palavra[i]!='\0'; i++){ // '\0' -> caractere nulo, caracter terminador de string;
		        if((int)palavra[i]==65||(int)palavra[i]== 69||(int)palavra[i]== 73||(int)palavra[i]== 79||(int)palavra[i]== 85){vogais++;}
		        if((int)palavra[i]==97||(int)palavra[i]==101||(int)palavra[i]==105||(int)palavra[i]==111||(int)palavra[i]==117){vogais++;}
		    }
		    return vogais;  
		}

		int conta_consoantes(char palavra[]){
		    int tamanho=0;
		    while(palavra[tamanho]!='\0'){tamanho++;}
		    return (tamanho-conta_vogais(palavra));
		}

		int conta_consoantes_recursivamente(char palavra[], int indice) {
		    if (palavra[indice] == '\0'){return 0;}
		    else {
		        short flag = palavra[indice] != 'a' &&
		                     palavra[indice] != 'e' &&
		                     palavra[indice] != 'i' &&
		                     palavra[indice] != 'o' &&
		                     palavra[indice] != 'u';
		        return flag + conta_consoantes_recursivamente(palavra, indice+1);
		    }
		}

		int main(){
		    char strg[15]="";
		    printf("Insira uma string: ");
		    scanf("%s", &strg);
		    printf("String: %s\n", strg);

		    printf("Qtd vogais:    %d\n", conta_vogais(strg));
		    printf("Qtd consoantes (sr): %d\n", conta_consoantes(strg));
		    printf("Qtd consoantes (cr): %d\n", conta_consoantes_recursivamente(strg, 0));
		    return 0;
		}

		//Solução da internet:
			int contarVogais(char palavra[]) {
			    char vogais[] = "aeiouAEIOU";
			    int numVogais = 0, i, j;

			    for (i = 0; palavra[i] != '\0'; i++) {
			        for (j = 0; vogais[j] != '\0'; j++) {
			            if (vogais[j] == palavra[i]) {
			                numVogais++;
			                break;
			            }
			        }
			    }

			    return numVogais;
			}

	//3.6: Qual o resultado?
		#include <stdio.h>

		int recursive (int i){
		    int count = 0;
		    count = count + i;
		    return count;
		}
		int main(){
		    int i,j=0;
		    for (i = 0; i<=5;  i++)
		        j = recursive(i);
		    printf("%d\n ", j);
		    return 0;
		}// -> Naturalmente, uma vez que count é do tipo auto e não matem seu valor:
		 //        O resultado será o ultimo valor que i alcança, logo, 5;
		 //	-> Se o count fosse uma variavel do tipo static, obteriamos um resultado diferente =15;

	//3.7: Qual o resultado?
		#include <stdio.h>

		int recursive (int i){
		    static int count = 0;
		    count = count + i;
		    return count;
		}
		int main(){
		    int i,j=0;
		    for (i = 0; i<=5;  i++)
		        j = recursive(i);
		    printf("%d\n ", j);
		    return 0;
		}//15;

	//3.8: Qual o resultado?
		#include <stdio.h>
		int x = -1;
		int main(){
		    while (x++ ==1)
		        printf("loop");
		    return 0;
		}// -> Uma vez que x++ passa o valor original de x=-1, o while nunca eh executado e o programa não apresenta saída;

	//3.9: Qual o resultado?	
		#include <stdio.h>
		int main (){
			int a=1,b=1, c;
			c = a++ + b;
			printf("a=%d, b=%d",a,b);
		}// -> a=2, b=1;

	//3.10: Qual o resultado?
		#include <stdio.h>
		int main (){
			int a=10,b=10;
			if(a==5){b--;}
			printf("%d, %d", a,b--);
		}// -> a=10, b=10;

	//3.11:
		#include <stdio.h>
		#include <math.h>

		double distancia(double x1,double y1,double x2,double y2){
			double dist=0;
			double distx=x2-x1;
			double disty=y2-y1;
			dist = sqrt(pow(disty,2)+pow(distx,2));
			return dist;
		}

		int main(){
			double xc=0,yc=0,r=0;
			printf("Insira as coordenadas do centro e o raio: ");
			scanf("%lf %lf %lf", &xc, &yc, &r);
			printf("Circunferencia de Centro (%.1lf, %.1lf) e raio %.1lf;\n\n", xc, yc, r);
			
			int dentro=0, sobre=0, fora=0;
			double x=0,y=0;
			do{ 
				printf("Insira coordenadas: ");
				scanf("%lf %lf", &x, &y);
				printf("Coordenadas: (%.1lf, %.1lf);\n", x,y);
				if(distancia(x,y,xc,yc)==0){
					printf("Fim do loop.\n\n");
					break;
				} else
				if(distancia(x,y,xc,yc) <r){printf("dentro.\n\n");dentro++;} else
				if(distancia(x,y,xc,yc)==r){printf("sobre. \n\n"); sobre++;} else
				if(distancia(x,y,xc,yc) >r){printf("fora.  \n\n");  fora++;}
			}	while(1);	

			printf("Quantidade de ponto dentro da circunferencia: %d;\n",dentro);
			printf("Quantidade de ponto sobre   a circunferencia: %d;\n", sobre);
			printf("Quantidade de ponto fora   da circunferencia: %d;\n",  fora);
			return 0;
		}			 

	//3.12: Qual o resultado?
		#include<stdio.h>
		#define x 2

		int main(){
		    int i;
		    i = x*x*x;
		    printf("%d",i);
		    return 0;
		}

	//3.13:
		#include <stdio.h>

		int func(int x){
		    if(x == 0){return 0;}
		    return ((x % 10) + func(x / 10));
		}// -> Soma os algarismo do número fornecido;

		int main(){
		    printf("%d",func(123456789));
		    return 0;
		}

	//3.14:
		#include <stdio.h>

		int fatorial(int n){
			int i=1;
			int fat=1;
			while(i<=n){fat *= i++;}
			return fat;
		}	

		int main(void){
			printf("%d", fatorial(3));
			return 0;
		}

	//3.15:
		#include <stdio.h>
		#include <math.h>

		double hrmc_serie_cr(int n){
		    static double soma_cr=0;
		    if(n==1){
		        printf(" 1 = ");
		        soma_cr += 1;
		        return 0;}
		    printf(" 1/%d +",n);
		    soma_cr += pow(n,-1);
		    //printf("%lf\n", soma_cr);
		    hrmc_serie_cr(n-1);
		    return soma_cr;
		}

		double hrmc_serie_sr(int n){
		    if(n<1 || (n-(int)n)!=0){return -1;}         //validando entrada;
		    float soma=0;
		    int i=1;
		    if(i==1 && n==1){
		        soma = pow(1,1);
		        printf(" 1 = ");
		        return soma;
		    }else{
		        while(i<=n){
		            if(i==1){printf(" 1 +");}       else
		            if(i==n){printf(" 1/%d = ",n);} else
		            {printf(" 1/%d +", i);}
		            soma += pow(i,-1); //Se eu coloco (1/i) o C mete zero e vc que se foda-se;
		            i++;
		        }
		    return soma;
		    }     
		}

		int main(void){
		    printf("%lf", hrmc_serie_sr(13));
		    printf("\n");
		    printf("%lf", hrmc_serie_cr(13));
		    return 0;
		}	

	//3.16:
		#include <stdio.h>

		double fib_cr(int n){
		    if(n==1){return 0;}
		    if(n==2){return 1;}
		    return fib_cr(n-1)+fib_cr(n-2);
		}

		void seq_fib_cr(int n){
		    for(int i=1; i<=n; i++){
		        printf("%.0lf ", fib_cr(i));
		   }
		}

		void fib_sr(int n){
		    if(n>=1){printf("%d ", 0);}
		    if(n>=2){printf("%d ", 1);}
		    int antr=0;
		    int prox=1;
		    int i=1;
		    while(i<=n-2){
		        prox=prox+antr;
		        antr=prox-antr;
		        i++;
		        printf("%d ",prox); 
		   }
		    return ;
		}

	//3.17: Qual o resultado?
		#include<stdio.h>
		int main(){
			int i, j;
			for(i = 1, j = 1;i<=3,j<=3;i++,j++)
			printf("%d %d ",i, j);
			return 0;
		}// -> 1 1 2 2 3 3 

	//3.18: Resultado de: printf("%d %d %d %d", !3, !0, 3+’a’>’b’+2 && !’b’, 1 || !2 && 3);
		#include <stdio.h>

		int main(void){
		    printf("%d \n", !3);    			// !3          -> 0
		    printf("%d \n", !0);    			// !0          -> 1
		    printf("%d \n", 3+'a'>'b'+2);		// 3+97>98+2   -> 0
		    printf("%d \n",  !'b');             // !'b' -> !98 -> 0
		    printf("%d \n", 1 || !2 && 3);      // 1 || 0 && 3 -> 1 || 0 -> 1
		    									// && tem precedencia sobre ||	
			return 0;
		}

	//3.19:
		double fib_cr(int n){
		    if(n==1){return 0;}
		    if(n==2){return 1;}
		    return fib_cr(n-1)+fib_cr(n-2);
		}

		double fib_sr(int n){
		    if(n==1){return 0;}
		    if(n==2){return 1;}
		    int antr=0;
		    int prox=1;
		    int i=1;
		    while(i<=n-2){
		        prox=prox+antr;
		        antr=prox-antr;
		        i++; 
		   }
		    return prox;
		}

	//3.20: 
		#include <stdio.h>

		double fatorial(int num){
		    if(num==0||num==1){return 1;}
		    return num*fatorial(num-1);
		}

		double resto(int divd, int divs){
		    if(divs==0){return -1;}
		    if(divd<divs){return divd;} 
		    return resto(divd-divs, divs);
		}

		double quociente(int divd, int divs){
		    static int cont=0;
		    if(divd<divs){return cont;}
		    cont++;
		    return quociente(divd-divs, divs);
		}

		double produto(int num, int time){
		    if(time==0){return 0;}
		    if(time==1){return num;}
		    return num+produto(num, time-1);
		}

		int suc (int n){return n+1;}
		int pred(int n){return n-1;}
		double soma(int maior, int menor){
		    if(menor<=0){return maior;}
		    return (soma(suc(maior), pred(menor))); 
		}

		int main(void){
		    int n1=0,n2=0;
		    printf("Insira 2 numeros: ");
		    scanf("%d %d", &n1, &n2);
		    printf("N1 = %d\n",n1);
		    printf("N2 = %d\n",n2);


		    printf("Fatorial: %d! = %.0lf\n", n1, fatorial(n1));

		    printf("Resto %d/%d: %.0lf\n", n1, n2, resto(n1,n2));
		    printf("Resto(conf): %d\n", n1%n2);

		    if(n2!=0){
		        printf("Quociente %d/%d: %.0lf\n", n1, n2, quociente(n1,n2));
		        printf("Quociente(conf): %d\n", (int)n1/n2);
		    }

		    printf("Produto %d*%d: %.0lf\n", n1, n2, produto(n1,n2));
		    printf("Produto(conf): %d\n", n1*n2);

		    printf("Soma %d+%d: %.0lf\n", n1, n2, soma(n1,n2));
		    printf("Soma(conf): %d\n", n1+n2);
		    return 0;
		}

	//3.21:
		#include <stdio.h>
		#include <math.h>

		void regr(int n){
		    static int i=0;
		    if(n<=0){printf("0...");}else
		    {
		        printf("%d ",n);
		        regr(n-1);
		    }
		}

		void bin_inv(int n){
		    if(n<=0){printf("...");}else
		    {
		        printf("%d", n%2);
		        bin_inv((n-(n%2))/2);
		    }    
		}


		double bin_f2(int n){
		    static int i=0;
		    if(n<=0){return 2;} //2 indica o fim do programa
		    i++;
		    return ( (n%2)*pow(10,i) + bin_f2((n-(n%2))/2 ));
		}

		double bin_p(int n){
		    static int i=0;
		    if(n<=1){return (n%2)*pow(10,i);}
		    i++;
		    return ( (n%2)*pow(10,i-1) + bin((n-(n%2))/2 ));
		}

		double bin(int n){
			static int f=0;
		    static int i=0;
		    if(f){i=0;f=0;}
		    if(n<=1){
		    	f=1;
		    	return (n%2)*pow(10,i);
		    }
		    i++;
		    return ( (n%2)*pow(10,i-1) + bin((n-(n%2))/2 ));
		}

		int main(void){
		    int n1=0;
		    printf("Insira um numero: ");
		    scanf("%d", &n1);
		    printf("N1 = %d\n",n1);

		    printf("Leia da direita pra esquerda: \n");
		    bin_inv(n1);
		    printf("\n");
		    printf("%.0lf\n", bin_f2(n1));
		    printf("%.0lf\n", bin(n1));
		    return 0;
		}

	//3.22:
		#include<stdio.h>
		int main(){
		    int i = 5, j = 6, k = 7;
		    if(i > j == k) printf("%d %d %d", i++, ++j, --k);
		    else           printf("%d %d %d", i, j, k);
		    return 0;
		}// -> 5 6 7; 
		 // Em C, o operador > tem precedencia sobre o operador == :
		 // 		5 > 6 == 7 
		 //			    0 == 7
		 //  		    0	

	//3.23:
	    #include<stdio.h>
	    #define sqr(x) ++x * ++x

	    int main(){
	        int a = 3, z;
	        z = ++a * ++a;              //z recebe 5*5, a incrementa pra 5; 
	        a -= 3;                     //a decrementa pra 2;    
	        printf("%d %d", sqr(a), z); //a incrementa pra 4*4;
	        return 0; 
	    }// -> 16 25
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
4. Vetores e Matrizes:	
	//4.1:
		#include <stdio.h>

		int main(void){
			int vetor[10];
			double soma=0, media=0;
			for(int i=0; i<=9; i++){
				printf("Insira elemento %d: ", i+1);
				scanf("%d", &vetor[i]);
				soma+=vetor[i];
				media=soma/(i+1);
			}
			printf("%.0lf\n", soma);
			printf("%.3lf\n", media);	
			return 0;
		}

	//4.2:
		#include <stdio.h>

		int main(void){
		    int size=0;
		    printf("Insira o numero de elementos a serem armazenados no array: ");
		    scanf("%d", &size);

		    int vetor[size];
		    printf("Insira %d elementos no array:\n", size);
		    for(int i=0; i<=size-1; i++){
		        printf("Elemento - %d: ", i+1);
		        scanf("%d", &vetor[i]);
		    }
		    printf("\n");

		    printf("Os valores armazenados no array sao:\n");
		    for(int i=0; i<=size-1; i++){
		        printf("%d ", vetor[i]);
		    }
		    printf("\n");
		    printf("Os valores armazenados no array ao contrário sao:\n");
		    for(int j=size-1; j>=0; j--){
		        printf("%d ", vetor[j]);
		    }            
		    printf("\n");

		    return 0;
		}

	//4.3:
		#include <stdio.h>
		#include <math.h>   //->função pow()
		#include <stdlib.h> //->função abs()

		double raiz_2_newton(double n, double r){
		    if(abs(pow(r,2)-n)<0.001){return r;}
		    else{
		        r = (pow(r,2)+n)/(2*r); 
		        return (raiz_2_newton(n,r));
		    }
		}

		int main(void){
		    double n=0;
		    printf("Insira um num real: ");
		    scanf("%lf", &n);
		    printf("Num: %lf\n", n);

		    printf("%lf", raiz_2_newton(n,1));
		    return 0;
		}

	//4.4:
		#include <stdio.h>
		int main(){
		    int a,b,c;
		    int arr[5]={1,2,3,25,7};
		    a = ++arr[1]; 
		    	//a = 3;
		    	//arr[5]={1,3,3,25,7};
		    	printf("%d %d\n",a, arr[1]);
		    b = arr[1]++;
		    	//b = 3;
		    	//arr[5]={1,4,3,25,7};    
		    	printf("%d %d\n",b, arr[1]); 
		    c = arr[a++];
		    	//c=arr[3++]=arr[3]=25;
		    	//a=4
		    	printf("%d\n",c);
		    	printf("%d %d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4]); 

		    printf("\n");   
		    printf("%d--%d--%d",a,b,c);      
	    return 0;
	    }// -> 4--3--2

	//4.5:
		#include <stdio.h> //programa 1
		int main (){
		int d,a=1,b=2;
		d = a++ + ++b;
		printf("%d %d %d", d, a, b);
		}//-> 4 2 3;

		#include <stdio.h> //programa 2
		int main(){ 
			int d,a=1,b=2;
			d = a++ +++b;
			printf("%d %d %d", d, a, b);
		}//-> Erro de compilação;

	//4.6:
		//Mesma questão do 4.1;

	//4.7:
		//Mesma questão do 4.2;

	//4.8:
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h> 

		int main(){
		    int size=0;
		    printf("Insira o tamanho do vetor: ");
		    scanf("%d", &size);
		    printf("Tamanho: %d\n", size);

		//Criando o vetor e já imprimindo ele
		    int vetor[size];
		    srand(time(NULL));
		    printf("vetor original = {");
		    for(int i=0; i<=size-1; i++){
		        vetor[i]=rand()%100;
		        if(i==size-1){printf("%d}", vetor[i]);}
		        else{printf("%d, ", vetor[i]);}
		    }
		    printf("\n");

		//Criando vetor ordenado crescente (metodo bolha, eu acho);
		    //Se eu quisse manter o vetor original intacto, era só criar um novo vetor;
		    int aux=0;
		    for(int i=0; i<=size-1; i++){
		        for(int j=i; j<=size-1; j++){
		            if(vetor[j]<vetor[i]){
		                aux=vetor[j];
		                vetor[j]=vetor[i];
		                vetor[i]=aux;
		            }
		        }    
		    }

		    printf("vetor ordenado = {");
		    for(int i=0; i<=size-1; i++){
		        if(i==size-1){
		            printf("%d}",vetor[i]);
		        }else{
		            printf("%d, ", vetor[i]);
		        }
		    }    
		    printf("\n");

		//criando vetor alternado menor/maior 
		    int vetor_alt[size];   
		    for(int i=0; i<=(size-1); i++){
		        if(i%2==0){vetor_alt[i]=vetor[i/2];}
		        else{vetor_alt[i]=vetor[size-((i+1)/2)];}    

		        // vetor_alt[0]=vetor_ord[0];
		        // vetor_alt[1]=vetor_ord[size-1]; 1/2 -> -1
		        // vetor_alt[2]=vetor_ord[1];
		        // vetor_alt[3]=vetor_ord[size-2]; 3/2 -> -2
		        // vetor_alt[4]=vetor_ord[2];
		        // vetor_alt[5]=vetor_ord[size-3]; 5/2 -> -3             
		    } 
		    printf("vetor alternad = {");
		    for(int i=0; i<=size-1; i++){
		        if(i==size-1){printf("%d}", vetor_alt[i]);}
		        else{printf("%d, ", vetor_alt[i]);}
		    }
		    printf("\n");   


		    return 0;
		}	

	//4.9:
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(void){
		    int size=0;
		    printf("Insira o tamanho do vetor: ");
		    scanf("%d", &size);
		    printf("Tamanho: %d\n", size);

		    int vetor[size];
		    srand(time(NULL));
		    printf("vetor = {");
		    for(int i=0; i<=size-1; i++){
		        vetor[i]=rand()%2;
		        if(i==size-1){printf("%d}", vetor[i]);}
		        else{printf("%d, ", vetor[i]);}
		    }
		    printf("\n");

		    int cont=0;
		    int sub=0;
		    for(int i=0; i<=size-1; i++){
		        if(vetor[i]==0){cont++;}
		        else{cont--;}
		        if(cont==0){sub=i+1;}
		    }

		    printf("Sub-vetor encontrado do indice 0 ao %d", sub);
		    return 0;
		}

	//4.10:	
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(void){
		    srand(time(NULL));

		    int size=0;
		    printf("Insira o tamanho do vetor: ");
		    scanf("%d", &size);
		    printf("Tamanho: %d\n", size);

		//Criando os vetores a serem subtraidos;
		    int vetor1[size];
		    int vetor2[size];
		    printf("vetor 1 = {");
		    for(int i=0; i<=size-1; i++){
		        vetor1[i]=rand()%100;
		        if(i==size-1){printf("%d", vetor1[i]);}
		        else{printf("%d, ", vetor1[i]);}
		    }
		    printf("}\n");
		    printf("vetor 2 = {");
		    for(int i=0; i<=size-1; i++){
		        vetor2[i]=rand()%100;
		        if(i==size-1){printf("%d", vetor2[i]);}
		        else{printf("%d, ", vetor2[i]);}
		    }
		    printf("}\n");

		//criando o vetor subtração e imprimindo ele
		    int vetor_sub[size];
		    for(int i=0; i<=size-1; i++){
		        vetor_sub[i]=vetor1[i]-vetor2[i];
		    }
		    
		    printf("vetor s = {");
		    for(int i=0; i<=size-1; i++){
		        if(i==size-1){printf("%d", vetor_sub[i]);}
		        else{printf("%d, ", vetor_sub[i]);}
		    }
		    printf("}\n");    
		    return 0;
		}	

	//4.11: -> Não eh bem o que a questão pediu, mas eu nem entendi direito o que ela quer, então...eh;
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(void){
		    srand(time(NULL));

		    int size=0;
		    printf("Insira o tamanho do vetor: ");
		    scanf("%d", &size);
		    printf("Tamanho: %d\n", size);

		//criando o vetor e imprimindo-o
		    int vetor[size];
		    printf("vetor original = {");
		    for(int i=0; i<=size-1; i++){
		        vetor[i]=rand()%100;
		        if(i==size-1){printf("%d", vetor[i]);}
		        else{printf("%d, ", vetor[i]);}
		    } printf("}\n");    

		//Ordenando o vetor:
		    int aux=0;
		    for(int i=0; i<=size-1; i++){
		        for(int j=i+1; j<=size-1; j++){
		            if(vetor[i]>vetor[j]){
		                aux     =vetor[j];
		                vetor[j]=vetor[i];
		                vetor[i]=     aux;}}}

		//Imprimindo vetor ordenado:
		    printf("vetor ordenado = {");
		    for(int i=0; i<=size-1; i++){
		        if(i==size-1){printf("%d", vetor[i]);}
		        else{printf("%d, ", vetor[i]);}
		    } printf("}\n");         

		//Imprimindo mediana
		    //eu podia usar a variavel "size", mas eu nem lembrei que ela existia, enfim...
		    int tam=sizeof(vetor)/sizeof(int);
		    float mediana=0;  
		    if(tam%2==0){
		        mediana = (vetor[(tam/2)-1] + vetor[tam/2]);
		        mediana /= 2;
		    }else{
		        mediana = vetor[((tam-1)/2)];
		    }
		    printf("%0.2f", mediana); 
		    return 0;
		}  	

	//4.12
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>
		#include <math.h>

		int main(void){
		    srand(time(NULL));

		    int size=0;
		    printf("Insira o tamanho do vetor: ");
		    scanf("%d", &size);
		    printf("Tamanho: %d\n", size);

		//criando o vetor e imprimindo-o
		    int vetor[size];
		    printf("vetor original = {");
		    for(int i=0; i<=size-1; i++){
		        vetor[i]= (rand()%100)*pow(-1,rand()%2); //Vetor possuir num negativos;
		        if(i==size-1){printf("%d", vetor[i]);}
		        else{printf("%d, ", vetor[i]);}
		    } printf("}\n");

		//Calculo par c/ soma minima, admitindo que os pares não podem contem elementos repetidos;
		    int soma_min=vetor[0]+vetor[1];
		    int el1=vetor[0],el2=vetor[1];
		    for(int i=0; i<=size-1; i++){
		        for(int j=i+1; j<=size-1; j++){   
		            if(vetor[i]+vetor[j]<soma_min){
		                soma_min=vetor[i]+vetor[j];
		                el1=vetor[i];
		                el2=vetor[j];
		            }
		        }          
		    }
			//Se eu quissese que os pares pudessem conter elementos
		    //repetidos, era só fazer: 
		    	// int soma_min=2*vetor[0];
		    	// int el1=vetor[0],el2=vetor[0];
		    	// ...
		    	//for(int j=i; j<=size-1; j++){       

		    printf("Par cuja soma eh minima: (%d,%d)\n", el1, el2);
		    printf("Soma: %d\n", soma_min);

		    return 0;
		}  

	//4.12(BONUS): encontre o par cujos elementos tenham a soma mais proxima de uma constante dada;
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>
		#include <math.h>

		//Calculo modulo da diferença
		double abs_dif(double cte, double valor){
		    if(cte-valor<0){return valor-cte;}
		    return cte-valor;
		}

		int main(void){
		    srand(time(NULL));
		    double cte=0;
		    printf("Insira uma constante: ");
		    scanf("%lf", &cte);
		    printf("Constante: %.2lf\n", cte);

		    int size=0;
		    printf("Insira o tamanho do vetor: ");
		    scanf("%d", &size);
		    printf("Tamanho: %d\n", size);

		//criando o vetor e imprimindo-o
		    int vetor[size];
		    printf("vetor original = {");
		    for(int i=0; i<=size-1; i++){
		        vetor[i]= (rand()%100)*pow(-1,rand()%2); //Vetor possuir num negativos;
		        if(i==size-1){printf("%d", vetor[i]);}
		        else{printf("%d, ", vetor[i]);}
		    } printf("}\n");

		//Calculo par c/ soma mais se aproxima da constante dada, admitindo que os pares não podem contem elementos repetidos;
		    double diff=abs_dif(cte,vetor[0]+vetor[1]);
		    int el1=vetor[0],el2=vetor[1];
		    for(int i=0; i<=size-1; i++){
		        for(int j=i+1; j<=size-1; j++){

		            if(abs_dif(cte,vetor[i]+vetor[j])<diff){
		                diff=abs_dif(cte,vetor[i]+vetor[j]);
		                el1=vetor[i];
		                el2=vetor[j];
		            }
		        }          
		    } 
		    //Se eu quissese que os pares pudessem conter elementos
		    //repetidos, era só fazer: 
		        // int soma=2*vetor[0];
		        // int el1=vetor[0],el2=vetor[0];
		        // ...
		        // for(int j=i; j<=size-1; j++){      

		    printf("Par cuja soma mais se aproxima de %lf: (%d,%d)\n",cte, el1, el2);
		    printf("Diff: %lf\n", diff);

		    return 0;
		}

		//Assim, eu poderia até fazer, provavelmente, uma questão parecida mas com pares ordenados formados com 2 vetores
		//mas parece repetitivo, além de chatinho considerando que existe a possibilidade de deixar pares formados com
		//elementos de 1 só vetor e se eles podem ser ou não repetidos;

	//4.13:
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(void){
		    srand(time(NULL));

		    int size=0;
		    printf("Insira o tamanho do vetor: ");
		    scanf("%d", &size);
		    printf("Tamanho: %d\n", size);

		//criando o vetor e imprimindo-o
		    int vetor[size];
		    printf("vetor original = {");
		    for(int i=0; i<=size-1; i++){
		        vetor[i]= (rand()%3);                   //Vamos diminuir o escopo pra ter mais zeros;
		        if(i==size-1){printf("%d", vetor[i]);}
		        else{printf("%d, ", vetor[i]);}
		    } printf("}\n");

		//Empurrando os zeros pro final
		    int cont=0; //conta zeros
		    int aux=-1;
		    int j  =-1;
		    for(int i=0; i<=((size-1)-cont); i++){ 
		        if(vetor[i]==0){
		            j=i;
		            while(j<((size-1)-cont)){
		                vetor[j]=vetor[j+1];
		                j++;           
		            }vetor[(size-1)-cont]=0;
		            cont++;
		            i--; //basicamente faz o programa checar o novo valor aloca na antiga posição do zero;
		        }
		    }
		    //A função do "cont" nesse programa eh otimização, ele evita que o compilador desnecessáriamente permute zeros que já foram alocado no final do codigo;
		    //Porém o programa alçança o mesmo resultado caso a variavel cont seja eliminada, apenas realiza compilação desnecessaria;

		//Imprimindo o novo vetor
		    printf("vetor novo     = {");
		    for(int i=0; i<=size-1; i++){                   
		        if(i==size-1){printf("%d", vetor[i]);}
		        else{printf("%d, ", vetor[i]);}
		    } printf("}\n");   
		    
		    return 0;
		} 

	//4.14:
		conio.h não funciona aqui, então vou skipar;

	//4.15:
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(void){
		    srand(time(NULL));

		    int row=0,col=0;
		    printf("Insira tamanho da matriz: ");
		    scanf("%d %d", &row, &col);
		    printf("Matriz %dx%d\n", row, col);

		    //Escrever a matriz bonitinha eh chato pqp, fiz uma vez pq eu consigo, proximo eh só números e \n´s
		    int mat[row][col];
		    printf("matriz = {\n");
		    for(int i=0; i<=row-1; i++){
		        printf("\t{");
		        for(int j=0; j<=col-1; j++){
		            mat[i][j]=rand()%100;
		           // mat[0][0]=-1;
		            if(mat[i][j]<10){
		                if(i<row-1){
		                    if(j==col-1){printf(" %d},\n", mat[i][j]);}
		                    else{printf(" %d, ",mat[i][j]);}
		                }else{
		                    if(j==col-1){printf(" %d}};\n", mat[i][j]);}
		                    else{printf(" %d, ",mat[i][j]);}}
		            }else{
		                if(i<row-1){
		                    if(j==col-1){printf("%d},\n", mat[i][j]);}
		                    else{printf("%d, ",mat[i][j]);}
		                }else{
		                    if(j==col-1){printf("%d}};\n", mat[i][j]);}
		                    else{printf("%d, ",mat[i][j]);}}
		            }
		        }
		    }

		    int _1menor=mat[0][0];
		    int _1p1=0,_1p2=0;
		    for(int i=0; i<=row-1; i++){
		        for(int j=0; j<=col-1; j++){
		            if(mat[i][j]<_1menor){
		                _1menor  =mat[i][j];
		                _1p1=i;
		                _1p2=j;
		            }
		        }
		    }
		    printf("Menor:         mat[%d][%d] = %d\n", _1p1,_1p2,_1menor);

		    int _2menor;
		    int _2p1,_2p2;
		    for(int i=0; i<=row-1; i++){
		        for(int j=0; j<=col-1; j++){
		            if(i!=_1p1 || j!=_1p2){
		                if(mat[i][j]<_2menor){
		                    _2menor  =mat[i][j];
		                    _2p1=i;
		                    _2p2=j;
		                }
		            }
		        }
		    }
		    printf("Segundo Menor: mat[%d][%d] = %d\n", _2p1, _2p2, _2menor);

		    return 0;
		}      			 	

	//Desafio meu->Ordenar cada linha da matriz;
	//Desafio meu->Ordenar cada coluna da matriz;
	//Desafio meu->Transforma uma matriz no vetor correspondenter	
	//Desafio meu->Ordenar uma matriz inteira em vetor;
	//Desafio meu->Ordenar uma matriz inteira em matriz;				
	//SOLUÇÃO:
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(void){
		    srand(time(NULL));

		    int row=0,col=0;
		    int l,c,mv;
		    int aux;    
		    printf("Insira tamanho da matriz: ");
		    scanf("%d %d", &row, &col);
		    printf("Matriz %dx%d\n", row, col);
		    int mat[row][col];

		    printf("Ordenar Linhas?  (1/0) ");
		    scanf("%d",&l);
		    printf("Ordenar Colunas? (1/0) ");
		    scanf("%d",&c);
		    printf("Ordenar Vetor?   (1/0) ");
		    scanf("%d",&mv);


		//Imprimir matriz original;    
		    printf("Matriz original = {\n");
		    for(int i=0; i<=row-1; i++){
		        printf("\t{");
		        for(int j=0; j<=col-1; j++){
		            mat[i][j]=rand()%100;
		            if(mat[i][j]<10){
		                if(i<row-1){
		                    if(j==col-1){printf(" %d},\n", mat[i][j]);}
		                    else{printf(" %d, ",mat[i][j]);}
		                }else{
		                    if(j==col-1){printf(" %d}};\n", mat[i][j]);}
		                    else{printf(" %d, ",mat[i][j]);}}
		            }else{
		                if(i<row-1){
		                    if(j==col-1){printf("%d},\n", mat[i][j]);}
		                    else{printf("%d, ",mat[i][j]);}
		                }else{
		                    if(j==col-1){printf("%d}};\n", mat[i][j]);}
		                    else{printf("%d, ",mat[i][j]);}}
		            }
		        }
		    }


		//Ordenar as linhas da matriz;
		    if(l){     
		        for(int i=0; i<=row-1; i++){ 
		            for(int j=0; j<=col-1; j++){
		                for(int k=j; k<=col-1; k++){
		                    if(mat[i][j]>mat[i][k]){
		                        aux=mat[i][j];
		                        mat[i][j]=mat[i][k];
		                        mat[i][k]=aux;
		        }}}}
		    
		        printf("Matriz ordena linhas= {\n");
		        for(int i=0; i<=row-1; i++){
		            printf("\t{");
		            for(int j=0; j<=col-1; j++){
		                if(mat[i][j]<10){
		                    if(i<row-1){
		                        if(j==col-1){printf(" %d},\n", mat[i][j]);}
		                        else{printf(" %d, ",mat[i][j]);}
		                    }else{
		                        if(j==col-1){printf(" %d}};\n", mat[i][j]);}
		                        else{printf(" %d, ",mat[i][j]);}}
		                }else{
		                    if(i<row-1){
		                        if(j==col-1){printf("%d},\n", mat[i][j]);}
		                        else{printf("%d, ",mat[i][j]);}
		                    }else{
		                        if(j==col-1){printf("%d}};\n", mat[i][j]);}
		                        else{printf("%d, ",mat[i][j]);}}
		    }}}
		}            

		//Ordenar as colunas da matriz;
		if(c){         
		    for(int j=0; j<=col-1; j++){ 
		        for(int i=0; i<=row-1; i++){
		            for(int k=i; k<=row-1; k++){
		                if(mat[i][j]>mat[k][j]){
		                    aux=mat[i][j];
		                    mat[i][j]=mat[k][j];
		                    mat[k][j]=aux;
		    }}}}

		    printf("Matriz ordena colunas= {\n");
		    for(int i=0; i<=row-1; i++){
		        printf("\t{");
		        for(int j=0; j<=col-1; j++){
		            if(mat[i][j]<10){
		                if(i<row-1){
		                    if(j==col-1){printf(" %d},\n", mat[i][j]);}
		                    else{printf(" %d, ",mat[i][j]);}
		                }else{
		                    if(j==col-1){printf(" %d}};\n", mat[i][j]);}
		                    else{printf(" %d, ",mat[i][j]);}}
		            }else{
		                if(i<row-1){
		                    if(j==col-1){printf("%d},\n", mat[i][j]);}
		                    else{printf("%d, ",mat[i][j]);}
		                }else{
		                    if(j==col-1){printf("%d}};\n", mat[i][j]);}
		                    else{printf("%d, ",mat[i][j]);}}
		}}}}

		//Matriz para vetor equivalente;
		if(mv){
		    int mat_vetor[row*col];
		    int k=0,i=0,j=0;
		    while(k<=(row*col)-1){
		        mat_vetor[k]=mat[i][j];
		        k++;
		        j++;
		        if(j>=col){i++;j=0;}
		    }


		    printf("Matriz vetor equivalente:\n\t{");
		    for(int k=0; k<=(row*col)-1; k++){
		        if(k<(row*col)-1){printf("%d, ",mat_vetor[k]);}
		        else{printf("%d}\n",mat_vetor[k]);}
		    }    

		//Matriz para vetor equivalente ordenado;
		    for(int i=0; i<=(row*col)-1; i++){
		        for(int j=i; j<=(row*col)-1; j++){
		            if(mat_vetor[i]>mat_vetor[j]){
		                aux=mat_vetor[i];
		                mat_vetor[i]=mat_vetor[j];
		                mat_vetor[j]=aux;
		            }
		        }
		    }
		    printf("Matriz vetor ordenado equivalente:\n\t{");
		    for(int k=0; k<=(row*col)-1; k++){
		        if(k<(row*col)-1){printf("%d, ",mat_vetor[k]);}
		        else{printf("%d}\n\n",mat_vetor[k]);}
		    }    

		//Matriz para Matriz Ordenada;
		    k=0;i=0;j=0;    
		    while(k<=(row*col)-1){
		        mat[i][j]=mat_vetor[k];
		        k++;
		        j++;
		        if(j>=col){i++;j=0;}
		    }
		    printf("Matriz ordena colunas= {\n");
		    for(int i=0; i<=row-1; i++){
		        printf("\t{");
		        for(int j=0; j<=col-1; j++){
		            if(mat[i][j]<10){
		                if(i<row-1){
		                    if(j==col-1){printf(" %d},\n", mat[i][j]);}
		                    else{printf(" %d, ",mat[i][j]);}
		                }else{
		                    if(j==col-1){printf(" %d}};\n", mat[i][j]);}
		                    else{printf(" %d, ",mat[i][j]);}}
		            }else{
		                if(i<row-1){
		                    if(j==col-1){printf("%d},\n", mat[i][j]);}
		                    else{printf("%d, ",mat[i][j]);}
		                }else{
		                    if(j==col-1){printf("%d}};\n", mat[i][j]);}
		                    else{printf("%d, ",mat[i][j]);}}
		}}}}

		    return 0;
		}          	




	//4.16:
		#include <stdio.h>

		int main(void){
			int pos = 3;
			int vetor[10]={1,2,3,4,5,6,7,8,9,10};
			int tam = sizeof(vetor)/sizeof(int);

			// Imprimindo o vetor:
			printf("vetor   = {");
		    for(int i=0; i<=tam-1; i++){
		        if(i==tam-1){printf("%d}\n",vetor[i]);}else
		        printf(" %d, ", vetor[i]);
		    } 

		//Fazer função que retorna vetor precisa de ponteiro (e a void deu ruim), então vamo deixar assim:

		// -- ALTERNATIVA 01 -------------------------------------------------------------------------------------
				// int aux=0;

				// for(int i=0; i<=pos-1; i++){ //pos-1
				// 	for(int j=0;j<=(tam-1)-1;j++){//tam
				// 		aux=vetor[j];
				// 		vetor[j]  = vetor[j+1];
				// 		vetor[j+1]= aux;
				// 		for(int i=0; i<=tam-1; i++){
				// 	        if(i==tam-1){printf("%d}\n",vetor[i]);}else
				// 	        printf(" %d, ", vetor[i]);
				// 	    } 
				// 	}printf("\n");
				// }
		//--------------------------------------------------------------------------------------------------------

		// -- ALTERNATIVA 02 -------------------------------------------------------------------------------------

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
		//----------------------------------------------------------------------------------------------------------



		    //Imprimindo o resultado:
		    int i=0;
		    printf("vetor   = {");
		    for(int i=0; i<=tam-1; i++){
		        if(i==tam-1){printf("%d}\n",vetor[i]);}else
		        printf(" %d, ", vetor[i]);
		    }  
			return 0;
		}

	//4.17:
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

	//4.18:
		#include <stdio.h>

		int sub_conj(int subc[], int conj[], int size_subc, int size_conj){
		    int flag=0;
		    for(int i=0; i<=size_subc-1; i++){
		        flag=0;
		        for(int j=0; j<=size_conj; j++){
		            if(subc[i]==conj[j]){flag=1;}
		        }
		        if(flag==0){return 0;}
		    }
		    return 1; 
		}

		int main(void){
		    int conj[10]={3,2,5,4,5,6,7,8,9,10};
		    int subc[4]={1,2,3,4};
		    int size_cj=sizeof(conj)/sizeof(int);
		    int size_sc=sizeof(subc)/sizeof(int);
		    printf("size conj = %d\n", size_cj);
		    printf("size subc = %d\n", size_sc);    

		    if(sub_conj(subc,conj,size_sc,size_cj)){printf("Eh subconjunto!\n");}
		    else{printf("Nao eh subconjunto.\n");}    

		    return 0;
		}

	//4.18(Desafio meu) -> Eu quero saber se o sub-conjunto aparece no conjunto com a mesmissima ordem;
		int sub_conj_exato(int subc[], int conj[], int size_subc, int size_conj){
		    for(int i=0; i<=size_conj-1; i++){ 
		        if(conj[i]==subc[0]){
		            int cont=0;
		            while(subc[cont]==conj[i+cont]){
		                cont++;
		                if(cont>=size_subc){
		                    return 1;
		                }
		            }
		        }    
		    }
		    return 0;
		}	

	//4.19:
		#include <stdio.h>
		int main(){
		    int size=4;
		    int A[4][4]={
		        {1 , 2, 3, 1},
		        {4 , 5, 6, 2},
		        {7 , 8, 9, 3},
		        {10,11,12,13}        
		    };
		    int x=0;
		    for(int row=0; row<size; row++){
		        for(int col=0; col<size; col++){
		            if(row+col == (size-1)){
		                x += A[row][col];
		                printf("%d\n",A[row][col] );
		            }
		        }
		    }
		    printf("%d", x);
		    return 0;
		}//-> Soma os elementos da diagonal secundaria;

	//4.20:
		#include <stdio.h>
		#include <stdlib.h>
		#include <time.h>

		int main(){
		    srand(time(NULL));

		    int size=0;
		    printf("Insira o tamanho: ");
		    scanf("%d", &size);
		    printf("Tamanho: %d\n",size);

		    int vet[size];
		    printf("vetor = {");
		    for(int i=0; i<=size-1; i++){
		        vet[i]=rand()%100;
		        if(i==size-1){printf("%d}\n",vet[i]);}
		        else{printf("%d, ",vet[i]);}
		    }

		    int ctr;
		    for(int i=0; i<=size-1; i++){
		        ctr=0;
		        for(int j=0; j<=size-1; j++ ){
		            if(i!=j && vet[i]==vet[j]){ctr++;}  
		        }
		        if(ctr==0){printf("%d\n",vet[i]);}
		    }

		    return 0;
		}//-> Retorna todos os elementos unicos dentro do vetor;
		 //-> Eu fiz alguma mudança na questão pra ficar + legivel e também pq
		 //-> Eu acho q o segundo for se estendia para além do vetor em 1 pos;	 

	//4.21:
		#include <stdio.h>
		int main(){
			int rows = 3, colums = 4, i, j, k;
			int a[3][4] = {1, 2, 3, 5, 7};
			i = j = k = 00;
				for(i = 0;i<rows;i++)
					for(j = 0;j<colums;j++)
						if(a[k][j]<k)
							k = a[i][j];
			printf("%d\n", k);
			return 0;    
		}//-> Retorna zero, i.e., k=0;

	//4.22:
		#include <stdio.h>
		int main(){
			int arr[2] = {1, 2, 3, 4, 5};
			printf("%d", arr[3]);
			return 0;
		}//-> Retorna algum lixo na memória;

	//4.23:
		#include <stdio.h>
		int main(){
		    int a,b,c;
		    int arr[5]={1,2,3,25,7};
		    a = ++arr[1]; 
		    //a = 3;
		    //arr[5]={1,3,3,25,7};
		    printf("%d %d\n",a, arr[1]);
		    b = arr[1]++;
		    //b = 3;
		    //arr[5]={1,4,3,25,7};    
		    printf("%d %d\n",b, arr[1]); 
		    c = arr[a++];
		    //c=arr[3++]=arr[3]=25;
		    //a=4
		    printf("%d\n",c);
		    printf("%d %d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4]); 

		    printf("\n");   
		    printf("%d--%d--%d",a,b,c);      
		    return 0;
		}//-> Retorna 3-4-25;  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

