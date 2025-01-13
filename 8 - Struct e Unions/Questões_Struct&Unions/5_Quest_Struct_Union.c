#include <stdio.h>
#include <math.h>

struct _ponto{
	float x;
	float y;
};

float distancia(struct _ponto p1, struct _ponto p2){
	float distancia = sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2));
	return distancia;
}

int main(void){
	struct _ponto p1;
	printf("Insira a coordenada do ponto p1: ");
	scanf("%f %f", &p1.x, &p1.y);
	struct _ponto p2;
	printf("Insira a coordenada do ponto p2: ");
	scanf("%f %f", &p2.x, &p2.y);	

	printf("Distancia entre os pontos (%f, %f) e (%f, %f): %f", p1.x, p1.y, p2.x, p2.y, distancia(p1,p2));
	return 0;
}