#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <queue>
#define MAX 100
using namespace std;

int n,et;
//distance of each room to ET room,dis[et]=0
//output of shortest()
int dis[MAX];
//reachable? 1 means reach
int m[MAX][MAX];
//used in the dfs
int used[MAX];

//determine the dis from i to et
//think from the et room
void shortest(){
  queue<int> q;
  q.push(et);
  int x,i;
  while( !q.empty() ) {
    x=q.front();
    q.pop();
    for(i = 0; i < n; ++i) {
      if(m[i][x] == 1 && dis[i] > (dis[x] + 1)){
        dis[i] = dis[x] + 1;
        q.push(i);
      }
    }
  }
}

//without room i,from 0 to et
//1 means reachable,we need room that opposite
//attention to used[i]
int dfs(int id){
  if(id == et)
    return 1;
  used[id] = 1;
  int i;
  //god understand recursive
  //i begins at 0
  for(i=0; i<n; ++i) {
    if(m[id][i] == 1 && !used[i])
      if(dfs(i))
        return 1;
  }
  return 0;

}

//main logical
//1 input,initial
//2 shortest()
//3 dfs
//4 output
int main(){
  FILE *f;
  f=freopen("A.in","r",stdin);
  int in,t,i,j;
  char line[10];

  scanf("%d\n",&in);
  for(t=0; t<in; ++t){
    scanf("%d%d\n",&n,&et);
    memset(dis,n,sizeof(dis));
    dis[et] = 0;
    memset(m,0,sizeof(m));
    while(gets(line)){
      if(strlen(line) == 0)
        break;
      sscanf(line,"%d%d",&i,&j);
      m[i][j] = 1;
    }

    shortest();

    int d = dis[0];
    int room = 0;
    //for each room except 0 and et
    for(i=1; i < n; ++i){
      if(i == et)
        continue;
      memset(used,0,sizeof(used));
      used[i] = 1;
      if (!dfs(0) && dis[i] < d) {
        d = dis[i];
        room = i;
      }
    }
    printf("Put guards in room %d.\n",room);
    if(t)
      printf("\n");
  }
  fclose(f);
  return 0;
}
