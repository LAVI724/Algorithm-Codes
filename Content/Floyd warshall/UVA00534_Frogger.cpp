#include<bits/stdc++.h>
using namespace std;
// 2023.02.16

const int maxn = 200+5;

double distance(int x1, int y1, int x2, int y2){
    return sqrt(((x1 - x2) * (x1 - x2)) + (y1 - y2) * (y1 - y2));
}

int N;
double dp[maxn][maxn];
void FloydWarshall(){
    for(int k = 0; k < N; ++k){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                double maxi = max(dp[i][k], dp[k][j]);
                if(maxi < dp[i][j]) dp[i][j] = maxi;
            }
        }
    }
}

int main(){
    int Case = 1;
    while(cin >> N && N){
        int x[maxn], y[maxn];
        for(int i = 0; i < N; ++i){
            cin >> x[i] >> y[i];
        }

        memset(dp, 0.0, sizeof(dp));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                dp[i][j] = distance(x[i], y[i], x[j], y[j]);
            }
        }

        FloydWarshall();
        cout << "Scenario #" << Case++ << "Frog Distance = " << fixed << setprecision(3) << dp[0][1] << endl;
    }
}