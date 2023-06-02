#include<bits/stdc++.h>
using namespace std;
// 2022.06.26

int main(){
    int n, k;
    cin >> n >> k;

    int num[n+5], dp[n+5][n+5];
    memset(num, 0, sizeof(num));

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num, num + n);

    int total = 0;
    for(int i = 0; i < k; i++){
        total += num[i];
    }
    cout << total << endl;
}