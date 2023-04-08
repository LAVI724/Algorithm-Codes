#include<bits/stdc++.h>
using namespace std;
// 2022.06.16

int main(){
    int n, k;
    cin >> n >> k;

    int d, a;
    string str;
    vector<int> v[n+5];
    for(int i = 0; i < k; i++){
        cin >> d;

        for(int j = 0; j < d; j++){
            cin >> a;
            v[a].emplace_back(i+1);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(v[i].empty()){
            ans++;
        }
    }
    cout << ans << endl;
}