#include<bits/stdc++.h>
using namespace std;
// 2022.05.26

/*
最小生成樹

用到觀念 :
kruskal
disjoint set
*/

struct Edge{
    int u;
    int v;
    int w;

    // 用權重排序 由小到大
    bool operator < (const Edge &other) const{
        return w < other.w;
    }
}edge[200000 + 5];

int n, m;
long long int total = 0;
int parent[100000 + 5];

// disjoint set
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

void init(){
    // 設所有人的父節點都是 -1
    for(int i = 0; i < n; i++){
        parent[i] = -1;
    }
	total = 0;
}

void kruskal(){
    init();

    sort(edge, edge + m);

    int i, j;
    for(i = 0, j = 0; j < m; j++){

        // 如果 u 和 v 的祖先相同, 則無視 (祖先相同代表會產生環 所以不要)
        if(find(edge[j].u) == find(edge[j].v)) continue;
        else{
            // 若部會產生環 則讓兩點之間產生橋 (連接兩顆子生成樹)
            unite(edge[j].u, edge[j].v);
            total += edge[j].w;
            i++;
        }
    }

    // 如果 i == n - 1 則為最小生成樹 ; 否則為最小生成樹林
    if(i == n - 1){
        cout << total << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(){

	while(cin >> n >> m){

        int u, v, w;
        for(int i = 0; i < m; i++){
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
        }

        kruskal();
    }
    return 0;
}