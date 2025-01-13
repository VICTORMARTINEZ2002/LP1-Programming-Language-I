#include <stdio.h>
#include <malloc.h>

// Igual a solução do exercicio apresentado no slide de ponteiros:
void printf_alfabeto_m(char* ptr){
	int i=0;
	char* ponteiro=NULL;
	while(i<=25){
		ponteiro = (ptr+i);        // O ponteiro recebe o endereço alphabet[0]+contador;
		printf("%c", *ponteiro);
		i++;
	}	printf("\n");
}

void* faz_alfabeto_M1(char* alphabet){
	for(int i=0; i<=26; i++){
		alphabet[i] = (char)(65+i);
	}
}

char* faz_alfabeto_M2(void){
	static char alphabet[27];
	for(int i=0; i<=26-1; i++){
		alphabet[i]  = (char)(65+i);
	}	alphabet[26] = '\0';
	return alphabet; // = return alphabet[0];
}

int main(void){	
	//Brincando de criar a string de um modo mais legal;
	char alphabet[27];
	int ascii=97;
	for(int i=0; i<=26-1; i++){
		alphabet[i]= (char)(i+ascii);
	}	alphabet[26]='\0';

	// O tamanho de um char é 1byte;
	//printf("%d ", &alphabet[0]);
	//printf("%d ", &alphabet[1]);
	printf_alfabeto_m(alphabet);
//-------------------------------------------------------
	char alphabet_2[27];
	faz_alfabeto_M1(alphabet_2);
	for(int i=0; i<=26-1; i++){
		printf("%c", alphabet_2[i]);
	}	printf("\n");
//-------------------------------------------------------
	char* ptr = faz_alfabeto_M2();
	for(int i=0; i<=26-1; i++){
		printf("%c", *(ptr+i));
	}	printf("\n");		


	return 0;
}