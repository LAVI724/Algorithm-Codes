#include<bits/stdc++.h>
using namespace std;
// 2022.06.27

int main(){

    string a, b;

    while(cin >> a >> b){
        if(b.size() < a.size()){
            cout << "No\n";
        }
        else{
            
            int j = 0;

            for(int i = 0; i < b.size(); i++){
                if(a[j] == b[i]){
                    j++;
                }
            }

            if(j == a.size()){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }

    return 0;
}