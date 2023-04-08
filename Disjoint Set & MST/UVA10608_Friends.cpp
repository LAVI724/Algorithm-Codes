#include<bits/stdc++.h>
using namespace std;

int n, m;
int a, b;

int parent[30000+5];

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
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;

		memset(parent, -1, sizeof(parent));

		for(int i = 0; i < m; i++){
			cin >> a >> b;
			unite(a, b);
		}

		int maxi = 0;
		for(int i = 1; i <= n; i++){
			if(parent[i] < 0){
				maxi = max(maxi, abs(parent[i]));
			}
		}

		cout << maxi << endl;
	}
}