#include<iostream>
#include<vector>
using namespace std;

vector<int> v[10+5];
int vis[10+5];
void dfs(int k){
    vis[k]=1;
    for(auto a : v[k]){
        if(!vis[a]){
            dfs(a);
        }
    }
}
int main(){
    int N, M;
    int i;
    cin >> N >> M;
    for(i=1; i<=N; i++){
        v[i].clear();
        vis[i]=0;
    }
    int a, b;
    for(i=0; i<M; i++){
        cin>> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    int ans = 0;
    for(i=1; i<=N; i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout<< ans << endl;
    return 0;
}