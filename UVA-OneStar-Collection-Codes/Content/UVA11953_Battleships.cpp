#include<bits/stdc++.h>
using namespace std;
//2021.09.17

int t, n;
int flag;
char ship[100][100];

int row[] = { 1, 0 };
int column[] = { 0, 1 };

int dfs( int x_now, int y_now ){

    if( x_now >= n || y_now >= n ){

        return 0;

    }
    
    if( ship[ x_now ][ y_now ] == '.' ){

        return 0;

    }

    if( ship[ x_now ][ y_now ] == 'x' ){

        ship[ x_now ][ y_now ] = '.';
        flag = 1;

    }

    for( int i = 0; i < 2; i++ ){

        // 如果超出邊界或是海洋會回傳 0 迴圈繼續找下一個點
        if( !dfs( x_now + row[i], y_now + column[i] ) ){

            continue;

        }

    }

    return flag;
}

int main(){

    cin >> t;
    int num = 1;

    while( t-- ){

        for( int i = 0; i < 100; i++ ){

            for( int j = 0 ; j < 100; j++ ){
                
                ship[i][j] = '.';

            }

        }

        cin >> n;

        for( int i = 0; i < n; i++ ){

            for( int j = 0; j < n; j++ ){

                cin >> ship[i][j];
            }
        }

        int count = 0;

        cout << "Case " << num << ": ";
        
        for( int i = 0; i < n; i++ ){

            for( int j = 0; j < n; j++ ){

                if( ship[i][j] == 'x' || ship[i][j] == '@' ){

                    flag = 0;
                    count += dfs( i, j );

                }
            }
        }

        cout << count << endl; 
        num++;
    }
}