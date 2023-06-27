#include<bits/stdc++.h>
using namespace std;
// 2023.06.26 PUPC 模擬賽 2

/*
二分圖匹配 + 最小點覆蓋
參考資料：
https://blog.nowcoder.net/n/71182cf43562423d8d35bbf73e4ace68?from=nowcoder_improve
*/

const int maxn = 1000+5;

int R, C, N;
bool arr[maxn][maxn];
bool visitX[maxn], visitY[maxn];
int matchX[maxn], matchY[maxn];

int dfs(int x){
    visitX[x] = true;

    for(int y = 1; y <= C; ++y){
        if(arr[x][y] && !visitY[y]){
            visitY[y] = true;
            if(matchY[y] == 0 || dfs(matchY[y])){
                matchX[x] = y;
                matchY[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

int Match(){
    int sum = 0;
    memset(matchX, 0, sizeof(matchX));
    memset(matchY, 0, sizeof(matchY));

    for(int i = 1; i <= R; ++i){
        memset(visitX, false, sizeof(visitX));
        memset(visitY, false, sizeof(visitY));
        sum += dfs(i);
    }
    return sum;
}
int main(){
    while(cin >> R >> C >> N && R && C && N){
        memset(arr, false, sizeof(arr));
        memset(visitX, false, sizeof(visitX));
        memset(visitY, false, sizeof(visitY));

        int row, col;
        for(int i = 0; i < N; ++i){
            cin >> row >> col;
            arr[row][col] = true;
        }
        
        int cnt = Match();
        cout << cnt;

        memset(visitX, 0, sizeof(visitX));
        memset(visitY, 0, sizeof(visitY));

        for(int i = 1; i <= R; ++i){
            if(matchX[i] == 0){
                dfs(i);
            }
        }
        for(int i = 1; i <= R; ++i){
            if(!visitX[i]) cout << " r" << i;
        }
        for(int i = 1; i <= C; ++i){
            if(visitY[i]) cout << " c" << i;
        }
        cout << endl;
    }
}