#include<bits/stdc++.h>
using namespace std;
// 2022.07.08 by LAVI

/*
解題觀念:
LIS、LDS

參考資料:
https://web.ntnu.edu.tw/~algo/Subsequence.html#3
*/

int N;
const int maxn = 10000 + 5;
int length[maxn];
int seq[maxn], revseq[maxn];

void LIS(vector<int> &s){
    // if(s.size() == 0) return 0;
    if(s.size() == 0) return;

    vector<int> v;
    v.emplace_back(s[0]);
    seq[0] = 1;

    for(int i = 1; i < s.size(); ++i){
        int n = s[i];
        if(n > v.back()){
            v.push_back(n);
        }
        else{
            *lower_bound(v.begin(), v.end(), n) = n;
        }
        seq[i] = v.size();
    }
    // return v.size();
    return;
}

// 其實就是把陣列 reverse 後做 LIS
void LDS(vector<int> &s){
    // if(s.size() == 0) return 0;
    if(s.size() == 0) return;

    vector<int> v;
    v.emplace_back(s[0]);
    revseq[0] = 1;

    for(int i = 1; i < s.size(); ++i){
        int n = s[i];
        if(n > v.back()){
            v.push_back(n);
        }
        else{
            *lower_bound(v.begin(), v.end(), n) = n;
        }
        revseq[i] = v.size();
    }
    // return v.size();
    return;
}

int main(){

    while(cin >> N){

        vector<int> s(N), revs(N);
        for(int i = 0; i < N; i++){
            cin >> s[i];
            revs[i] = s[i];
        }
        reverse(revs.begin(), revs.end());

        LIS(s);
        LDS(revs);

        reverse(revseq, revseq + N);
        
        int maxi = -1;  
        for(int i = 0; i < N; i++){
            // cout << seq[i] << " " << revseq[i] << endl;
            if(min(seq[i], revseq[i]) > maxi){
                maxi = min(seq[i], revseq[i]);
            }
        }
        cout << maxi * 2 - 1 << endl;

    }
}