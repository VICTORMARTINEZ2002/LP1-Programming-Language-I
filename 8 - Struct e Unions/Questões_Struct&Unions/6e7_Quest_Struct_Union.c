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
	char location[201];
	int telefone;
	struct _data nasc;
};

void addPessoa(struct _pessoa *agenda, struct _pessoa umaPessoa, int qtd_pessoas){
	agenda = (struct _pessoa*)realloc(agenda, (qtd_pessoas+1)*sizeof(struct _pessoa));
	if(agenda==NULL){printf("Erro realloc"); return;}
	strcpy(agenda[qtd_pessoas].nome, umaPessoa.nome);
	strcpy(agenda[qtd_pessoas].location, umaPessoa.location);
	agenda[qtd_pessoas].telefone = umaPessoa.telefone;
	agenda[qtd_pessoas].nasc.dia = umaPessoa.nasc.dia;	
	agenda[qtd_pessoas].nasc.mes = umaPessoa.nasc.mes;
	agenda[qtd_pessoas].nasc.ano = umaPessoa.nasc.ano;
}

void buscaPessoa(struct _pessoa *agenda, char name[], int qtd_pessoas){
	for(int i=0; i<=qtd_pessoas-1; i++){
		if(strcmp(agenda[i].nome, name)==0){
			printf("Contato encontrado!\n");
			printf("\tNome: %s",       agenda[i].nome);
			printf("\tTelefone: %d\n", agenda[i].telefone); 
			printf("\tDia nasc: %d\n", agenda[i].nasc.dia);
			printf("\tMes nasc: %d\n", agenda[i].nasc.mes); 
			printf("\tAno nasc: %d\n", agenda[i].nasc.ano);
			printf("\tLocation: %s\n", agenda[i].location); 
			return;
		}
	}
	printf("Não encontrado");
}

int main(){
	int num=0;
	printf("Insira quantos contatos deseja adicionar: ");
	scanf("%d", &num); getchar();

	struct _pessoa *agenda;
	agenda = (struct _pessoa*)malloc(num*sizeof(struct _pessoa));

	int qtd_pessoas=0;
	struct _pessoa umaPessoa;
	for(int i=0; i<=num-1; i++){
		printf("Pessoa %d:\n", i+1);
		printf("\tNome: "); fgets(umaPessoa.nome, sizeof(umaPessoa.nome)-1, stdin);
		printf("\tTelefone: "); scanf("%d", &(umaPessoa.telefone)); getchar();
		printf("\tDia nasc: "); scanf("%d", &(umaPessoa.nasc.dia)); getchar();	
		printf("\tMes nasc: "); scanf("%d", &(umaPessoa.nasc.mes)); getchar();		
		printf("\tAno nasc: "); scanf("%d", &(umaPessoa.nasc.ano)); getchar();
		printf("\tLocation: "); fgets(umaPessoa.location, sizeof(umaPessoa.location)-1, stdin);	
		addPessoa(agenda, umaPessoa, i);
		qtd_pessoas++;				
	}

	printf("\n\nIMPRIMINDO CONTATOS\n");
	for(int i=0; i<=num-1; i++){
		printf("Pessoa %d:\n", i+1);
		printf("\tNome: %s",   agenda[i].nome);
		printf("\tTelefone: %d\n", agenda[i].telefone); 
		printf("\tDia nasc: %d\n", agenda[i].nasc.dia);
		printf("\tMes nasc: %d\n", agenda[i].nasc.mes); 
		printf("\tAno nasc: %d\n", agenda[i].nasc.ano);
		printf("\tLocation: %s\n", agenda[i].location); 
	}
	
	char busca[101];
	printf("Insira busca: ");
	fgets(busca, sizeof(busca)-1, stdin);
	buscaPessoa(agenda, busca, qtd_pessoas);


}