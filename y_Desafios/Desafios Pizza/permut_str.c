#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
    if(n<1){return 1;}
    return n*fatorial(n-1);
}
  
/* Function to swap values at two pointers */
void swap(char* x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */

void permute(char* a, int l, int r)
{
    int i;
    if(l==r){
        printf("%s\n", a);
       // printf("%lf\n", inter(a));
        return;
    }else{
        for(i=l; i<=r; i++){
            swap((a + l), (a + i)); // Permutar o elemento e Fixa-lo
            permute(a, l + 1, r);
            swap((a + l), (a + i)); // backtrack
        }
    }
}
  
/* Driver program to test above functions */
int main()
{
    char str[] = "123";
    int n = sizeof(str)/sizeof(char)-1;
    permute(str, 0, n - 1);
    return 0;
}