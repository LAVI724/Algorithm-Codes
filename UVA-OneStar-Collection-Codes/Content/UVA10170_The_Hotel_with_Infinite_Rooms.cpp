#include<bits/stdc++.h>
using namespace std;
//2021.07.09

int main(){
   long long int s, d;
   while( cin >> s >> d ){
        long long int flag = s;
        while(d>0){
           d -= s;
           s++;
           flag++;
        }
        cout << flag-1 << endl;
    } 
}