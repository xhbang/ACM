/* filename:A+B 2008.c
 * author:hang@sonix
 * date:05 Sep 2011
 * gcc (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2
 */

#include <stdio.h>

void trans(int sum,int base){
    char str[32];
    int i=0;
    while(sum){
        str[i++] = sum % base + '0';
        sum = sum / base;
    }
    while(i--)
        putchar(str[i]);
    putchar('\n');
}

int main(){
    int a,b,sum,base;
    while(scanf("%d",&base) && base){
        scanf("%d%d",&a,&b);
        sum = a + b;
        if(sum)
            trans(sum,base);
        else
            printf("0\n");
    }

}
