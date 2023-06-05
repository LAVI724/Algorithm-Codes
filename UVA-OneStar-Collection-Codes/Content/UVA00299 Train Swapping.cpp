#include<bits/stdc++.h>
using namespace std;
// 2022/02/10

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        deque<int> dq;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            dq.emplace_back(num);
        }

        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(dq[j] < dq[i]){
                    swap(dq[j], dq[i]);
                    cnt++;
                }
            }
        }

        cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
    }
}