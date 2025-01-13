#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int vet[10000000];
//Funções para criar o vetor
int fatorial(int n){
    if(n<1){return 1;}
    return n*fatorial(n-1);
}
  
void swap(char* x, char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
void permute(char* a, int l, int r){
    static int cont=0;
    if(l==r){
        vet[cont]=atoi(a);
        cont++;               
        return;       
    }else{
        for(int i=l; i<=r; i++){
            swap((a + l), (a + i)); // Permutar o elemento e Fixa-lo
            permute(a, l + 1, r);
            swap((a + l), (a + i)); // backtrack
        }
    }}

//Funções para criar a matriz
double sequencia(int n){
    int cont=1;
    double seq=0;
    while(cont<=n){ 
        seq+=cont*(pow(10,n-cont));
        cont++;
    }
    return seq;
}

double resto(int divd, int divs){
    if(divs==0){return -1;}
    if(divd<divs){return divd;} 
    return resto(divd-divs, divs);
}

int qts_digitos(int num){  
    int cont=0;
    while ((num/10)>=1){
        num=num/10;
        cont+=1;
    }
    cont+=1;
    return cont;
}

int digt(int n, int num){
    char arr[qts_digitos(num)];
    itoa(num,arr,10);
    //transformar de ascii pra num;
    for(int i=0; i<=9; i++){
        if(i+48==(int)arr[n]){return i;}
    }
}  

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

// mat[0][0]=-1;
// mat[0][1]=5;
// mat[0][2]=12;    
// mat[0][3]=3;
// mat[0][4]=11;
// mat[1][0]=5;
// mat[1][1]=-1;
// mat[1][2]=12;
// mat[1][3]=20;
// mat[1][4]=6;
// mat[2][0]=12;
// mat[2][1]=12;
// mat[2][2]=-1;   
// mat[2][3]=17;
// mat[2][4]=12;
// mat[3][0]=3;
// mat[3][1]=20;
// mat[3][2]=17;   
// mat[3][3]=-1;
// mat[3][4]=20;
// mat[4][0]=11;
// mat[4][1]=6;
// mat[4][2]=12;   
// mat[4][3]=20;
// mat[4][4]=-1;


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

//Preparação - parte 1:
    //Criando o vetor com as permutações:
    char str[size]; 
    itoa((int)sequencia(size-1),str,10);
    //printf("String: %s\n",str);
    int n = sizeof(str)/sizeof(char)-1;
    permute(str, 0, n - 1);

    // printf("vetor={");
    // for(int i=0; i<=fatorial(n)-1; i++){
    //     if(i==fatorial(n)-1){printf("%d}\n\n",vet[i]);}
    //     else{printf("%d, ",vet[i]);}
    // }

    //Criando a matriz com as permutações
    int temp;
    int mat_digt[fatorial(n)][n];
    for(int i=0; i<=fatorial(n)-1; i++){
        for(int j=0; j<=n-1;j++){
            for(int k=0; k<=n-1; k++){
                if(j%n==k){
                    mat_digt[i][j]=digt(k,vet[i]);
                }
            }
        }
    }
    // for(int i=0; i<=fatorial(n)-1; i++){
    //     for(int j=0; j<=n-1;j++){
    //         printf("%d ",mat_digt[i][j]);
    //     }printf("\n");    
    // }   

//Luzes, camera e ação
    int cam[casas];
    int dist;
    int menor_dist=999;
    int menor_poss=-1;
    //int stop;
    for(int k=0; k<=fatorial(n)-1; k++){
        for(int l=0; l<=casas-1; l++){cam[l]=mat_digt[k][l];} 
        dist=0;
        //stop=0;
        for(int i=0; i<=casas; i++){
            //if(stop!=1){ 
                for(int j=0; j<=casas-1; j++){
                    dist+=mat[i][cam[j]];
                    i=cam[j];
                    if(j>=casas-1){
                        dist+=mat[0][cam[j]];
                        i=casas+1;
                    } 
                }
            }
            if(dist<menor_dist){
                menor_dist=dist;
                menor_poss=k;
       
            }

        }
// printf("d= %d\n", menor_dist); 
// printf("p= %d\n\n", menor_poss);         

printf("Compilacao Concluida!\n");
printf("Melhor rota: \n");
printf("\tPizzaria->");
for(int i=0; i<=casas-1; i++){
    printf(" casa %d->",mat_digt[menor_poss][i]);
}
printf(" pizzaria.\n");

printf("Distancia: %d.\n", menor_dist);
return 0;
}       