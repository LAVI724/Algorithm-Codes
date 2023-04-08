#include<bits/stdc++.h>
using namespace std;
// 2022.06.15

int main(){
    int n;
    int num;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int fir = 0, last = 0;
        string str;
        cin >> str;

        for(int j = 0; j < 3; j++){
            fir += str[j] - '0';
        }

        for(int j = 3; j < 6; j++){
            last += str[j] - '0';
        }

        if(fir == last){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}