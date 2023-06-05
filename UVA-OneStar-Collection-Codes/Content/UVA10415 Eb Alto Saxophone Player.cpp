#include<bits/stdc++.h>
using namespace std;
// 2022/02/12

int main(){
    int t;
    string ptr = "cdefgabCDEFGAB";
    string num[14] = {  "00111001111",
                        "00111001110",
                        "00111001100",
                        "00111001000",
                        "00111000000",
                        "00110000000",
                        "00100000000",
                        "00010000000",
                        "01111001110",
                        "01111001100",
                        "01111001000",
                        "01111000000",
                        "01110000000",
                        "01100000000" };
    cin >> t;
    cin.ignore();
    
    while(t--){
        int finger[10+5];
        string str;

        getline(cin, str);
        memset(finger, 0, sizeof(finger));

        int last;
        for(int i = 0; i < str.size(); i++){
            int pt = ptr.find(str[i]);
            for(int j = 0; j <= 10; j++){
                if(i == 0 && num[pt][j] - '0'){
                    finger[j]++;
                }
                else if((num[pt][j] - '0') - (num[last][j] - '0') == 1){
                    finger[j]++;
                }
            }
            last = pt;
        }

        for(int i = 1; i < 10; i++){
            cout << finger[i] << " ";
        }
        cout << finger[10] << endl;
    }
}