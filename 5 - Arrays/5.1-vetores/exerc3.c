#include <stdio.h>

int main(void){
	int pos = 3;
	int vetor[10]={1,2,3,4,5,6,7,8,9,10};
	int tam = sizeof(vetor)/sizeof(int);

	// Imprimindo o vetor:
	printf("vetor   = {");
    for(int i=0; i<=tam-1; i++){
        if(i==tam-1){printf("%d}\n",vetor[i]);}else
        printf(" %d, ", vetor[i]);
    } 

//Fazer função que retorna vetor precisa de ponteiro (e a void deu ruim), então vamo deixar assim:

// -- ALTERNATIVA 01 -------------------------------------------------------------------------------------
		int aux=0;

		for(int i=0; i<=pos-1; i++){ //pos-1
			for(int j=0;j<=(tam-1)-1;j++){//tam
				aux=vetor[j];
				vetor[j]  = vetor[j+1];
				vetor[j+1]= aux;
				// for(int i=0; i<=tam-1; i++){
			    //     if(i==tam-1){printf("%d}\n",vetor[i]);}else
			    //     printf(" %d, ", vetor[i]);
			    // } 
			}printf("\n");
		}
//--------------------------------------------------------------------------------------------------------

// -- ALTERNATIVA 02 vet_aux------------------------------------------------------------------------------

    // int vet_aux[pos-1];
    // for(int i=0; i<=pos-1; i++){
    // 	vet_aux[i]=vetor[i];
    // }

    // for(int i=0; i<=tam-pos-1; i++){vetor[i]=vetor[pos+i];}
   	// int j=0;
    // for(int i=tam-pos; i<=tam-1; i++){
    // 	vetor[i]=vet_aux[j];
    // 	j++;
    // }	
//----------------------------------------------------------------------------------------------------------



    //Imprimindo o resultado:
    int i=0;
    printf("vetor   = {");
    for(int i=0; i<=tam-1; i++){
        if(i==tam-1){printf("%d}\n",vetor[i]);}else
        printf(" %d, ", vetor[i]);
    }  
	return 0;
}