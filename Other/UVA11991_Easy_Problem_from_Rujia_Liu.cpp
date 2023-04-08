#include<bits/stdc++.h>
using namespace std;
// 2022.06.11

vector<int> a[1000000+5];

int main(){
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i < 1000000+5; i++){
            a[i].clear();
        }
        
        int num;
        for(int i = 0; i < n; i++){
            cin >> num;
            a[num].emplace_back(i+1);
        }

        int k, v;
        while(m--){
            cin >> k >> v;

            if(a[v].size() < k){
                cout << 0 << endl;    
            }
            else{
                cout << a[v][k-1] << endl;
            }
        }
    }
}