#include<bits/stdc++.h>
using namespace std;
// 2022.08.05

/*
解題觀念:
upper_bound
lower_bound
類似二分搜但更快 (?)
*/

int main(){
    int N, Q;
    int ca = 1;
    while(cin >> N >> Q && N && Q){
        vector<int> v(N);

        for(int i = 0; i < N; ++i){
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        cout << "CASE# " << ca++ << ":" << endl;
        int marble;
        for(int i = 0; i < Q; ++i){
            cin >> marble;

            int lef = lower_bound(v.begin(), v.end(), marble) - v.begin();
            int rig = upper_bound(v.begin(), v.end(), marble) - v.begin();

            if(lef == rig) cout << marble << " not found" << endl;
            else{
                cout << marble << " found at " << lef + 1 << endl;
            }
        }
    }
}