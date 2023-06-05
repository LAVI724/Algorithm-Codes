#include<bits/stdc++.h>
using namespace std;
// 2022.07.22

/*
解題觀念:
divide and conquer
逆序數對

參考資料:
https://fjuonlinejudge.github.io/Training/algorithm/divideandconquer/#_3
*/

const int maxn = 500000+5;
long long int arr[maxn], buf[maxn];

// 逆序數對
long long int count_inversions(int lef, int rig){
    if(rig - lef <= 1) return 0;

    int mid = (lef + rig)/2;
    long long int ans = count_inversions(lef, mid) + count_inversions(mid, rig);
    
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

        long long int ans = count_inversions(0, N);
        cout << ans << endl;
    }
}