Strings
	● String não eh um tipo básico em C, como em outras linguagens;
	● É uma série de caracteres terminada com um caractere nulo ("\0");
	● Representada por um vetor de char: permitindo o acesso individual de cada caractere, o que aumenta
	  a felxibilidade de manipulação de string;
	● Por ex.: a string "verde e amarelo" é armazenada da seguinte maneira na memória: 
	 	|v|e|r|d|e| |e| |a|m|a|r|e|l|o|\0|
	 	- cada posição armazena um caractere;
	 	- o caractere nulo é um "terminador";

Inclusão do "\0"
	● Devido à necessidade do "\0", vetores que armazenam strings devem ter uma posição a mais;
	● Quando a string é constante, o "\0" é adicionado automaticamente pelo compilador;
		Por exemplo:
			#include <stdio.h>

			void main(void) {
				printf("Espaço alocado = %d bytes\n", sizeof("verde e amarelo"));
			}
		-> Saída: Espaço alocado = 16 bytes;
		-> De fato, o "\0" é inserido, pois a string possui apenas 15 caracteres;

	● No uso de strings variaveis, o "\0" é responsabilidade do programador que deve reservar o espaço adicional;
	● Lembre-se: O COMPILADOR NÃO VERIFICA A CONSISTÊNCIA DE INDEXAÇÃO!
		Por ex.:
			#include <stdio.h>

			void main(void) {
				char n[21];
				printf("Qual o seu nome? ");
				gets(n);
				printf("Olá, %s!",n);
			}
		-> Nesse exemplo, a função gets(n) lê a string do teclado e armazena no vetor n;
		-> O <enter> digitado é automaticamente subtituido por "\0", então não precisamos nos preocupar em por "\0";

Inicialização de Strings
	● Como qualquer outro vetor, strings podem ser inicializadas quando declaradas:
	 -Sintaxe convencional:
	 	- char convencional[3]={'o','i','\0'};				  
	 	- obrigatório por o "\0";
	 -Sintaxe própria de strings:
	 	- char propria[3]="oi";
	 	- "\0" é colocado automaticamente;

	● Exemplo com erro de declaração:
		#include <stdio.h>

		void main(void){
			char x[]="um";
			char y[]={'d','o','i','s'}; //não inclui "\0"
			printf("%s\t%s\n",x , y);
		}//-> saída: um doisum
		 // A primeira string eh mostrada corretamente;
		 // Na segunda string, como não se sabe onde termina a string, o compilador exibe caracteres até encontrar "\0";

	● "Uma string é um ponteiro"
	 - Arrays são ponteiros para o seu primeiro elemento;
	 - Como strings são arrays de caracteres, strings também são ponteiros;

	● Uma string pode ser atribuida em uma declaração para uma variavel do tipo char*
	 - char *cor_ptr="azul"; equivale a char cor[]="azul";
	 -> Cria uma variável ponteiro cor_ptr que aponta para a string "azul" em algum lugar da memória;

	● Dica de portabilidade: se for modificar a string, a armazene em um array. Não inicialize como sendo uma variavel
	 	do tipo char*, pois alguns compiladores podem colocá-la em um lugar da memória onde não pode ser modificada;

Leitura de Strings	 
	● scanf():
	 -lê uma string até o encontro do primeiro espaço em branco (espaço, tab, nova linha, etc);
	 -ex:
	 	char str1[80], str2[80];
	 	printf("Entre com o sobrenome: ");
	 	scanf("%s",str2);
	 	scanf("%79s", str1); //Especificando o tamanho da string a ser lida
	 -OBS: note que não é preciso por o '&', pois a passagem do vetor por si só já informa o endereço da 1° possição;
	 
	● fgets():
	 -lê uma linha inteira como string, até aparecer o '\n' (nova linha);
	 -ex:
	 	char nome[30];
	 	printf("Entre com o nome: ");
	 	fgets(nome, sizeof(nome), stdin);
	 	printf("nome: %s\n");
	 -Obs1: sizeof(nome)-limita a leitura para o tamanho exato da variavel 'nome';
	 -Obs2: stdin       -dispositivo de entrada padrão (geralmente o teclado);
	  		stdout      -dispositivo de saída   padrão (geralmente o vídeo);

	 -> Inserindo a palavra "sexo", o fgets ira ler "sexo\n\0" e o strlen(palavra) ira retornar 5 (012345); 		

	● gets():
	 -foi removida da mais recente revisão do C standart(2011);
	 -permite a entrada de qualquer quantidade de caracteres, podendo causar overflow

	-> OBS: limpando o buffer do teclado para que não haja leituras incorretas: fflush(stdin); 

Erros comuns de programação
	● A função scanf() não lê o caractere '\n';
	● Vamos testar o seguinte código:
		int main(void){
			int indade;
			char nome[30];
			printf("Entre com a idade: ");
			scanf("%d", &idade);
			printf("Entre com o nome: ");
			fgets(nome, 30, stdin);
			printf("idade: %d     nome: %s\n", idade, nome);
		}
	//-> O que geralmente acorre:
		-ao digitar um valor e precionar <enter>, o scanf() lê o valor e deixa o '\n' no buffer(stdin);
		-em seguida a função fgets() lê a próxima linha (apenas '\n'), e não lê o que deveria ser a entrada de fato;
	//-> Como resolver:
		1:usar scanf(), caso precise ler apenas 1 string
			printf("idade: ");
			scanf("%d", &idade);
			printf("nome: ");
			scanf("%s", nome);
		2:usar getchar() para ler o '\n', caso precise da linha inteira;
			printf("idade: ");
			scanf("%d", &idade);
			printf("nome: ");
			getchar();
			fgets(nome, 30, stdin);	
		3:scanf(" %[^\n]s",nome);
			-O espaço no inicio diz ao scanf() para pular qualquer caractere de "espaço em branco"
			 (incluindo nova linha), antes de ler o próximo caractere;
			-Ao usar "^\n", somos capazes de escrever strings com espaços e armazenar em uma variavel,
			 até que \n seja encontrado;
			 		
Funções Para Manipulação de Strings
	● Para funções de string, deve-se incluir a biblioteca <string.h>
	● As principais funções são:
		->strlen(): calcula o tamanho de uma string
			char a[20]="program";
			printf("Tam de a: %ld \n", strlen(a)); //retorna 7;
		->strcpy(): copia uma string para outra
			char str1[10]="oi";
			char str2[10],str3[10];
			strcpy(str2, str1);
			strcpy(str3, "td bem?");
			printf("%s %s", str2, str3);
		->strcmp(): compara 2 strings, retorna um valor inteiro, que se iguala a '0' para strings iguais;
			char str1[]="abc",str2[]="abc",str3[]="cab";
			int result;
			//Comparando a str1 com a str2;
			result = strcmp(str1, str2);
			printf("strcmp(str1, str2) = %d\n", result); //retorna 0
			// comparando strings str1 e str3
			result = strcmp(str1, str3);
			printf("strcmp(str1, str3) = %d\n", result); //retorna -1
		->strcat: concatena duas strings;
			char str1[]="bom", str2[]="dia!";
			//concatena str1 e str2, e a string resultante é armazenada em str1;
			strcat(str1,str2);
			printf("%s\n",str1); //retorna "bomdia!"

Exercício
	1. Codifique uma função semelhante a strlen(s), que devolve o número de caracteres armazenados 
	   na string s. Lembre-se que o '\0' não faz parte e, portanto, não deve ser contado;
	Solução:
		int strlen_1(char str[]){
		    int cont=0,i=0;
		    while(str[i]!='\0'){
		        cont++;
		        i++;
		    }
		    return cont-1;    
		}

	2. Crie um programa em C para checar se uma string é palindromo ou não;
	   OBS: palindromo-igual independentemente se lido da esquerda p/ direita ou da direita p/ esquerda;
	   ex: Entrada: RADAR; 
	       SAÍDA: É PALINDROMO;
	Solução:
		int palindr(char str[]){
		    int tam = strlen(str);
		    int flag=1;
		    for(int i=0; i<=(int)((tam-1)/2); i++){
		        if(str[i]!=str[tam-1-i]){flag=0;}
		    }
		    return flag;
		}       

	3. Escreva um programa C para contar o número total de palavras em uma string usando loop;
	Solução:
	#include <stdio.h>
	#include <string.h>

	//Desafio meu, armazenar essas palavras num vetor;
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

	int main(void){
	    char str1[80];
	    do{
	        printf("Escreva alguma coisa: ");
	        fgets(str1, sizeof(str1), stdin);
	        printf("Palavras: %d\n\n", qtd_palav(str1));
	    }while(str1[0]!='0');
	    return 0;
	}

	4. O código de cesar é uma das mais simples e conhecidas técnicas de criptografia. É um tipo de cifra de substituição
	   na qual cada letra do texto é subtituida por outra, que se apresenta no alfabeto abaixo dela um número fixo de
	   vezes(k). Considera-se a lista do alfabeto como sendo circular.
	   ex: com k=3, A seria subtituido por D, B se tornaria E, e assim por diante.
	   Utilizando o código de Cesar, crie uma função para criptografar e outra para descriptografar uma string do teclado;
	Solução:
		#include <stdio.h>
		#include <string.h>

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
		    printf("Escreva alguma coisa para ser codificado: ");
		    fgets(str1, sizeof(str1), stdin);
		    printf("Escreva alguma coisa para ser traduzido:  ");
		    fgets(str2, sizeof(str2), stdin);    
		    cript(str1,size,8);
		    descript(str2, size, 8);
		    return 0;
		}   









