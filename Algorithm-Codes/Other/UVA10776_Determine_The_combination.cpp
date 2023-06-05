#include<bits/stdc++.h>
using namespace std;
//2021.10.18

string s;
int r;
bool letter[26];
deque<char> tmp;

void dps( int depth ){

    cout << r;
    if( tmp.size() == r ){
        
        for( int i = 0; i < tmp.size(); i++ ){
            printf("%c", tmp[i]);
        }
        
        printf("\n");
        tmp.pop_back();
        return;
    }

    for( int i = depth; i < s.size(); i++ ){
        
        cout << "hewd";
        if( !letter[ s[i]-'a' ] ){
            
            cout << "hi";
            letter[ s[i]-'a' ] = true;
            tmp.push_back(s[i]);

            dps(i + 1);

        }
    }

}

int main(){

    while( scanf("%s %d", &s, &r) ){

        memset( letter, false, sizeof(letter) );
        sort( s.begin(), s.end() );
        
        dps(0);
        tmp.clear();

    }

}