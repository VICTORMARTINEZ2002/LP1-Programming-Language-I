A R Q U I V O S :
INTRODUÇÃO:
	● O armazenamento de dados em variáveis é temporário
		- os dados são perdidos quando o programa é finalizado;
	● ARQUIVOS são utilizados para armazenamento permanente de dados;
	● Nessa aula aprenderemos como arquivos de dados são criados, atualizados e processados por programas em C;

ARQUIVOS E STREAMS (FLUXOS):
	● O C "enxerga"	cada arquivo como uma stream (fluxo) de bytes;
	● Cada arquivos termina ou com um marcador end-of-file (eof) ou um número especifico de byte armazenado em uma estrutura do SO;	
		0 	 ▭
		1	 ▭
		2	 ▭
		3	 ▭
		...  ▭
		n-1  ▭
		eof  ▭
	● Quando um arquivo é aberto, uma stream é associado a ele; e...
	● Mais 2 arquivos e suas respectivas streams também são abertos:
		- standard input;
		- standard output;

	● As streams funcionam como canais de comunicação entre arquivos e programas:
		- standard input:  permite um programa ler dados do teclado;
		- standard output: permite um programa mostrar dados na tela;
	● Buffers melhoram a eficiência do uso de arquivos
		- São espaços de armazenamento temporario na memória;
		- reduzem o num de acessos ao disco (HD/SSD), aumentando a velocidade de execução do programa;
		- Cada stream (stdin e stdout) possuem seus respectivos buffers;

	● STDOUT:
		- dados gravados pelo programa são temporariamente armazenados no buffer (stdout);
		- quando o buffer está cheio, o SO descarrega de uma vez seu conteudo no disco;
		-> DE MANEIRA ANÁLOGO, DURANTE A LEITURA, É UTILIZADO O BUFFER STDIN;
				teclado -> programa -> video
							  ↕
							buffer
							  ↕
						    disco

	● A abertura de um arquivo retorna um ponteiro para uma struct FILE 
		- essa struct é definida em <stdio.h> e contém informações para processar o arquivo, como:
			-> I/O mode:	       indica se o arquivo será de leitura ou escrita;
			indicador end-of-file: indica se a leitura chegou ao final do arquivo;
			indicador de posição:  indica a posição atual de leitura/escrita no arquivo;
			uma 'id', que é armazenada pelo SO em um vetor de arquivos abertos;				    

	● A abertura de um arquivo é realizada pela seguinte função:
		- FILE *fopen( const char *filename, const char *mode);
			- const:    modificador indicando que o valor da variável não pode ser alterado;
			- filename: string contendo o nome do arquivo a ser aberto;
			- mode:     string contendo o modo de abertura do arquivo: para leitura, escrita, etc;		

MODOS DE ABERTURA:
	● Na abertura de arquivos há vários tipos de mode, alguns são:
	-> "r"  (leitura):             
		Abre um arquivo unicamente para leitura; 
		O arquivo deve existir;
	-> "r+" (leitura/atualização): 
		Abre um arquivo para atualização (leitura ou gravação);		
		Caso o arquivo não exista, ele será criado;
		Caso o arquivo sim exista, seu conteudo será apagado e substituido pelo novo;
	-> "w"  (escrita):             
		Cria um arquivo unicamente para escrita;
		Se um arquivo com mesmo nome existir, seu conteúdo é descartado, e um novo arquivo em branco é criado;
	-> "w+" (escrita/atualização):
		cria um arquivo para atualização;	
		Caso o arquivo já exista, seu conteudo será substituido;
	-> "a"  (anexa):
		abre ou cria um arquivo para unicamente gravação no final de seu conteudo prévio;
		Preserva o conteudo antigo do arquivo, caso esse exista;
	-> "a+" (anexa/atualização):
		cria um arquivo para atualização (leitura e gravação);
		escrita realizada no final de seu conteudo prévio;

EXEMPLO COM FOPEN():
	int main(){
		FILE * arq;
		arq = fopen("meuarquivo.txt", "w");
		if(arq!=NULL){
			fputs("exemplo fopen", arq);
			fclose(arq);
		}else{
			printf("Abertura do arquivo falhou");
		}
		return 0;
	}

	-> se aqr==NULL, então a abertura do arquivo falhou;
	-> fputs(): escreve uma string no arquivo;
	-> Outras funções para escrita:
		fprintf(arq, "%s", exemplo);
		fputc('a', arq);
	-> fclose(): fecha o arquivo e o desassocia à stream.
		-todo conteudo do buffer stdin  é descartado;
		-todo conteudo no buffer stdout é escrito;	

FUNÇÕES DE LEITURA:
	● int fgetc(FILE *stream);
		retorna o caractere lido ou EOF;
	● char* fgets(char* str, int num, FILE *stream);
		retorno: str ou NULL se o final do arquivo foi atingido sem nenhum caractere ter sido lido;
	● int fscanf(FILE *stream, const char *format, ...);
		Assim como o scanf lê uma entrada formatada, mas do arquivo;
		retorno: numero de argumentos lidos corretamente ou EOF;

EXEMPLO COM FGETS():
	● Nesse exemplo, o comando while é utilizado para "iterar" no arquivo;
	● Começando do inicio do arquivo, a cada chamada do fgets(), o ponteiro arq aponta para o inicio de uma nova linha;
		int main(){
			FILE * arq;
			char str[100];
			arq = fopen("arquivo.txt", "r");
			if(arq == NULL){
				printf("Erro de abertura\n");
				return -1;
			}
			while(fgets(str, 100, arq)!=NULL){
				printf("%s", str);
			}
			fclose(arq);
			return 0;
		}

EXEMPLO COM fscanf():		
	● A função int feof() acessa o indicador de end-of-file e verifica seu status
		- caso retorne 0, o final do arquivo não foi alcançado;
		- caso contrário, atingiu-se o final do arquivo;
	int main(){
		FILE * arq;
		char str[100];
		arq = fopen("arquivo.txt", "r");
		if(arq==NULL){
			printf("Erro de abertura");
			return -1;
		}
		while(feof(arq)==0){
			fscanf(arq, "%s", str);
			printf("%s", str);
		}
		fclose(arq);
		return 0;
	}		

LER / ESCREVER struct em um arquivo em C:
	● É fácil escrever string ou int em arquivo usando fprintf e putc;
	● Mas você pode enfrentar dificuldade ao escrever o conteúdo de uma struct;
	● fwrite e fread tornam a tarefa mais fácil quando vc desejar escrever e ler blocos de dados;

FWRITE():
	size_t fwrite (const void * ptr, size_t size, size_t count, FILE * stream);
	PARAMETROS:
		ptr:    Ponteiro para a arraya de elementos a serem gravados;
		size:   Tamanho em bytes de cada elemento a ser escrito;
			- size_t é um apelido para unsigned int;
		count:  Número de elementos, cada um com um tamanho de size bytes;
		stream:	Ponteiro para um objeto FILE que especifica uma stream de saída;

	RETORNO:
		o número total de elementos gravados com sucesso é retornado;	

EXEMPLO COM fwrite():
	struct person{
		int id;
		char fname[20];
		char lname[20];
	};

	int main(){
		FILE *outfile;

		// open file for writing
		outfile = fopen("person.dat", "w");
		if(outfile == NULL){
			fprintf(stderr, "\nError opend file\n");
			exit (1);
		}

		struct person input1 = {1, "rohan", "sharma"};
		struct person input2 = {2, "malena", "dhoni"};

		// write struct to file
		fwrite(&input1, sizeof(struct person), 1, outfile);
		fwrite(&input2, sizeof(struct person), 1, outfile);
		if(fwrite!=0){
			printf("contents to file written successfully!\n");
		}else{
			printf("error writing file!\n");
		}

		//close file
		fclose(outfile);
		return 0;
	}		

FREAD():
	size_t fread(void * ptr, size_t size, size_t count, FILE * stream);
	PARAMETROS:
		ptr:    ponteiro para um bloco de memória com um tamanho minimo de size*count bytes;
		size:   tamanho em bytes de cada elemento a ser lido; 
		count:  número de elementos a serem lidos;
		stream: ponteiro para um objeto FILE que especifica uma stream de entrada;
	RETORNO:
		o número total de elementos lidos com sucesso é retornado;

FREAD() EXEMPLO:
	struct person{
		int id;
		char fname[20];
		char lname[20];
	}

	int main(){
		FILE *infile;
		struct person input;

		// open person.dat for reading
		infile = fopen("person.dat", "r");
		if(infile == NULL){
			fprintf(stderr, "\nError opening file\n");
			exit (1);
		}

		// read file contents till end of file
		while(fread(&input, sizeof(struct person), 1, infile)){
			printf("id = %d\n name = %s %s\n ", input.id, input.fname, input.lname);
		}

		//close file
		fclose(infile);
		return 0;
	}			

EXERCICIO: escreva um programa em C para contar o número de caracteres em um arquivo;
	#include <stdio.h>
	#define MAX_SIZE 100

	int main(){
		FILE * arq;

		int cont=0;
		arq = fopen("arquivo_1.txt", "r");
		if(arq==NULL){
			printf("ERRO AO ABRIR O ARQUIVO!");
		}

		for(char c=getc(arq); c!=EOF; c=getc(arq)){	
			cont++;
		}
		fclose(arq);

		printf("%d", cont);
	}

EXERCICIO: escreva um programa em C para contar o número de palavras em um arquivo;
	#include <stdio.h>
	#include <string.h>
	#include <malloc.h>

	void concerta_string(char *texto){
		//O texto lido é, por exemplo: 123456\n\0;	(teclado)
		//O texto lido é, pro exemplo: 123456\0;    (arquivo)
		int tam = strlen(texto); //ex: tam=7, não 8;
		//printf("Tamanho Original: %d\n", tam);
		//texto[tam-1]='\0'; -> só para input teclado que vem com o \n;


		//Tirar os espaços no inicio da string;
		while(texto[0]==' '){
			for(int i=0; i<=(tam-1)+1; i++){
				texto[i]=texto[i+1];
			}
			tam--;
		}

		//Tirar os espaços no fim da string;
		while(texto[(tam-1)-1]==' '){
			texto[(tam-1)-1]='\0';
			tam--;
		}

		//Tirar os espaços duplos no meio da string;
		for(int i=0; i<=tam-1; i++){
			if(texto[i]=='\0'){break;}
			if(texto[i]==' ' && (texto[i+1]==' ' ||texto[i+1]=='\0')){
				tam--;
				for(int j=i; j<=tam-1; j++){
					texto[j]=texto[j+1];		
				}
				i--;
			}
		}
	}

	int main(){
		FILE * arq;

		arq = fopen("arquivo_1.txt", "r");
		if(arq==NULL){printf("ERRO AO ABRIR O ARQUIVO!");}

		char* texto_ptr;
		texto_ptr = (char*)malloc(1*sizeof(char));
		if(texto_ptr==NULL){printf("Erro malloc.\n"); return 0;}

		int i=0;
		for(char c=getc(arq); c!=EOF; c=getc(arq)){
			texto_ptr[i++]= c; 
			texto_ptr = (char*)realloc(texto_ptr, (i+1)*sizeof(char));
			if(texto_ptr==NULL){printf("a");}
		}	fclose(arq);
		texto_ptr[i]='\0';

		concerta_string(texto_ptr);

		int palavras=0;
		for(int i=0; texto_ptr[i]!='\0'; i++){
			if(texto_ptr[i]==' '){palavras++;}
		}
		palavras++; // pra contar a ultima palavra;

		printf("texto:    %s\n", texto_ptr);
		printf("palavras: %d", palavras);
		return 0;
	}

EXERCICIO: escreva um programa em C para deletar uma linha especifica de um arquivo;
	Suponha que o conteúdo do arquivo test.txt seja:
		linha de teste 1
		linha de teste 2
		linha de teste 3
		linha de teste 4
		Insira o nome do arquivo a ser aberto: test.txt
		Insira a linha que deseja remover: 2
	Resultado esperado:
	O conteúdo do arquivo test.txt é:
		linha de teste 1
		linha de teste 3
		linha de teste 4

	● Você pode precisar das seguintes funções
		○ int remove ( const char * filename );
			■ retorna 0, caso sucesso e diferente de 0 caso haja falha;
		○ int rename ( const char * oldname, const char * newname );
			■ retorna 0, caso sucesso e diferente de 0 caso haja falha;

SOLUÇÃO:
	#include <stdio.h>

	int main(void){
		FILE *f1, *f2;
		f1 = fopen("arquivo_2i.txt", "r");
		f2 = fopen("arquivo_2f.txt", "w");
		if(f1==NULL || f2==NULL){printf("Erro Abrir arquivo\n");}



		int linha_ex=-1;
		printf("Insira linha a ser deletada: ");
		scanf("%d", &linha_ex);

		char texto[301];
		int linha_atual=1;
		while(fgets(texto, 301, f1)!=NULL){
			if(linha_atual != linha_ex){
				fputs(texto, f2);
			}
			linha_atual++;
		}	

		fclose(f1);
		fclose(f2);

		// remove("arquivo_2i"); //apagar o arquivo 2 inicial;
		// rename("arquivo_2f", "arquivo_2");
		return 0;
	}			

EXERCICIO: Escreva um programa em C para mesclar dois arquivos e gravá-lo em um novo arquivo;
	Ex.:
		Arquivo1.txt:		Arquivo2.txt:		Mesclado.txt:
		1 					4					1
		2                   5					2		
		3                   6                   3
												4
												5
												6		

SOLUÇÃO:
	#include <stdio.h>

	int main(void){
		FILE *f1, *f2, *fr;
		f1=fopen("arquivo_4_1.txt", "r");
		f2=fopen("arquivo_4_2.txt", "r");
		fr=fopen("arquivo_4_r.txt", "w");
		if(f1==NULL || f2==NULL || fr==NULL){
			printf("Erro abertura arquivo!\n");
			return 0;
		}

		char temp[301];
		while(fgets(temp, 301, f1) != NULL){
			fputs(temp, fr);
		}
		fputs("\n", fr);
		while(fgets(temp, 301, f2) != NULL){
			fputs(temp, fr);
		}

		fclose(f1); fclose(f2); fclose(fr);
		return 0;	
	}												














