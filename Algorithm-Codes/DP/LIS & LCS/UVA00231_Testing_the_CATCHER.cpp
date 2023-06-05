#include<bits/stdc++.h>
using namespace std;
// 2022.10.15

/*
解題觀念:
LDS 把 LIS 倒過來做
換了另一種 LIS 的寫法，可以判斷非嚴格遞增
*/

int LIS(vector<int> &a){
    int len[a.size()];
    for(int i = 0; i < a.size(); ++i) len[i] = 1;
    
    int maxi = -1;
    for(int i = 0; i < a.size(); ++i){
        for(int j = i + 1; j < a.size(); ++j){
            if(a[i] <= a[j]) len[j] = max(len[j], len[i] + 1);
        }
    }
    for(int i = 0; i < a.size(); ++i){
        maxi = max(maxi, len[i]);
    }
    return maxi;
}

int main(){
    bool space = false;
    int n, ca = 1;
    vector<int> a;
    while(cin >> n){
        if(n < 0 && a.empty()) break;

        if(n < 0){
            if(space) cout << endl;
            space = true;
            reverse(a.begin(), a.end());

            cout << "Test #" << ca++ << ":" << endl;
            cout << "  maximum possible interceptions: " << LIS(a) << endl;
            a.clear();
        }
        else a.push_back(n);
    }
}