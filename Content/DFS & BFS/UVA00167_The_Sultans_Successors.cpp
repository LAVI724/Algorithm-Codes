#include<bits/stdc++.h>
using namespace std;
// 2023.02.14

/*
解題觀念
DFS
八皇后變體
*/

vector<int> v; // 用來放 queen 的位址

bool check(int row, int col){
    for(int i = 0; i < row; ++i){
        if(v[i] == col) return false;

        // 是否在同一斜排上
        if(abs(row - i) == abs(v[i] - col)) return false;
    }
    return true;
}

int ansSum = 0;
int value[8+5][8+5]; 
bool visited[8+5][8+5];
void dfs(int queen){
    if(v.size() == 8){
        int tmpSum = 0;
        for(int i = 0; i < 8; ++i){
            tmpSum += value[i][v[i]];
        }

        if(tmpSum > ansSum) ansSum = tmpSum;
        return;
    }

    // 因為每 row 必至少有一皇后 所以直接每 col 去 dfs 皇后要放哪就好
    for(int col = 0; col < 8; ++col){
        if(check(queen, col)){
            visited[queen][col] = true;

            v.push_back(col);
            dfs(queen + 1);

            visited[queen][col] = false;
            v.pop_back();
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        
        memset(value, 0, sizeof(value));
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                cin >> value[i][j];
            }
        }

        ansSum = 0;
        dfs(0);

        cout << setw(5) << ansSum << endl;
    }
}