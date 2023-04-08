#include<bits/stdc++.h>
using namespace std;
// 2022.06.17

int main(){
    string str = "";
    for(int i = 0; i < 10; i++){
        str += "oxx";
    }
    // cout << str << endl;
    
    string ss;
    bool flag = false;
    cin >> ss;
    int len = ss.size();
    for(int i = 0; i < str.size() - ss.size(); i++){
        string sub = str.substr(i, len);
        // cout << sub << endl;

        if(sub == ss){
            cout << "Yes" << endl;
            flag = true;
            break;
        }
    }

    if(!flag){
        cout << "No" << endl;
    }
}