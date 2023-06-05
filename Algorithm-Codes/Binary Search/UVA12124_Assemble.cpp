#include<bits/stdc++.h>
using namespace std;
// 2023.03.12

/*
binary search
map
*/

int n, budget;
map<string, vector<pair<int, int>>> mp;

bool check(int qualityNow, int budget){
    int totalCost = 0;
    map<string, vector<pair<int, int>>>::iterator mpv;
    for(mpv = mp.begin(); mpv != mp.end(); ++mpv){
        int mini = 1000000+5;
        for(int j = 0; j < mpv->second.size(); ++j){
            if(mpv->second[j].second >= qualityNow && mpv->second[j].first < mini) mini = mpv->second[j].first;
        }

        if(mini == 1000000+5) return false;
        totalCost += mini;  
        // cout << mpv->first << " " << mini << endl;
    }
    // cout << totalCost << endl;

    if(totalCost <= budget) return true;
    else return false;
}

int binarySearch(int lef, int rig){
    if(lef >= rig) return lef;

    int mid = lef + (rig - lef + 1) / 2;

    // cout << lef << " " << mid << " " << rig << endl;
    if(check(mid, budget)){
        return binarySearch(mid, rig);
    }
    else{
        return binarySearch(lef, mid-1);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> budget;
        mp.clear();

        string component, type;
        int price, quality;
        int rig = -1;
        for(int i = 0; i < n; ++i){
            cin >> component >> type >> price >> quality;
            mp[component].push_back({price, quality});

            rig = max(rig, quality);
        }

        int ans = binarySearch(0, rig);
        cout << ans << endl;
    }
}