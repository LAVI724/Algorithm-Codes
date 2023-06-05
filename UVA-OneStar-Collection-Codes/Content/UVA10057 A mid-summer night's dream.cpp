#include<bits/stdc++.h>
using namespace std;
// 2022/02/10

int main(){
    int n;
    while(cin >> n){
        deque<int> dq;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            dq.push_back(num);
        }
        sort(dq.begin(), dq.end());

        int mid, mid2;
        int midnum = 1;
        if(n & 1){
            mid = dq[n/2];
        }
        else{
            mid = dq[n/2-1], mid2 = dq[n/2];
            midnum = mid2 - mid + 1;
        }

        int cnt = 0;
        deque<int>::iterator it;
        while(find(dq.begin(), dq.end(), mid) != dq.end()){
            it = find(dq.begin(), dq.end(), mid);
            dq.erase(it);
            cnt++;
        }

        if(!(n & 1)){
            while(find(dq.begin(), dq.end(), mid2) != dq.end()){
                it = find(dq.begin(), dq.end(), mid2);
                dq.erase(it);
                cnt++;
            }
        }

        cout << mid << " " << cnt << " " << midnum << endl;
    }
}