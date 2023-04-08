#include<bits/stdc++.h>
using namespace std;
// 2022.06.25

int main(){
    long long int n;
    cin >> n;

    map<long long int, long long int> mp;
    long long int num, ans = 0;
    for(long long int i = 0; i < n; i++){
        cin >> num;
        mp[num]++;
        ans += num;
    }

    long long int q, b, c;
    cin >> q;
    for(long long int i = 0; i < q; i++){
        cin >> b >> c;

        if(mp[b] != 0){
            ans -= (b * mp[b]);
            ans += (c * mp[b]);

            mp[c] += mp[b];
            mp[b] = 0;
        }

        cout << ans << endl;
    }
}