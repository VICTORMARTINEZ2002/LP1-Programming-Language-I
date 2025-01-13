// #include <stdio.h>
// #define MAX_SIZE 100

// int func(const char * str, const char x);

// int main(){
// 	char str[MAX_SIZE];
// 	char x;
// 	int y;
// 	gets(str);
// 	x = getchar();
// 	y = func(str, x);
// 	printf("%d",y);
// 	return 0;
// }//-> retorna a ultima ocorrencia de um caractere em uma determinada string;

// int func(const char * str, const char x){
// 	int y=-1;
// 	int i=0;
// 	while(str[i]!='\0'){
// 		if(str[i]==x){
// 			y=i;
// 		}
// 		i++;
// 	}
// 	return y;
// }
/////////////////////////////////////////////////////////////////////////////////////
// #include <stdio.h>

// int main(){
// 	int arri[]={1,2,3};
// 	int *ptri = arri;

// 	char arrc[]={1,2,3};
// 	char *ptrc = arrc;

// 	printf("sizeof arri[] = %d\n",sizeof(arri));
// 	printf("sizeof ptri[] = %d\n",sizeof(ptri));

// 	printf("sizeof arrc[] = %d\n",sizeof(arrc));	
// 	printf("sizeof ptrc[] = %d\n",sizeof(ptrc));	
// }//->12,4,3,4;
///////////////////////////////////////////////////////////////////////////////////////
// #include <stdio.h>

// #define R 10
// #define C 20

// int main(){
// 	int (*p)[R][C];
// 	printf("%d", sizeof(*p));
// 	getchar();
// 	return 0;
// }//-> 4*10*20=800;
////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void myStrcat(char *a, char *b){
	a = (char *)malloc(sizeof(char)*(strlen(a)+strlen(b)+1));
	int m=strlen(a);
	int n=strlen(b);
	int i;
	for(i=0; i<=n; i++){
		a[m+i]=b[i];
	}
   // a[m+n-1]='\0'; 
}

int main(){
	char *str1 = "Linguagem";
	char *str2 = "Programacao";
	myStrcat(str1, str2);
	printf("%s ", str1);
	return 0;
}