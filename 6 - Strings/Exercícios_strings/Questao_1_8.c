#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

void del_car_rep(char texto[]){
	for(int i=0; i<=strlen(texto)-2; i++){
		for(int j=i+1; j<=strlen(texto)-2; j++){
			if((texto[i]==texto[j])&&(texto[i]!='*')){
				texto[j]='*';
			}
		}
	}

	int tam=0;
	for(int i=0; i<=(strlen(texto)-2)-tam; i++){
		if(texto[i]=='*'){
			for(int j=i; j<=strlen(texto)-2; j++){
				texto[j]=texto[j+1];
			}
			i--;
			tam++;
		}
	}
	texto[(strlen(texto)-1)-tam]='\0';
	//printf("%d", strlen(texto));

	printf("%s",texto);

}


int main(void){
	char texto[MAX_SIZE];
	printf("Insira uma string: ");
	fgets(texto, MAX_SIZE, stdin);
	printf("string inserida: %s", texto);

	del_car_rep(texto);
}