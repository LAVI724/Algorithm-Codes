#include<bits/stdc++.h>
using namespace std;
// 2022.05.26

/*
解題思維 : 
形成最大生成樹後
沒有在樹上的邊即為放攝影機的位址 (權重最小)

用到觀念 :
kruskal
disjoint set
*/

const int maxn = 100000 + 5;

struct Edge{
    int u;
    int v;
    int w;

    // 用權重排序 由大大小
    bool operator < (const Edge &other) const{
        return w > other.w;
    }
}edge[maxn];

int n, m;
int total = 0;
int parent[maxn];

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
    for(i = 0, j = 0; i < n - 1 && j < m; i++){
        // 如果 u 和 v 的祖先相同, 則 j++ (祖先相同代表會產生環 所以不要)
        while(find(edge[j].u) == find(edge[j].v)) j++;

        // 若不會產生環 則讓兩點之間產生橋 (連接兩顆子生成樹)
        unite(edge[j].u, edge[j].v);
		total += edge[j].w;
        j++;
    }
}

int main(){
	int t;
	while(cin >> t && t){
		while(t--){
			cin >> n >> m;

			memset(parent, -1, sizeof(parent));

			int u, v, w;
			int sum = 0;
			for(int i = 0; i < m; i++){
				cin >> edge[i].u >> edge[i].v >> edge[i].w;
				sum += edge[i].w;
			}

			kruskal();
			cout << sum - total << endl;
		}
	}
}