#include <stdio.h>
#include <malloc.h>

void addNum(int* vet, int num){
	static int index=0;
	vet = (int*)realloc(vet, (index+1)*sizeof(int));
	vet[index]=num;
	index++;
}

int main(void){
	int* vetNum = NULL;
	vetNum = malloc(0*sizeof(int)); // Para usar realloc, eu precisa criar o vetor com malloc;
	int cont=0;
	int num =0;

	while(1){
		printf("Insira numero %d: ", cont+1);
		scanf("%d", &num);
		if(num==0){break;}
		cont++;
		addNum(vetNum, num);
	}

 	//imprime vetor;
 	printf("Vetor = {");
	for(int i=0; i<=cont-1; i++){
		printf("%d, ", vetNum[i]);
	}	printf("}\n");

	return 0;
}