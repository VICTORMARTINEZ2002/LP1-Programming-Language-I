#include <stdio.h>

int sub_conj(int subc[], int conj[], int size_subc, int size_conj){
    int flag=0;
    for(int i=0; i<=size_subc-1; i++){
        flag=0;
        for(int j=0; j<=size_conj-1; j++){
            if(subc[i]==conj[j]){flag=1;}
        }
        if(flag==0){return 0;}
    }
    return 1; 
}

int sub_conj_exato(int subc[], int conj[], int size_subc, int size_conj){
    for(int i=0; i<=size_conj-1; i++){ 
        if(conj[i]==subc[0]){
            int cont=0;
            while(subc[cont]==conj[i+cont]){
                cont++;
                if(cont>=size_subc){
                    return 1;
                }
            }
        }    
    }
    return 0;
}

int main(void){
    int conj[10]={1,2,3,4,5,6,7,8,9,10};
    int subc[3]={9,10,1};
    int size_cj=sizeof(conj)/sizeof(int);
    int size_sc=sizeof(subc)/sizeof(int);
    printf("size conj = %d\n", size_cj);
    printf("size subc = %d\n", size_sc);    

    if(sub_conj(subc,conj,size_sc,size_cj)){printf("Eh subconjunto!\n");}
    else{printf("Nao eh subconjunto.\n");}    

    printf("Sub conjunto exato: %d", sub_conj_exato(subc, conj, size_sc, size_cj));
    return 0;
}