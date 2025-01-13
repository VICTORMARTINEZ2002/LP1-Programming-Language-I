#include <stdio.h>

int max(int *total){
  int maior=total[0];
  for(int i=1;i<7;++i){
    if(maior<=total[i]){
      maior=total[i];
    }
  }
  return maior;
}
int min(int *total){
  int menor=total[0];
  for(int i=1;i<7;++i){
    if(menor>=total[i]){
      menor=total[i];
    }
  }
  return menor;
}

int imax(int *total){
  int indice=0;
  for(int i=1;i<7;++i){
    if(total[indice]<=total[i]){
      indice=i;
      }
  }
  return indice;
}

int imin(int *total){
  int indice=0;
  for(int i=1;i<7;++i){
    if(total[indice]>=total[i]){
      indice=i;
      }
  }
  return indice;
}
int removemax(int *total){
  for(int i=0;i<7;++i){
    if(i==imax(total)){
      total[i]=min(total)-1;
      break;
      }
    }
  return 0;
}


int main(void){
  int x,maior;
  int count=0,lucro=0;
  int luc[7]={70,20,29,37,7,5,10},cost[7]={31,21,20,19,4,3,6},tot[7],invs[7];
  for(int i=0;i<7;++i){
    tot[i]=luc[i]-cost[i];
    }
  printf("Insira a quantidade de dinheiro para o melhor investimento possível:\n");
  scanf("%d",&x);

for(int i=0;i<7;++i){
  if(x-cost[imax(tot)]>=0){
    x-=cost[imax(tot)];
    invs[i]=imax(tot);
    lucro+=luc[imax(tot)];
    removemax(tot);
    }
  else{
    removemax(tot);
    invs[i]=-1;
  }
  }
for(int i=0;i<7;++i){
  if(invs[i]>=0)
  printf("%d ",invs[i]);
}
  printf("\n");
  printf("Lucro = %d",lucro);

  return 0;
}