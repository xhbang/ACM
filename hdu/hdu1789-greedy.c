/**
 *filename:hdu1789.c
 *date:26  4月 2011
 *author:hang@sonix
 *email:sonicisdreaming # gmail.com
 *ac is fun!
 *compiled under g++/debian 6.0
 */
#include <stdio.h>
#include <memory.h>
#define N 1002
typedef struct Node{
     int deadline;
     int score;
}node;

node work[N];
int mark[N];

//score big->small
//deadline eariler -> later
int cmp(const void *a,const void *b){
     if( (*(node*)a).score != (*(node *)b).score)
          return (*(node*)b).score - (*(node *)a).score;
     else
          return (*(node*)a).deadline - (*(node *)b).deadline;
}

int main(){
     freopen("in.txt","r",stdin);
     int sum,i,j,cases,n;
     scanf("%d",&cases);
     while( cases-- ){
          sum = 0;
          memset(mark,0,sizeof(mark));
          scanf("%d",&n);
          for( i = 0; i < n; i++)
               scanf("%d",&work[i].deadline);
          for( i = 0; i < n; i++)
               scanf("%d",&work[i].score);
          qsort(work,n,sizeof(node),cmp);
          for( i = 0; i < n; i++){
               for( j = work[i].deadline; j > 0; j--)
                    if( mark[j] == 0){
                         mark[j] = 1;
                         break;
                    }
               if( j == 0)
                    sum += work[i].score;
          }
          printf("%d\n",sum);
     }
     return 0;
}
