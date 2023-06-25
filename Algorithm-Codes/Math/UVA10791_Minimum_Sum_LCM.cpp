# include<bits/stdc++.h>
using namespace std;
// 2023.06.25 PUPC 模擬賽 2
/*
Math
質因數、規律查找
*/


int main(){
    int Case = 1;
    long long int N;
    while(cin >> N && N){
        long long int tmp = N, ans = 0;

        if(N == 1){
            ans = 1;
        }

        int cnt = 0, degree = 1;
        for(long long int i = 2; i * i <= tmp; ++i){
            if(tmp % i == 0){
                cnt++;
                degree = 1;
                while(tmp % i == 0){
                    degree *= i;
                    tmp /= i;
                }
                ans += degree;
            }
        }

        if(tmp > 1){
            cnt++;
            ans += tmp;
        }

        if(cnt < 2){
            ans++;
        }

        cout << "Case " << Case++ << ": " << ans << endl;
    }
}