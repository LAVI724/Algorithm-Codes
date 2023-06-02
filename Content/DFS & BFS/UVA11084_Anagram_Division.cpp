#include<bits/stdc++.h>
using namespace std;
// 2022.05.09

int d, ans, s_size;
string s;
bool visited[10+5];

void dfs(int depth, string str){

    // 確認結束狀態
    if(depth == s_size){

        long long int num = 0;
		for(int i = 0; i < s_size; i++){
			num *= 10;
			num += str[i] - '0';
		}

        if(num % d){
            return;
        }
        else{
            ans++;
        }
    }

    bool used[10+5];
    memset(used, false, sizeof(used));

    for(int i = 0; i < s_size; i++){
        
        if(!visited[i] && !used[s[i] - '0']){

            visited[i] = true;
            used[s[i] - '0'] = true;

            dfs(depth + 1, str + s[i]);

            visited[i] = false;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){

        cin >> s >> d;
        memset(visited, false, sizeof(visited));

        ans = 0;
        s_size = s.size();
        dfs(0, "");

        cout << ans << endl;
    }
}