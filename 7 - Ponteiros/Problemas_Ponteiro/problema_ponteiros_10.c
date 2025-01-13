#include <stdio.h>

int main(void){
	int i=25;
	int *j;
	int **k;
	j = &i;
	k = &j;
	printf("%u\n",   k);
	// k   == &j == endereço;
	printf("%u\n",  *k);
	// *k  == conteudo do endereço de j == endereço de i;
	printf("%u\n", **k);
	// **k == conteudo de *k == conteudo do endereço de i == 25;	
	return 0;
}