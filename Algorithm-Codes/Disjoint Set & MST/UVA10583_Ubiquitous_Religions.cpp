#include<bits/stdc++.h>
using namespace std;
// 2022.05.26

const int maxn = 50000 + 5;

int n, m;
int a, b;

int parent[maxn];

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

int main(){

    int ca = 1;
	while(cin >> n >> m && (n || m)){

		memset(parent, -1, sizeof(parent));

		for(int i = 0; i < m; i++){
			cin >> a >> b;
			unite(a, b);
		}

		int sum = 0;
		for(int i = 1; i <= n; i++){
			if(parent[i] < 0){
				sum++;
			}
		}

		cout << "Case " << ca++ << ": " << sum<< endl;
	}
}