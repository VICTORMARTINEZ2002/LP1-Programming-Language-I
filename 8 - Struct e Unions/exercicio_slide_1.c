#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct _data{
	int dia;
	int mes;
	int ano;
};

struct _pessoa{
	char nome[101];
	int  telefone;
	struct _data nasc;
};

void addPessoa(struct _pessoa *agenda, struct _pessoa umaPessoa, int indice){
	strcpy(agenda[indice].nome, umaPessoa.nome);
	agenda[indice].telefone = umaPessoa.telefone;
	agenda[indice].nasc     = umaPessoa.nasc;
}

void buscaPessoa(struct _pessoa *agenda, char* nomeBuscado, int tam){
	for(int i=0; i<=tam-1; i++){
		if(strcmp(agenda[i].nome, nomeBuscado)==0){
			printf("Encontrado!\n Telefone: %d\nNascimento: %d/%d/%d", agenda[i].telefone, agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
			return;
		}
	}
	printf("Não Encontrado!");
}

int main(void){
	int n=2;
	struct _pessoa *agenda;
	agenda = malloc(n*sizeof(struct _pessoa));

	for(int i=0; i<=n-1; i++){
		struct _pessoa umaPessoa;
		printf("Nome da pessoa %d: ", i+1);
		fgets(umaPessoa.nome, sizeof(umaPessoa.nome)-1, stdin);
		printf("Telefone da pessoa %d: ", i+1);
		scanf("%d", &(umaPessoa.telefone));
		getchar();

		printf("dia nasc da pessoa %d: ", i+1);
		scanf("%d", &(umaPessoa.nasc.dia));
		getchar();	
		printf("mes nasc da pessoa %d: ", i+1);
		scanf("%d", &(umaPessoa.nasc.mes));
		getchar();		
		printf("ano nasc da pessoa %d: ", i+1);
		scanf("%d", &(umaPessoa.nasc.ano));
		getchar();							
		addPessoa(agenda, umaPessoa, i);
	}

	for(int i=0; i<=n-1; i++){
		printf("Nome da pessoa %d = %s", i+1, agenda[i].nome);
		printf("Telf da pessoa %d = %d\n", i+1, agenda[i].telefone);
		printf("Nascimento da pessoa %d: %d/%d/%d\n", i+1, agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
	}

	char name[101];
	printf("Insira nome para ser buscado: ");
	fgets(name, sizeof(name), stdin);
	buscaPessoa(agenda, name, n);


















	return 0;
}