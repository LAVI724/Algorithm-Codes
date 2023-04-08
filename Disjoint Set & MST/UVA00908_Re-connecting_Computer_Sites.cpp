#include<bits/stdc++.h>
using namespace std;
// 2023.02.16

/*
Disjoint Set
MST - Kruskal
*/

const int maxn = 1000000+5;

struct Edge{
    int u;
    int v;
    int w;

    bool operator < (const Edge &rhs) const{
        return w < rhs.w;
    }
};

int N, M;
int total = 0; // 紀錄最小生成樹的權重總和
int parent[maxn];
vector<Edge> edge;

// disjoint set
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(parent[a] < parent[b]){
            parent[a] += parent[b];
            parent[b] = a;
        }
        else{
            parent[b] += parent[a];
            parent[a] = b;
        }
    }
}

void kruskal(){
    // 先讓所有人父節點都是 -1 (沒有父親)
    memset(parent, -1, sizeof(parent));
    sort(edge.begin(), edge.end());

    int i, j;
    total = 0;
    // i < N-1 因為一顆樹最多只會有 N (點的數量) -1 條邊
    // j < M (M 是目前測資給予的邊的總數量 可能會有重邊 所以可能不只 N-1 條邊)
    for(i = 0, j = 0; i < N-1 && j < M; ++i){
        // 如果 u 和 v 的祖先相同 則 ++j (祖先相同會產生環 所以不要建立邊)
        while(find(edge[j].u) == find(edge[j].v)) ++j;

        // 若不會產生環 則讓兩點之間產生橋 (連接兩顆子生成樹)
        Union(edge[j].u, edge[j].v);
        total += edge[j].w;
        ++j;
    }
}

int main(){
    bool space = false;
    while(cin >> N){
        if(space) cout << endl;
        space = true;

        int u, v, w;
        total = 0;
        for(int i = 0; i < N-1; ++i){
            cin >> u >> v >> w;
            total += w;
        }
        cout << total << endl;

        int K;
        cin >> K;
        for(int i = 0; i < K; ++i){
            cin >> u >> v >> w;
            edge.push_back({u, v, w});
        }
        
        cin >> M;
        for(int i = 0; i < M; ++i){
            cin >> u >> v >> w;
            edge.push_back({u, v, w});
        }

        M = K + M;
        kruskal();

        cout << total << endl;
        while(!edge.empty()) edge.pop_back();
    }

}