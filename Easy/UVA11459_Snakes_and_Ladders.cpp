#include<bits/stdc++.h>
using namespace std;
// 2022.09.25

const int maxn = 1000000+5;

int per[maxn];
int ladder[maxn];
int die[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        int p, s, d;
        cin >> p >> s >> d;

        for(int i = 1; i <= p; ++i){
            per[i] = 1;
        }

        memset(ladder, 0, sizeof(ladder));
        for(int i = 0; i < s; ++i){
            int head, tail;
            cin >> head >> tail;
            ladder[head] = tail;
        }

        for(int i = 0; i < d; ++i){
            cin >> die[i];
        }

        for(int i = 0, j = 1; i < d; ++i){         
            int nx = per[j] + die[i];
            
            if(ladder[nx] != 0){
                nx = ladder[nx];
            }

            if(nx >= 100){
                per[j] = 100;
                break;
            }

            per[j] = nx;

            j++;
            if(j > p) j = 1;
        }

        for(int i = 1; i <= p; ++i){
            cout << "Position of player " << i << " is " << per[i] << "." << endl;
        }
    }
}