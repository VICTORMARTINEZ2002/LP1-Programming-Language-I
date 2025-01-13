#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct pessoa{
	char nome[100];
	int tele;
};

void add_pessoa(pessoa *agenda, pessoa sujeito, int index){
	strcpy(agenda[index].nome, sujeito.nome);
	agenda[index].tele=sujeito.tele;
}

void buscar_name(pessoa *agenda, char *name, int qtd){
	for(int i=0; i<=qtd-1; i++){
		if(strcmp(agenda[i].nome,name)==0){
			printf("Contato %d: telefone-%d\n", i+1, agenda[i].tele);
			return;
		}
	}
	printf("Contato não encontrado! Verifique se digitou o nome corretamente.");
}

int main(void){
	int qtd=0;
	printf("Insira quantos contatos deseja salvar: ");
	scanf("%d", &qtd);
	printf("Contatos: %d\n\n", qtd);
	getchar();

	pessoa *agenda;
	agenda = (pessoa*)malloc(qtd*sizeof(pessoa));

	for(int i=0; i<=qtd-1; i++){
		struct pessoa p;
		printf("Insira o nome da pessoa %d: ", i+1);
		fgets(p.nome, sizeof(p.nome), stdin);	
		printf("Insira o tele da pessoa %d: ", i+1);
		scanf("%d", &(p.tele));	
		getchar();	
		add_pessoa(agenda, p, i);
	}	printf("\n");

	for(int i=0; i<=qtd-1; i++){
		printf("Pessoa %d: \n", i+1);
		printf("\tnome: %s", agenda[i].nome);
		printf("\ttele: %d\n", agenda[i].tele);
	}	printf("\n\n\n");

	//busca
	char name[50];
	printf("Digite o nome da pessoa buscada: ");
	fgets(name, sizeof(name), stdin);
	buscar_name(agenda, name, qtd);


}