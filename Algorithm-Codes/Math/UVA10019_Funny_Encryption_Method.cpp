#include<bits/stdc++.h>
using namespace std;
//2021.08.30

int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;

        int x1, b1 = 0;
        x1 = n;
        while( x1 ){
            
            if( x1 % 2 ){
                b1++;
            }
            x1 /= 2;
        }
        cout << b1 << " ";

        int x2, b2 = 0;
        while( n ){
            x2 = n % 10;
            n /= 10;
            while( x2 ){
            
                if( x2 % 2 ){
                    b2++;
                }
                x2 /= 2;
            }
        }
        cout << b2 << endl;

    }
}