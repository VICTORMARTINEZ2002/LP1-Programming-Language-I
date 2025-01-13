#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int vet[10000];

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
  
int main(){
    char str[] = "123";
    int n = sizeof(str)/sizeof(char)-1;
    printf("%d\n\n\n",n);
    permute(str, 0, n - 1);

    printf("vetor={");
    for(int i=0; i<=fatorial(n)-1; i++){
        if(i==fatorial(n)-1){printf("%d}\n\n",vet[i]);}
        else{printf("%d, ",vet[i]);}
    }

    //matriz
    int temp;
    int size=fatorial(n);
    int mat_digt[size][n];
    for(int i=0; i<=size-1; i++){
        for(int j=0; j<=n-1;j++){
            for(int k=0; k<=n-1; k++){
                if(j%n==k){
                    mat_digt[i][j]=digt(k,vet[i]);
                }
            }
        }
    }
    for(int i=0; i<=size-1; i++){
        for(int j=0; j<=n-1;j++){
            printf("%d ",mat_digt[i][j]);
        }printf("\n");    
    }    

    return 0;
}