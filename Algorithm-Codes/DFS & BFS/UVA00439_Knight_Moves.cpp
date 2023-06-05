#include<bits/stdc++.h>
using namespace std;
// 2023.02.14

/*
解題觀念
BFS
乖乖用 queue 來 BFS 了
*/

struct Node{
    int row;
    int col;
    int step;
};

int stepRow[] = {1, 2, 2, 1, -1, -2, -2, -1};
int stepCol[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
    string startX, endY;
    while(cin >> startX >> endY){
        bool visited[8+5][8+5];
        memset(visited, false, sizeof(visited));

        queue<Node> q;
        q.push({startX[1] - '1', startX[0] - 'a', 0});
        visited[startX[1] - '1'][startX[0] - 'a'] = true;
        
        // BFS
        while(!q.empty()){
            int nowRow = q.front().row;
            int nowCol = q.front().col;
            int nowStep = q.front().step;
            if(nowRow == endY[1] - '1' && nowCol == endY[0] - 'a'){
                cout << "To get from " << startX << " to " << endY << " takes " << nowStep << " knight moves." << endl;
                break;
            }
            q.pop();

            for(int i = 0; i < 8; ++i){
                int nextRow = nowRow + stepRow[i];
                int nextCol = nowCol + stepCol[i];

                if(visited[nextRow][nextCol] || nextCol < 0 || nextRow < 0 || nextCol >= 8 || nextRow >= 8) continue;
                q.push({nextRow, nextCol, nowStep + 1});
                visited[nextRow][nextCol] = true;
            }
        }
    }
}