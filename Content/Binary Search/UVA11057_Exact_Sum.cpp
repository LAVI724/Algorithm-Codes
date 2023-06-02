#include<bits/stdc++.h>
using namespace std;
// 2022.08.06 by LAVI

/*
解題觀念:
binary search
*/

const int maxn = 10000+5;

int binary_search(int arr[maxn], int lef, int rig, int target){
    if(lef > rig) return 0x3f3f3f3f;

    int mid = (lef + rig) >> 1;
    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target){
        return binary_search(arr, lef, mid - 1, target);
    }
    else{
        return binary_search(arr, mid + 1, rig, target);
    }
}

int main(){
    int N;
    bool space = false;
    while(cin >> N){
        int arr[maxn];
        for(int i = 0; i < N; ++i){
            cin >> arr[i];
        }
        sort(arr, arr + N);

        int M;
        int ansi, ansj, mini = 0x3f3f3f3f;
        cin >> M;
        for(int i = 0; i < N; ++i){
            int mid = binary_search(arr, 0, N-1, M - arr[i]);
            if(mid != 0x3f3f3f3f && mid != i && abs(arr[i] - arr[mid]) <= mini){
                mini = abs(arr[i] - arr[mid]);
                ansi = min(arr[i], arr[mid]);
                ansj = max(arr[i], arr[mid]); 
            }
        }
        
        cout << "Peter should buy books whose prices are " << ansi << " and " << ansj << ".\n\n";
    }
}