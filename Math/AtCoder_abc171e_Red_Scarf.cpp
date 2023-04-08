#include<bits/stdc++.h>
using namespace std;
// 2022.06.28

/*
bitwise operator - xor or
找規律

ex:
4
20 11 9 24
20 = 10100
11 = 01011
09 = 01001
24 = 11000
全部 xor total = 01110

去比較 total 與數字們的規律
*/

int main(){
    int n;
    cin >> n;

    int a[n+5], ans[n+5];
    memset(a, 0, sizeof(a));
    memset(ans, 0, sizeof(ans));

    // total 最後會剩下這些數字中出現奇數次的位元
    int total = 0; 
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total ^= a[i];
    }

    // i 不會超過 64 bits
    for(int i = 0; i < 32; i++){

        // 如果 total 有這一位元的話
        if(total & (1 << i)){
            for(int j = 0; j < n; j++){

                // 如果對於此數 這一位元若是不存在 但是 total 存在 代表其他有奇數個數有此位元
                if(!(a[j] & (1 << i))){
                    ans[j] |= (1 << i);
                }
            }
        }
        else{
            for(int j = 0; j < n; j++){

                // 如果對於此數 這一位元若是存在 但 total 不存在 代表總共有偶數個數有此位元
                if(a[j] & (1 << i)){
                    ans[j] |= (1 << i);
                }
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // int mask = 1 << 4;
    // for(int i = 0; i < 4; ++i){
    //     for(int j = 0; j < 5; ++j){
    //         int tmp = (a[i] & mask);
    //         a[i] <<= 1;

    //         if(tmp == mask) cout << 1;
    //         else cout << 0;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    // cout << endl;
    // for(int i = 0; i < 4; ++i){
    //     for(int j = 0; j < 5; ++j){
    //         int tmp = (ans[i] & mask);
    //         ans[i] <<= 1;

    //         if(tmp == mask) cout << 1;
    //         else cout << 0;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

