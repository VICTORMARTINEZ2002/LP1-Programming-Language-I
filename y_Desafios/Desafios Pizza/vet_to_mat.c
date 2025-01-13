#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	int n=3;
	int size=6;
	int temp;
	int vet[6]={123,132,213,231,312,321};
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
}