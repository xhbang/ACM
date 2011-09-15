/* filename:poj3253.c
 * author:hang@sonix
 * date:12 Sep 2011
 * gcc (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2
 */

#include <stdio.h>
#include <queue>

using namespace std;

//WA: must use long long type,for sum
struct node{
    long long x;
    bool operator < (const node &a ) const{
        return x > a.x;
        //from small to large
    }
};

int main(){
    priority_queue<node> q;
    int i,n;
    node m;
    node n1,n2;
    //quit method is EOF
    while(scanf("%d",&n) != EOF){
       for(i = 0; i < n; ++i){
           scanf("%lld",&m.x);
           //be careful with the input type "lld"
           q.push(m);
       } 

       long long sum = 0;
       while(q.size() > 1){
           n1 = q.top();
           q.pop();
           n2 = q.top();
           q.pop();
           n1.x += n2.x;
           sum += n1.x;
           q.push(n1);
       }
       printf("%lld\n",sum);
       q.pop();
       //must pop the last node before next turn
    }
    return 0;

}
