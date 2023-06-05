#include<bits/stdc++.h>
using namespace std;
// 2021.09.22

int sum;
bool vis[8][8];
int number[8][8];
deque<int> dq[2];

// 八皇后 上下左右斜行皆不重複
int check( int x, int y ){

    for( int i = 0; i < x; i++ ){

        if( dq[1][i] == y ){

            return 0;

        }

        // 如果兩皇后在同一斜線上 其斜率為 1
        // 如果 x2 - x1 == y2 - y1 -> y2 - y1 / x2 - x1 == 1
        if( abs( x - i ) == abs( dq[1][i] - y ) ){

            return 0;

        }

    }
    return 1;

    // for( int i = 0; i < 8; i++ ){

    //     if( vis[x][i] ){

    //         return 0;
    //     }

    //     if( vis[i][y] ){

    //         return 0;

    //     }

    // }

    // for( int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j-- ){

    //     if( vis[i][j] ){

    //         return 0;

    //     }

    // }

    // for( int i = x - 1, k = y + 1; i >= 0 && k < 8; i--, k++ ){
        
    //     if( vis[i][k] ){

    //         return 0;

    //     }

    // }
    
    // return 1;
}

void dfs( int q ){

    // 因為每排必至少有一個皇后
    // 所以 x 直接用 q 去代，每行每行去 dfs
    if( dq[0].size() == 8 ){

        int tmp = 0;

        for( int i = 0; i < 8; i++ ){

            tmp += number[ dq[0][i] ][ dq[1][i] ];

        }

        if( tmp > sum ){

            sum = tmp;

        }

        return;

    }

    // 這個 i 是 y 因為 x 已由 q 決定 
    for( int i = 0; i < 8; i++ ){

        // 確認是否此為可放皇后
        if( check( q, i ) ){

            vis[q][i] = true;

            // 把 x y 座標分別放入 deque
            dq[0].push_back(q);
            dq[1].push_back(i);

            // 去算下一排的 q 的 y 會在哪
            dfs( q + 1 );

            // 找完回來要把剛找的那個點設為沒找過
            vis[q][i] = false;

            // 記得把 deque 裡放的點拿出來
            dq[0].pop_back();
            dq[1].pop_back();

        }

    }

}

int main(){
    
    int t;
    
    cin >> t;

    while( t-- ){

        memset( number, 0, sizeof(number) );
        memset( vis, false, sizeof(vis) );

        dq[0].clear();
        dq[1].clear();

        for( int i = 0; i < 8; i++ ){

            for( int j = 0; j < 8; j++ ){

                cin >> number[i][j];

            }

        }

        sum = 0;
        dfs( 0 );

        cout << setw(5) << sum << endl;

    }
}