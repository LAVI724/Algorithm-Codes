#include<bits/stdc++.h>
using namespace std;
// 2022.06.26

/*
解題觀念:
找規律
*/

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n, x;
        cin >> n >> x;

        long long int num[n+5];
        memset(num, 0, sizeof(num));
        
        for(long long int i = 1; i <= n; i++){
            cin >> num[i];
        }
        sort(num, num + n + 1);

        for(long long int i = 1; i <= n; i++){
            num[i] += num[i-1];
        }

        long long int total = 0;
        for(long long int i = n, j = 0; i > 0; i--){
            if(x - num[i] < 0) continue;
            
            int m = (x - num[i])/i + 1;
            m -= j;
            total += i * m;
            j += m;
        }
        cout << total << endl;
    }
}