#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

//faz o lulu livre -> strlen de 17
//faz o lulu livre\n\0
//lulu             -> strlen de 5
//lulu\n\0



int frist_occurrence(char palavra[], char texto[]){
	int flag=0;
	int k=0;

	for(int i=0; i<=strlen(texto)-2; i++){
		if(texto[i]==palavra[0]){
			flag=1;
			for(k=0; k<=strlen(palavra)-2; k++){
				if(texto[i+k]!=palavra[k]){
					flag=0;
					break;
				}	
			}
			if( (texto[i+strlen(palavra)-1]!=' ') && (texto[i+strlen(palavra)-1]!='\n')){flag=0;}
			//Garantir que a palavra acabe ali e que eu não conte uma palavra dentro de outra, por exemplo:
			//     "A portaria esta ocupada" & "porta" resultaria na identificação da palavra porta dentro da str;				
			if(flag){return i;}
		}	
	}
	return -1;
}


int main(void){
	char texto[MAX_SIZE];
	printf("Insira uma string: ");
	fgets(texto, MAX_SIZE, stdin);
	fflush(stdin); //limpar o buffer se necessario
	printf("String inserida: %s\n\n", texto);	
	printf("Strlen texto: %d\n", strlen(texto));	

	char palavra[MAX_SIZE];
	printf("Insira uma palavra: ");
	fgets(palavra, MAX_SIZE, stdin);
	fflush(stdin);
	printf("palavra inserida: %s\n\n", palavra);		

	printf("\nFrist occurence: %d.", frist_occurrence(palavra, texto));


	return 0;
}