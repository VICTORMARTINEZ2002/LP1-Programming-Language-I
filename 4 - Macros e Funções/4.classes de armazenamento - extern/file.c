#include <stdio.h>
#include "file.h"

//Verdade seja dita, funcionaria sem:
extern int idade;
extern int sexo(int);

extern int main(void){
	printf("Idade: %d\n", idade);
	printf("Sexo? %d\n", sexo(idade));
	return 0;

	
}




