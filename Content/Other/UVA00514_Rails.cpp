#include<bits/stdc++.h>
using namespace std;
// 2022.09.14

int main(){
    int n;
    while(cin >> n && n){
        int train;
        deque<int> dq;

        while(cin >> train && train){
            dq.emplace_back(train);

            deque<int> lis, ans;
            for(int i = 2; i <= n; ++i){
                cin >> train;
                dq.emplace_back(train);
            }

            for(int i = 1; i <= n; ++i){
                lis.emplace_back(i);
            }

            for(int i = 0, j = 0; j < n, i < n; ++i){

                if(lis[i] == dq[j]){
                    ++j;
                }
                else{
                    ans.emplace_back(lis[i]);
                }

                while(!ans.empty()){
                    if(dq[j] != ans.back()) break;

                    ans.pop_back();
                    ++j;
                }
            }

            if(!ans.empty()){
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }

            dq.clear();
        }
        cout << endl;
    }
}

/*

1 2 3 4 5
3 2 4 1 5

*/