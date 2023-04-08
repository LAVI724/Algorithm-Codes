#include<bits/stdc++.h>
using namespace std;
// 2022.06.28

/*
解題觀念:
bfs tree

解題思維:
在樹上玩鬼抓人，用 bfs 做兩次判斷步數
*/

# define maxn 100000+5

int u,  v;
int step_u[maxn], step_v[maxn];
bool visited[maxn];
vector<int> G[maxn];

void bfs_u(){
    queue<int> q;
    q.push(u);

    step_u[u] = 0;
    visited[u] = true;

    while(!q.empty()){
        int nx = q.front();
        q.pop();

        for(int i = 0; i < G[nx].size(); i++){
            if(!visited[G[nx][i]]){
                step_u[G[nx][i]] = step_u[nx] + 1;
                visited[G[nx][i]] = true;
                q.push(G[nx][i]);
            }
        }
    }
}

void bfs_v(){
    queue<int> q;
    q.push(v);

    step_v[v] = 0;
    visited[v] = true;

    while(!q.empty()){
        int nx = q.front();
        q.pop();

        for(int i = 0; i < G[nx].size(); i++){
            if(!visited[G[nx][i]]){
                step_v[G[nx][i]] = step_v[nx] + 1;
                visited[G[nx][i]] = true;
                q.push(G[nx][i]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    cin >> u >> v;

    memset(step_u, 0, sizeof(step_u));
    memset(step_v, 0, sizeof(step_v));
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    bfs_u();
    memset(visited, false, sizeof(visited));
    bfs_v();

    int ans = -1;
    for(int i = 1; i <= n; i++){
        if(step_u[i] < step_v[i]){
            ans = max(ans, step_v[i]);
        }
    }
    cout << ans-1 << endl;
}