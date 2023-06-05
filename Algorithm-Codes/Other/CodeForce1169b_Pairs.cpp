#include<bits/stdc++.h>
using namespace std;
// 2022.08.11 二版

/*
解題觀念:
沒有技巧 都是眼淚
*/

const int maxn = 300000+5;

struct Node{
    int siz;
    int index;

    bool operator < (const Node &rhs) const{
        return siz < rhs.siz;
    }

}siz[maxn];

set<int> stf[maxn], sts[maxn];

int main(){
    int n, m;
    cin >> n >> m;

    memset(siz, 0, sizeof(siz));

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        stf[a].insert(b);
        stf[b].insert(a);

        sts[a].insert(b);
        sts[b].insert(a);
    }

    for(int i = 1; i <= n; ++i){
        siz[i].siz = stf[i].size();
        siz[i].index = i;
    }
    sort(siz, siz + n + 1);

    int maxi = siz[n].index, maxn = siz[n].siz;

    // for(int i = 0; i <= n; ++i){
    //     cout << siz[i].index << " " << siz[i].siz << endl;
    // }
    // cout << "maxi " << maxi << endl;

    for(auto i = stf[maxi].begin(); i != stf[maxi].end(); i++){
        stf[*i].erase(stf[*i].find(maxi));
    }
    stf[maxi].clear();

    maxi = -1, maxn = 0;
    for(int i = 1; i <= n; i++){
        if(stf[i].size() >= maxn){
            maxi = i;
            maxn = stf[i].size();
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << "i: " << i << " " << stf[i].size() << endl;
    // }
    // cout << endl;

    bool flag = false;
    if(maxn != 0){
        for(auto i = stf[maxi].begin(); i != stf[maxi].end(); i++){
            stf[*i].erase(stf[*i].find(maxi));
        }
        stf[maxi].clear();

        // for(int i = 1; i <= n; i++){
        //     cout << "i: " << i << " " << stf[i].size() << endl;
        // }
    }

    for(int i = 1; i <= n; i++){
        if(stf[i].size() != 0){
            flag = true;
            break;
        }
    }

    if(flag){
        // cout << "hello" << endl;
        maxi = siz[n-1].index, maxn = siz[n-1].siz;

        // cout << maxi << endl;
        for(auto i = sts[maxi].begin(); i != sts[maxi].end(); i++){
            sts[*i].erase(sts[*i].find(maxi));
        }
        sts[maxi].clear();

        // for(int i = 1; i <= n; i++){
        //     cout << "i: " << i << " " << sts[i].size() << endl;
        // }

        maxi = -1, maxn = 0;
        for(int i = 1; i <= n; i++){
            if(sts[i].size() >= maxn){
                maxi = i;
                maxn = sts[i].size();
            }
        }
        // cout << maxi << endl;

        if(maxn != 0){
            for(auto i = sts[maxi].begin(); i != sts[maxi].end(); i++){
                sts[*i].erase(sts[*i].find(maxi));
            }
            sts[maxi].clear();

            // for(int i = 1; i <= n; i++){
            //     cout << "i: " << i << " " << stf[i].size() << endl;
            // }
        }

        // for(int i = 1; i <= n; i++){
        //     cout << "i: " << i << " " << sts[i].size() << endl;
        // }

        flag = false;
        for(int i = 1; i <= n; i++){
            if(sts[i].size() != 0){
                flag = true;
                break;
            }
        }
    }

    if(flag){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}