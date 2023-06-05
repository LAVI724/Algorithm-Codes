#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N,M;
    int i, j;
    cin>>N>>M;
    vector<int> v[10+5];
    for(i=0; i<=N; i++){
        v[i].clear();
    }
    for(i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(i=1; i<=N; i++){
        sort(v[i].begin(), v[i].end());
    }
    for(i=1; i<=N; i++){
        cout<<i<<":";
        for(j=0; j<v[i].size(); j++){
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}