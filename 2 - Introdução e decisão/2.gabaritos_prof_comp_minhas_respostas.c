#include <stdio.h>      / usar o input-output //incluir a biblioteca

int main(){
	double tc,tf;
	printf("Informe um valor em F: \n");
	scanf("%lf", &tf);
	tc = (tf-32);         // tc = (tf-32)*(5/9) //5/9 é menor q um, e o c trunca pra 0.0
	tc = tc * 5;
	tc = tc / 9;
	printf("A temperatura em C é %.2lf", tc);
	return 0;
}
-------------------------------------------------------------------
#include <stdio.h>      // usar o input-output //incluir a biblioteca

int main(void){
	float temp_f=0.0;
	float temp_c=0.0;
	printf("Informe um valor em F: \n");
	scanf("%f", &temp_f);
	float temp_c=0.0;
	printf("temperatura lida: %.2f", temp_f );
	tc = (tf-32) * (float)5 / 9;             //casting //em c cuidado ao misturar inteiro com float na mesma operação;
	printf("A temperatura em C é %.2f", tc); //pressisão q eu quero mostrar na tela %.4f;
	return 0;
}
=====================================================================================
#include <stdio.h>
#include <math.h>

int main(){
	double cat_ops, cat_adj, hiptn;
	printf("Informe o valor do cateto oposto: \n");
	scanf("%lf", &cat_ops);
	printf("Informe o valor do cateto adjact: \n");
	scanf("%lf", &cat_adj);
	//hiptn = sqrt(cat_ops*cat_ops + cat_adj*cat_adj);
	hiptn = sqrt(pow(cat_ops,2) + pow(cat_adj,2));
	printf("A hipotenusa tem comprimento igual a %.2lf u.c.", hiptn);
	return 0;
}
------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>

int main(void){
	float cateto1=0.0, cateto2=0.0, hipotenusa=0.0;
	printf("Informe os valores do catetos: \n");
	scanf("%f %f", &cateto1,&cateto2);
	printf("Cateto 1: %.2f \t Cateto 2: %.2f \n");     //legal printar na tela esses valores;
	hipotenusa = sqrt((cat_ops*cat_ops) + (cat_adj*cat_adj));
	printf("hipotenusa=%.f u.c.", hipotenusa);
	return 0;
}
=============================================================================
#include <stdio.h>
#include <math.h>

int main(void){
	int num=0;
	printf("Insira um número inteiro: ");
	scanf("%d", &num);
	printf("O número inserido foi %d;\n", num);
	if (num%5==0 && num%3==3==0){
		printf("O número %d é divisivel por 5 e por 3;\n", num);
	} else {
		printf("O número %d não é divisivel por 5 e por 3;\n", num);
	}
	return 0;
}
-------------------------------------------------------------------------------
