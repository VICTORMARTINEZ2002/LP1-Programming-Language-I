Questões Macros & Funções
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





















		