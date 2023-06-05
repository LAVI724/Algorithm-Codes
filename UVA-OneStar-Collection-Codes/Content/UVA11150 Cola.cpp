#include<bits/stdc++.h>
using namespace std;
// 2022/02/12

int main(){
    int n;
    while(cin >> n){
        int cnt = n;
        while(n > 0){
            if(n >= 3){
                cnt += n/3;
                n = (n/3) + (n%3);
            }
            else if(n == 2){
                cnt++;
                n = 0;
            }
            else{
                n = 0;
            }
        }
        cout << cnt << endl;
    }
}