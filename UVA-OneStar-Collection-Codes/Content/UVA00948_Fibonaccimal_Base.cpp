#include<bits/stdc++.h>
using namespace std;
//2021.08.30

deque<long long int> fib;

void fib_func( long long int max ){

    long long int last = fib.size() - 1;
    long long int tmp = fib[ last ];

    while( tmp <= max ){
        
        tmp = fib[ last ] + fib [ last - 1 ];
        fib.push_back( tmp );
        last++;
        // cout << fib[last] << " ";
    }
}

int main(){

    int n;
    long long int max = 0; 
    
    cin >> n;

    fib.push_back( 0 );
    fib.push_back( 1 );

    while( n -- ){

        long long int num;

        bool flag = false;

        cin >> num;
        cout << num << " = " ;

        if( num > max ){

            max = num;
            fib_func( max );

        }

        for( int i = fib.size() - 2; i > 1 ; i-- ){
            
            if( num - fib[i] >= 0 ){
                
                cout << "1";
                num -= fib[i];
                flag = true;

            }

            else if( flag ){
                cout << "0";
            }
        }
        cout << " (fib)" << endl;
    }
    fib.clear();
}