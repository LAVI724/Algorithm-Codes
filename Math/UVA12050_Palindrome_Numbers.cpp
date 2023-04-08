#include<bits/stdc++.h>
using namespace std;
// 2023.01.11 信宏 110-1/1027

const long long int maxn = 2 * 1e9 + 5; 

int main(){
    long long int totalSum = 9;
    vector<long long int> palindromeSum;
    palindromeSum.emplace_back(0); 
    for(long long int digit = 1; totalSum < maxn; ++digit){
        palindromeSum.emplace_back(palindromeSum[digit-1] + totalSum);
        if(digit % 2 == 0) totalSum *= 10;
    }
    // for(int i = 0; i < palindromeSum.size(); ++i){
    //     cout << palindromeSum[i] << endl;
    // }
    
    int n;
    while(cin >> n && n){
        int k = lower_bound(palindromeSum.begin(), palindromeSum.end(), n) - palindromeSum.begin();
        int cnt = n - palindromeSum[k-1];
        // cout << "k: " << k << " cnt: " << cnt << endl;
        
        cnt--;
        int ans[k*2+5];
        memset(ans, 0, sizeof(ans));
        int len = k/2 + 1;
        for(int i = len; i <= k; ++i){
            ans[i] = cnt % 10;
            cnt /= 10;
        }
        ans[k]++;
        for(int i = 1; i < len; ++i){
            ans[i] = ans[k - i + 1];
        }

        for(int i = 1; i <= k; ++i){
            cout << ans[i];
        }
        cout << endl;
    }
}