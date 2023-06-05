#include<bits/stdc++.h>
using namespace std;
// 2022.06.01

int main(){
    long long int n;
    cin >> n;

    long long int num = n;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){

            num = n/i;
        }
    }

    string str = to_string(num);
    cout << str.size() << endl;
}