#include<bits/stdc++.h>
using namespace std;
// 2022/02/10

bool cmp(const pair<string, int>& a, const pair<string, int>& b){
    return a.first < b.first;
}

int main(){
    int t;
    bool flag = false;
    string name;

    cin >> t;
    cin.ignore();
    getline(cin, name);
    while(t--){
        double total = 0.0;
        map<string, int> tree;
        map<string, int>::iterator it;

        while(getline(cin, name) && name != ""){
            tree[name]++;
            total += 1.0;
        }
        deque<pair<string, int>> dq(tree.begin(), tree.end());
        sort(dq.begin(), dq.end(), cmp);

        if(flag){
            cout << endl;
        }

        for(auto iter : dq){
            double ans = (iter.second) / total * 100.0;
            cout << iter.first << " " << fixed << setprecision(4) << ans << endl;
        }   

        flag = true;
        tree.clear();
    }
}