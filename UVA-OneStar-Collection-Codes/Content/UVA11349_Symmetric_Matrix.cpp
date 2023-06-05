#include<bits/stdc++.h>
using namespace std;
//2021.08.24

void checking( int n, int count ){
    bool flag = false;
    bool negative = false;
    long long int check[100+5][100+5]={0};
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            cin >> check[i][j];
            if( check[i][j] < 0 ){
                negative = true;
                flag = true;
            }
        }
    }
    if( !negative ){
        for( int i = 0; i < n / 2; i++ ){
            for( int j = 0; j < n; j++ ){
                if( check[i][j] != check [ n-1-i ][ n-1-j ] ){
                    flag = true;
                    break;
                }
            }
            if( flag ){
                break;
            }
        }
        if( n % 2 != 0){
            for( int i = 0; i < n/2; i++){
                if( check[ n / 2 ][ i ] != check[ n / 2 ][ n-1-i ] ){
                    flag = true;
                    break;
                }
            }
        }
    }
    cout << "Test #" << count;
    if( flag ){
        cout << ": Non-symmetric." << endl;
    }
    else{
         cout << ": Symmetric." << endl;
    }
}

int main(){
    int t, count = 1;
    cin >> t;
    while( t-- ){
        int n;
        char a;
        cin >> a >> a >> n;
        checking(n, count);
        count++;
    }
}