#include<bits/stdc++.h>
using namespace std;
// 2022.06.24

int main(){
    string str;
    char mi[][] = { {'S', '2'}, {'E', '3'}};
    while(cin >> str){
        bool pal = false, mir = false;

        for(int i = 0, j = str.size() - 1; ; i++, j++){
            if(i == j){
                pal = true;
                break;
            }
            
            if(str[i] != str[j]) break;
        }


    }
}