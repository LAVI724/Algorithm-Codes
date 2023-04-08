#include<bits/stdc++.h>
using namespace std;
// 2022.07.22

/*
解題觀念:
divide and conquer
逆序數對

參考資料:
https://fjuonlinejudge.github.io/Training/algorithm/divideandconquer/#_3

ex: 5 1 5 3 4 2 (nlogn)
lef: 0 mid: 1 rig: 2 i: 1 j: 1 k: 1
buf: 1 0 0 0 0

lef: 0 mid: 1 rig: 2 i: 1 j: 2 k: 2
buf: 1 5 0 0 0

lef: 3 mid: 4 rig: 5 i: 3 j: 5 k: 4
buf: 1 5 0 2 0

lef: 3 mid: 4 rig: 5 i: 4 j: 5 k: 5
buf: 1 5 0 2 4

lef: 2 mid: 3 rig: 5 i: 2 j: 4 k: 3
buf: 1 5 2 2 4

lef: 2 mid: 3 rig: 5 i: 3 j: 4 k: 4
buf: 1 5 2 3 4

lef: 2 mid: 3 rig: 5 i: 3 j: 5 k: 5
buf: 1 5 2 3 4

lef: 0 mid: 2 rig: 5 i: 1 j: 2 k: 1
buf: 1 5 2 3 4

lef: 0 mid: 2 rig: 5 i: 1 j: 3 k: 2
buf: 1 2 2 3 4

lef: 0 mid: 2 rig: 5 i: 1 j: 4 k: 3
buf: 1 2 3 3 4 

lef: 0 mid: 2 rig: 5 i: 1 j: 5 k: 4
buf: 1 2 3 4 4

lef: 0 mid: 2 rig: 5 i: 2 j: 5 k: 5
buf: 1 2 3 4 5
*/

const int maxn = 100000+5;
int arr[maxn], buf[maxn];

// 逆序數對
int count_inversions(int lef, int rig){
    if(rig - lef <= 1) return 0;

    int mid = (lef + rig)/2;
    int ans = count_inversions(lef, mid) + count_inversions(mid, rig);
    
    int i = lef, j = mid, k = lef;
    while(i < mid || j < rig){
        if(i >= mid){
            buf[k] = arr[j++];
        }
        else if(j >= rig){
            buf[k] = arr[i++];
        }
        else{
            // 如果不用交換
            if(arr[i] <= arr[j]){
                buf[k] = arr[i++];
            }
            else{
                // 如果是要交換的狀況
                buf[k] = arr[j++];
                ans += mid - i;
            }
        }
        k++;

        // cout << "lef: " << lef << " mid: " << mid << " rig: " << rig;
        // cout << " i: " << i << " j: " << j << " k: " << k << endl;
        // cout << "buf: ";
        // for(int p = 0; p < 5; ++p){
        //     cout << buf[p] << " ";
        // }
        // cout << endl;
    }
    // 因為 buf[num] 通常都是 0，只有有更新數字會被轉成 arr[num]
    for(int k = lef; k < rig; ++k){
        arr[k] = buf[k];
    }
    return ans;
}

int main(){
    int N;
    while(cin >> N && N){
        memset(arr, 0, sizeof(arr));
        memset(buf, 0, sizeof(buf));

        for(int i = 0; i < N; ++i){
            cin >> arr[i];
        }

        if(count_inversions(0, N) & 1){
            cout << "Marcelo" << endl;
        }
        else{
            cout << "Carlos" << endl;
        }
    }
}