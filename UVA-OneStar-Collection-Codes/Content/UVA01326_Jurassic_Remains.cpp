#include<bits/stdc++.h>
using namespace std;
// 2021.09.14

int lenth, loop;
int m, n, q;
int r, c;

char graph[100+5][100+5];
bool visited[100+5][100+5];

int bfs( int r, int c ){

    while( r - loop >= 0 && r + loop < m && c - loop >= 0 && c + loop < n ){

        for( int i = -1 * loop; i <= 1 * loop; i++ ){

            if( ( graph[ r - loop ][ c + i ] != graph[r][c] ) || r - loop < 0 ){

                return lenth;

            }

            if( ( graph[ r + loop ][ c + i ] != graph[r][c] ) || r + loop >= m ){
                
                return lenth;

            }

            if( ( graph[ r + i ][ c - loop ] != graph[r][c] ) || c - loop < 0 ){
                
                return lenth;

            }

            if( ( graph[ r + i ][ c + loop ] != graph[r][c] ) || c + loop >= n ){
                
                return lenth;

            }

        }   
        
        lenth += 2;
        loop++;

    }

    return lenth;

}

int main(){
    
    int t;

    cin >> t;

    while( t-- ){

        memset( graph, '0', sizeof(graph) );
        memset( visited, false, sizeof(visited) );

        
        cin >> m >> n >> q;
        cout << m << " " << n << " " << q << endl;

        for( int i = 0; i < m; i++ ){

            for( int j = 0; j < n; j++ ){

                cin >> graph[i][j];

            }

        }

        while( q-- ){

            lenth = loop = 1;

            cin >> r >> c;
            cout << bfs( r, c ) << endl;

        }
    }
}