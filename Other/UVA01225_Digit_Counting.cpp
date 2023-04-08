#include<bits/stdc++.h>
using namespace std;
// 2022.09.23

/*
程競 110-1 week2

感謝建中提供構思
*/

int maxi = 1;
int num[100000+5][10];

void count(int N){
    for(int i = maxi; i <= N; ++i){
        int tmp = i;

        for(int j = 0; j <= 9; ++j){
            num[i][j] = num[i-1][j];
        }

        while(tmp > 0){
            num[i][tmp % 10]++;
            tmp /= 10;
        }
    }
    maxi = N;
}

int main(){
    int t;
    cin >> t;

    memset(num, 0, sizeof(num));
    while(t--){
        int N;
        cin >> N;

        if(N > maxi) count(N);

        for(int i = 0; i < 9; ++i){
            cout << num[N][i] << " ";
        }
        cout << num[N][9] << endl;
    }
}