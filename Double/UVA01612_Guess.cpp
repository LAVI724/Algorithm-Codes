#include<bits/stdc++.h>
using namespace std;
// 2022.09.26

int score[200000+5][10];

int main(){
    int n;
    int ca = 1;
    while(cin >> n && n){

        memset(score, 0, sizeof(score));
        for(int i = 1; i <= n; ++i){
            double s1, s2, s3;
            cin >> s1 >> s2 >> s3;

            score[i][0] = (int)round(s1 * 100.0);
            score[i][1] = (int)round(s2 * 100.0);
            score[i][2] = (int)round(s3 * 100.0);

            score[i][3] = score[i][0] + score[i][1];
            score[i][4] = score[i][0] + score[i][2];
            score[i][5] = score[i][1] + score[i][2];
            score[i][6] = score[i][0] + score[i][1] + score[i][2];

            for(int k = 0; k < 6; ++k){
                for(int j = k + 1; j < 6; ++j){
                    if(score[i][j] < score[i][k]) swap(score[i][k], score[i][j]);
                }
            }
        }

        int rk[20000+5];
        for(int i = 1; i <= n; ++i){
            cin >> rk[i];
        }
        
        bool flag = false;
        double maxi = score[rk[1]][6];
        for(int i = 2; i <= n; ++i){

            flag = false;
            if(rk[i] < rk[i-1]){
                for(int j = 6; j >= 0; --j){
                    if(score[rk[i]][j] < maxi){
                        maxi = score[rk[i]][j];
                        flag = true;
                        break;
                    }
                }
            }
            else{
                for(int j = 6; j >= 0; --j){
                    if(score[rk[i]][j] <= maxi){
                        maxi = score[rk[i]][j];
                        flag = true;
                        break;
                    }
                }
            }
        }

        cout << "Case " << ca++ << ": ";
        if(n == 1 || flag){
            cout << fixed << setprecision(2) << maxi/100.0 << endl;
        }
        else{
            cout << "No solution" << endl;
        }
    }
}
