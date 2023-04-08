#include<bits/stdc++.h>
using namespace std;
// 2022.03.21

int main(){
    int t;
    int ca = 1;
    cin >> t;

    int n;
    char field[100+5];
    while(t--){
        cin >> n;
        memset(field, '#', sizeof(field));

        for(int i = 0; i < n; i++){
            cin >> field[i];
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(field[i] == '.'){
                cnt++;
                field[i+1] = '#';
                field[i+2] = '#';
            }
        }

        cout << "Case " << ca++ << ": " << cnt << endl;
    }
}