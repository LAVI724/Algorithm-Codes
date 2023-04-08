#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
// 2022.09.24

map<char, int> mp;
char keyb[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

void king(string start, string end){
    if(start == end){ 
        cout << 0 << " ";
        return;
    }

    if(mp[start[0]] == mp[end[0]]){
        cout << abs((start[1] - '0') - (end[1] - '0')) << " ";
        return;
    }
    else if(start[1] == end[1]){
        cout << abs(mp[start[0]] - mp[end[0]]) << " ";
        return;
    }
    
    for(int i = 0; i < 8; ++i){
        if(abs(mp[start[0]] - mp[end[0]]) == abs((start[1] - '0') - (end[1] - '0'))){
            cout << abs((start[1] - '0') - (end[1] - '0')) << " ";
            return;
        }
    }

    if(abs(mp[start[0]] - mp[end[0]]) > abs((start[1] - '0') - (end[1] - '0'))){
        cout << abs((start[1] - '0') - (end[1] - '0')) + abs(abs(mp[start[0]] - mp[end[0]]) - abs((start[1] - '0') - (end[1] - '0'))) << " ";
    }
    else{
        cout << abs(mp[start[0]] - mp[end[0]]) + abs(abs(mp[start[0]] - mp[end[0]]) - abs((start[1] - '0') - (end[1] - '0'))) << " ";
    }
}

void queen(string start, string end){
    if(start == end){ 
        cout << 0 << " ";
        return;
    }

    if(mp[start[0]] == mp[end[0]]){
        cout << 1 << " ";
        return;
    }
    else if(start[1] == end[1]){
        cout << 1 << " ";
        return;
    }
    
    for(int i = 0; i < 8; ++i){
        if(abs(mp[start[0]] - mp[end[0]]) == abs((start[1] - '0') - (end[1] - '0'))){
            cout << 1 << " ";
            return;
        }
    }

    cout << 2 << " ";
    return;
}

void rook(string start, string end){
    if(start == end){ 
        cout << 0 << " ";
        return;
    }

    if(mp[start[0]] == mp[end[0]]){
        cout << 1 << " ";
        return;
    }
    else if(start[1] == end[1]){
        cout << 1 << " ";
        return;
    }

    cout << 2 << " ";
    return;
}

void bishop(string start, string end){
    if(start == end){ 
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < 8; ++i){
        if(abs(mp[start[0]] - mp[end[0]]) == abs((start[1] - '0') - (end[1] - '0'))){
            cout << 1 << endl;
            return;
        }
    }

    for(int i = 0; i < 8; ++i){
        if((abs(mp[start[0]] - mp[end[0]]) + abs((start[1] - '0') - (end[1] - '0')) % 2 == 0)){
            cout << 2 << endl;
            return;
        }
    }

    cout << "Inf" << endl;
    return;
}

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < 8; ++i){
        mp[keyb[i]] = i + 1;
    }

    while(t--){
        string start, end;
        cin >> start >> end;

        king(start, end);
        queen(start, end);
        rook(start, end);
        bishop(start, end);
    }
}