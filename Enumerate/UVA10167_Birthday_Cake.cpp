#include<bits/stdc++.h>
using namespace std;
// 2022.03.11

struct Edge{
    int x;
    int y;
}edge[100+5];

int main(){
    int n;
    while(cin >> n && n){
        for(int i = 0; i < 2*n; i++){
            cin >> edge[i].x >> edge[i].y;
        }

        bool flag = false;
        for(int i = -500; i <= 500 && !flag; i++){
            for(int j = -500; j <= 500 && !flag; j++){
                int left = 0, right = 0;
                flag = false;
                for(int k = 0; k < 2*n; k++){
                    if(i*edge[k].x + j*edge[k].y == 0) break;
                    if(i*edge[k].x + j*edge[k].y < 0) left++;
                    if(i*edge[k].x + j*edge[k].y > 0) right++;

                    if(left == n && right == n){
                        cout << i << " " << j << endl;
                        flag = true;
                    }
                }
            }
        }
    }
}