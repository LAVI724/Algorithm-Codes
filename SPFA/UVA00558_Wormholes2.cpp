#include<bits/stdc++.h>
using namespace std;
// 2023.02.16 竟然跟去年同一天寫

const int maxn = 2000+5;
const int INF = 0x3f3f3f3f;

struct Edge{
    int v;
    int w;
};

int N, M;
vector<Edge> G[maxn];

bool SPFA(int S){
    int cnt[maxn]; // 記錄此點被更新過幾次
    int dist[maxn];

    bool inqueue[maxn];
    queue<int> q;

    memset(cnt, 0, sizeof(cnt));
    memset(dist, INF, sizeof(dist));
    memset(inqueue, false, sizeof(inqueue));

    // 推入起點
    q.push(S);
    dist[S] = 0;
    inqueue[S] = true;
    cnt[S] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        inqueue[now] = false;

        for(auto &e : G[now]){
            if(dist[e.v] > dist[now] + e.w){
                dist[e.v] = dist[now] + e.w;

                if(!inqueue[e.v]){
                    // 如果這個點被鬆弛過 N 次以上 代表存在負環
                    // 因為一個點最多跟 N-1 個點相連 最多更新 N-1 次
                    if(++cnt[e.v] >= N) return false;
                    
                    q.push(e.v);
                    inqueue[e.v] = true;
                }
            }
        }
    }
    return true;
}


int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> N >> M;
        for(int i = 0; i <= N; ++i) G[i].clear();
        
        int u, v, w;
        for(int i = 0; i < M; ++i){
            cin >> u >> v >> w;
            // 有向圖
            G[u].push_back({v, w});
        }

        if(!SPFA(0)) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
}