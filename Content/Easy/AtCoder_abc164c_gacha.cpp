#include<bits/stdc++.h>
using namespace std;
// 2022.06.15

int main(){
    int n;
    cin >> n;
    map<string, int> mp;

    while(n--){
        string str;
        cin >> str;
        mp[str]++;

    }
    cout << mp.size() << endl;
}