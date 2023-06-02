#include<bits/stdc++.h>
using namespace std;
// 2022.06.02

/*
解題思維:
這題 n q 很大 要用技巧判斷 不能直接 bfs
*/

int n, q;
int visited[3][100000+5];

int main(){
    int x, y;
    cin >> n >> q;
    memset(visited, 0, sizeof(visited));

    int cnt = 0;
    for(int i = 0; i < q; i++){
        cin >> x >> y;

        if(visited[x][y]){
            visited[x][y] = 0;

            if(x == 1){
                cnt -= visited[2][y-1];
                cnt -= visited[2][y];
                cnt -= visited[2][y+1];
            }
            else{
                cnt -= visited[1][y-1];
                cnt -= visited[1][y];
                cnt -= visited[1][y+1];
            }
        }
        else{
            visited[x][y] = 1;

            if(x == 1){
                cnt += visited[2][y-1];
                cnt += visited[2][y];
                cnt += visited[2][y+1];
            }
            else{
                cnt += visited[1][y-1];
                cnt += visited[1][y];
                cnt += visited[1][y+1];
            }
        }

        if(cnt != 0){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}