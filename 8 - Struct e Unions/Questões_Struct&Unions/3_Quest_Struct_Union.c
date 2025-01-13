//OBS1: Para todos os fins o ID não pode ser zero;

// Implementar para que 2 alunos não possam ter o mesmo ID; -> Feito;
// Implementar para que um ID não possa ser negativo? 
// -> Possivel, mas id negativos poderiam apresentar alguma classificação - turnos, por exemplo; 

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE 30

struct _aluno{
	int ID;
	char nome[MAX_SIZE];
	char sexo;
	float pt_1;
	float pt_2;
	float pt_t;
};

// Função que eu fiz na parte de strings;
void concerta_string(char* texto){
	int tam = strlen(texto);
	texto[tam-1]='\0';

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

// void concerta_string(char* str){
// 	int tam=0;
// 	int cont=0;
// 	while(str[cont]!='\0'){cont++;}
// 	str[cont-1] = '\0';
// }

void normaliza_string(char* str){
	int i=0;
	while(str[i]!='\0'){
		if(((int)str[i]>=97) && ((int)str[i]<=122)){
			str[i] -= 32;
		}
		i++;
	}
}

int menu(void){
	int opt=0;
	printf("=============================================\n");
	printf("                    MENU                     \n");
	printf("=============================================\n");
	printf("\t1. Adicionar registro de estudante\n");
	printf("\t2. Deletar   registro de estudante\n");
	printf("\t3. Atualizar registro de estudante\n");
	printf("\t4. Ver registro de todos estudantes\n");
	printf("\t5. Mostrar aluno com maior nota total\n");
	printf("\t6. Mostrar aluno com menor nota total\n");	
	printf("\t7. Mostrar aluno com maior nota absoluta\n");
	printf("\t8. Mostrar aluno com menor nota absoluta\n");
	printf("\t9. Encontrar aluno por ID\n");
	printf("\t10. Ordenar os registros por pontuation total\n");
	printf("\t11. Ordenar os registros por ID\n");
	printf("\t12. Ordenar os registros alfabeticamente\n");		
	printf("\t13. Finalizar Programa.\n");	
	printf("Entre com sua option: ");
	scanf("%d", &opt); getchar();		
	printf("\n");
	return opt;
}

// Quando vou atualizar um aluno, eu ignoro o proprio aluno a ser atualizado;
// Quando vou cadastrar um aluno novo eu ignoro o proprio aluno que ocupa a ultima posição;
int verifID(struct _aluno *registros, int ID, int qtd_alunos, int ignorar){
	for(int i=0; i<=qtd_alunos-1; i++){             
		if(i==ignorar){continue;}
		if(registros[i].ID == ID){
			return 1;
		}
	}
	return 0;
}

void addAluno(struct _aluno *registros, struct _aluno umAluno, int* ptr_indice){
	//coletando informações para armazenar:
	//id
			printf("\tInsira ID: ");
			scanf("%d", &(umAluno.ID)); getchar();	
			if(verifID(registros, umAluno.ID, *ptr_indice, *ptr_indice)){
				do{
					printf("ID %d ja em uso! Insira outro ID: ", umAluno.ID);
					scanf("%d", &(umAluno.ID)); getchar();	
				}while(verifID(registros, umAluno.ID, (*ptr_indice)+1, (*ptr_indice)+1)); 
				// note na linh acima que o (*ptr_indice) ainda não foi incrementado, logo...
				// o fiz manualmente para representar a quantidade de alunos;
			}
	//nome	
		printf("\tInsira Nome: ");
		fgets(umAluno.nome, MAX_SIZE, stdin);
		concerta_string(&(umAluno.nome[0])); //supostamente é o mesmo que: concerta_string(umAluno.nome);
		normaliza_string(&(umAluno.nome[0]));
	//sexo	
		do{ 
			printf("\tInsira Sexo: (M/F) ");
			scanf("%c", &(umAluno.sexo)); getchar();
			if(umAluno.sexo=='m'){umAluno.sexo='M';}
			if(umAluno.sexo=='f'){umAluno.sexo='F';}
		}while((umAluno.sexo != 'M')&&(umAluno.sexo != 'F'));
	//pts	
		printf("\tInsira Pontuation Teste 1: ");
		scanf("%f", &(umAluno.pt_1)); 
		printf("\tInsira Pontuation Teste 2: ");
		scanf("%f", &(umAluno.pt_2)); 
		umAluno.pt_t = (umAluno.pt_1 + umAluno.pt_2)/2;
		printf("\tPontuation Total: %.2f\n", umAluno.pt_t);

	registros[*ptr_indice].ID   = umAluno.ID;
	strcpy(registros[*ptr_indice].nome, umAluno.nome);
	registros[*ptr_indice].sexo = umAluno.sexo;
	registros[*ptr_indice].pt_1 = umAluno.pt_1;
	registros[*ptr_indice].pt_2 = umAluno.pt_2;
	registros[*ptr_indice].pt_t = umAluno.pt_t;
	(*ptr_indice)++;
	return;
}

// O quantidade de alunos é passado para fazer a verificação de ID;
void attAluno(struct _aluno *registros, int indice, int qtd_alunos){
	char mdr='n';
	printf("Atualiazando Aluno %d: %s.\n", indice+1, registros[indice].nome);
	//ID
		do{ 
			printf("Mudar ID? ");
			fflush(stdin);
			scanf("%c", &mdr); getchar();
			if(mdr=='Y'){mdr='y';}
			if(mdr=='N'){mdr='n';}
		}while(mdr!='n' && mdr!='y');

		if(mdr=='y'){
			mdr='n';
			printf("  Insira Novo ID: ");
			scanf("%d", &(registros[indice].ID)); getchar();
			if(verifID(registros, registros[indice].ID, qtd_alunos-1, indice)){
				do{ 
					printf("  O ID %d ja esta em uso, insira novo ID: ", registros[indice].ID);
					scanf("%d", &(registros[indice].ID)); getchar();
				}while(verifID(registros, registros[indice].ID, qtd_alunos-1, indice));	
			}

		}	
	//nome	
		do{ 
			printf("Mudar Nome? ");
			fflush(stdin);
			scanf("%c", &mdr); getchar();
			if(mdr=='Y'){mdr='y';}
			if(mdr=='N'){mdr='n';}
		}while(mdr!='n' && mdr!='y');
		if(mdr=='y'){
			mdr='n';
			printf("  Insira Novo Nome: ");
			fgets(registros[indice].nome, MAX_SIZE, stdin);
			concerta_string(registros[indice].nome);
			normaliza_string(registros[indice].nome);
		}	
				
	//eita bixo sexo	
		do{ 
			printf("Mudar Sexo? ");
			fflush(stdin);
			scanf("%c", &mdr); getchar();
			if(mdr=='Y'){mdr='y';}
			if(mdr=='N'){mdr='n';}
		}while(mdr!='n' && mdr!='y');
		if(mdr=='y'){
			mdr='n';
			if(registros[indice].sexo == 'M'){
				registros[indice].sexo = 'F';
				printf("  Seu novo SeXo: F.\n");
			}else{ 				
				registros[indice].sexo = 'M';
				printf("  Seu novo SeXo: M.\n");
			}
		}		

	//pts
		do{ 
			printf("Mudar Pontuation? ");
			fflush(stdin);
			scanf("%c", &mdr); getchar();
			if(mdr=='Y'){mdr='y';}
			if(mdr=='N'){mdr='n';}
		}while(mdr!='n' && mdr!='y');
		if(mdr=='y'){
			mdr='n';
			printf("  Insira Nova Pontuation Teste 1: ");
			scanf("%f", &(registros[indice].pt_1)); getchar();
			printf("  Insira Nova Pontuation Teste 2: ");
			scanf("%f", &(registros[indice].pt_2)); getchar();
			registros[indice].pt_t = (registros[indice].pt_1 + registros[indice].pt_2)/2;
		}		
}

float maior_nota_total(struct _aluno *registros, int qtd_alunos){
	int maior_index=0;
	for(int i=1; i<=qtd_alunos-1; i++){
		if(registros[i].pt_t > registros[maior_index].pt_t){
			maior_index = i;
		}
	}
	return registros[maior_index].pt_t;
}

float menor_nota_total(struct _aluno *registros, int qtd_alunos){
	int menor_index=0;
	for(int i=1; i<=qtd_alunos-1; i++){
		if(registros[i].pt_t < registros[menor_index].pt_t){
			menor_index = i;
		}
	}
	return registros[menor_index].pt_t;
}

float maior_nota_abs(struct _aluno *registros, int qtd_alunos){
	int maior_index_1=0;
	for(int i=1; i<=qtd_alunos-1; i++){
		if(registros[i].pt_1 > registros[maior_index_1].pt_1){
			maior_index_1 = i;
		}
	}
	int maior_index_2=0;
	for(int i=1; i<=qtd_alunos-1; i++){
		if(registros[i].pt_2 > registros[maior_index_2].pt_2){
			maior_index_2 = i;
		}
	}

	if(registros[maior_index_1].pt_1 > registros[maior_index_2].pt_2){
		return registros[maior_index_1].pt_1;
	}
	return registros[maior_index_2].pt_2; 
}

float menor_nota_abs(struct _aluno *registros, int qtd_alunos){
	int menor_index_1=0;
	for(int i=1; i<=qtd_alunos-1; i++){
		if(registros[i].pt_1 < registros[menor_index_1].pt_1){
			menor_index_1 = i;
		}
	}
	int menor_index_2=0;
	for(int i=1; i<=qtd_alunos-1; i++){
		if(registros[i].pt_2 < registros[menor_index_2].pt_2){
			menor_index_2 = i;
		}
	}

	if(registros[menor_index_1].pt_1 < registros[menor_index_2].pt_2){
		return registros[menor_index_1].pt_1;
	}
	return registros[menor_index_2].pt_2; 
}

void buscaID(struct _aluno *registros, int ID, int qtd_alunos){
	for(int i=0; i<=qtd_alunos-1; i++){
		if(registros[i].ID == ID){
			printf("ID %d Encontrado: \n", ID);
			printf("  Nome: %s\n", registros[i].nome);
			printf("  Sexo: %c\n", registros[i].sexo);
			printf("  Pts1: %.2f\n", registros[i].pt_1);
			printf("  Pts2: %.2f\n", registros[i].pt_2);
			printf("  PtsT: %.2f\n", registros[i].pt_t);
			return;
		}
	}
	printf("ID %d not found!\n", ID);
}

void troca(struct _aluno *registros, int i, int j){
		struct _aluno temp;
		temp = registros[i];
		registros[i] = registros[j];
		registros[j] = temp;
}

void ord_pts(struct _aluno *registros, int qtd_alunos){
	for(int i=0; i<=qtd_alunos-1; i++){
		for(int j=i+1; j<=qtd_alunos-1; j++){             //i+1 pra não comparar um aluno consigo mesmo;
			if(registros[j].pt_t > registros[i].pt_t){
				troca(registros, i, j);
			}
		}
	}
}

void ord_ID(struct _aluno *registros, int qtd_alunos){
	for(int i=0; i<=qtd_alunos-1; i++){
		for(int j=i+1; j<=qtd_alunos-1; j++){
			if(registros[j].ID < registros[i].ID){
				troca(registros, i, j);
			}
		}
	}	
}

void ord_nome(struct _aluno *registros, int qtd_alunos){
	for(int i=0; i<=qtd_alunos-1; i++){
		for(int j=i+1; j<=qtd_alunos-1; j++){
			if(strcmp(registros[j].nome, registros[i].nome)<0){
				troca(registros, i, j);
			}
		}
	}	
}

int main(void){
	int  indice = 0;
	int* ptr_indice = &indice;

	// criando o vetor tipo struct que vai armazenar os alunos
	struct _aluno *registros;
	registros = (struct _aluno*)malloc(0*sizeof(struct _aluno));
	if(registros==NULL){printf("Erro Alocando Memoria 1");}

	// Criando a struct temporaria
	struct _aluno umAluno;



	int del=-1;
	int att=-1;
	float Ma_pt_t=-1;
	float Me_pt_t=-1;
	float Ma_pt_a=-1;
	float Me_pt_a=-1;	
	int id_temp  =-1;

	int chose=0;
	char flag='n';	
	while(flag=='n'){
		chose = menu();
		switch(chose){
			// SKIP
			case -1: break;

			// ADICIONAR
			case 1:
				printf("Adicionar Aluno Num %d: \n", indice);
				// realocando mais espaço pro vetor:
				do{ 
					registros = (struct _aluno*)realloc(registros,  (indice+1)*sizeof(struct _aluno));
					if(registros==NULL){printf("Erro Alocando Memoria 2");}
				}while(registros==NULL);
				addAluno(registros, umAluno, ptr_indice);
				break;

			// DELETAR
			case 2:
				if(indice==0){printf("Qtd de alunos = %d\n", indice); break;}

				// MOSTRAR OS ALUNOS:
				for(int i=0; i<=indice-1; i++){printf("\nAluno %d: %s\n ", i+1, registros[i].nome);}

				do{				
					printf("Qual Aluno deseja escluir? ");
					scanf("%d", &del);
					if(del==-1){break;}
				}while((del>indice) || (del<=0));
				for(int i=del-1; i<=indice-2; i++){
					registros[i]=registros[i+1];
				}
				do{ 
					registros = (struct _aluno*)realloc(registros,  (indice-1)*sizeof(struct _aluno));
					if(registros==NULL){printf("Erro Alocando Memoria 2");}
				}while(registros==NULL);
				indice--;
				break;

			// ATUALIZAR	
			case 3:
				if(indice==0){printf("Qtd de alunos = %d\n", indice); break;}

				// MOSTRAR OS ALUNOS:
				for(int i=0; i<=indice-1; i++){printf("\nAluno %d: %s\n ", i+1, registros[i].nome);}

				do{				
					printf("Qual Aluno deseja atualizar? ");
					scanf("%d", &att);
					if(att==-1){break;}
				}while((att>indice) || (att<=0));	
				attAluno(registros, att-1, indice);


				break;

			// MOSTRAR	
			case 4:	
				if(indice==0){printf("Qtd de alunos = %d\n", indice); break;}
				printf("Imprimindo Os Alunos Registrados: ");
				for(int i=0; i<=indice-1; i++){
					printf("\n");
					printf("Aluno %d:\n ", i+1);
						printf("\tid  = %d\n",   registros[i].ID);
						printf("\tnome= %s\n",   registros[i].nome);
						printf("\tsexo= %c\n",   registros[i].sexo);
						printf("\tpt_1= %.2f\n", registros[i].pt_1);
						printf("\tpt_2= %.2f\n", registros[i].pt_2);
						printf("\tpt_t= %.2f\n", registros[i].pt_t);	
				}
				break;

			// MAIOR NOTA TOTAL
			case 5:	
				if(indice==0){printf("Qtd de alunos = %d\n", indice); break;}

				Ma_pt_t = maior_nota_total(registros, indice);
				printf("A Maior Nota Total eh: %.2f\n", Ma_pt_t);
				printf("O(s) Aluno(s) com maior desempenho eh:\n");
				for(int i=0; i<=indice-1; i++){
					if(registros[i].pt_t == Ma_pt_t){printf("\t%s;\n",registros[i].nome);}
				}
				break;

			// MENOR NOTA TOTAL	
			case 6:	
				if(indice==0){printf("Qtd de alunos = %d\n", indice); break;}

				Me_pt_t = menor_nota_total(registros, indice);
				printf("A Menor Nota Total eh: %.2f\n", Me_pt_t);
				printf("O(s) Aluno(s) com pior desempenho eh:\n");
				for(int i=0; i<=indice-1; i++){
					if(registros[i].pt_t == Me_pt_t){printf("\t%s;\n",registros[i].nome);}
				}
				break;

			// MAIOR NOTA ABSOLUTA	
			case 7:	
				if(indice==0){printf("Qtd de alunos = %d\n", indice); break;}

				Ma_pt_a = maior_nota_abs(registros, indice);
				printf("A Maior Nota Absoluta eh: %.2f\n", Ma_pt_a);
				printf("O(s) Aluno(s) com maior nota absoluta eh:\n");
				for(int i=0; i<=indice-1; i++){
					if(registros[i].pt_1 == Ma_pt_a){
						printf("\t%s;\n",registros[i].nome);
						continue;
					}
					if(registros[i].pt_2 == Ma_pt_a){
						printf("\t%s;\n",registros[i].nome);
						continue;
					}					
				}

				break;

			// MENOR NOTA ABSOLUTA	
			case 8:
				if(indice==0){printf("Qtd de alunos = %d\n", indice); break;}

				Me_pt_a = menor_nota_abs(registros, indice);
				printf("A Menor Nota Absoluta eh: %.2f\n", Me_pt_a);				
				printf("O(s) Aluno(s) com menor nota absoluta eh:\n");
				for(int i=0; i<=indice-1; i++){
					if(registros[i].pt_1 == Me_pt_a){
						printf("\t%s;\n",registros[i].nome);
						continue;
					}
					if(registros[i].pt_2 == Me_pt_a){
						printf("\t%s;\n",registros[i].nome);
						continue;
					}					
				}
				break;

			// BUSCA ID	
			case 9:
				if(indice==0){printf("Qtd de alunos = %d\n", indice); break;}

				printf("Insira ID: ");
				scanf("%d", &id_temp); getchar();
				buscaID(registros, id_temp, indice);
				break;	

			// ORDENA PTS TOTAL	
			case 10:
				if(indice==0 || indice==1){printf("Qtd de alunos = %d\n", indice); break;}

				printf("Ordenando os Alunos por pontuation: ");
				ord_pts(registros, indice);
				for(int i=0; i<=indice-1; i++){
					printf("\n");
					printf("Aluno %d:\n ", i+1);
					printf("\tid  = %d\n",   registros[i].ID);
					printf("\tnome= %s\n",   registros[i].nome);
					printf("\tsexo= %c\n",   registros[i].sexo);
					printf("\tpt_1= %.2f\n", registros[i].pt_1);
					printf("\tpt_2= %.2f\n", registros[i].pt_2);
					printf("\tpt_t= %.2f\n", registros[i].pt_t);	
				}
				break;	

			// ORDENA ID	
			case 11:
				if(indice==0 || indice==1){printf("Qtd de alunos = %d\n", indice); break;}

				printf("Odenando os Alunos por ID: ");
				ord_ID(registros, indice);
				for(int i=0; i<=indice-1; i++){
					printf("\n");
					printf("Aluno %d:\n ", i+1);
					printf("\tid  = %d\n",   registros[i].ID);
					printf("\tnome= %s\n",   registros[i].nome);
					printf("\tsexo= %c\n",   registros[i].sexo);
					printf("\tpt_1= %.2f\n", registros[i].pt_1);
					printf("\tpt_2= %.2f\n", registros[i].pt_2);
					printf("\tpt_t= %.2f\n", registros[i].pt_t);	
				}
				break;	
				
			case 12:
				if(indice==0 || indice==1){printf("Qtd de alunos = %d\n", indice); break;}

				printf("Odenando os Alunos por nome: ");
				ord_nome(registros, indice);
				for(int i=0; i<=indice-1; i++){
					printf("\n");
					printf("Aluno %d:\n ", i+1);
					printf("\tid  = %d\n",   registros[i].ID);
					printf("\tnome= %s\n",   registros[i].nome);
					printf("\tsexo= %c\n",   registros[i].sexo);
					printf("\tpt_1= %.2f\n", registros[i].pt_1);
					printf("\tpt_2= %.2f\n", registros[i].pt_2);
					printf("\tpt_t= %.2f\n", registros[i].pt_t);	
				}
				break;			

			case 13:
				printf("FIM DO PROGRAMA!\n");
				flag='y';
				break;	

			default:
				printf("Invalid Option!");		
				break;							
		}

		printf("Fim switch\n\n\n");

		// do{
		// 	printf("Sair do loop? (y/n): ");
		// 	fflush(stdin);
		// 	scanf("%c", &flag); getchar();
		// 	if(flag=='Y'){flag='y';}
		// 	if(flag=='N'){flag='n';}
		// }while(flag!='y' && flag!='n');	
		printf("\n");
	}

	return 0;
}


































