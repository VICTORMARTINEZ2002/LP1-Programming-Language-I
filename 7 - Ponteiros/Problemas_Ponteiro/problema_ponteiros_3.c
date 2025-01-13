#include <stdio.h>

void troca(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void){
	int a=0, b=0;
	printf("Insira a: ");
	scanf("%d", &a);
	printf("Insira b: ");
	scanf("%d", &b);	
	printf("a: %d, b: %d\n", a, b);

	int* ptr_a = &a;
	int* ptr_b = &b;
	troca(ptr_a, ptr_b);
	printf("a: %d, b: %d\n", a, b);	
}