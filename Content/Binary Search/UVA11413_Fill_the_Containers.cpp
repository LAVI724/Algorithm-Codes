#include<bits/stdc++.h>
using namespace std;
// 2022.08.06

/*
解題觀念:
binary search 變形
*/

int n, m;
bool flag = false;
const int maxn = 1000+5;

int binary_search(int arr[maxn], int lef, int rig, int mini){
    if(lef > rig) return mini;

    int amount = 1, fill = 0;
    int mid = (lef + rig) >> 1;
    for(int i = 0; i < n; ++i){
        if(amount > m) break;
        
        fill += arr[i];
        if(fill > mid){
            fill = arr[i];
            amount++;
        }
    }
    // cout << lef << " " << rig << " " << mid << " " << amount << endl;

    if(!flag && amount <= m) mini = mid;
    if(flag && amount == m) mini = mid;

    if(amount == m){
        flag = true;
        return binary_search(arr, lef, mid - 1, mid);
    }
    else if(amount < m){
        return binary_search(arr, lef, mid - 1, mini);
    }
    else{
        return binary_search(arr, mid + 1, rig, mini);
    }
}

int main(){
    int ca = 1;
    while(cin >> n >> m){
        flag = false;

        int arr[maxn];
        int maxi = 0, sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }
        cout << binary_search(arr, maxi, sum, maxi) << endl;
    }
}