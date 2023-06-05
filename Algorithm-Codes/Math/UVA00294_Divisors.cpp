#include<bits/stdc++.h>
using namespace std;
// 2022.06.03

/*
解題思維:
質因數分解
排列組合
一個數的質因數分解可以這樣算:
EX: 360 = 2^3 * 3^2 * 5
因數個數共有 (3+1)*(2+1)*(1+1) 個

解題觀念:
質數表
*/

bool prime[100000+5];
vector<int> pri;

void primelist(){
    memset(prime, false, sizeof(prime));

    // 需要算質因數分解的質數不會超過 sqrt(1000000000)
    for(int i = 2; i <= sqrt(1000000000); i++){
        if(!prime[i]){
            pri.emplace_back(i);
            for(long long int j = i * i; j <= sqrt(1000000000); j += i){
                prime[j] = true;
            }
        }
    }
}

int main(){

    primelist();

    int t;
    cin >> t;
    while(t--){
        int L, U;
        cin >> L >> U;

        int P, P_num = 0;
        for(int i = L; i <= U; i++){
            int total = 1;
            int num = i;
            for(int j = 0; j < pri.size() && pri[j] <= num; j++){
                int cnt = 0;
                while(num % pri[j] == 0){
                    cnt++;
                    num /= pri[j];
                }
                total *= (cnt+1);
            }

            if(total > P_num){
                P = i;
                P_num = total;
            }
        }

        cout << "Between " << L << " and " << U << ", " << P << " has a maximum of " << P_num << " divisors." << endl;
    }
}