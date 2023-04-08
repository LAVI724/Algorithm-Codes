#include<bits/stdc++.h>
using namespace std;
// 2022.02.14

int main(){
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;

        sort(str.begin(), str.end());
        
        cout << str << endl;
        while(next_permutation(str.begin(), str.end())){
            cout << str << endl;
        }
        cout << endl;
    }
}