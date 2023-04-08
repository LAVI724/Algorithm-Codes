#include<bits/stdc++.h>
using namespace std;
// 2022.03.11

int n, cnt;
bool flag = false;
bool used[10000+5];
deque<int> num;
struct Edge{
    int stick;

    bool operator < (const Edge &rhs) const{
        return stick > rhs.stick;
    }
}edge[10000+5];

void dfs(int len, int now, int finish){

    if(len == cnt){
        finish++;
        len = now = 0;

        if(finish == 3){
            flag = true;
            return;
        }
    }

    for(int i = now; i < n; i++){
        if(!used[i]){
            if(len + edge[i].stick <= cnt){
                used[i] = true;
                num.emplace_back(edge[i].stick);

                dfs(len + edge[i].stick, i + 1, finish);

                if(flag) return;

                used[i] = false;
                num.pop_back();
            }
        }
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> edge[i].stick;
            cnt += edge[i].stick;
        }
        sort(edge, edge + n);

        if(cnt % 4 != 0){
            cout << "no" << endl;
            continue;
        }

        bool check = false;
        cnt /= 4;
        for(int i = 0; i < n; i++){
            if(edge[i].stick > cnt){
                cout << "no" << endl;
                check = true;
                break;
            }
        }

        if(check) continue;

        flag = false;
        num.clear();
        memset(used, false, sizeof(used));
        dfs(0, 0, 0);

        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}