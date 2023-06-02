#include<bits/stdc++.h>
using namespace std;
// 2022.02.16

#define inf 0x3f3f3f3f

struct Edge{
    int t;
    int w;
};

int m, n;
deque<Edge> G[1000+5];

bool SPFA(int s){
    int cnt[1000+5], dis[1000+5];
    bool inqueue[1000+5];
    queue<int> q;

    memset(cnt, 0, sizeof(cnt));
    memset(dis, inf, sizeof(dis));
    memset(inqueue, false, sizeof(inqueue));

    q.push(s);
    dis[s] = 0;
    inqueue[s] = true;
    cnt[s] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        inqueue[now] = false;

        for(auto &e : G[now]){
            if(dis[e.t] > dis[now] + e.w){
                dis[e.t] = dis[now] + e.w;
                if(!inqueue[e.t]){
                    cnt[e.t]++;
                    if(cnt[e.t] > m){
                        return false;
                    }
                    inqueue[e.t] = true;
                    q.push(e.t);
                }
            }
        }
    }
    return true;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int s, t, w;
        cin >> m >> n;

        for(int i = 0; i < n; i++){
            cin >> s >> t >> w;
            G[s].push_back({t, w});
            // G[t].push_back({s, w});
        }

        if(!SPFA(0)){
            cout << "possible" << endl;
        }
        else{
            cout << "not possible" << endl;
        }
        
        for(int i = 0; i <= m; i++){
            G[i].clear();
        }
    }
}