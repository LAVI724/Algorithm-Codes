#include<bits/stdc++.h>
using namespace std;
// 2022.03.10

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int p;
        int maxi;
        set<int> score;
        cin >> maxi;
        for(int i = 1; i < n; i++){
            cin >> p;
            score.insert(maxi - p);
            maxi = max(maxi, p);
        }

        cout << *score.rbegin() << endl;
    }
}