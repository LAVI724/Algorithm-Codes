#include<bits/stdc++.h>
using namespace std;
// 2022.05.30

/*
解題思維:
找規律
n ~ n/2 的值使 n/i = 1
n/2 ~ n/3 的值使 n/i = 2
...
直到 n/sqrt(n)-1 ~ n/sqrt(n)
剩下小於 sqrt(n) 的值都沒有規律 都一個一個加就好 數量也不多
*/

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        long long int sum = 0;

        // 大於平方根的值有規律
        for(int i = 1; i <= (int)sqrt(n); i++){
            sum += i * (n/i - n/(i+1));
        }

        // 小於平方根的值沒有規律 直接加
        for(int i = n/((int)sqrt(n)+1); i >= 1; i--){
            sum += n/i;
        }
        cout << sum << endl;
    }
}