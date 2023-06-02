#include<bits/stdc++.h>
using namespace std;
// 2022.06.01

int main(){
    int t;
    cin >> t;
    while(t--){
        string str1, str2;
        cin >> str1 >> str2;

        int total = 0;
        deque<int> dq;
        for(int i = 0; i < str2.size(); i++){
            for(int j = 0; j < str1.size(); j++){
                if(str1[j] == str2[i]){
                    dq.emplace_back(j+1);
                    break;
                }
            }
        }

        for(int i = 1; i < dq.size(); i++){
            total += abs(dq[i] - dq[i-1]);
        }

        cout << total << endl;
    }
}