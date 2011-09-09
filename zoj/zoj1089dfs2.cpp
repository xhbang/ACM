#include<iostream>
#include<stdlib.h>
using namespace std;

int Numb[ 50 ];
int Sign[ 50 ];

void DFS( int k , int n , int star )
{
    if ( k == 6 )
    {
        int Count = 0;
        for ( int i = 0 ; i < n ; ++ i )
        {
            if ( Sign[ i ] )
            {
                cout << Numb[ i ];
                Count ++;
                if ( Count != 6 ) cout << " ";
            }
        }
        cout << endl;
        return;
    }
    for ( int i = star ; i < n ; ++ i )
    if ( !Sign[ i ] )
    {
        Sign[ i ] = 1;
        DFS( k+1 , n , i+1 );
        Sign[ i ] = 0;
    }
}

int main()
{
    int n;cin >> n;
    while ( n )
    {
        for ( int i = 0 ; i < n ; ++ i )
            cin >> Numb[ i ];
        for ( int i = 0 ; i < n ; ++ i )
            Sign[ i ] = 0;
        DFS( 0 , n , 0 );
        cin >> n;
        if ( n ) cout << endl;
    }
}
