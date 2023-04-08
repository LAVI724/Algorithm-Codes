#include<bits/stdc++.h>
using namespace std;
// 2022.06.15

struct Edge{
    int n;
    int m;

    bool operator < (const Edge &other) const{
        return m < other.m;
    }
};

Edge edge[100000+5];

int main(){
    int n;
    int num;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        edge[i].n = i+1;
        edge[i].m = num;
    }
    sort(edge, edge + n);

    for(int i = 0; i < n; i++){
        cout << edge[i].n << " ";
    }
}