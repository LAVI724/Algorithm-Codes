#include<bits/stdc++.h>
using namespace std;
// 2022.10.03

/*
解題觀念:
前綴和
*/

const int maxn = 20000+5;
int arr[maxn];

int main(){
    int t;
    int ca = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        memset(arr, 0, sizeof(arr));

        for(int i = 1; i < n; ++i){
            cin >> arr[i];
        }

        int sum = 0;
        int maxi = 0, maxidxi = 1, maxidxj = 1;
        int tmpi = -1;
        for(int i = 1; i < n; ++i){
            sum += arr[i];

            if(tmpi == -1) tmpi = i;

            if(sum > maxi || (sum == maxi && i+1 - tmpi > maxidxj - maxidxi)){
                maxi = max(maxi, sum);
                maxidxi = tmpi;
                maxidxj = i+1;
            }
            else if(sum < 0){
                sum = 0;
                tmpi = -1;
            }
        }

        if(maxi > 0)
            cout << "The nicest part of route " << ca++ << " is between stops " << maxidxi << " and " << maxidxj << endl;
        else cout << "Route " << ca++ << " has no nice parts" << endl;    
    }
}