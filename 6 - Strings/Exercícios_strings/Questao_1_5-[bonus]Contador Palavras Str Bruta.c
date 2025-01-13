#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

//CONTADOR DE PALAVRAS, EU FIZ ISSO ANTES DE ME SURGIR A IDEIA DE CONCERTAR A STRING
int qtd_palav(char str[]){
    int tam=strlen(str); //tamanho da string que inclui o '\n', mas não inclui o \0;
    // printf("Tamanho da string sem o '\\0': %d\n", tam);

    // printf("String inserida: \n");
    // for(int i=0; i<=(tam-1)-1; i++){ //imprimindo todo mundo menos o '\0'
    //     printf("%c", str[i]);
    // }   printf("\\n", str[tam-1]);
    // printf("\n");

    int cont=0;
    if(tam<=1){return cont;}
    if(str[0]==' '){
        printf("INICIA COM ESPAÇO: \n");
        for(int i=0; i<=tam-1; i++){
            if(str[i]==' ' && str[i+1]!=' ' && (i+1)!=tam-1){cont++;}
        }
    }else{
        printf("INICIA COM LETRA: \n");
        if(str[(tam-1)-1]==' '){
            for(int i=0; i<=tam-1; i++){
                if(str[i]!=' ' && str[i+1]==' '){cont++;}
            }
        }else{
            for(int i=0; i<=tam-1; i++){
                if(str[i]!=' ' && (str[i+1]==' ' || str[i+1]=='\0')){cont++;}
            }
        }
    }
    return cont;
} 

int eh_espaco(char chr){
	if((int)chr==32){return 1;}
	return 0;	
}

int main(void){
	char str1[MAX_SIZE];
	for(int i=0; i<=sizeof(str1)-1; i++){str1[i]='\0';}

	printf("Insira uma string: ");
	fgets(str1, sizeof(str1), stdin);
	printf("String inserida: %s", str1);

    printf("Palavras: %d\n\n", qtd_palav(str1));

    //Tentativa 0:
	for(int i=sizeof(str1)-1; i>=0; i--){
		if(str1[i]>=32){printf("%c",str1[i]);}
	}printf("\n");

    return 0;
}


