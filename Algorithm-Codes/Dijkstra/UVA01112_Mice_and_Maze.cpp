#include<bits/stdc++.h>
using namespace std;
// 2022.05.25

int n, ed, ti, m;
const int inf = 1e9;
const int maxn = 100 + 5;

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
    for(int i = 0; i <= n; i++){
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
    int t;
    cin >> t;
    while(t--){
        cin >> n >> ed >> ti >> m;
        for(int i = 0; i <= n; i++){
            G[i].clear();
        }

        int u, v, w;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            // 有向圖
            G[v].push_back({u, w});
        }

        dijkstra(ed);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dis[i] <= ti){
                ans++;
            }
        }

        cout << ans << endl;
        if(t) cout << endl;
    }
}