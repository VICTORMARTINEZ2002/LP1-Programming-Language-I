#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));

    int row=0,col=0;
    int l,c,mv;
    int aux;    
    printf("Insira tamanho da matriz: ");
    scanf("%d %d", &row, &col);
    printf("Matriz %dx%d\n", row, col);
    int mat[row][col];

    printf("Ordenar Linhas?  (1/0) ");
    scanf("%d",&l);
    printf("Ordenar Colunas? (1/0) ");
    scanf("%d",&c);
    printf("Ordenar Vetor?   (1/0) ");
    scanf("%d",&mv);


//Imprimir matriz original;    
    printf("Matriz original = {\n");
    for(int i=0; i<=row-1; i++){
        printf("\t{");
        for(int j=0; j<=col-1; j++){
            mat[i][j]=rand()%100;
            if(mat[i][j]<10){
                if(i<row-1){
                    if(j==col-1){printf(" %d},\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}
                }else{
                    if(j==col-1){printf(" %d}};\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}}
            }else{
                if(i<row-1){
                    if(j==col-1){printf("%d},\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}
                }else{
                    if(j==col-1){printf("%d}};\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}}
            }
        }
    }


//Ordenar as linhas da matriz;
    if(l){     
        for(int i=0; i<=row-1; i++){ 
            for(int j=0; j<=col-1; j++){
                for(int k=j; k<=col-1; k++){
                    if(mat[i][j]>mat[i][k]){
                        aux=mat[i][j];
                        mat[i][j]=mat[i][k];
                        mat[i][k]=aux;
        }}}}
    
        printf("Matriz ordena linhas= {\n");
        for(int i=0; i<=row-1; i++){
            printf("\t{");
            for(int j=0; j<=col-1; j++){
                if(mat[i][j]<10){
                    if(i<row-1){
                        if(j==col-1){printf(" %d},\n", mat[i][j]);}
                        else{printf(" %d, ",mat[i][j]);}
                    }else{
                        if(j==col-1){printf(" %d}};\n", mat[i][j]);}
                        else{printf(" %d, ",mat[i][j]);}}
                }else{
                    if(i<row-1){
                        if(j==col-1){printf("%d},\n", mat[i][j]);}
                        else{printf("%d, ",mat[i][j]);}
                    }else{
                        if(j==col-1){printf("%d}};\n", mat[i][j]);}
                        else{printf("%d, ",mat[i][j]);}}
    }}}
}            

//Ordenar as colunas da matriz;
if(c){         
    for(int j=0; j<=col-1; j++){ 
        for(int i=0; i<=row-1; i++){
            for(int k=i; k<=row-1; k++){
                if(mat[i][j]>mat[k][j]){
                    aux=mat[i][j];
                    mat[i][j]=mat[k][j];
                    mat[k][j]=aux;
    }}}}

    printf("Matriz ordena colunas= {\n");
    for(int i=0; i<=row-1; i++){
        printf("\t{");
        for(int j=0; j<=col-1; j++){
            if(mat[i][j]<10){
                if(i<row-1){
                    if(j==col-1){printf(" %d},\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}
                }else{
                    if(j==col-1){printf(" %d}};\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}}
            }else{
                if(i<row-1){
                    if(j==col-1){printf("%d},\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}
                }else{
                    if(j==col-1){printf("%d}};\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}}
}}}}

//Matriz para vetor equivalente;
if(mv){
    int mat_vetor[row*col];
    int k=0,i=0,j=0;
    while(k<=(row*col)-1){
        mat_vetor[k]=mat[i][j];
        k++;
        j++;
        if(j>=col){i++;j=0;}
    }


    printf("Matriz vetor equivalente:\n\t{");
    for(int k=0; k<=(row*col)-1; k++){
        if(k<(row*col)-1){printf("%d, ",mat_vetor[k]);}
        else{printf("%d}\n",mat_vetor[k]);}
    }    

//Matriz para vetor equivalente ordenado;
    for(int i=0; i<=(row*col)-1; i++){
        for(int j=i; j<=(row*col)-1; j++){
            if(mat_vetor[i]>mat_vetor[j]){
                aux=mat_vetor[i];
                mat_vetor[i]=mat_vetor[j];
                mat_vetor[j]=aux;
            }
        }
    }
    printf("Matriz vetor ordenado equivalente:\n\t{");
    for(int k=0; k<=(row*col)-1; k++){
        if(k<(row*col)-1){printf("%d, ",mat_vetor[k]);}
        else{printf("%d}\n\n",mat_vetor[k]);}
    }    

//Matriz para Matriz Ordenada;
    k=0;i=0;j=0;    
    while(k<=(row*col)-1){
        mat[i][j]=mat_vetor[k];
        k++;
        j++;
        if(j>=col){i++;j=0;}
    }
    printf("Matriz ordena colunas= {\n");
    for(int i=0; i<=row-1; i++){
        printf("\t{");
        for(int j=0; j<=col-1; j++){
            if(mat[i][j]<10){
                if(i<row-1){
                    if(j==col-1){printf(" %d},\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}
                }else{
                    if(j==col-1){printf(" %d}};\n", mat[i][j]);}
                    else{printf(" %d, ",mat[i][j]);}}
            }else{
                if(i<row-1){
                    if(j==col-1){printf("%d},\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}
                }else{
                    if(j==col-1){printf("%d}};\n", mat[i][j]);}
                    else{printf("%d, ",mat[i][j]);}}
}}}}

    return 0;
}            