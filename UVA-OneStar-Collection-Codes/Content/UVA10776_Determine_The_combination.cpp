#include<bits/stdc++.h>
using namespace std;
//2021.10.18

string str;
int r;
deque<char> tmp;

void dps( int depth ){

    if( tmp.size() == r ){
        
        for( int i = 0; i < tmp.size(); i++ ){
            printf("%c", tmp[i]);
        }
        
        printf("\n");
        return;
    }
    
    for( int i = depth; i < str.length();){
        
        char c = str[i];
        tmp.push_back(str[i]);
        
        dps(i + 1);
        tmp.pop_back();

        // 利用 c 來判斷是否要跳過 str[i]
        while( str[i] == c ){
            i++;
        }
        
    }
}

int main(){

    while( cin >> str >> r ){
        
        sort( str.begin(), str.end() );
        
        dps(0);
        tmp.clear();

    }

}