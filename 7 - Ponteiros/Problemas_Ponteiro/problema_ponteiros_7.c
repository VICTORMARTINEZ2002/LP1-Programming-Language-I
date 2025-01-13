#include <stdio.h>

int main(void){
	char* ptr = "auladelp";
	printf("%c\n", *&*ptr); // *& cancela-se;
	return 0;
}	// Saida: a;