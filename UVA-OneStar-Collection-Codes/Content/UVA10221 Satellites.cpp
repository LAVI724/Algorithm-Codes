#include<bits/stdc++.h>
using namespace std;
// 2022/02/08

int main(){
    double s, a;
    string str;
    double r = 6440;
    while(cin >> s >> a >> str){
        if(str == "min"){
            // 一度 = 60 分
            a /= 60;
        }
        while(a >= 360){
            a -= 360;
        }
        if(a > 180){
            a = 360 - a;
        }

        // arc 弧長 = n（圓心角）× π（圓周率）× r（半徑）/180
        // PI = 2 * acos(0.0)
        double arc =  a * (2.0 * acos(0.0)) * (r+s) / 180.0;
        // chord = 半徑 * sin(弧度) * 2 by 畫中垂線
        // 弧度 = 角度 * π/180
        double chord = (r+s) * sin(a/2.0 * (2.0 * acos(0.0))/180.0 ) * 2.0;
        cout << fixed << setprecision(6) << arc << " " << chord << endl;
    }
    return 0;
}