#include <stdio.h>
#define MAX_SIZE 100

int func(const char * str, const char x){
	int y = -1;
	int i = 0;
	while(str[i] != ’\0’) {
		if(str[i]==x){y = i;}
		i++;
	}
	return y;
}

int main(){
	char str[MAX_SIZE];
	char x;
	int y;
	gets(str);
	x = getchar();
	y = func(str, x);
	printf("%d", y);
	return 0; 
}//->Retorna a ultima ocorrencia de um caractere numa string;