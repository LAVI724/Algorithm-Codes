#include<bits/stdc++.h>
using namespace std;
//2021.07.18

int main(){
    int num;
    cin >> num;
    while( num-- ){
        int s, d;
        bool flag = 0;
        cin >> s >> d;
        for( int i = 0; i <= s/2 ; i++ ){
            if( abs( i - ( s - i ) ) == d ){
                cout << s - i << " "  << i << endl;
                flag = 1;
                break;
            }
        }
        if( !flag ){
            cout << "impossible" << endl;
        }
    }
}