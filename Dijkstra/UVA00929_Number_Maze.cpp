#include<bits/stdc++.h>
using namespace std;
// 2022.05.25

const int inf = 1e9;
const int maxn = 1000 + 5;

struct Item{
    int x;
    int y;
    int dis;

    bool operator < (const Item &other) const{
        return dis > other.dis;
    }
};

int n, m;
int maze[maxn][maxn], dis[maxn][maxn];

int step_x[4] = {1, 0, -1, 0};
int step_y[4] = {0, 1, 0, -1};

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dijkstra(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dis[i][j] = inf;
        }
    }

    dis[0][0] = maze[0][0];

    priority_queue<Item> pq;
    pq.push({0, 0, dis[0][0]});

    while(!pq.empty()){

        Item now = pq.top();
        pq.pop();

        if(now.dis > dis[now.x][now.y]){
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nx = now.x + step_x[i];
            int ny = now.y + step_y[i];

            if(!check(nx, ny)){
                continue;
            }

            if(dis[nx][ny] > now.dis + maze[nx][ny]){
                dis[nx][ny] = now.dis + maze[nx][ny];
                pq.push({nx, ny, dis[nx][ny]});
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> maze[i][j];
            }
        }

        dijkstra();
        cout << dis[n - 1][m - 1] << endl;
    }
}