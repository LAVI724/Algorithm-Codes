#include<bits/stdc++.h>
using namespace std;
// 2022.07.22

/*
解題觀念:
prefix sum
*/

int main(){
    int N;
    cin >> N;

    long long int arr[N+5], sum[N+5];

    memset(arr, 0, sizeof(arr));
    memset(sum, 0, sizeof(sum));

    for(int i = 1; i <= N; ++i){
        cin >> arr[i];

        sum[i] = arr[i] + sum[i-1];
        cout << sum[i] << " ";
    }
    cout << endl;
}