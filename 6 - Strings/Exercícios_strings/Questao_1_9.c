#include <stdio.h>
#include <string.h>
#define MAX_SIZE 2000
#define WRD_SIZE 15

//Reciclagem da questão 1.6
//Retorna o index da primeira letra da palavra
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

void cont_palavras(char palavra[], char texto[]){
	static int cont=0;

	int f_oc=frist_occurrence(palavra, texto);
	if(f_oc==-1){
		printf("%d", cont); 
		return;
	}

	cont++;
	//printf("%s\n", texto, cont);
	for(int i=0; i<=strlen(texto)-f_oc; i++){
		texto[i]=texto[i+(f_oc+1)]; //Carrega o \0 também
	}
	printf("%s%d\n", texto, cont);

	cont_palavras(palavra, texto);
}


int main(void){
	char texto[MAX_SIZE];
	printf("Insira uma string: ");
	fgets(texto, MAX_SIZE, stdin);
	printf("String inserida: %s", texto);
	printf("\n%d", strlen(texto));

	char palavra[WRD_SIZE];
	printf("Insira uma palavra: ");
	fgets(palavra, WRD_SIZE, stdin);
	printf("palavra inserida: %s", palavra);
	printf("\n");

	cont_palavras(palavra, texto);
	return 0;
}