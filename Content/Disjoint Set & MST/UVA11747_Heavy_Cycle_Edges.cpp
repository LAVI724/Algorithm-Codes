#include<bits/stdc++.h>
using namespace std;
// 2022.07.07 by LAVI

/*
解題觀念:
disjoint set
MST - kruskal
*/

const int maxn = 25000 + 5;

struct Edge{
    int u, v, w;

    bool operator < (const Edge &other) const{
        return w < other.w;
    }
};

int n, m;
int parent[maxn];
vector<Edge> edge;

int find(int x){
	if(parent[x] < 0){
		return x;
	}
	else{
		return parent[x] = find(parent[x]);
	}
}

void unite(int a, int b){
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
    for(int i = 0; i < n; i++){
        parent[i] = -1;
    }
    sort(edge.begin(), edge.end());

    bool flag = false;
    for(int i = 0; i < m; i++){

        // 如果 u 和 v 的祖先相同, 則 j++ (祖先相同代表會產生環 所以不要)
        if(find(edge[i].u) == find(edge[i].v)) {
            if(!flag) flag = true;
            else cout << " ";

            cout << edge[i].w;
        }

        // 若不會產生環 則讓兩點之間產生橋 (連接兩顆子生成樹)
        unite(edge[i].u, edge[i].v);
    }

    if(!flag){
        cout << "forest";
    }
    cout << endl;
}

int main(){
	while(cin >> n >> m && (n || m)){
        memset(parent, -1, sizeof(parent));
        edge.clear();

        int u, v, w;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            edge.push_back({u, v, w});
        }

        kruskal();
    }
}