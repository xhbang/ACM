#include <stdio.h>
#include <memory.h>
#define N 64

int k[N][N];

void shortest(){
  int i,j,m;
  int x,y;
  for(i=0; i<N; ++i)
    k[i][i]=0;
  for(i=0; i<N; ++i){
    for(j=0; j<N; ++j){
      //i means begin pos
      //j means end pos
      x=abs(i/8-j/8);
      y=abs(i%8-j%8);
      if(x == 2 && y == 1 || x == 1 && y == 2)
        k[i][j]=k[j][i]=1;
    }
  }
  for(m=0; m<N; ++m){
    for(i=0; i<N; ++i){
      for(j=0; j<N; ++j){
        if(k[i][m]+k[m][j]<k[i][j])
          k[i][j]=k[i][m]+k[m][j];
      }
    }
  }
}

int main(){
  int x,y;
  char a[3],b[3];
  memset(k,10,sizeof(k));
  //attention
  shortest();

  while(scanf("%s%s",&a,&b) != EOF){
    x=(a[0]-'a')*8+(a[1]-'1');
    y=(b[0]-'a')*8+(b[1]-'1');
    printf("To get from %s to %s takes %d knight moves.\n",a,b,k[x][y]);
  }
  return 0;
}
