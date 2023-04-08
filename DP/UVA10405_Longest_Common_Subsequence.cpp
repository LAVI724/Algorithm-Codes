#include<bits/stdc++.h>
using namespace std;
// 2022.02.14

string str1, str2;
int dp[1000+5][1000+5];

int main(){
    while(getline(cin, str1)){
        getline(cin, str2);
        for(int i = 0; i < 1000+5; i++){
            memset(dp[i], 0, sizeof(dp[i]));  
        }

        for(int i = 1; i <= str1.size(); i++){
            for(int j = 1; j <= str2.size(); j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        cout << dp[str1.size()][str2.size()] << endl;
    }
}