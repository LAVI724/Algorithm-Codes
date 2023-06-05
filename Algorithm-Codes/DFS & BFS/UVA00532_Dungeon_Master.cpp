#include<bits/stdc++.h>
using namespace std;
// 2022.05.09

int l, r, c;
int ansec;

// 三維陣列存這個 3D 地牢
char dungeon[50][50][50];
bool visited[50][50][50];

// 步數
int step_x[6] = {1, 0, -1, 0, 0, 0};
int step_y[6] = {0, 1, 0, -1, 0, 0};
int step_z[6] = {0, 0, 0, 0, 1, -1};

struct Edge{
    int x, y, z;
    int sec;
}start, ended, edge[10000], now, nxt;

void BFS(){
    queue<Edge> queue;
    queue.push(start);

    while(!queue.empty()){

        // 從 queue 中拿出一個點實作
        now = queue.front();
        queue.pop();

        // 確認結束狀態
        if(now.x == ended.x && now.y == ended.y && now.z == ended.z){
            ansec = now.sec;
            return;
        }

        // 遍歷各個方位，因為有 6 個方位，迴圈跑 6 次
        for(int j = 0; j < 6; j++){
            nxt.x = now.x + step_x[j];
            nxt.y = now.y + step_y[j];
            nxt.z = now.z + step_z[j];

            // 確認是否出界
            if(nxt.x < 0 || nxt.x >= r || nxt.y < 0 || nxt.y >= c || nxt.z < 0 || nxt.z >= l){
                continue;
            }

            // 確認此格未拜訪過，且不是石頭才可以走
            if(!visited[nxt.z][nxt.x][nxt.y] && dungeon[nxt.z][nxt.x][nxt.y] != '#'){
                
                // 先更新資訊
                visited[nxt.z][nxt.x][nxt.y] = true;
                nxt.sec = now.sec + 1;
                queue.push(nxt);
            }
        }
    }
}

int main(){

    while(cin >> l >> r >> c && l && r && c){

        memset(dungeon, '#', sizeof(dungeon));
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> dungeon[i][j][k];

                    if(dungeon[i][j][k] == 'S'){
                        start.x = j;
                        start.y = k;
                        start.z = i;
                    }
                    else if(dungeon[i][j][k] == 'E'){
                        ended.x = j;
                        ended.y = k;
                        ended.z = i;
                    }
                }
            }
        }

        // 初始化 ansec
        ansec = -1;
        BFS();

        // 如果 BFS 回來後 ansec 仍為初始化的值，即代表未到終點更新過
        if(ansec == -1){
            cout << "Trapped!" << endl;
        }
        else{
            cout << "Escaped in " << ansec << " minute(s)." << endl;
        }
    }
}