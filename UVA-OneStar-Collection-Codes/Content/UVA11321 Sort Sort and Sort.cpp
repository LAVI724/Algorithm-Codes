#include<bits/stdc++.h>
using namespace std;
// 2022/02/09

struct Edge{
    long long int num;
    long long int r;
}edge[10000+5];

bool cmp(Edge n1, Edge n2){
    if(n1.r != n2.r){
        return n1.r < n2.r;
    }
    else{
        if((n1.num & 1) * (n2.num & 1)){
            return n1.num > n2.num;
        }
        else if((n1.num & 1) || (n2.num & 1)){
            return n1.num & 1;
        }
        else{
            return n1.num < n2.num;
        }
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            cout << "0 0" << endl;
            break;
        }
        cout << n << " " << m << endl;

        for(int i = 0; i < n; i++){
            cin >> edge[i].num;
            edge[i].r = edge[i].num % m;
        }
        sort(edge, edge+n, cmp);

        for(int i = 0; i < n; i++){
            cout << edge[i].num << endl;
        }
    }
}