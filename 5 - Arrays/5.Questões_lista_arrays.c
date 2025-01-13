//4.1:
	#include <stdio.h>

	int main(void){
		int vetor[10];
		double soma=0, media=0;
		for(int i=0; i<=9; i++){
			printf("Insira elemento %d: ", i+1);
			scanf("%d", &vetor[i]);
			soma+=vetor[i];
			media=soma/(i+1);
		}
		printf("%.0lf\n", soma);
		printf("%.3lf\n", media);	
		return 0;
	}

//4.2:
	#include <stdio.h>

	int main(void){
	    int size=0;
	    printf("Insira o numero de elementos a serem armazenados no array: ");
	    scanf("%d", &size);

	    int vetor[size];
	    printf("Insira %d elementos no array:\n", size);
	    for(int i=0; i<=size-1; i++){
	        printf("Elemento - %d: ", i+1);
	        scanf("%d", &vetor[i]);
	    }
	    printf("\n");

	    printf("Os valores armazenados no array sao:\n");
	    for(int i=0; i<=size-1; i++){
	        printf("%d ", vetor[i]);
	    }
	    printf("\n");
	    printf("Os valores armazenados no array ao contrário sao:\n");
	    for(int j=size-1; j>=0; j--){
	        printf("%d ", vetor[j]);
	    }            
	    printf("\n");

	    return 0;
	}

//4.3:
	#include <stdio.h>
	#include <math.h>   //->função pow()
	#include <stdlib.h> //->função abs()

	double raiz_2_newton(double n, double r){
	    if(abs(pow(r,2)-n)<0.001){return r;}
	    else{
	        r = (pow(r,2)+n)/(2*r); 
	        return (raiz_2_newton(n,r));
	    }
	}

	int main(void){
	    double n=0;
	    printf("Insira um num real: ");
	    scanf("%lf", &n);
	    printf("Num: %lf\n", n);

	    printf("%lf", raiz_2_newton(n,1));
	    return 0;
	}

//4.4:
	#include <stdio.h>
	int main(){
	    int a,b,c;
	    int arr[5]={1,2,3,25,7};
	    a = ++arr[1]; 
	    	//a = 3;
	    	//arr[5]={1,3,3,25,7};
	    	printf("%d %d\n",a, arr[1]);
	    b = arr[1]++;
	    	//b = 3;
	    	//arr[5]={1,4,3,25,7};    
	    	printf("%d %d\n",b, arr[1]); 
	    c = arr[a++];
	    	//c=arr[3++]=arr[3]=25;
	    	//a=4
	    	printf("%d\n",c);
	    	printf("%d %d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4]); 

	    printf("\n");   
	    printf("%d--%d--%d",a,b,c);      
    return 0;
    }// -> 4--3--2

//4.5:
	#include <stdio.h> //programa 1
	int main (){
	int d,a=1,b=2;
	d = a++ + ++b;
	printf("%d %d %d", d, a, b);
	}//-> 4 2 3;

	#include <stdio.h> //programa 2
	int main(){ 
		int d,a=1,b=2;
		d = a++ +++b;
		printf("%d %d %d", d, a, b);
	}//-> Erro de compilação;

//4.6:
	//Mesma questão do 4.1;

//4.7:
	//Mesma questão do 4.2;

//4.8:
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h> 

	int main(){
	    int size=0;
	    printf("Insira o tamanho do vetor: ");
	    scanf("%d", &size);
	    printf("Tamanho: %d\n", size);

	//Criando o vetor e já imprimindo ele
	    int vetor[size];
	    srand(time(NULL));
	    printf("vetor original = {");
	    for(int i=0; i<=size-1; i++){
	        vetor[i]=rand()%100;
	        if(i==size-1){printf("%d}", vetor[i]);}
	        else{printf("%d, ", vetor[i]);}
	    }
	    printf("\n");

	//Criando vetor ordenado crescente (metodo bolha, eu acho);
	    //Se eu quisse manter o vetor original intacto, era só criar um novo vetor;
	    int aux=0;
	    for(int i=0; i<=size-1; i++){
	        for(int j=i; j<=size-1; j++){
	            if(vetor[j]<vetor[i]){
	                aux=vetor[j];
	                vetor[j]=vetor[i];
	                vetor[i]=aux;
	            }
	        }    
	    }

	    printf("vetor ordenado = {");
	    for(int i=0; i<=size-1; i++){
	        if(i==size-1){
	            printf("%d}",vetor[i]);
	        }else{
	            printf("%d, ", vetor[i]);
	        }
	    }    
	    printf("\n");

	//criando vetor alternado menor/maior 
	    int vetor_alt[size];   
	    for(int i=0; i<=(size-1); i++){
	        if(i%2==0){vetor_alt[i]=vetor[i/2];}
	        else{vetor_alt[i]=vetor[size-((i+1)/2)];}    

	        // vetor_alt[0]=vetor_ord[0];
	        // vetor_alt[1]=vetor_ord[size-1]; 1/2 -> -1
	        // vetor_alt[2]=vetor_ord[1];
	        // vetor_alt[3]=vetor_ord[size-2]; 3/2 -> -2
	        // vetor_alt[4]=vetor_ord[2];
	        // vetor_alt[5]=vetor_ord[size-3]; 5/2 -> -3             
	    } 
	    printf("vetor alternad = {");
	    for(int i=0; i<=size-1; i++){
	        if(i==size-1){printf("%d}", vetor_alt[i]);}
	        else{printf("%d, ", vetor_alt[i]);}
	    }
	    printf("\n");   


	    return 0;
	}	

//4.9:
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main(void){
	    int size=0;
	    printf("Insira o tamanho do vetor: ");
	    scanf("%d", &size);
	    printf("Tamanho: %d\n", size);

	    int vetor[size];
	    srand(time(NULL));
	    printf("vetor = {");
	    for(int i=0; i<=size-1; i++){
	        vetor[i]=rand()%2;
	        if(i==size-1){printf("%d}", vetor[i]);}
	        else{printf("%d, ", vetor[i]);}
	    }
	    printf("\n");

	    int cont=0;
	    int sub=0;
	    for(int i=0; i<=size-1; i++){
	        if(vetor[i]==0){cont++;}
	        else{cont--;}
	        if(cont==0){sub=i+1;}
	    }

	    printf("Sub-vetor encontrado do indice 0 ao %d", sub);
	    return 0;
	}

//4.10:	
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main(void){
	    srand(time(NULL));

	    int size=0;
	    printf("Insira o tamanho do vetor: ");
	    scanf("%d", &size);
	    printf("Tamanho: %d\n", size);

	//Criando os vetores a serem subtraidos;
	    int vetor1[size];
	    int vetor2[size];
	    printf("vetor 1 = {");
	    for(int i=0; i<=size-1; i++){
	        vetor1[i]=rand()%100;
	        if(i==size-1){printf("%d", vetor1[i]);}
	        else{printf("%d, ", vetor1[i]);}
	    }
	    printf("}\n");
	    printf("vetor 2 = {");
	    for(int i=0; i<=size-1; i++){
	        vetor2[i]=rand()%100;
	        if(i==size-1){printf("%d", vetor2[i]);}
	        else{printf("%d, ", vetor2[i]);}
	    }
	    printf("}\n");

	//criando o vetor subtração e imprimindo ele
	    int vetor_sub[size];
	    for(int i=0; i<=size-1; i++){
	        vetor_sub[i]=vetor1[i]-vetor2[i];
	    }
	    
	    printf("vetor s = {");
	    for(int i=0; i<=size-1; i++){
	        if(i==size-1){printf("%d", vetor_sub[i]);}
	        else{printf("%d, ", vetor_sub[i]);}
	    }
	    printf("}\n");    
	    return 0;
	}	

//4.11: -> Não eh bem o que a questão pediu, mas eu nem entendi direito o que ela quer, então...eh;
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main(void){
	    srand(time(NULL));

	    int size=0;
	    printf("Insira o tamanho do vetor: ");
	    scanf("%d", &size);
	    printf("Tamanho: %d\n", size);

	//criando o vetor e imprimindo-o
	    int vetor[size];
	    printf("vetor original = {");
	    for(int i=0; i<=size-1; i++){
	        vetor[i]=rand()%100;
	        if(i==size-1){printf("%d", vetor[i]);}
	        else{printf("%d, ", vetor[i]);}
	    } printf("}\n");    

	//Ordenando o vetor:
	    int aux=0;
	    for(int i=0; i<=size-1; i++){
	        for(int j=i+1; j<=size-1; j++){
	            if(vetor[i]>vetor[j]){
	                aux     =vetor[j];
	                vetor[j]=vetor[i];
	                vetor[i]=     aux;}}}

	//Imprimindo vetor ordenado:
	    printf("vetor ordenado = {");
	    for(int i=0; i<=size-1; i++){
	        if(i==size-1){printf("%d", vetor[i]);}
	        else{printf("%d, ", vetor[i]);}
	    } printf("}\n");         

	//Imprimindo mediana
	    //eu podia usar a variavel "size", mas eu nem lembrei que ela existia, enfim...
	    int tam=sizeof(vetor)/sizeof(int);
	    float mediana=0;  
	    if(tam%2==0){
	        mediana = (vetor[(tam/2)-1] + vetor[tam/2]);
	        mediana /= 2;
	    }else{
	        mediana = vetor[((tam-1)/2)];
	    }
	    printf("%0.2f", mediana); 
	    return 0;
	}  	

//4.12
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <math.h>

	int main(void){
	    srand(time(NULL));

	    int size=0;
	    printf("Insira o tamanho do vetor: ");
	    scanf("%d", &size);
	    printf("Tamanho: %d\n", size);

	//criando o vetor e imprimindo-o
	    int vetor[size];
	    printf("vetor original = {");
	    for(int i=0; i<=size-1; i++){
	        vetor[i]= (rand()%100)*pow(-1,rand()%2); //Vetor possuir num negativos;
	        if(i==size-1){printf("%d", vetor[i]);}
	        else{printf("%d, ", vetor[i]);}
	    } printf("}\n");

	//Calculo par c/ soma minima, admitindo que os pares não podem contem elementos repetidos;
	    int soma_min=vetor[0]+vetor[1];
	    int el1=vetor[0],el2=vetor[1];
	    for(int i=0; i<=size-1; i++){
	        for(int j=i+1; j<=size-1; j++){   
	            if(vetor[i]+vetor[j]<soma_min){
	                soma_min=vetor[i]+vetor[j];
	                el1=vetor[i];
	                el2=vetor[j];
	            }
	        }          
	    }
		//Se eu quissese que os pares pudessem conter elementos
	    //repetidos, era só fazer: 
	    	// int soma_min=2*vetor[0];
	    	// int el1=vetor[0],el2=vetor[0];
	    	// ...
	    	//for(int j=i; j<=size-1; j++){       

	    printf("Par cuja soma eh minima: (%d,%d)\n", el1, el2);
	    printf("Soma: %d\n", soma_min);

	    return 0;
	}  

//4.12(BONUS): encontre o par cujos elementos tenham a soma mais proxima de uma constante dada;
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <math.h>

	//Calculo modulo da diferença
	double abs_dif(double cte, double valor){
	    if(cte-valor<0){return valor-cte;}
	    return cte-valor;
	}

	int main(void){
	    srand(time(NULL));
	    double cte=0;
	    printf("Insira uma constante: ");
	    scanf("%lf", &cte);
	    printf("Constante: %.2lf\n", cte);

	    int size=0;
	    printf("Insira o tamanho do vetor: ");
	    scanf("%d", &size);
	    printf("Tamanho: %d\n", size);

	//criando o vetor e imprimindo-o
	    int vetor[size];
	    printf("vetor original = {");
	    for(int i=0; i<=size-1; i++){
	        vetor[i]= (rand()%100)*pow(-1,rand()%2); //Vetor possuir num negativos;
	        if(i==size-1){printf("%d", vetor[i]);}
	        else{printf("%d, ", vetor[i]);}
	    } printf("}\n");

	//Calculo par c/ soma mais se aproxima da constante dada, admitindo que os pares não podem contem elementos repetidos;
	    double diff=abs_dif(cte,vetor[0]+vetor[1]);
	    int el1=vetor[0],el2=vetor[1];
	    for(int i=0; i<=size-1; i++){
	        for(int j=i+1; j<=size-1; j++){

	            if(abs_dif(cte,vetor[i]+vetor[j])<diff){
	                diff=abs_dif(cte,vetor[i]+vetor[j]);
	                el1=vetor[i];
	                el2=vetor[j];
	            }
	        }          
	    } 
	    //Se eu quissese que os pares pudessem conter elementos
	    //repetidos, era só fazer: 
	        // int soma=2*vetor[0];
	        // int el1=vetor[0],el2=vetor[0];
	        // ...
	        // for(int j=i; j<=size-1; j++){      

	    printf("Par cuja soma mais se aproxima de %lf: (%d,%d)\n",cte, el1, el2);
	    printf("Diff: %lf\n", diff);

	    return 0;
	}

	//Assim, eu poderia até fazer, provavelmente, uma questão parecida mas com pares ordenados formados com 2 vetores
	//mas parece repetitivo, além de chatinho considerando que existe a possibilidade de deixar pares formados com
	//elementos de 1 só vetor e se eles podem ser ou não repetidos;

//4.13:
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main(void){
	    srand(time(NULL));

	    int size=0;
	    printf("Insira o tamanho do vetor: ");
	    scanf("%d", &size);
	    printf("Tamanho: %d\n", size);

	//criando o vetor e imprimindo-o
	    int vetor[size];
	    printf("vetor original = {");
	    for(int i=0; i<=size-1; i++){
	        vetor[i]= (rand()%3);                   //Vamos diminuir o escopo pra ter mais zeros;
	        if(i==size-1){printf("%d", vetor[i]);}
	        else{printf("%d, ", vetor[i]);}
	    } printf("}\n");

	//Empurrando os zeros pro final
	    int cont=0; //conta zeros
	    int aux=-1;
	    int j  =-1;
	    for(int i=0; i<=((size-1)-cont); i++){ 
	        if(vetor[i]==0){
	            j=i;
	            while(j<((size-1)-cont)){
	                vetor[j]=vetor[j+1];
	                j++;           
	            }vetor[(size-1)-cont]=0;
	            cont++;
	            i--; //basicamente faz o programa checar o novo valor aloca na antiga posição do zero;
	        }
	    }
	    //A função do "cont" nesse programa eh otimização, ele evita que o compilador desnecessáriamente permute zeros que já foram alocado no final do codigo;
	    //Porém o programa alçança o mesmo resultado caso a variavel cont seja eliminada, apenas realiza compilação desnecessaria;

	//Imprimindo o novo vetor
	    printf("vetor novo     = {");
	    for(int i=0; i<=size-1; i++){                   
	        if(i==size-1){printf("%d", vetor[i]);}
	        else{printf("%d, ", vetor[i]);}
	    } printf("}\n");   
	    
	    return 0;
	} 

//4.14:
	conio.h não funciona aqui, então vou skipar;

//4.15:
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main(void){
	    srand(time(NULL));

	    int row=0,col=0;
	    printf("Insira tamanho da matriz: ");
	    scanf("%d %d", &row, &col);
	    printf("Matriz %dx%d\n", row, col);

	    //Escrever a matriz bonitinha eh chato pqp, fiz uma vez pq eu consigo, proximo eh só números e \n´s
	    int mat[row][col];
	    printf("matriz = {\n");
	    for(int i=0; i<=row-1; i++){
	        printf("\t{");
	        for(int j=0; j<=col-1; j++){
	            mat[i][j]=rand()%100;
	           // mat[0][0]=-1;
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

	    int _1menor=mat[0][0];
	    int _1p1=0,_1p2=0;
	    for(int i=0; i<=row-1; i++){
	        for(int j=0; j<=col-1; j++){
	            if(mat[i][j]<_1menor){
	                _1menor  =mat[i][j];
	                _1p1=i;
	                _1p2=j;
	            }
	        }
	    }
	    printf("Menor:         mat[%d][%d] = %d\n", _1p1,_1p2,_1menor);

	    int _2menor;
	    int _2p1,_2p2;
	    for(int i=0; i<=row-1; i++){
	        for(int j=0; j<=col-1; j++){
	            if(i!=_1p1 || j!=_1p2){
	                if(mat[i][j]<_2menor){
	                    _2menor  =mat[i][j];
	                    _2p1=i;
	                    _2p2=j;
	                }
	            }
	        }
	    }
	    printf("Segundo Menor: mat[%d][%d] = %d\n", _2p1, _2p2, _2menor);

	    return 0;
	}      			 	

//Desafio meu->Ordenar cada linha da matriz;
//Desafio meu->Ordenar cada coluna da matriz;
//Desafio meu->Transforma uma matriz no vetor correspondenter	
//Desafio meu->Ordenar uma matriz inteira em vetor;
//Desafio meu->Ordenar uma matriz inteira em matriz;				
//SOLUÇÃO:
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




//4.16:
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
			// int aux=0;

			// for(int i=0; i<=pos-1; i++){ //pos-1
			// 	for(int j=0;j<=(tam-1)-1;j++){//tam
			// 		aux=vetor[j];
			// 		vetor[j]  = vetor[j+1];
			// 		vetor[j+1]= aux;
			// 		for(int i=0; i<=tam-1; i++){
			// 	        if(i==tam-1){printf("%d}\n",vetor[i]);}else
			// 	        printf(" %d, ", vetor[i]);
			// 	    } 
			// 	}printf("\n");
			// }
	//--------------------------------------------------------------------------------------------------------

	// -- ALTERNATIVA 02 -------------------------------------------------------------------------------------

	    int vet_aux[pos-1];
	    for(int i=0; i<=pos-1; i++){
	    	vet_aux[i]=vetor[i];
	    }

	    for(int i=0; i<=tam-pos-1; i++){vetor[i]=vetor[pos+i];}
	   	int j=0;
	    for(int i=tam-pos; i<=tam-1; i++){
	    	vetor[i]=vet_aux[j];
	    	j++;
	    }	
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

//4.17:
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

//4.18:
	#include <stdio.h>

	int sub_conj(int subc[], int conj[], int size_subc, int size_conj){
	    int flag=0;
	    for(int i=0; i<=size_subc-1; i++){
	        flag=0;
	        for(int j=0; j<=size_conj; j++){
	            if(subc[i]==conj[j]){flag=1;}
	        }
	        if(flag==0){return 0;}
	    }
	    return 1; 
	}

	int main(void){
	    int conj[10]={3,2,5,4,5,6,7,8,9,10};
	    int subc[4]={1,2,3,4};
	    int size_cj=sizeof(conj)/sizeof(int);
	    int size_sc=sizeof(subc)/sizeof(int);
	    printf("size conj = %d\n", size_cj);
	    printf("size subc = %d\n", size_sc);    

	    if(sub_conj(subc,conj,size_sc,size_cj)){printf("Eh subconjunto!\n");}
	    else{printf("Nao eh subconjunto.\n");}    

	    return 0;
	}

//4.18(Desafio meu) -> Eu quero saber se o sub-conjunto aparece no conjunto com a mesmissima ordem;
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

//4.19:
	#include <stdio.h>
	int main(){
	    int size=4;
	    int A[4][4]={
	        {1 , 2, 3, 1},
	        {4 , 5, 6, 2},
	        {7 , 8, 9, 3},
	        {10,11,12,13}        
	    };
	    int x=0;
	    for(int row=0; row<size; row++){
	        for(int col=0; col<size; col++){
	            if(row+col == (size-1)){
	                x += A[row][col];
	                printf("%d\n",A[row][col] );
	            }
	        }
	    }
	    printf("%d", x);
	    return 0;
	}//-> Soma os elementos da diagonal secundaria;

//4.20:
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main(){
	    srand(time(NULL));

	    int size=0;
	    printf("Insira o tamanho: ");
	    scanf("%d", &size);
	    printf("Tamanho: %d\n",size);

	    int vet[size];
	    printf("vetor = {");
	    for(int i=0; i<=size-1; i++){
	        vet[i]=rand()%100;
	        if(i==size-1){printf("%d}\n",vet[i]);}
	        else{printf("%d, ",vet[i]);}
	    }

	    int ctr;
	    for(int i=0; i<=size-1; i++){
	        ctr=0;
	        for(int j=0; j<=size-1; j++ ){
	            if(i!=j && vet[i]==vet[j]){ctr++;}  
	        }
	        if(ctr==0){printf("%d\n",vet[i]);}
	    }

	    return 0;
	}//-> Retorna todos os elementos unicos dentro do vetor;
	 //-> Eu fiz alguma mudança na questão pra ficar + legivel e também pq
	 //-> Eu acho q o segundo for se estendia para além do vetor em 1 pos;	 

//4.21:
	#include <stdio.h>
	int main(){
		int rows = 3, colums = 4, i, j, k;
		int a[3][4] = {1, 2, 3, 5, 7};
		i = j = k = 00;
			for(i = 0;i<rows;i++)
				for(j = 0;j<colums;j++)
					if(a[k][j]<k)
						k = a[i][j];
		printf("%d\n", k);
		return 0;    
	}//-> Retorna zero, i.e., k=0;

//4.22:
	#include <stdio.h>
	int main(){
		int arr[2] = {1, 2, 3, 4, 5};
		printf("%d", arr[3]);
		return 0;
	}//-> Retorna algum lixo na memória;

//4.23:
	#include <stdio.h>
	int main(){
	    int a,b,c;
	    int arr[5]={1,2,3,25,7};
	    a = ++arr[1]; 
	    //a = 3;
	    //arr[5]={1,3,3,25,7};
	    printf("%d %d\n",a, arr[1]);
	    b = arr[1]++;
	    //b = 3;
	    //arr[5]={1,4,3,25,7};    
	    printf("%d %d\n",b, arr[1]); 
	    c = arr[a++];
	    //c=arr[3++]=arr[3]=25;
	    //a=4
	    printf("%d\n",c);
	    printf("%d %d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4]); 

	    printf("\n");   
	    printf("%d--%d--%d",a,b,c);      
	    return 0;
	}//-> Retorna 3-4-25;    	    	

