#include<bits/stdc++.h>
using namespace std;
// 2022.10.12

/*
解題觀念:
法一:
1. 如果 B 內 == N，輸出並回傳 ture
2. 若 B 滿了，清空 B，繼續 dfs
3. 若 A 為空，注滿 A，繼續 dfs
4. 如果 A 有水，把 A 倒入 B，繼續 dfs
法二:
把法一的 A 和 B 全部倒過來做
*/

const int maxn = 1000+5;

bool visited[maxn][maxn];
int Ca, Cb, N;

bool flag = false;
vector<int> ins;
string ans[] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};


bool dfs(int A, int B){
    if(visited[A][B]) return false;

    visited[A][B] = true;

    if(B == N){
        for(int i = 0; i < ins.size(); ++i){
            // cout << ins[i] << " ";
            cout << ans[ins[i]] << endl;
        }
        cout << "success" << endl;
        return true;
    }

    if(A != Ca){
        ins.push_back(0);

        // 將 A 填滿
        if(dfs(Ca, B)) return true;
        else ins.pop_back();
    }

    if(B != Cb){
        ins.push_back(1);

        // 將 B 填滿
        if(dfs(A, Cb)) return true;
        else ins.pop_back();
    }

    if(A != 0){
        ins.push_back(2);

        // 把 A 清空 
        if(dfs(0, B)) return true;
        else ins.pop_back();
    }

    if(B != 0){
        ins.push_back(3);

        // 把 B 清空 
        if(dfs(A, 0)) return true;
        else ins.pop_back();
    }

    if(A != 0 && B != Cb){
        ins.push_back(4);

        // 把 A 倒進 B
        if(dfs(A - min(A, Cb - B), B + min(A, Cb - B))) return true;
        else ins.pop_back();
    }

    if(B != 0 && A != Ca){
        ins.push_back(5);

        // 把 B 倒進 A
        if(dfs(A + min(B, Ca - A), B - min(B, Ca - A))) return true;
        else ins.pop_back();
    }
}

int main(){
    while(cin >> Ca >> Cb >> N){
        memset(visited, false, sizeof(visited));
        ins.clear();

        dfs(0, 0);
    }
}