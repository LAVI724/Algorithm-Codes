#include<bits/stdc++.h>
using namespace std;
// 2022.07.16

/*
解題觀念:
dijkstra 微變形

解題思維:
不用 vector 改用 map 紀錄點
*/

const int inf = 1e9;

struct Item{
    int u;
    int dis;

    bool operator < (const Item &other) const{
        return dis > other.dis;
    }
};

int nc, TTL, cnt, visited;
map<int, vector<int>> G;
map<int, int> dis;

void dijkstra(int s){
    for(auto i = G.begin(); i != G.end(); ++i){
        dis[i->first] = inf;
    }
    dis[s] = 0;
    visited++;

    priority_queue<Item> pq;
    pq.push({s, 0});

    while(!pq.empty()){
        Item now = pq.top();
        pq.pop();

        if(now.dis > dis[now.u]){
            continue;
        }
      
        for(auto e : G[now.u]){
            if(dis[e] > now.dis + 1){
                // visited 紀錄在 s 樹上有多少點
                visited++;

                // cnt 紀錄在 s 樹上有多少點超出 TTL
                dis[e] = now.dis + 1;
                if(dis[e] > TTL) cnt++;

                pq.push({e, dis[e]});
            }
        }
    }
}

int main(){
    int ca = 1;
    while(cin >> nc && nc){
        G.clear();

        int u, v;
        for(int i = 0; i < nc; i++){
            cin >> u >> v;
            
            // 無向圖
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int st;
        int nodecnt = G.size();
        while(cin >> st >> TTL && (st || TTL)){
            cnt = 0;
            visited = 0;
            if(G[st].empty()){
                cout << "Case " << ca++ << ": " << nodecnt << " nodes not reachable from node " << st << " with TTL = " << TTL << "." << endl;
            }
            else{
                dijkstra(st);
                cout << "Case " << ca++ << ": " << nodecnt - visited + cnt << " nodes not reachable from node " << st << " with TTL = " << TTL << "." << endl;
            }
        }
    }
}