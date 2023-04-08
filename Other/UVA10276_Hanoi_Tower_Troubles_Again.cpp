#include<bits/stdc++.h>
using namespace std;

deque<int> dq[50+5];
int ans[50+5];

void pegs(){
    int max = 0;
    for(int i = 1; ; i++){
        for(int j = 0; j <= 50; j++){
            
            if(j == 50){
                return;
            }
            else if(dq[j].empty()){
                dq[j].emplace_back(i);
                ans[j] = i;
                max = j;
                break;
            }
            else if(sqrt(dq[j].back() + i) == (int)(sqrt(dq[j].back() + i))){
                dq[j].emplace_back(i);
                ans[max] = i;
                break;
            }

        }
    }
}

int main(){
    int t, n;
    pegs();

    cin >> t;
    while(t--){
        cin >> n;

        cout << ans[n - 1] << endl;
    }
}