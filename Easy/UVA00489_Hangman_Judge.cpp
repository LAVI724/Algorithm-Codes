#include<bits/stdc++.h>
using namespace std;
// 2022.09.10

int main(){
    int n;
    while(cin >> n && (n != -1)){
        cout << "Round " << n << endl;

        string ans;
        map<char, int> mp;
        cin >> ans;

        int final = 0;
        char c;
        stringstream ss;
        ss << ans;
        while(ss >> c){
            mp[c] = true;
        }
        final = mp.size();

        int lose = 0, win = 0, flag = 0;
        string str;
        cin >> str;
        for(auto i : str){
            if(!mp[i]){
                lose++;
                mp[i] = 2;
            }
            else if(mp[i] == 1){
                win++;
                mp[i] = 2;
            }

            if(lose == 7){
                flag = 1;
                break;
            }
            else if(win == final){
                flag = 2;
                break;
            }
        }
        if(!flag) cout << "You chickened out." << endl;
        else if(flag == 1) cout << "You lose." << endl;
        else cout << "You win." << endl;
    }
}