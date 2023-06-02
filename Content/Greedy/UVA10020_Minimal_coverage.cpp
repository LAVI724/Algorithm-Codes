#include<bits/stdc++.h>
using namespace std;
// 2023.02.13

/*
解題觀念
Greedy
最小區間覆蓋
*/

struct Node{
    int lef, rig;

    // 左邊由小到大 右邊由大到小
    bool operator < (const Node &rhs) const{
        if(lef == rhs.lef) return rig > rhs.rig;
        else return lef < rhs.lef;
    } 
};

int main(){
    int t;
    cin >> t;

    bool space = false;
    while(t--){
        if(space) cout << endl;
        space = true;

        int M;
        cin >> M;

        vector<Node> seg;
        int lef, rig;
        while(cin >> lef >> rig && (lef || rig)){
            seg.push_back({lef, rig});
        }
        sort(seg.begin(), seg.end());

        // for(int j = 0; j < seg.size(); ++j){
        //     cout << seg[j].lef << " " << seg[j].rig << endl;
        // }

        int ptrLef = 0, ptrRig = -1;
        vector<pair<int, int>> ans;
        while(ptrRig < M){
            int tmpLef = -50001;
            for(int j = 0; seg[j].lef <= ptrLef && j < seg.size(); ++j){
                if(seg[j].rig > ptrRig){
                    ptrRig = seg[j].rig;
                    tmpLef = seg[j].lef;
                }
            }

            if(tmpLef == -50001) break;
            // cout << tmpLef << " " << ptrRig << endl;
            ans.push_back({tmpLef, ptrRig});
            ptrLef = ptrRig;
        }

        if(ptrRig >= M){
            cout << ans.size() << endl;
            for(int j = 0; j < ans.size(); ++j){
                cout << ans[j].first << " " << ans[j].second << endl;
            }
        }
        else cout << "0" << endl;

        seg.clear();
        ans.clear();
    }
}