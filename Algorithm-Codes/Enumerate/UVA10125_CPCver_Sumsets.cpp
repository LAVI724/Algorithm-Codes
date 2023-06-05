#include<bits/stdc++.h>
using namespace std;
// 2022.07.15

/*
本題觀念:
折半枚舉

參考資料:
https://fjuonlinejudge.github.io/Training/algorithm/enumerate/#_7
https://blog.csdn.net/qq_45735851/article/details/109285973
https://www.codeleading.com/article/25121469639/
*/

const int maxn = 1000+5;

struct Edge{
    int a, b, sum;
    bool operator < (const Edge &a) const{
        return sum < a.sum;
    }
}edge[maxn*maxn];;

int main(){
    std::ios::sync_with_stdio(false);
    int s;
    while(cin >> s && s){
        int it = 0;
        bool flag = false;
        int num[maxn];

        for(int i = 0; i < s; ++i){
            cin >> num[i];
        }
        sort(num, num + s);
        
        // a + b
        for(int i = 0; i < s - 1; ++i){
            for(int j = i + 1; j < s; ++j){
                edge[it++] = (Edge){num[i], num[j], num[i] + num[j]};
            }
        }
        sort(edge, edge + it);

        // d - c
        for(int i = s - 1; i >= 0 && !flag; --i){
            for(int j = 0; j < s && !flag; ++j){
                if(i == j) continue;

                int sub = num[i] - num[j];
                Edge dc = (Edge){num[i], num[j], sub};

                int ituper = upper_bound(edge, edge + it, dc) - edge;
                int itlower = lower_bound(edge, edge + it, dc) - edge;

                for(int k = itlower; k < ituper; ++k){
                    if(num[i] != edge[k].a && num[i] != edge[k].b && num[j] != edge[k].a && num[j] != edge[k].b){
                        cout << num[i] << endl;
                        flag = true;
                        break;
                    }
                }
                
            }
        }

        if(!flag) cout << "no solution" << endl;
    }
}