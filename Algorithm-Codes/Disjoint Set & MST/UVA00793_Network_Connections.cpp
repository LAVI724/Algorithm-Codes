#include<bits/stdc++.h>
using namespace std;
// 2022.07.09 by LAVI

/*
解題觀念:
disjoint set
*/

const int maxn = 1000+5;

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
		parent[a] = b;
	}
}

void init(){
    // 設所有人的父節點都是 -1
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
}

int main(){
    int t;
    bool space = false;
    cin >> t;
    while(t--){
        if(!space) space = true;
        else cout << endl;

        int N;
        cin >> N;

        memset(parent, -1, sizeof(parent));
        init();

        cin.ignore();
        string str;
        int yes = 0, no = 0;
        while(getline(cin, str) && str != ""){

            stringstream ss;
            ss << str;

            char inst;
            int cp1, cp2;
            ss >> inst >> cp1 >> cp2;

            if(inst == 'c'){
                unite(cp1, cp2);
            }
            else{
                if(find(cp1) == find(cp2)){
                    yes++;
                }
                else{
                    no++;
                }
            }
        }
        cout << yes << "," << no << endl;
    }
}