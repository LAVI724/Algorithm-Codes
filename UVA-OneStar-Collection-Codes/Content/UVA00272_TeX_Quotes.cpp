#include<bits/stdc++.h>
using namespace std;
//2021.06.29

int main(){
    string str;
    int flag = 0;
    while( getline(cin, str) ){
        for( int i = 0 ; i < str.size() ; i++ )
            if( str[i] == '"' && flag == 0 ){
                cout << "``";
                flag = 1;
            }
            else if( str[i] == '"' && flag ==1 ){
                cout << "''";
                flag = 0;
            }
            else if( str[i] == '.'){
                cout << str[i];
                flag = 0;
            }
            else{
                cout << str[i];
            }
        cout << endl; 
        str.clear();
    }
}