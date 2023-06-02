#include<bits/stdc++.h>
using namespace std;
// 2022.07.15

int m, n;
const int inf = 1e9;
const int maxn = 10000000+5;

struct Edge{
    int v;
    int w;
};

struct Item{
    int u;
    int dis;

    // 取路徑最短
    bool operator < (const Item &other) const{
        return dis > other.dis;
    }
};

int dis[maxn];
vector<Edge> G[maxn];

void dijkstra(int s){
    for(int i = 0; i <= m; i++){
        dis[i] = inf;
    }
    dis[s] = 0;

    priority_queue<Item> pq;
    pq.push({s, 0});

    while(!pq.empty()){
        
        // 取路徑最短的點
        Item now = pq.top();
        pq.pop();

        if(now.dis > dis[now.u]){
            continue;
        }
      
        // 鬆弛 更新
        // 把與 now.u 相連的點都跑一遍
        for(Edge e : G[now.u]){
            if(dis[e.v] > now.dis + e.w){
                dis[e.v] = now.dis + e.w;
                pq.push({e.v, dis[e.v]});
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i <= m; i++){
        G[i].clear();
    }

    int s, t, w;
    for(int i = 0; i < n; i++){
        cin >> s >> t >> w;
        // 無向圖
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }

    dijkstra(1);

    for(int i = 2; i <= m; ++i){
        cout << dis[i] << endl;
    }
}