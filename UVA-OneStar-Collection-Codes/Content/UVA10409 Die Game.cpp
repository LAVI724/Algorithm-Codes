#include<bits/stdc++.h>
using namespace std;
// 2022/02/12

int main(){
    int n;
    while(cin >> n && n){
        
        int die[3][4];
        string str;
        memset(die, 0, sizeof(die));
        
        die[0][0] = 2;
        die[1][0] = 1;
        die[1][1] = 4;
        die[1][2] = 6;
        die[1][3] = 3;
        die[2][0] = 5;
        
        for(int i = 0; i < n; i++){
            cin >> str;

            int tmp;
            if(str == "north"){
                tmp = die[1][0];
                die[1][0] = die[2][0];
                die[2][0] = die[1][2];
                die[1][2] = die[0][0];
                die[0][0] = tmp;
            }
            else if(str == "south"){
                tmp = die[1][0];
                die[1][0] = die[0][0];
                die[0][0] = die[1][2];
                die[1][2] = die[2][0];
                die[2][0] = tmp;
            }
            else if(str == "west"){
                tmp = die[1][0];
                for(int i = 0; i < 3; i++){
                    die[1][i] = die[1][i+1];
                }
                die[1][3] = tmp;
            }
            else if(str == "east"){
                tmp = die[1][3];
                for(int i = 3; i > 0; i--){
                    die[1][i] = die[1][i-1];
                }
                die[1][0] = tmp;
            }
        }
        cout << die[1][0] << endl;
    }
}