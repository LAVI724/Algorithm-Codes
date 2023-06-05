#include<bits/stdc++.h>
using namespace std;
//2021.06.25

int main(){
    string a;
    char n[100+5][100+5]={'\0'};
    int i=0;
    int longer=0;
    while(getline(cin, a)){
        if(a=="\0")
            break;
        for( int j=0; j<a.size(); j++ ){
            n[i][j] = a[j];
        }
        i++;
        if(a.size()>longer)
            longer = a.size();
    }
    for( int j=0 ; j<longer ; j++ ){
        for( int k=i-1 ; k>=0; k--){
            if(n[k][j]=='\0')
                cout<<" ";
            else{
                cout<<n[k][j];
            }
        }
        cout<<endl;
    }
}