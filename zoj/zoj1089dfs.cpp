#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory.h>
using namespace std;
int n,num[14],put[14];
void DFS(int d,int current)
{
	if( d > 6 )
	{
		for(int j=1; j<=5; j++)
			cout << put[j] << ' ';
		cout << put[6] << endl;
	}
	else
		for(int i=current; i<n-(6-d)+1; i++)
		{
			put[d] = num[i];
			DFS( d+1, i+1 );
		}
}
int main(void)
{
	int flag = 1 ;
	while( cin >> n && n)
	{
		if( flag == 0 )
		    cout << endl;
		for(int i=1; i<=n; i++)
		{
			cin >> num[i];
		}
		DFS(1,1);
		flag = 0;
	}
return 0;
}

