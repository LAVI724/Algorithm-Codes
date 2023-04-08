#include<bits/stdc++.h>
using namespace std;
// 2023.01.12 信宏 110-1/1103

const int maxn = 500+5;
struct Edge{
    int v, w;
};
vector<Edge> G[maxn];

int dist[maxn];
int passList[maxn]; // 用來記錄每個點從哪個點來
struct Item{
    int u, dis;
    bool operator < (const Item &rhs) const{
        return dis > rhs.dis;
    }
};

int N, S, E;
void dijkstra(int s){
    for(int i = 0; i <= N; ++i){
        dist[i] = 0x3f3f3f3f;
        passList[i] = i;
    }

    priority_queue<Item> pq;
    dist[s] = 0;
    pq.push({s, 0});

    while(!pq.empty()){
        Item now = pq.top();
        pq.pop();

        if(now.dis > dist[now.u]) continue;

        for(auto e: G[now.u]){
            if(dist[e.v] > now.dis + e.w){
                dist[e.v] = now.dis + e.w;
                passList[e.v] = now.u;
                pq.push({e.v, dist[e.v]});
            }
        }
    }
}

vector<int> passAns; // 紀錄最終輸出點的連接路徑
void dfs(int s){ 
    if(passList[s] != s) dfs(passList[s]);
    passAns.emplace_back(s);
}

int main(){
    bool space = false;
    while(cin >> N >> S >> E){
        for(int i = 0; i <= N; ++i){
            G[i].clear();
        }
        passAns.clear();
        
        if(space) cout << endl;
        space = true;

        int M;
        cin >> M;
        for(int i = 0; i < M; ++i){
            int x, y, z;
            cin >> x >> y >> z;
            G[x].push_back({y, z});
            G[y].push_back({x, z});
        }
        dijkstra(S);
        dfs(E);
        int mini = dist[E];

        int K, miniTicket;
        cin >> K;
        bool flag = false;
        for(int i = 0; i < K; ++i){
            int x, y, z;
            cin >> x >> y >> z;

            G[x].push_back({y, z});
            dijkstra(S);
            if(dist[E] < mini){
                mini = dist[E];
                miniTicket = x; 
                flag = true;

                passAns.clear();
                dfs(E);
            }
            G[x].pop_back();

            G[y].push_back({x, z});
            dijkstra(S);
            if(dist[E] < mini){
                mini = dist[E];
                miniTicket = y; 
                flag = true;

                passAns.clear();
                dfs(E);
            }
            G[y].pop_back();
        }

        for(int i = 0; i < passAns.size(); ++i) cout << (i == 0 ? "" : " ") << passAns[i];
        cout << endl;
        if(!flag) cout << "Ticket Not Used" << endl;
        else cout << miniTicket << endl;
        cout << mini << endl;
    }
}