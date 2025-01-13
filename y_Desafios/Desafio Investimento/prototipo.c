#include <stdio.h>
#include <stdlib.h>// -> rand
#include <time.h>  // -> time
#include <math.h>

// double bin(int n){
//     static int i=0;
//     if(n<=1){return (n%2)*pow(10,i);}
//     i++;
//     return ( (n%2)*pow(10,i-1) + bin((n-(n%2))/2 ));
// }



//Eu sei que essa solução tem erros, mas acho que ela eh tipo, "boa o bastante";
//ex erro:
	// cash=15; 
	// lucros[3]={48, 16, 44}
	// custos[3]={12,  4, 11}
//O problema consiste no fato que eu não posso comprar a fração de uma ação com o dinheiro
//que me sobrou, e portanto ao escolher individualmente a melhor ação, corro o risco de que
//outras ações menores que somadas custem mais que a melhor ação e ainda me mantenham abaixo do limite
//me possibilitem um retorno maior;
//E eu não tive que fazer caso a caso;
int main(void){
	srand(time(NULL));
	//ENTRADA DE DADOS
	int cash=0;
	int ac=0;
	printf("Insira o valor em caixa disponivel e a quantidade de ac: ");
	scanf("%d %d",&cash, &ac);
	printf("Cash = %d\n", cash);
	printf("Acoes= %d\n", ac);

	//CRIANDO E IMPRIMINDOS OS VETORES LUCROS/CUSTOS & criando o vetor vant
	int custos[ac];
	int lucros[ac];
	double vantgs[ac];

	//Testa o exemplo inicial da questão;
	//Lembre-se de comentar a parte abaixo que atribui valores aleatorios para o vetor;
	lucros[0]=70;
	lucros[1]=20;
	lucros[2]=29;
	lucros[3]=37;
	lucros[4]=7;
	lucros[5]=5;
	lucros[6]=10;
	custos[0]=31;
	custos[1]=21;
	custos[2]=20;
	custos[3]=19;
	custos[4]=4;
	custos[5]=3;
	custos[6]=6;



	for(int i=0; i<=ac-1; i++){
		//ustos[i]=1+rand()%10;
		//lucros[i]=1+rand()%15;
		vantgs[i]=((double)lucros[i]/custos[i]);
	}



	printf("Lucros[%d]={",ac);
	for(int i=0; i<=ac-1; i++){
		if(lucros[i]<10){
			if(i>=ac-1){printf(" %d}\n",lucros[i]);}
			else{printf(" %d, ",lucros[i]);}
		}else{
			if(i>=ac-1){printf("%d}\n",lucros[i]);}
			else{printf("%d, ", lucros[i]);}
		}
	}
	printf("Custos[%d]={",ac);
	for(int i=0; i<=ac-1; i++){
		if(custos[i]<10){
			if(i>=ac-1){printf(" %d}\n",custos[i]);}
			else{printf(" %d, ",custos[i]);}
		}else{
			if(i>=ac-1){printf("%d}\n",custos[i]);}
			else{printf("%d, ", custos[i]);}
		}
	}
	printf("vantgs[%d]={",ac);
	for(int i=0; i<=ac-1; i++){
		if(i>=ac-1){printf("%0.2lf}\n",vantgs[i]);}
		else{printf("%0.2lf, ", vantgs[i]);}
	}

	//Brincadeira	
	double melhor =-1;
	int pos_melhor=-1;
	double pior   =-1;
	int pos_pior  =-1;

	int compra[ac];
	for(int i=0; i<=ac-1; i++){
		compra[i]=-1;
	}
	int cont_compras=0;
	double win=0;
	int flag=1;
	while(flag){
		melhor    =-1;
		pos_melhor=-1;
		pior      =-1;
		pos_pior  =-1;
		//Calcular o melhor investimento;
		for(int i=0; i<=ac-1; i++){
			if(vantgs[i]>melhor){
				melhor=vantgs[i];
				pos_melhor=i;
			}
			if(vantgs[i]<pior){ 
				pior=vantgs[i];
				pos_pior=i;
			}		
		}

		//verificar possibilidade de lucro;
		if(melhor<1){
			flag=0;
			break;
		}

		//verificar se eu consigo comprar a melhor ação e se sim, eu a compro;
		if(custos[pos_melhor]<=cash){
			compra[cont_compras]=pos_melhor;
			win +=lucros[pos_melhor];
			cash-=custos[pos_melhor];
			cont_compras++;
		} vantgs[pos_melhor]=-1; //comprando ou não a melhor ação, ela não mais eh considerada como compravel;
	}

	//Imprimindo a saida
	printf("Compras: %d\n", cont_compras);
	for(int i=0; i<=cont_compras-1; i++){
		printf("%d, ",compra[i]+1);
	}printf("\n");
	printf("Lucro: %.1lf\n", win);
	printf("Sobrou: %d.0\n", cash);
	return 0;
}