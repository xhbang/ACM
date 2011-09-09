#include <stdio.h>
#include <memory.h>
#include <queue>

using namespace std;
#define N 8
typedef struct Node{
  int x,y;
  int p;
}point;

int main(){
  char a[3],b[3];
  int i,x,y;
  point from,to,temp;
  queue<point> q;
  int used[N][N];
  int dx[]={1,1,2,2,-1,-1,-2,-2};
  int dy[]={2,-2,1,-1,2,-2,1,-1};
  
  while(scanf("%s%s",&a,&b) != EOF){
    printf("To get from %s to %s takes ",a,b);
    memset(used,0,sizeof(used));
    while(!q.empty())
      q.pop();

    from.x=a[0]-'a';
    from.y=a[1]-'1';
    from.p=0;

    to.x=b[0]-'a';
    to.y=b[1]-'1';

    q.push(from);

    while(!q.empty()){
      temp=q.front();
      q.pop();
      used[temp.x][temp.y]=1;
      //more generation means more length
      if(temp.x == to.x && temp.y == to.y)
        break;
      for(i=0; i<N; ++i){
        x=temp.x+dx[i];
        y=temp.y+dy[i];
        if(x>=0 && y>=0 && x<N && y<N && !used[x][y]){
        //if(x>=0 && y>=0 && x<N && y<N){
          from.x=x;
          from.y=y;
          from.p=temp.p+1;
          q.push(from);
        }
      }
    }
    printf("%d knight moves.\n",temp.p);
  }
  return 0;
}
