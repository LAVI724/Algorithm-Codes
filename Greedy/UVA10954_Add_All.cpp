#include<bits/stdc++.h>
using namespace std;
// 2022.03.14

int main(){
    int n;
    while(cin >> n && n){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            pq.push(num);
        }

        int ans = 0;
        while(pq.size() != 1){
            int cnt = 0;
            cnt = pq.top();
            pq.pop();

            cnt += pq.top();
            pq.pop();

            ans += cnt;
            pq.push(cnt);
        }

        cout << ans << endl;
    }
    
}