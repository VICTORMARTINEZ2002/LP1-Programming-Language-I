#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 15

void busca_elemento(int* ptr_vet, int tam, int elem){
	int flag=0;
	for(int i=0; i<=tam-1; i++){
		if(ptr_vet[i]==elem){
			if(flag==0){printf("Elemento encontrado na position (1 -> tam): ");}
			printf("%d, ", i+1);
			flag=1;
		}
	}
	if(!flag){printf("Element not found!");}
}

int main(void){
	srand(time(NULL));

	int vet[MAX_SIZE];
	for(int i=0; i<=MAX_SIZE-1; i++){
		vet[i]=1+(rand()%20);
	}

	printf("->   IMPRIMINDO O VETOR:\n");
	printf("Position:  ");
	for(int i=0; i<=MAX_SIZE-1; i++){
		if(i<9){printf("%d   ", i+1);}else{printf("%d  ", i+1);}
	}	printf("\n");
	printf("Element:   ");
	for(int i=0; i<=MAX_SIZE-1; i++){
		if(vet[i]< 10 && vet[i+1]< 10){printf("%d   ", vet[i]);}else{
		if(vet[i]< 10 && vet[i+1]>=10){printf("%d   ", vet[i]);}else{
		if(vet[i]>=10 && vet[i+1] <10) {printf("%d  ", vet[i]);}else{
		if(vet[i]>=10 && vet[i+1]>=10) {printf("%d  ", vet[i]);}}}}
	}	printf("\n");	

	busca_elemento(vet, MAX_SIZE, 13);
	return 0;
}