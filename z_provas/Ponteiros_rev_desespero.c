//EXERCÍCIO 1:
	// #include <stdio.h>

	// void troca(int *x, int *y){
	// 	int aux=*y;
	// 	*y=*x;
	// 	*x=aux;
	// }

	// int main(void){
	// 	int n1=3,n2=23;
	// 	int *ptr_n1=NULL, *ptr_n2=NULL;
	// 	ptr_n1=&n1;
	// 	ptr_n2=&n2;
	// 	printf("n1: %d\n", n1);
	// 	printf("n2: %d\n", n2);	
	// 	troca(ptr_n1, ptr_n2);
	// 	printf("n1: %d\n", n1);
	// 	printf("n2: %d\n", n2);	
	// 	printf("n1: %d\n", *ptr_n1);
	// 	printf("n2: %d\n", *ptr_n2);			
	// 	return 0;
	// }

//EXERCÍCIO 2:
	// #include <stdio.h>

	// //Dá pra fazer usando a tabela ascii, mas vamo com string;
	// int main(void){
	// 	char alfb[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// 	int index=0;
	// 	int *ptr_index=NULL;
	// 	ptr_index=&index;

	// 	while(*ptr_index<=25){ //25 pra não incluir o '\0';
	// 		printf("%c_", alfb[*ptr_index]);
	// 		(*ptr_index)++;
	// 	}
	// 	return 0;
	// }

//EXRCÍCIO 3.1:
	// #include <stdio.h>
	// #include <stdlib.h>
	// #include <time.h>
	// #define MAX_SIZE 5

	// int main(void){
	// 	srand(time(NULL));
	// 	int vet[MAX_SIZE];
	// 	int soma=0;
	// 	printf("Vetor = {");

	// 	for(int i=0; i<=MAX_SIZE-1; i++){
	// 		vet[i]=(rand()%20)+1;
	// 		soma+=vet[i];
	// 		printf("%d, ", vet[i]);
	// 	}   printf("}\n");

	// 	printf("Soma: %d", soma);

	// }

//EXRCÍCIO 3.2:
	// #include <stdio.h>
	// #include <stdlib.h>
	// #include <time.h>
	// #define MAX_SIZE 5

	// int main(void){
	// 	srand(time(NULL));
	// 	int vet[MAX_SIZE];
	// 	int soma=0;
	// 	int *ptr_soma=NULL;
	// 	ptr_soma=&soma;
	// 	int *ptr_vet =NULL;


	// 	printf("Vetor = {");
	// 	for(int i=0; i<=MAX_SIZE-1; i++){
	// 		vet[i]=(rand()%20)+1;
	// 		ptr_vet= &(vet[i]);
	// 		*ptr_soma += *ptr_vet;
	// 		printf("%d, ", *ptr_vet);
	// 	}   printf("}\n");

	// 	printf("Soma: %d", *ptr_soma);

	// }

//EXERCÍCIO 4
	// #include <stdio.h>
	// #define MAX_SIZE 20

	// void add_contato(int *agenda, int *num, int pos){
	// 	agenda[pos]=*num;
	// }

	// void print_contato(int *agenda, int pos){
	// 	printf("Contato %d: %d\n", pos+1, *(agenda+pos));
	// }

	// int main(void){
	// 	int qtd=0;
	// 	printf("Insira a qtd de pessoas: ");
	// 	scanf("%d", &qtd);
	// 	printf("Qtd: %d\n\n", qtd);

	// 	int agenda[qtd];

	// 	int num=0;
	// 	int *ptr_num=NULL;
	// 	ptr_num=&num;
	// 	for(int i=0; i<=qtd-1; i++){		
	// 		printf("Insira o numero do contato %d: ", i+1);
	// 		scanf("%d", &num);
	// 		printf("Num Inserido: %d\n", num);
	// 		add_contato(agenda, ptr_num, i);
	// 	}	printf("\n");

	// 	for(int i=0; i<=qtd-1; i++){		
	// 		print_contato(agenda, i);
	// 	}

	// 	return 0;
	// }

//EXERCÍCIO 5:
#include <stdio.h>
#include <malloc.h>

void add_contato(int *agenda, int *num, int pos){
	agenda[pos]=*num;
}

void print_contato(int *agenda, int pos){
	printf("Contato %d: %d\n", pos+1, *(agenda+pos));
}

int main(void){
	int qtd=0;
	printf("Insira a qtd de pessoas: ");
	scanf("%d", &qtd);
	printf("Qtd: %d\n\n", qtd);

	int *agenda;
	agenda = (int*)malloc(qtd*sizeof(int));

	int num=0;
	int *ptr_num;
	ptr_num=&num;
	for(int i=0; i<=qtd-1; i++){		
		printf("Insira o numero do contato %d: ", i+1);
		scanf("%d", &num);
		printf("Num Inserido: %d\n", num);
		add_contato(agenda, ptr_num, i);
	}	printf("\n");

	for(int i=0; i<=qtd-1; i++){		
		print_contato(agenda, i);
	}	printf("\n-> Realocando: ");

	int qtd2=0;
	printf("Insira a qtd de pessoas extras: ");
	scanf("%d", &qtd2);
	printf("Qtd2: %d\n\n", qtd2);

	int qtdn=qtd+qtd2;
	agenda = (int*)realloc(agenda, qtdn*sizeof(int));

	for(int i=qtd; i<=qtdn-1; i++){		
		printf("Insira o numero do contato %d: ", i+1);
		scanf("%d", &num);
		printf("Num Inserido: %d\n", num);
		add_contato(agenda, ptr_num, i);
	}	printf("\n");

	for(int i=0; i<=qtdn-1; i++){		
		print_contato(agenda, i);
	}

	return 0;
}

















