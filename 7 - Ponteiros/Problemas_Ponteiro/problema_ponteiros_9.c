#include <stdio.h>

int main(void){
	int a=36;
	int *ptr;
	ptr = &a;
	// %u == unsigned int;
	printf("%u\n", *&ptr);   
	// conteudo do (endereço do ponteiro de a) == ponteiro de a == endereço de a;
	printf("%u\n", &*ptr);  
	// endereço do (conteudo do ponteiro de a) == endereço de a;
	return 0;
}	