#include<bits/stdc++.h>
using namespace std;
// 2022.03.14

int main(){
    std::ios::sync_with_stdio(false);
    int t, n;
    while(cin >> t && t){
        int num[1000+5];
        unordered_set<int> st;
        for(int i = 0; i < t; ++i){
            cin >> num[i];
            st.insert(num[i]);
        }

        bool flag = false;
        sort(num, num + t, greater<int>());
        for(int i = 0; i < t && !flag; ++i){
            int d = num[i];
            for(int j = 0; j < t && !flag; ++j){
                if(j == i) continue;
                int c = num[j];
                for(int k = 0; k < t && !flag; ++k){
                    if(k == i || k == j) continue;
                    int b = num[k];
                    int a = d - c - b;
                    if(st.count(a) && a != b && a != c && a != d){
                        cout << d << endl;
                        flag = true;
                    }
                }
            }
        }

        if(!flag){
            cout << "no solution" << endl;
        }
    }
}