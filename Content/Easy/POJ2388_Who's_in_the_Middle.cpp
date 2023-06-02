#include<iostream>
#include<algorithm>
using namespace std;
// 2022.09.24

int main(){
    int n;
    int num[10000+5];

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num[i];
    }
    sort(num, num + n);

    cout << num[n/2] << endl;
}