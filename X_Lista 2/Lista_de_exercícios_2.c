//	STRINGS:
//1.1:	
	// #include <stdio.h>
	// #include <string.h>

	// int main(void){
	// 	char str1[]="abc";
	// 	char str2[]="abc";
	// 	printf("%d\n", strcmp(str1,str2));
	// 	return 0;
	// }//-> Retorna 0 se as strings são iguais;

//1.2: O que esse programa faz?
	// #include <stdio.h>
	// #define MAX_SIZE 100

	// int func(const char * str, const char x){
	// 	int y = -1;
	// 	int i = 0;
	// 	while(str[i] != ’\0’) {
	// 		if(str[i]==x){y = i;}
	// 		i++;
	// 	}
	// 	return y;
	// }

	// int main(){
	// 	char str[MAX_SIZE];
	// 	char x;
	// 	int y;
	// 	gets(str);
	// 	x = getchar();
	// 	y = func(str, x);
	// 	printf("%d", y);
	// 	return 0; 
	// }//->Retorna a ultima ocorrencia de um caractere numa string;

//1.3: minusculas -> CAIXA ALTA
	// #include <stdio.h>
	// #include <string.h>
	// #define MAX_SIZE 100

	// int main(void){
	// 	char str1[MAX_SIZE];
	// 	for(int i=0; i<=sizeof(str1)-1; i++){str1[i]='\0';}

	// 	printf("Insira uma string: ");
	// 	fgets(str1, sizeof(str1), stdin);
	// 	str1[sizeof(str1)-1]='\0';

	// 	for(int i=0; i<=sizeof(str1)-1; i++){
	// 		if((int)str1[i]>=97 && (int)str1[i]<=122){str1[i]-=32;}
	// 	}

	// 	printf("Nova String:       %s", str1);
	// 	return 0;
	// }

//1.4: Palindromo?
	// #include <stdio.h>
	// #include <string.h>
	// #define MAX_SIZE 100

	// int palindr(char str[]){
	// 	int tam = strlen(str);
	// 	for(int i=0; i<=(int)((tam-1)/2); i++){
	//     	if(str[i]!=str[tam-1-i]){
	//     		return 0;
	//     	}
	// 	}
	// 	return 1;
	// }   

	// int main(void){
	// 	char str1[MAX_SIZE],str2[MAX_SIZE];
	// 	printf("Insira uma string: ");
	// 	fgets(str1, sizeof(str1), stdin);
	// 	//a str1: "ovo\0\n";
	// 	str1[strlen(str1)-1]='\0'; //->Transforma o \n em \0;
	// 	printf("String inserida: %s;\n", str1);
	// 	printf("%d: ", palindr(str1));

	// 	if(palindr(str1)){printf("Eh Palindromo");}
	// 	else{printf("Nao Eh Palindromo");}
	// 	return 0;
	// }	

//1.5:
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int qtd_palav(char str[]){
    int tam=strlen(str); //tamanho da string que inclui o <enter> ou '\0'
    // printf("Tamanho da string com o '\\0': %d\n", tam);

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
	for(int i=sizeof(str1)-1; i>=0; i--){
		if(str1[i]>=32){printf("%c",str1[i]);}
	}
	return 0;
}


