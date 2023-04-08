#include<bits/stdc++.h>
using namespace std;
// 2022.07.23

int main(){
    int N, M;
    cin >> N >> M;

    int arr[N+5];
    memset(arr, 0, sizeof(arr));

    int fir, las, seat;
    for(int i = 0; i < M; ++i){
        cin >> fir >> las >> seat;
        for(int j = fir; j <= las; ++j){
            arr[j] += seat;
        }
    }

    for(int i = 1; i <= N; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}