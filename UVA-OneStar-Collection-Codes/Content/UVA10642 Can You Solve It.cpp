#include<bits/stdc++.h>
using namespace std;
// 2022/02/08

int main(){
    int t;
    int x1, y1, x2, y2;
    int ca = 1;
    
    cin >> t;
    while(t--){
        cin >> x1 >> y1;
        long long int start = 0;
        for(int i = 0; i < x1+y1; i++){
            start += i+1;
        }
        start += x1;

        cin >> x2 >> y2;
        long long int end = 0;
        for(int i = 0; i < x2+y2; i++){
            end += i+1;
        }
        end += x2;

        cout << "Case " << ca++ << ": " << end - start << endl;
    }
}