#include<bits/stdc++.h>
using namespace std;
// 2022.06.27

/*
解題觀念:
disjoint set
minimum spanning tree

很像經典的 racing 那題
*/

int parent[100000+5];

int find(int x){
    if(parent[x] < 0){
        return x;
    }
    else{
        return parent[x] = find(parent[x]);
    }
}
bool unite(int a, int b){
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
        return true;
    }
    return false;
}

int main(){
    
    int a, b;
    while(cin >> a){
        vector<pair<int, int>> v;
        
        cin >> b;
        v.push_back({a, b});

        memset(parent, -1, sizeof(parent));
        while(cin >> a && (a != -1)){
            cin >> b;
            v.push_back({a, b});
        }

        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
            if(!(unite(v[i].first, v[i].second))){
                cnt++;
            }
        }
        cout << cnt << endl; 
    }

    return 0;
}