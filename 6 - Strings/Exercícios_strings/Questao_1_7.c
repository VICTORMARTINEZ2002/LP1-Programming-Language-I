#include <stdio.h>

//Eu acabei fazendo isso já na questão 1.5, então vou só colar a função;
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