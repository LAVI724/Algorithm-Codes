#include<bits/stdc++.h>
using namespace std;
// 2022.11.11

/*
110 程式競賽專論 阿和

解題觀念:
數論
不能直接模擬，會超時

f(1)=0
f(i)=(f(i-1)+k)%i
f(n)=(f(n-1)+m)%n

最後石頭編號:
f(n)+1=1，因為我們編號設 0 開始，所以要 +1
*/

const int maxn = 10000+5;
int f[maxn];

int main(){
    int n, k, m;
    while(cin >> n >> k >> m && n && k && m){
        f[1] = 0;
        // i 是剩下的石頭數量
        for(int i = 2; i < n; ++i){
            f[i] = (f[i-1] + k) % i;
        }
        f[n] = (f[n-1] + m) % n;
        cout << f[n] + 1 << endl;
    }
}