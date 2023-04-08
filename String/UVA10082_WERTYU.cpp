#include<bits/stdc++.h>
using namespace std;
// 2022.06.24

int main(){
    string str;
    char ori[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./ ";
    char chan[] = "=`1234567890-\\QWERTYUIOP[]'ASDFGHJKL;/ZXCVBNM,. ";

    while(getline(cin, str)){
        for(int i = 0; i < str.size(); i++){
            for(int j = 0; j < sizeof(ori); j++){
                if(str[i] == ori[j]){
                    cout << chan[j];
                    break;
                }
            }
        }
        cout << endl;
    }
}