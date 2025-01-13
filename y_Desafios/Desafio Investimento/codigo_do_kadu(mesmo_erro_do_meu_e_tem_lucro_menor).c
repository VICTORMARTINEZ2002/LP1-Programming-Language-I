#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    printf("Insira o dinheiro e a qtd de ações: ");

    srand(time(NULL));

    int X=100, n=7, aux=0, cont = 0;
    int totall = 0;

    //scanf("%d", &X);
    //scanf("%d", &n);

    int retorno[n];
    int custo[n];
    int indice[n];

    retorno[0]=48;
    retorno[1]=16;
    retorno[2]=44;
    retorno[3]=37;
    retorno[4]=7;
    retorno[5]=5;
    retorno[6]=10;
    custo[0]=12;
    custo[1]=4;
    custo[2]=11;
    custo[3]=19;
    custo[4]=4;
    custo[5]=3;
    custo[6]=6;

    for (int i = 0; i < n; i++){
        //retorno[i] = 1+(rand()%10);
        //custo[i]   = 1+(rand()%15);
        indice[i]  = i;
        printf("%d %d\n", retorno[i], custo[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(retorno[i] < retorno[j]){
                aux = retorno[i];
                retorno[i] = retorno[j];
                retorno[j] = aux;

                aux = indice[i];
                indice[i] = indice[j];
                indice[j] = aux;
            }
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d\t%d\n", retorno[i], indice[i]);
    }

    for (int i = 0; i < n; i++){
        if (X < custo[indice[i]]){
            continue;
        }

        if (retorno[i] < custo[i]){
            continue;
        }

        totall += retorno[indice[i]];
        X -= custo[indice[i]];

        printf("Lucro:%d\nSobrou:%d\n %d\n", totall, X, indice[i]);

    }

    return 0;
}