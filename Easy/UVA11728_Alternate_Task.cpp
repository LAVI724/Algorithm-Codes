#include<bits/stdc++.h>
using namespace std;
// 2022.09.24

const int maxn = 1000+5;
int num[maxn];

int main(){
    memset(num, 0, sizeof(num));
    for(int i = 1; i < maxn; ++i){
        for(int j = i; j < maxn; j += i){
            num[j] += i;
        }
    }

    int n, ca = 1;
    while(cin >> n && n){

        cout << "Case " << ca++ << ": ";

        bool flag = false;
        for(int i = n; i > 0; --i){
            if(num[i] == n){
                cout << i << endl;
                flag = true;
                break;
            }
        }

        if(!flag) cout << -1 << endl;
    }
}