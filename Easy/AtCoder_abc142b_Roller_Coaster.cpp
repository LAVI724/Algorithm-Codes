#include<bits/stdc++.h>
using namespace std;
// 2022.06.15

int main(){
    int n, k;
    cin >> n >> k;
    int total = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num >= k){
            total++;
        }
    }
    cout << total << endl;
}