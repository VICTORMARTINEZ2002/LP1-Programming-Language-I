#include <stdio.h>
#include <string.h>

int strlen_vet(char str[]){
    int cont=0,i=0;
    while(str[i]!='\0'){
        cont++;
        i++;
    }
    return cont-1;    
}

int palindr(char str[]){
    int tam = strlen_vet(str);
    int flag=1;
    for(int i=0; i<=(int)((tam-1)/2); i++){
        if(str[i]!=str[tam-1-i]){flag=0;}
    }
    return flag;
}

//Desafio, armazenar essas palavras num vetor;
int qtd_palav(char str[]){
    int tam=strlen(str); //tamanho da string que inclui o <enter> ou '\0'
    // printf("Tamanho da string com o '\\0': %d\n", tam);

    // printf("String inserida: \n");
    // for(int i=0; i<=(tam-1)-1; i++){ //imprimindo todo mundo menos o '\0'
    //     printf("%c", str[i]);
    // }   printf("\\n", str[tam-1]);
    // printf("\n");

    int cont=0;
    if(tam<=1){return cont;}
    if(str[0]==' '){
        printf("INICIA COM ESPAÇO: \n");
        for(int i=0; i<=tam-1; i++){
            if(str[i]==' ' && str[i+1]!=' ' && (i+1)!=tam-1){cont++;}
        }
    }else{
        printf("INICIA COM LETRA: \n");
        if(str[(tam-1)-1]==' '){
            for(int i=0; i<=tam-1; i++){
                if(str[i]!=' ' && str[i+1]==' '){cont++;}
            }
        }else{
            for(int i=0; i<=tam-1; i++){
                if(str[i]!=' ' && (str[i+1]==' ' || str[i+1]=='\0')){cont++;}
            }
        }
    }
    return cont;
}    


void cript(char str[],int size, int pos){
    char alfb[27]       ="abcdefghijklmnopqrstuvwxyz"; //inclui o '\0'
    char alfb_crip[27]  ="abcdefghijklmnopqrstuvwxyz";
    char alfb_M[27]     ="ABCDEFGHIJQLMNOPQRSTUVWXYZ"; 
    char alfb_crip_M[27]="ABCDEFGHIJQLMNOPQRSTUVWXYZ";    
    //usar a função strdup tb séria uma possibilidade, enfim...

    //Rotacinar a string para obter o alfabeto codificado:
    int aux=0;
    for(int i=0; i<=pos-1; i++){
        for(int j=0;j<=(26-1)-1;j++){
            aux=alfb_crip[j];
            alfb_crip[j]  = alfb_crip[j+1];
            alfb_crip[j+1]= aux;

            aux=alfb_crip_M[j];
            alfb_crip_M[j]  = alfb_crip_M[j+1];
            alfb_crip_M[j+1]= aux;
        };
    }// (Provavelmente dava pra fazer usando a tabela ascii e incrementos);

    //Imprimindo os alfabetos:
    // for(int i=0; i<=26; i++){
    //     printf("%c, ", alfb[i]);
    // }printf("\n");
    // for(int i=0; i<=26; i++){
    //     printf("%c, ", alfb_crip[i]);
    // }printf("\n");
    // for(int i=0; i<=26; i++){
    //     printf("%c, ", alfb_M[i]);
    // }printf("\n");
    // for(int i=0; i<=26; i++){
    //     printf("%c, ", alfb_crip_M[i]);
    // }printf("\n");    


    // //Caso eu quissese imprimir a tabela de Cesar:
    // static int pos_original=pos;
    // if(pos<=25+pos_original){cript(str,size,pos+1);}

    char str_crpt[size];
    for(int i=0; i<=size-1; i++){str_crpt[i]='\0';}

    //Preenchendo a string criptografada com seus valores correspondentes
    int i=0;
    int flag=0;
    while((int)str[i]!=0){
        flag=0;
        for(int j=0; j<=26-1; j++){
            //minusculas
            if(str[i]==alfb[j]){
                str_crpt[i]=alfb_crip[j];
                printf("%c",str[i]);
                flag=1;
            }
            //maiusculas
            if(str[i]==alfb_M[j]){
                str_crpt[i]=alfb_crip_M[j];
                printf("%c",str[i]);
                flag=1;
            }
        }
        //caso seja um caractere especial, não faremos alterações (espaços, numeros, etc)
        if(flag==0 && (int)str[i]>=32){
            str_crpt[i]=str[i];
            printf("%c",str[i]);
        }
        i++;
    }printf("\\0\n");

    //Imprimindo a string codificada
    i=0;
    while((int)str_crpt[i]!=0){
        //printf("%c", str[i]);
        printf("%c", str_crpt[i]);
        i++;
    }printf("\\0\n");
}

void descript(char str[],int size, int pos){
    char alfb[27]       ="abcdefghijklmnopqrstuvwxyz"; //inclui o '\0'
    char alfb_crip[27]  ="abcdefghijklmnopqrstuvwxyz";
    char alfb_M[27]     ="ABCDEFGHIJQLMNOPQRSTUVWXYZ"; 
    char alfb_crip_M[27]="ABCDEFGHIJQLMNOPQRSTUVWXYZ";

    //Rotacinar a string para obter o alfabeto codificado:
    int aux=0;
    for(int i=0; i<=pos-1; i++){
        for(int j=0;j<=(26-1)-1;j++){
            aux=alfb_crip[j];
            alfb_crip[j]  = alfb_crip[j+1];
            alfb_crip[j+1]= aux;

            aux=alfb_crip_M[j];
            alfb_crip_M[j]  = alfb_crip_M[j+1];
            alfb_crip_M[j+1]= aux;
        };
    }

    //Imprimindo os alfabetos:
    // for(int i=0; i<=26; i++){
    //     printf("%c, ", alfb[i]);
    // }printf("\n");
    // for(int i=0; i<=26; i++){
    //     printf("%c, ", alfb_crip[i]);
    // }printf("\n");
    // for(int i=0; i<=26; i++){
    //     printf("%c, ", alfb_M[i]);
    // }printf("\n");
    // for(int i=0; i<=26; i++){
    //     printf("%c, ", alfb_crip_M[i]);
    // }printf("\n");   

    char str_crpt[size];
    for(int i=0; i<=size-1; i++){str_crpt[i]='\0';}

    //Preenchendo a string criptografada com seus valores correspondentes
    int i=0;
    int flag=0;
    while((int)str[i]!=0){
        flag=0;         
        for(int j=0; j<=26-1; j++){
            //minusculas
            if(str[i]==alfb_crip[j]){
                str_crpt[i]=alfb[j];
                printf("%c",str[i]);
                flag=1;
            }
            //maiusculas
            if(str[i]==alfb_crip_M[j]){
                str_crpt[i]=alfb_M[j];
                printf("%c",str[i]);
                flag=1;
            }
        }
        //caso seja um caractere especial, não faremos alterações
        if(flag==0 && (int)str[i]>=32){
            str_crpt[i]=str[i];
            printf("%c",str[i]);
        }
        i++;
    }printf("\\0\n");

    //Imprimindo a string descodificada;
    i=0;
    while((int)str_crpt[i]!=0){
        //printf("%c", str[i]);
        printf("%c", str_crpt[i]);
        i++;
    }printf("\\0\n");
}


int main(void){
    int size=80;
    char str1[size], str2[size];
    // do{
    //     printf("Escreva alguma coisa: ");
    //     fgets(str1, sizeof(str1), stdin);
    //     //printf("Tamanho da string(meu-in) : %d\n", strlen_vet(str1));
    //     //printf("Tamanho da string(real):    %d\n", strlen(str1)-1);      //não considerar o <enter>
    //     printf("Palavras: %d\n\n", qtd_palav(str1));
    // }while(str1[0]!='0');
    printf("Escreva alguma coisa para ser codificado: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Escreva alguma coisa para ser traduzido:  ");
    fgets(str2, sizeof(str2), stdin);    
    cript(str1,size,8);
    descript(str2, size, 8);
    return 0;
}