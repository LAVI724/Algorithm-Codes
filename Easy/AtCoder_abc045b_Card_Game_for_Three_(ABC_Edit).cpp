#include<bits/stdc++.h>
using namespace std;
// 2022.06.15


int main(){
    string str;
    deque<char> a, b, c;

    cin >> str;
    for(int j = 0; j < str.size(); j++){
        a.emplace_back(str[j]);
    }

    cin >> str;
    for(int j = 0; j < str.size(); j++){
        b.emplace_back(str[j]);
    }

    cin >> str;
    for(int j = 0; j < str.size(); j++){
        c.emplace_back(str[j]);
    }

    char n = a.front();
    a.pop_front();

    while(true){
        if(n == 'a'){
            if(a.empty()){
                cout << "A" << endl;
                break;
            }
            n = a.front();
            a.pop_front();

        }
        else if(n == 'b'){
            if(b.empty()){
                cout << "B" << endl;
                break;
            }
            n = b.front();
            b.pop_front();
        }
        else if(n == 'c'){
            if(c.empty()){
                cout << "C" << endl;
                break;
            }
            n = c.front();
            c.pop_front();
        }
    }
}