#include<bits/stdc++.h>
using namespace std;
// 2022.06.17

int main(){
    int n;
    cin >> n;
    int num;
    vector<int> v1, v2;
    for(int i = 0; i < n; i++){
        cin >> num;
        v1.emplace_back(num);
    }

    for(int i = 0; i < n; i++){
        cin >> num;
        v2.emplace_back(num);
    }
    
    int total = 0;
    for(int i = 0; i < n; i++){
        total += v1[i] * v2[i];
    }

    if(total){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}