#include<bits/stdc++.h>
using namespace std;
// 2022.09.24

int main(){
    int n;
    while(cin >> n && n){
        deque<int> dq;

        for(int i = 1; i <= n; ++i){
            dq.emplace_back(i);
        }

        cout << "Discarded cards:";
        while(dq.size() > 2){
            cout << " " << dq.front() << ",";
            dq.pop_front();

            dq.emplace_back(dq.front());
            dq.pop_front();
        }

        if(n != 1) cout << " " << dq.front();
        cout << endl;

        cout << "Remaining card: " << dq.back() << endl;
    }
}