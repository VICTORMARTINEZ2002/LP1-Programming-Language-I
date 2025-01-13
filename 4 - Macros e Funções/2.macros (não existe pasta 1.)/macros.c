#include <stdio.h>
#include "macros.h"

int main(void){
	double num1=-1,num2=-1;
	printf("Insira dois numeros: ");
	scanf("%lf %lf", &num1, &num2);
	printf("Minimo: %lf \n", min(num1,num2));
	printf("Maximo: %lf \n", max(num1,num2));

	return 0;
}