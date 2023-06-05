#include<bits/stdc++.h>
using namespace std;
// 2022.03.25

int main(){
    int t;
    int ca = 1;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int lader[n+5] = {0};
        for(int i = 1; i <= n; i++){
            cin >> lader[i];
        }

        int maxi = 0;
        int dis[n+5];
        for(int i = 1; i <= n ; i++){
            dis[i-1] = lader[i] - lader[i-1];
            maxi = max(maxi, dis[i-1]);
        }

        int k = maxi;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(maxi == dis[i]){
                maxi -= 1;
            }
            else if(maxi < dis[i]){
                flag = true;
                break;
            }
        }

        cout << "Case " << ca++ << ": ";
        if(flag){
            cout << k + 1 << endl;
        }
        else{
            cout << k << endl;
        }
    }
}