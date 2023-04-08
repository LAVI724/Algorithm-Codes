#include<bits/stdc++.h>
using namespace std;
// 2022.07.07 by LAVI

/*
解題觀念:
disjoint set
*/

map<string, string> parent;
map<string, int> cnt;

string find(string x){
    if(parent[x] == ""){
        return x;
    }
    else{
        return parent[x] = find(parent[x]);
    }
}

int unite(string name1, string name2){
    name1 = find(name1);
    name2 = find(name2);

    if(name1 != name2){
        cnt[name1] += cnt[name2] + 1;
        parent[name2] = name1;

        return cnt[name1] + 1;
    }

    return cnt[name1] + 1;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int F;
        cin >> F;

        parent.clear();
        cnt.clear();

        string name1, name2;
        for(int i = 0; i < F; i++){
            cin >> name1 >> name2;
            cout << unite(name1, name2) << endl;
        }
    }
}