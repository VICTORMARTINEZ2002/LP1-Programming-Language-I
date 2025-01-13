#include <stdio.h>
#include <string.h>

int main(void){
	char str1[]="abc";
	char str2[]="abc";
	printf("%d\n", strcmp(str1,str2));
	return 0;
}//-> Retorna 0 se as strings são iguais;