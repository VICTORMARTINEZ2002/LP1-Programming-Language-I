#include <stdio.h>

struct _fraction{
	int num;
	int den;
};

// mesmo que a%b
int resto(int a, int b){
	while(a>=b){
		a -= b;
	}
	return a;
}

// O Algoritmo de Euclides para o MDC
// https://www.youtube.com/watch?v=3RMoD5ntt4k&list=PLFP-aSI41CNTAzNhiyntzHwXE2LkqyeSp&index=7&ab_channel=Andr%C3%A9Costa
int maior_divisor_comum(int a, int b){
	return (b==0? a : maior_divisor_comum(b, a%b));
}

void soma_fraction(struct _fraction f1, struct _fraction f2, struct _fraction *fs){
	fs->num = (f1.num*f2.den)+(f2.num*f1.den);
	fs->den = f1.den*f2.den;
}

int main(void){
	struct _fraction f1;
	struct _fraction f2;
	printf("Insira fraction 1: ");
	scanf("%d %d", &f1.num, &f1.den);
	printf("Insira fraction 2: ");
	scanf("%d %d", &f2.num, &f2.den);	

	printf("Fraction 1: %d/%d\n", f1.num, f1.den);
	printf("Fraction 2: %d/%d\n", f2.num, f2.den);	

	struct _fraction fs;
	soma_fraction(f1, f2, &fs);
	printf("Fraction Soma Original: %d/%d\n", fs.num, fs.den);

	struct _fraction fr;
	soma_fraction(f1, f2, &fr);
	int mdc = maior_divisor_comum(fr.num, fr.den);
	printf("Fraction Soma Reduzida: %d/%d\n", fr.num/mdc, fr.den/mdc);		

	return 0;
}