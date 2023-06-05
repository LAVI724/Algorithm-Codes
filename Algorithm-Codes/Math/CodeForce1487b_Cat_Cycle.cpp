#include<bits/stdc++.h>
using namespace std;
// 2022.06.26

/*
解題思維:
找規律
*/

int main(){
    int t;
    long long int n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n & 1){
            k--;
            int num = n/2;
            k += k/num;
            cout << (k % n) + 1 << endl;
        }
        else{
            if(k % n == 0){
                cout << n << endl;
            }
            else{
                cout << k % n << endl;
            }
        }
    }
}