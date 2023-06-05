#include<bits/stdc++.h>
using namespace std;
//2021.09.10

int main(){

    long long int n, m;

    while( cin >> n >> m ){
        
        if( n <= 1 || m <= 1 || n < m || n % m != 0 ){
            
            cout << "Boring!" << endl;
            continue;

        }

        bool flag = false;
        long long int tmp = m;

        for( int i = 1; tmp <= n ; i++ ){

            tmp = pow( m, i );

            if( tmp == n ){
                
                flag = true;
                break;

            }

        }

        if( flag ){
            
            cout << n;

            while( n != 1 ){

                cout << " " << n / m ;
                n /= m;

            } 
            
            cout << endl;

        }

        else{

            cout << "Boring!" << endl;

        }

    }

}
