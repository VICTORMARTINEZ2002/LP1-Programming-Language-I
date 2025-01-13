#include <stdio.h>
//#include <malloc.h>

int main(void){
	int v[]={0};
	v[0] = 1;
	free(v);
	printf("%d", v[0]);
	return 0;
}

	// replit:  invalid pointer -> core dumped -> abort
	// sublime: attempt to free a non-heap object 'v' -> Saida: 1;
