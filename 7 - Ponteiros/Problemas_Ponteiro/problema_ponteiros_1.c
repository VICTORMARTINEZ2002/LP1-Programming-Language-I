#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void str_contraria(char* ptr_str, int tam){
	printf("String ao contrario 1: ");
	for(int i=tam; i>=0; i--){
		printf("%c", ptr_str[i]);
	}
}

int main(void){
	char str[MAX_SIZE]="\0";
	printf("Insira uma string: ");
	fgets(str, MAX_SIZE, stdin);
	str[strlen(str)-1]='\0';             // tirar o \n no final da string;
	printf("string insirida: %s;\n", str);

	char* ptr_str=&str[0];                // mesmo que: int* ptr_str=&str;
	str_contraria(ptr_str, strlen(ptr_str));

	return 0;
}