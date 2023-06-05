#include<bits/stdc++.h>
using namespace std;
// 2022.05.10

int node, ans;
int arr[9+5][9+5];
bool sql[9][10], row[9][10], col[9][10];

bool check(){
	memset(sql, false, sizeof(sql));
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(arr[i][j] != 0){
                if(sql[3 * (i / 3) + (j / 3)][arr[i][j]] || row[i][arr[i][j]] || col[j][arr[i][j]]){
                    return false;
                }
                else{
                    // sql[3 * (i / 3) + (j / 3)][arr[i][j]] 神奇魔法，把每九宮格的數字放置成一整 row
                    sql[3 * (i / 3) + (j / 3)][arr[i][j]] = true;
                    row[i][arr[i][j]] = true;
                    col[j][arr[i][j]] = true;
                }
            }
        }
    }
    return true;
}

void dfs(int depth, deque<pair<int, int>> nxt){

    // 把所有的空格都遍歷過了
    if(depth == node){
        ans++;
        return;
    }

    int i = nxt[depth].first, j = nxt[depth].second;
    for(int k = 1; k <= 9; k++){

        // 確認該數字是否在同 3 * 3 正方格、同 row、同 col
        if(sql[3 * (i / 3) + (j / 3)][k] || row[i][k] || col[j][k]){
            continue;
        }

        // [3 * (i / 3) + (j / 3)] 是他所在的 3 * 3 正方格，k 是 1 ~ 9 的數字
        // 現在是直接把 1 ~ 9 都搜過
        sql[3 * (i / 3) + (j / 3)][k] = true;
        row[i][k] = true;
        col[j][k] = true;

        dfs(depth + 1, nxt);

        sql[3 * (i / 3) + (j / 3)][k] = false;
        row[i][k] = false;
        col[j][k] = false;
    }
    return;
}

int main(){

    int ca = 1;
    while(cin >> arr[0][0]){

        ans = 0;
    	node = 0;
    	deque<pair<int, int>> nxt;	
    	for(int i = 0; i < 9; i++){
    		for(int j = 0; j < 9; j++){
                if(i == 0 && j == 0) continue;

    			cin >> arr[i][j];
    			if(arr[i][j] == 0){
    				nxt.push_back(make_pair(i, j));
    				node++;
    			}
    		}
    	}

        cout << "Case " << ca++;
    	if(!check()){
            cout << ": Illegal." << endl;
    	}
    	else{
            dfs(0, nxt);

            if(ans == 1){
                cout << ": Unique." << endl;
            }
            else if(ans > 1){
                cout << ": Ambiguous." << endl;
            }
            else{
                cout << ": Impossible." << endl;
            }
    	}
    }
}