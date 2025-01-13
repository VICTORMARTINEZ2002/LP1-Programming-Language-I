#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){
    srand(time(NULL));     
    int casas=0;
    printf("Insira em quantas casas devemos entregar PIZZA!: ");
    scanf("%d", &casas);
    printf("Total de entregas: %d\n", casas);
    int size=casas+1;

//Criando a matriz das distancias:

    int mat[size][size];
    for(int i=0; i<=size-1; i++){
        for(int j=0; j<=size-1; j++){
            if(j>i){mat[i][j]=1+rand()%15;}
            if(i<j){mat[j][i]=mat[i][j];}
            if(i==j){mat[i][j]=-1;}
        }
    }

//Imprimindo a matriz das distancias;
    printf("matriz das distancias = {");
    for(int i=0; i<=size-1; i++){
        if(i==0){printf("{");}
        else{printf("                        {");}
        for(int j=0; j<=size-1; j++){
            if(mat[i][j]<10 &&mat[i][j]!=-1){
                if(i<size-1){
                    if(j==size-1){printf(" %d},\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}
                }else{
                    if(j==size-1){printf(" %d}};\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}}
            }else{
                if(i<size-1){
                    if(j==size-1){printf("%d},\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}
                }else{
                    if(j==size-1){printf("%d}};\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}}
            }
        }
    }    
    printf("\n");

//Calculo caminho de 1 vetor 
    int cam[]={2,1,3,4};
    int dist=0;
    int contd=0;
    int stop=0;
    for(int i=0; i<=casas; i++){
        if(stop!=1){ 
            for(int j=0; j<=casas-1; j++){
                contd++;
                dist+=mat[i][cam[j]];
                i=cam[j];
                printf(" %d",dist);
                if(j>=casas-1){
                    dist+=mat[0][cam[j]];
                    stop=1;
                    printf(" %d",dist);
                } 
            }
        }    
    }
    printf(" %d", dist);

        

return 0;}        