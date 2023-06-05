#include<bits/stdc++.h>
using namespace std;
//2021.08.30

int main(){

    long long int n;

    while( cin >> n && n){

        if( n == 0 ){

            break;

        }

        deque<int> binary;

        long long int count = 0;

        while( n ){

            if( n % 2 ){

                count++;

            }

            binary.push_back( n % 2 );
            n /= 2;
        }

        cout << "The parity of ";

        reverse( binary.begin(), binary.end() );

        for( auto i : binary ){

            cout << i;

        }

        cout << " is " << count << " (mod 2)." << endl;
        
        binary.clear();
    }
}