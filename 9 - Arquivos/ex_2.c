#include <stdio.h>
#include <string.h>
#include <malloc.h>

void concerta_string(char *texto){
	//O texto lido é, por exemplo: 123456\n\0;	(teclado)
	//O texto lido é, pro exemplo: 123456\0;    (arquivo)
	int tam = strlen(texto); //ex: tam=7, não 8;
	//printf("Tamanho Original: %d\n", tam);
	//texto[tam-1]='\0'; -> só para input teclado que vem com o \n;


	//Tirar os espaços no inicio da string;
	while(texto[0]==' '){
		for(int i=0; i<=(tam-1)+1; i++){
			texto[i]=texto[i+1];
		}
		tam--;
	}

	//Tirar os espaços no fim da string;
	while(texto[(tam-1)-1]==' '){
		texto[(tam-1)-1]='\0';
		tam--;
	}

	//Tirar os espaços duplos no meio da string;
	for(int i=0; i<=tam-1; i++){
		if(texto[i]=='\0'){break;}
		if(texto[i]==' ' && (texto[i+1]==' ' ||texto[i+1]=='\0')){
			tam--;
			for(int j=i; j<=tam-1; j++){
				texto[j]=texto[j+1];		
			}
			i--;
		}
	}
}

int main(){
	FILE * arq;

	arq = fopen("arquivo_1.txt", "r");
	if(arq==NULL){printf("ERRO AO ABRIR O ARQUIVO!");}

	char* texto_ptr;
	texto_ptr = (char*)malloc(1*sizeof(char));
	if(texto_ptr==NULL){printf("Erro malloc.\n"); return 0;}

	int i=0;
	for(char c=getc(arq); c!=EOF; c=getc(arq)){
		texto_ptr[i++]= c; 
		texto_ptr = (char*)realloc(texto_ptr, (i+1)*sizeof(char));
		if(texto_ptr==NULL){printf("a");}
	}	fclose(arq);
	texto_ptr[i]='\0';

	concerta_string(texto_ptr);

	int palavras=0;
	for(int i=0; texto_ptr[i]!='\0'; i++){
		if(texto_ptr[i]==' '){palavras++;}
	}
	palavras++; // pra contar a ultima palavra;

	printf("texto:    %s\n", texto_ptr);
	printf("palavras: %d", palavras);
	return 0;
}