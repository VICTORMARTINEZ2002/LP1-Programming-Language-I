#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main(void){
	char str1[MAX_SIZE];
	for(int i=0; i<=sizeof(str1)-1; i++){str1[i]='\0';}

	printf("Insira uma string: ");
	fgets(str1, sizeof(str1), stdin);
	str1[sizeof(str1)-1]='\0';

	for(int i=0; i<=sizeof(str1)-1; i++){
		if((int)str1[i]>=97 && (int)str1[i]<=122){str1[i]-=32;}
	}

	printf("Nova String:       %s", str1);
	return 0;
}