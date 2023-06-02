#include<bits/stdc++.h>
using namespace std;
// 2022.05.30

/*
解題觀念:
建質數表
*/

bool prime[1000000+5];
vector<int> pri;

void primelist(){
    memset(prime, false, sizeof(prime));

    for(int i = 2; i <= 1000000+5; i++){
        if(!prime[i]){
            pri.emplace_back(i);
            // 這邊寫的不夠漂亮 應該要 i * i 但是因為會爆所以就這樣寫了
            for(long long int j = i; j < 1000000 + 5; j += i){
                prime[j] = true;
            }
        }
    }
}

int main(){
    int n;
    primelist();
    while(cin >> n && n){
        int cnt = 0;
        for(int i = 0; i < pri.size() && pri[i] <= n; i++){
            if(n % pri[i] == 0){
                cnt++;
            }
        }
        cout << n << " : " << cnt << endl;
    }
}