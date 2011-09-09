#include <stdio.h>
int H,U,D,F,d,s;
int main()
{
    while(scanf("%d %d %d %d",&H,&U,&D,&F)==4)
    {
       if(H==0) break;
       F*=U; H*=100; U*=100; D*=100;
       s=d=0;
       while(1)
       {
          if(U>=0) s+=U;
          d++;
          if(s>H) { printf("success on day %d\n",d); break; }
          s-=D;
          if(s<0) { printf("failure on day %d\n",d); break; }
          U-=F;
       }
    }
    return 0;
}
