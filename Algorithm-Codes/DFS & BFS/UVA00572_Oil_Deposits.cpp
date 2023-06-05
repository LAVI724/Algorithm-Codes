#include<bits/stdc++.h>
using namespace std;
// 2022.02.17

int m, n;
char field[1000+5][1000+5];

int step[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs(int xn, int yn){

	for(int i = 0; i < 8; i++){
		int xx = xn + step[i][0];
		int yx = yn + step[i][1];

		if(xx >= 0 && xx < m && yx >= 0 && yx < n && field[xx][yx] == '@'){
			field[xx][yx] = '.';
			dfs(xx, yx);
		}
	}
}

int main(){

	while(cin >> m >> n && m && n){
	
		memset(field, '.', sizeof(field));

		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> field[i][j];
			}
		}

		int cnt = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(field[i][j] == '@'){
					cnt++;
					dfs(i, j);
				}
			}
		}

		cout << cnt << endl;
	}
}