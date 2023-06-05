#include<bits/stdc++.h>
using namespace std;
//2021.09.17

int n, m;

deque<int> root[1000+5];
bool check[1000+5];
int leaf[100+5];

bool dfs( int depth ){

    int size = root[ depth ].size();

    for( int i = 0; i < size; i++ ){

        leaf[ depth ] += dfs( root[ depth ][i] );
        
    }

    // 如果是根
    if( check[ depth ] ){
        return 0;
    }

    // 不是根
    else{
        return 1;
    }
}

int main(){
    
    cin >> n;

    int max = 1;

    memset( check, false, sizeof(check) );
    memset( leaf, 0, sizeof(leaf) );

    for( int i = 0; i <= n; i++ ){

        root[i].clear();

    }

    for( int i = 2; i <= n; i++ ){

        cin >> m;

        // m 是子根
        root[m].push_back(i);
        check[m] = true;

    }

    // 根必從 1 開始
    dfs(1);   
    
    bool flag = true;
    for( int i = 1; i <= n; i++ ){

        if( check[i] && leaf[i] < 3 ){
            
            cout << "No" << endl;
            flag = false;
            break;

        }

    }
    if( flag ){
        cout << "Yes" << endl;
    }

}