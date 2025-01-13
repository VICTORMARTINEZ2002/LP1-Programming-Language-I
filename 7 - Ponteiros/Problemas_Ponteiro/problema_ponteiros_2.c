#include <stdio.h>

int main(){
	int arri[] = {1, 2 ,3};
	int *ptri = arri;
	char arrc[] = {1, 2 ,3};
	char *ptrc = arrc;
	printf("sizeof arri[] = %d\n", sizeof(arri)); // 3*int=12
	printf("sizeof ptri   = %d\n", sizeof(ptri)); // ponteiro=4;
	printf("sizeof arrc[] = %d\n", sizeof(arrc)); // 3*char=3
	printf("sizeof ptrc   = %d\n", sizeof(ptrc)); // ponteiro=4;
	return 0; 
}	// Saida: ...12...4...3...4;