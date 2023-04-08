#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        
        bool flag = false;
        int cnt = 0;
        int G[10000+5];
        for(int i = 0; i < n; i++){
            cin >> G[i];
            cnt += G[i];
        }

        if(cnt & 1){
            flag = true;
        }

        for(int i = 0; i < n; i++){

            if(G[i] >= n - i){
                flag = true;
                break;
            }
            sort(G + i, G + n, greater<int>());

            int now = G[i];
            for(int j = 0; j < now; j++){
                G[i + j + 1]--;
                if(G[i + j + 1] < 0){
                    flag = true;
                    break;
                }
            }
        }

        if(!flag){
            cout << "Possible\n";
        }
        else{
            cout << "Not possible\n";
        }
    }
}