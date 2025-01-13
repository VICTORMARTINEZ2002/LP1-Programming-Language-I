#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int palindr(char str[]){
	int tam = strlen(str);
	for(int i=0; i<=(int)((tam-1)/2); i++){
    	if(str[i]!=str[tam-1-i]){
    		return 0;
    	}
	}
	return 1;
}   

int main(void){
	char str1[MAX_SIZE],str2[MAX_SIZE];
	printf("Insira uma string: ");
	fgets(str1, sizeof(str1), stdin);
	//a str1: "ovo\0\n";
	str1[strlen(str1)-1]='\0'; //->Transforma o \n em \0;
	printf("String inserida: %s;\n", str1);
	printf("%d: ", palindr(str1));

	if(palindr(str1)){printf("Eh Palindromo");}
	else{printf("Nao Eh Palindromo");}
	return 0;
}	