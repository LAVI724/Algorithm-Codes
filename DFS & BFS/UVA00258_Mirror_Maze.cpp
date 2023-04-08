#include<bits/stdc++.h>
using namespace std;
// 2022.05.25

int m, n;
int start_direct, nx, ny, nx_direct;
int start_x, start_y, end_x, end_y;

bool space, ans;
bool visited[50+5][50+5];

char arr[50+5][50+5];
int step_x[4] = {-1, 0, 1, 0};
int step_y[4] = {0, 1, 0, -1};

void dfs(int x, int y, int direct){
    if(ans) return;

    if(x == end_x && y == end_y){
        ans = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        return;
    }

    if(arr[x][y] == '.'){
        nx = x + step_x[direct];
        ny = y + step_y[direct];
        dfs(nx, ny, direct);
    }
    else if(arr[x][y] == '*'){
        return;
    }
    else{
        if(arr[x][y] == '/'){
            bool tmp = visited[x][y];
            visited[x][y] = true;

            // direct xor 1 為鏡子新旋轉的結果 2 xor 1 = 3, 3 xor 1 = 2, 1 xor 1 = 0, 0 xor 1 = 1
            nx_direct = direct ^ 1;

            nx = x + step_x[nx_direct];
            ny = y + step_y[nx_direct];

            dfs(nx, ny, nx_direct);

            // 把鏡子設回還沒折射過的狀態
            visited[x][y] = tmp;
            
            // 旋轉鏡子
            if(!visited[x][y]){
                visited[x][y] = true;
                arr[x][y] = '\\';

                // 換折射方向
                nx_direct = 3 - direct;

                nx = x + step_x[nx_direct];
                ny = y + step_y[nx_direct];

                dfs(nx, ny, nx_direct);

                arr[x][y] = '/';
                visited[x][y] = false;
            }
        }
        else{
            bool tmp = visited[x][y];
            visited[x][y] = true;

            nx_direct = 3 - direct;

            nx = x + step_x[nx_direct];
            ny = y + step_y[nx_direct];

            dfs(nx, ny, nx_direct);

            visited[x][y] = tmp;

            if(!visited[x][y]){
                visited[x][y] = true;
                arr[x][y] = '/';

                // direct xor 1 為鏡子新旋轉的結果 2 xor 1 = 3, 3 xor 1 = 2, 1 xor 1 = 0, 0 xor 1 = 1
                nx_direct = direct ^ 1;

                nx = x + step_x[nx_direct];
                ny = y + step_y[nx_direct];

                dfs(nx, ny, nx_direct);

                arr[x][y] = '\\';
                visited[x][y] = false;
            }
        }
    }
}

int main(){
    while(cin >> m >> n && (m != -1 && n != -1)){
        if(space) cout << endl;
        else space = true;

        ans = false;
        start_x = start_y = end_x = end_y = -1;
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];

                // 找起點
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && arr[i][j] == '.'){
                    if(start_x == -1){
                        start_x = i;
                        start_y = j;

                        // direct:
                        // 0:up, 1:right, 2:down, 3:left
                        if(i == 0){
                            start_direct = 2;
                        }
                        else if(i == n - 1){
                            start_direct = 0;
                        }
                        else if(j == 0){
                            start_direct = 1;
                        }
                        else{
                            start_direct = 3;
                        }
                    }
                    else{
                        end_x = i;
                        end_y = j;
                    }
                }
            }
        }
        dfs(start_x, start_y, start_direct);
    }
    return 0;
}