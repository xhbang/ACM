/* filename:A+B for matrices.c
 * author:hang@sonix
 * date:05 Sep 2011
 * gcc (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2
 */

#include <stdio.h>
#include <memory.h>
#define M 10
int matrix[M][M];
int ans[M+M];

int main(){
    int m,n,t;
    int i,j;
    while(scanf("%d",&m) && m){
        memset(matrix,0,sizeof(matrix));
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(i = 0; i < m; ++i){
            for(j = 0; j < n; ++j){
                scanf("%d",&matrix[i][j]);
            }
        }
        for(i = 0; i < m; ++i){
            for(j = 0; j < n; ++j){
                scanf("%d",&t);
                matrix[i][j] += t;
                if(matrix[i][j])
                    ans[i] = ans[m+j] =1;
            }
        }
        int res = 0;
        for(i = 0; i < (m + n); ++i){
            if(!ans[i])
                ++res;
        }
        printf("%d\n",res);
    }

}
