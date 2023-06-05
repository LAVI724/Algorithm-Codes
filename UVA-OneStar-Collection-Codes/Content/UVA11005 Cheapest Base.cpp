#include<bits/stdc++.h>
using namespace std;
// 2022/01/28

bool sort_map(const int a, const int b){
    return a > b;
}

int main(){
    int t, cases = 1;
    bool flag = false;
    cin >> t;

    while(t--){
        if(flag){
            cout << endl;
        }
        cout << "Case " << cases++ << ":" << endl;
        map<int, int> mp;
        for(int i = 0; i < 36; i++){
            cin >> mp[i];
        }

        int ca;
        cin >> ca;
        while(ca--){
            int x;
            int mini = 0x7fffffff;
            cin >> x;

            map<int, int> cost;
            for(int i = 2; i <= 36; i++){
                int tmp = x;
                cost.emplace(i, 0);
                while(tmp){
                    cost[i] += mp[tmp%i];
                    tmp /= i;
                }
                mini = min(cost[i], mini);
            }

            cout << "Cheapest base(s) for number " << x << ":";
            for(int i = 2; i <= 36; i++){
                if(cost[i] == mini){
                    cout << " " << i;
                }
            }
            cout << endl;
            flag = true;
        }
    }
}