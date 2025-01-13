#include <stdio.h>
#include <malloc.h>

//Considerações, o input nos retângulos sempre são os dois ponto que formam a diagonal não principal:
//Exemplo, considere o retangulo formado pelos pontos 1,2,3,4:
//1    2 -> Diagonal não principal:
//3    4 -> É a diagonal que liga 3-2;

struct retangulo{
	int extb_x; //extb: extremo baixo
	int extb_y;
	int extc_x; //extc: extremo cima
	int extc_y;		
};

struct ponto{
	int x;
	int y;
};

// A padronização do retangulo acontecerá dentro da checagem de pertencimento;

int pt_in_rec(struct ponto p, struct retangulo r){
	//Parametrizar o retangulo:
	int aux=0;
	if(r.extb_x>=r.extc_x){
		//troca horizontal:
		aux = r.extb_x;
		r.extb_x = r.extc_x;
		r.extc_x = aux;
		//troca vertical:
		aux = r.extb_y;
		r.extb_y = r.extc_y;
		r.extc_y = aux;
	}

	//checar se o ponto p está contido no retangulo:		
	if(p.x>=r.extb_x && p.y>=r.extb_y){
		if(p.x<=r.extc_x && p.y<=r.extc_y){
			return 1;
		}
	}
	return 0;
}



int main(void){
	//Leitura arquivo(não implementado):
	// FILE *arq = fopen("task", "r");
	// fscanf("input.txt", "%d", )
	// for(int i=0; i<=n-1; i++){
	// fscanf(arq, "%d %d", p.x, p.y);
	// }
	// for(int i=0; i<=n-1; i++){
	// 	fscanf(arq, "%d %d %d %d", r.extb_x, r.extb_y, r.extc_x, r.extc_y);
	// }
	// fclose();



	int num=3;
	//scanf("%d", num);

	//Alocação dinâmica:
	int *vet_pontos; //Vetor para armazenar as coordenadas do pontos individuais;
	vet_pontos = (int*)malloc(2*num*sizeof(int));
	int *vet_rect;   //Vetor para armazenar as coordenadas do retângulo;
	vet_rect   = (int*)malloc(4*num*sizeof(int));


	// for(int i=0; i<=num-1; i++){
	// 	for(int j=0; j<=num-1; j++){

	// 	}		
	// }

	


	// Inicialização manual:
	struct ponto p1;
	p1.x=-3;
	p1.y= 1;
	struct ponto p2;
	p2.x= 2;
	p2.y= 2;
	struct ponto p3;
	p3.x= 0;
	p3.y= 3;	

	//futuramente, implementar 2 for´s para automatizar o processo:
	struct retangulo r1;
	r1.extb_x=-3;
	r1.extb_y=-1;
	r1.extc_x= 2;
	r1.extc_y= 2;
	struct retangulo r2;
	r2.extb_x= 1;
	r2.extb_y= 1;
	r2.extc_x= 4;
	r2.extc_y= 3;
	struct retangulo r3;
	r3.extb_x=-1;
	r3.extb_y= 1;
	r3.extc_x= 1;
	r3.extc_y= 4;	


	// Retorno "manual" do programa:
	// Futuramente, adicionar dois for´s para automatizar o processo abaixo:
	printf("Considere que o primeiro ponto/retângulo é o de número 01: \n");
	printf("Retangulo 1 contém: ");
	if(pt_in_rec(p1, r1)){printf("p1, ");}
	if(pt_in_rec(p2, r1)){printf("p2, ");}
	if(pt_in_rec(p3, r1)){printf("p3, ");}
	printf("\n");	

	printf("Retangulo 2 contém: ");
	if(pt_in_rec(p1, r2)){printf("p1, ");}
	if(pt_in_rec(p2, r2)){printf("p2, ");}
	if(pt_in_rec(p3, r2)){printf("p3, ");}	
	printf("\n");	

	printf("Retangulo 3 contém: ");
	if(pt_in_rec(p1, r3)){printf("p1, ");}
	if(pt_in_rec(p2, r3)){printf("p2, ");}
	if(pt_in_rec(p3, r3)){printf("p3, ");}								
	printf("\n");

			

	printf("Fim.");
	return 0;
}