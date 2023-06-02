#include<bits/stdc++.h>
using namespace std;
// 2022.06.17

int main(){
    int t;
    cin >> t;
    long long int num[100+5];
    memset(num, 0, sizeof(num));
    for(int i = 0; i < t; i++){
        cin >> num[i];
    }
    sort(num, num + t);

    cout << num[t-1] - num[0] << endl;
}