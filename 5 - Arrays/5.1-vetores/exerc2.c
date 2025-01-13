#include <stdio.h>



int main(void){
	int vetor[10]={3, 3, 8, 14, 2, 1, 3, 57, 99, 0};
	int tamn = sizeof(vetor)/sizeof(int);

	printf("vetor   = {");
    for(int i=0; i<=tamn-1; i++){
        if(i==tamn-1){printf("%d}\n",vetor[i]);}else{
        printf(" %d, ", vetor[i]);}
    }	

	for(int i=0; i<=tamn-1; i++){
		for(int j=0; j<=tamn-1; j++){ //No geral, podemos alterar se queremos o vetor crescente ou decrescente iniciando j=i;
			if(vetor[i]>vetor[j]){    // e/ou alterando o sinal < ou > ; 	
				int aux=vetor[j];
				vetor[j]=vetor[i];
				vetor[i]=aux;

			    printf("vetor   = {");
			    for(int i=0; i<=tamn-1; i++){
			        if(i==tamn-1){printf("%d}\n",vetor[i]);}else{
			        printf(" %d, ", vetor[i]);}
			    }	
			}
		}
		printf("Fim for;\n");
	}

    printf("vetor   = {");
    for(int i=0; i<=tamn-1; i++){
        if(i==tamn-1){
        	printf("%d}\n",vetor[i]);
        }else{
        printf(" %d, ", vetor[i]);
    	}
    }
 

	return 0;
}