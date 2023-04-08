#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    bool space = false;
    string str;

    cin >> t;
    cin.ignore();
    while(t--){
        if(space){
            cout << endl;
        }

        getline(cin, str);
        getline(cin, str);

        bool flag = false;
        for(int i = 1; i <= str.size() && !flag; i++){
            string sub = str.substr(0, i);
            if(str.size() % sub.size() != 0) continue;

            string laststr = str.substr(i);
            for(int j = 1; j < str.size()/i; j++){
                if(laststr.substr(0, i) != sub){
                    break;
                }
                else if(j == str.size()/i -1){
                    cout << sub.size() << endl;
                    flag = true;
                }
                else{
                    laststr = laststr.substr(i);
                }
            }
        }

        if(!flag){
            cout << str.size() << endl;
        }
        space = true;
    }
}