#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<unsigned long long int, vector<unsigned long long int>, greater<unsigned long long int>> pq;
    map<unsigned long long int, bool> mp;
    pq.push(1);
    mp[1] = true;

    int cnt = 0;
    while(true){
        cnt++;
        if(cnt == 1500) break;

        int top = pq.top();
        pq.pop();
        if(!mp[top*2]){
            pq.push(top*2);
            mp[top*2] = true;
        }

        if(!mp[top*3]){
            pq.push(top*3);
            mp[top*3] = true;
        }

        if(!mp[top*5]){
            pq.push(top*5);
            mp[top*5] = true;
        }
    }

    cout << "The 1500'th ugly number is " << pq.top() << "." << endl;
}