#include <stdio.h>
#include <string.h>
#define MAX_SIZE 150

//Reciclagem da questão 1.8
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

	//printf("%s",texto);
}

int cont_caracter(char texto[], char a){
	int cont=0;
	for(int i=0; i<=strlen(texto)-1; i++){
		if(texto[i]==a){cont++;}
	}
	return cont;
}



int main(void){
	char texto[MAX_SIZE];
	printf("Insira uma string: ");
	fgets(texto, MAX_SIZE, stdin);
	printf("String inserida: %s", texto);
	//printf("\n%d", strlen(texto));
	printf("\n");

	char rsm[MAX_SIZE];
	strcpy(rsm, texto);
	del_car_rep(rsm);
	//printf("%s %d",rsm, strlen(rsm));

	for(int i=0; i<=strlen(rsm)-1; i++){
		for(int j=0; j<=strlen(texto)-1; j++){
			if(cont_caracter(texto, rsm[i])==1){
				printf("\n%c",rsm[i]);
				return 0;
			}
		}
	}

	printf("Nao foi encontrado nenhum caractere unico!");


	return 0;
}