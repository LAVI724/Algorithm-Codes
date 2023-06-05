#include<bits/stdc++.h>
using namespace std;
// 2022/02/11

int now, n;
char mp[100+5][100+5];
int cnt[100+5][100+5];
int step[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

struct Edge{
    int re;
    int ce;
}edge[10000+5];

void initial(){
    now = 0, n = 0;
    for(int i = 0; i <= 100; i++){
        memset(cnt[i], 0, sizeof(cnt[i]));
    }
}

void bfs(int rn, int cn){   
    
    if(now == n){
        return;
    }

    for(int i = 0; i < 8; i++){
        int cx = cn + step[i][0];
        int rx = rn + step[i][1];

        if(cx >= 0 && rx >= 0){
            cnt[rx][cx]++;
        }
    }
    now++;
    bfs(edge[now].re, edge[now].ce);
}
int main(){
    int ca = 1;
    int r, c;
    bool flag = false;
    while(cin >> r >> c && r && c){
        
        initial();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> mp[i][j];
                if(mp[i][j] == '*'){
                    edge[n].re = i;
                    edge[n].ce = j;
                    n++;
                }
            }
        }
        bfs(edge[0].re, edge[0].ce);

        if(flag){
            cout << endl;
        }
        cout << "Field #" << ca++ << ":" << endl;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mp[i][j] != '*'){
                    cout << cnt[i][j];
                }
                else{
                    cout << '*';
                }
            }
            cout << endl;
        }
        flag = true;

    }
}