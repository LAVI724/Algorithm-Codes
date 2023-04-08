#include<bits/stdc++.h>
using namespace std;
// 2022.06.25

int main(){
    int n, m;
    cin >> n >> m;

    map<int, bool> pro;
    map<int, int> wa;
    int num, ans1 = 0, ans2 = 0;
    string str;
    for(int i = 0; i < m; i++){
        cin >> num >> str;
        if(str == "AC"){
            if(pro[num] != true){
                ans1++;
                ans2 += wa[num];
            }
            pro[num] = true;
        }

        if(str == "WA"){
            if(pro[num] != true){
                wa[num]++;
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;
}