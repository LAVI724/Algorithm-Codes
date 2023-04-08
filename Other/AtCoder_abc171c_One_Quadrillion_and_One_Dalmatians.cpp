#include<bits/stdc++.h>
using namespace std;
// 2022.06.24

int main(){
    long long int a = 1000000000000001;

    long long int n;
    cin >> n;

    long long int tmp = n, cnt = 0;
    char alpha[] = "zabcdefghijklmnopqrstuvwxy";
    vector<char> v;

    
    while(tmp){
        v.emplace_back(alpha[tmp % 26]);
        tmp =  (tmp-1) / 26;
    }

    reverse(v.begin(), v.end());

    for(auto i : v){
        cout << i;
    }
    cout << endl;
}