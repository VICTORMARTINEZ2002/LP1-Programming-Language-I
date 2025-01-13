#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101


void concerta_string(char texto[]){
	//O texto lido é, por exemplo: 123456\n\0;	
	int tam = strlen(texto); //ex: tam=7, não 8;
	//printf("Tamanho Original: %d\n", tam);
	texto[tam-1]='\0';


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

	//Imprimir a string;
	// for(int i=0; i<=tam-1; i++){
	// 	if(texto[i]=='\0'){
	// 		printf("0");
	// 		break;
	// 	}
	// 	printf("%c", texto[i]);
	// }printf("\n");
}

void print_str_contrario(char texto[]){
	concerta_string(texto);
	//A função anterior concertou o texto que agora é: algumacoisa\0
	int tam = strlen(texto)+1; //pra incluir o \0;
	printf("Tamanho Novo: %d\n", tam);

	//Imprimir a string;
	for(int i=0; i<=tam; i++){
		if(texto[i]=='\n'){
			printf("0");
			break;
		}
		printf("%c", texto[i]);
	}printf("\n\n\n");	

	//Contar os espaços da string;
	int cont_esp=0;
	for(int i=0; i<=tam-1; i++){
		if(texto[i]==' '){cont_esp++;}
	}
	//Armazenar decrescentemente a posição dos espaços num vetor;
	int vet[cont_esp+1]; //Uma posição a mais que vai ser util mais tarde(*);
	for(int i=0; i<=cont_esp; i++){
		vet[i]=-1; //esse -1 na ultima posição é necessario na hora de imprimir como a questão pediu(*)
	}	

	int cont_pos=0;
	for(int i=tam-1; i>=0; i--){
		if(texto[i]==' '){
			vet[cont_pos]=i;
			cont_pos++;
		}
	}//note que a ultima posição do vetor permanece com

	//Imprimir o vet das posições dos espaços;
	printf("Vetor posição dos espaços = {");
	for(int i=0; i<=cont_esp; i++){
		printf("%d ", vet[i]);
	}printf("}\n");

	//Printar as palavras na ordem inversa;
	int stop=tam-1; //pos do \0
	for(int i=0; i<=(cont_esp-1)+1; i++){ 			//interar sobre o vet
		for(int j=vet[i]+1; j<=stop-1; j++){//(*)	//interar sobre o texto
			printf("%c",texto[j]);
		}
		if(i!=cont_esp){printf(" ");}
		stop=vet[i]; //Note que o stop nunca chega ao -1, o ultimo elemento no vetor;
	}


}

int main(void){
	char texto[MAX_SIZE];
	printf("Insira uma string: ");
	fgets(texto, MAX_SIZE, stdin);
	printf("String inserida: %s\n\n", texto);	
	//concerta_string(texto);
	print_str_contrario(texto);


	return 0;
}