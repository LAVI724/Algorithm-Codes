#include<bits/stdc++.h>
using namespace std;
//2021.07.18

int main(){
    int num, n, m;
    int flag = 1;
    cin >> num;
    while( num-- ){
        cin >> n >> m;
        int count = 0;
        for( int i = n; i <= m; i++ ){
            if( i % 2 != 0 ){
                count += i;
            }
        }
        cout << "Case " << flag << ": " << count << endl;
        flag++;
    }
    
}