#include <stdio.h>

//Passar um vetor como parametro passa apenas o endereço do 1 termo e nesse ponto o tamanho eh perdido;
int pertence(int n, int vet[], int size){

    for(int i=0; i<=size-1; i++){
        if(n==vet[i]){return 1;}
    }return 0;
}

int main(void){
    int num=0;
    printf("Insira o numero de elementos a serem armazenados no array:  ");
    scanf("%d", &num);
    printf("Tamanho do array: %d\n\n", num);

    //Criando vetor e recebendo entradas:
    int vetor[num];

    printf("Insira %d elementos no array: \n", num);  
    int i=0;
    while(i<=(num-1)){
    printf("Elemento %d: ", i);
    scanf("%d", &vetor[i]);
    i++;
    } printf("Vetor Completamente cheio!\n\n");
    i=0;

    //Imprimindo o vetor:
    printf("vetor   = {");
    for(i=0; i<=num-1; i++){
        if(i==num-1){printf("%d}\n",vetor[i]);}else
        printf(" %d, ", vetor[i]);
    }
    i=0;  

    //criando vetor auxiliar e imprimindo-o:
    int vet_aux[num];
    for(i=0; i<=num-1; i++){vet_aux[i]=-1;}

    printf("vet_aux = {");
    for(i=0; i<=num-1; i++){
        if(i==num-1){printf(" %d}\n",vet_aux[i]);}else
        printf(" %d,", vet_aux[i]);
    }
    i=0;     

    //checarem de repetidos:
    for(int i=0; i<=num-1; i++){
        for(int j=0; j<=num-1; j++){
            if(vetor[i]==vetor[j] && i!=j && !(pertence(vetor[i],vet_aux, sizeof(vet_aux)/sizeof(int)))){
                vet_aux[i]=vetor[i];
            }
        }
    }

    //re-impressão do vetor aux:
    printf("vet_aux = {");
    for(i=0; i<=num-1; i++){
        if(i==num-1){printf(" %d}\n",vet_aux[i]);}else
        printf(" %d,", vet_aux[i]);
    }
    i=0;    

    //contagem repetidos:
    int cont=0;
    for(int i=0; i<=num-1; i++){
        if(vet_aux[i]!=-1){  
            for(int j=0; j<=num-1; j++){
                if(vet_aux[i]==vetor[j]){
                    printf("%d ",vet_aux[i]);
                    cont++;}
            }
                
        }
    }
    printf("\n");
    printf("Numeros repetidos (orig): %d\n", cont); 

    //fazendo com que o primeiro numero que vai ser repetido não seja contado:
    int nums_rept=0;
    for(int i=0; i<=num-1; i++){
        if(vet_aux[i]!=-1){nums_rept++;}
    }
    cont -= nums_rept;

    printf("Numeros repetidos: %d\n", cont);
    return 0;
}    
    


  
