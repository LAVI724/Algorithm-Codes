#include<bits/stdc++.h>
using namespace std;
// 2022.09.24

struct Edge{
    int idx;
    int name;
    int num;

    bool operator < (const Edge &rhs) const{
        if(num == rhs.num){
            return name > rhs.name;
        }

        return num > rhs.num;
    }
}edge[1000+5];

int main(){
    int cnt = 0;
    string str;
    priority_queue<Edge> pq;
    while(cin >> str){
        if(str == "#") break;

        cin >> edge[cnt].name >> edge[cnt].num;
        edge[cnt].idx = cnt;

        pq.push({edge[cnt].idx, edge[cnt].name, edge[cnt].num});
        cnt++;
    }

    int period;
    cin >> period;

    for(int i = 0; i < period; ++i){
        Edge tp = pq.top();
        pq.pop();

        cout << tp.name << endl;
        pq.push({tp.idx, tp.name, tp.num += edge[tp.idx].num});
    }
}