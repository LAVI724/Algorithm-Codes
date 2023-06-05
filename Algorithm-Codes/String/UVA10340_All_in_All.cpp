#include<bits/stdc++.h>
using namespace std;
//2021.06.27

int main(){
    string str1;
    string str2;
    while( cin >> str1 >> str2 ){
        bool flag = 0;

        int i=0;
        for( int j=0; j<str2.size(); j++ ){
            if( str2[j] == str1[i]){
                i++;
            }
        }
        if( i == str1.size() )
            cout<<"Yes"<<endl;
        else{
            cout<<"No"<<endl;
        }
    // if( isupper(str2[i]) )    
    //    size_t found = str2.find(str1,0);
       str1.clear();
       str2.clear();
    }
}