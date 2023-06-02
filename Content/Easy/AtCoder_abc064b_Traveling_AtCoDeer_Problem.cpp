#include<bits/stdc++.h>
using namespace std;
// 2022.06.01

int main(){
    int n;
    deque<int> dq;

    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        dq.emplace_back(num);
    }
    sort(dq.begin(), dq.end());

    int dis;
    dis = dq[dq.size()-1] - dq[0];
    cout << dis << endl;
}