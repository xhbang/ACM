#include<iostream>
#include<string.h>
#include<algorithm>
#define N 100
using namespace std;

int main()
{
    char a[N],b[N];
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    if(n<N)
        a[n]='\0';
    strcpy(b,a);
    sort(a,a+n);
    i=0;
    while(strcmp(a,b))
    {
        i++;
        next_permutation(a,a+n);
    }
    cout<<i<<endl;
    next_permutation(a,a+n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
