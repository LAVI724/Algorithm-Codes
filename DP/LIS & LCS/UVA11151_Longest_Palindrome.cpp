#include<bits/stdc++.h>
using namespace std;
// 2022.06.27 with 阿鼠

/*
解題觀念:
LCS
*/

int LCS(string s1, string s2) {

    int n1 = s1.size(), n2 = s2.size();
    int dp[n1+1][n2+1];
    memset(dp, 0, sizeof(dp));

    // dp[i][j] = s1的前i個字元和s2的前j個字元
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n1][n2];
}

int main(){

    int t;
    string a, b;

    cin >> t;
    cin.ignore();

    while(t--){

        getline(cin, a);

        b = a;
        reverse(b.begin(), b.end());

        cout << LCS(a, b) << "\n"; 
    }

    return 0;
}