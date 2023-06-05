#include<bits/stdc++.h>
using namespace std;
//2021.08.25

int main(){

    int n, count = 1;
    while( cin >> n ){
        bool flag = false;
        deque<int> num;
        num.clear();
        deque<int> check;
        check.clear();
        deque<int>::iterator it;

        for( int i = 0; i < n; i++ ){
            int b;
            cin >> b;
            if( b == 0 || b < 0 || n == 1 ){
                flag = true;
            }
            num.push_back(b);
        }

        for( int i = 0; i < n; i++ ){
            
            if( flag ){
                break;
            }

            for( int j = i; j < n ; j++ ){
                
                if( num [i] > num[j] ){
                    flag = true;
                    break;
                }

                it = find( check.begin(), check.end(), num[i] + num[j] );
                if( it != check.end() ){
                    flag = true;
                    break;
                }
                else{
                    check.push_back( num[i] + num[j] );
                }

            }
        }
        cout << "Case #" << count;
        count++;
        if( flag ){
            cout << ": It is not a B2-Sequence." << endl;
        }
        else{
            cout << ": It is a B2-Sequence." << endl;
        }
        cout << endl;
    }
}