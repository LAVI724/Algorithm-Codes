#include<bits/stdc++.h>
using namespace std;
//2021.07.09

int main(){

    int s;
    int n, i;
    double p;

    cin >> s;

    while( s-- ){

        cin >> n >> p >> i;

        double p2;

        p2 = pow( 1.0 - p , n );

        if( p2 == 1){

            cout << "0.0000" << endl;
            continue;

        }

        double ans;
        
        //第i個人成功的機率 / 全部的人有機會成功的機率(1-全部人都失敗)
        ans = p * pow( 1.0 - p , i-1 ) / ( 1.0 - pow( 1.0 - p , n ) );

        cout << fixed << setprecision(4) << ans <<endl;
    }
}