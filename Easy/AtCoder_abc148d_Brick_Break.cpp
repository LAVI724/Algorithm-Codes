#include<bits/stdc++.h>
using namespace std;
// 2022.06.25

int main(){
    int n;
    cin >> n;

    int num[200000+5] = {0};
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    int ans = 0;
    bool flag = false;
    for(int i = 1, j = 1; i <= n; i++){
        if(num[i] != j){
            ans++;
        }
        else{
            j++;
            flag = true;
        }
    }

    if(flag){
        cout << ans << endl;    
    }
    else{
        cout << -1 << endl;
    }
}