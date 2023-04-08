#include <bits/stdc++.h>
using namespace std;
// 2021.05.14

long long int a[50+1];
long long int func(long long int n){
    if (a[n] != -1){
        return a[n];
    }
    if (n < 3){
        return a[n] = n;
        
    }
    else{
        return a[n] = func(n - 1) + func(n - 2);
    }
}

int main(){
    memset(a, -1, sizeof(a));

    int n;
    while (cin >> n && n){
        cout << func(n) << endl;
    }
}